#include "Jugador.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
/**
typedef struct {
    int         Id;                  //(entero): campo identificador del jugador.
    char        Nombre[40];              //(cadena): nombre del jugador.
    int         Goles;               //(entero): Cantidad de goles Convertidos (los goles en contra restan).
}Jugador;
*/

using namespace std;

void cargarJugadores(Lista &listaJugadores){
    FILE *f;
    f = fopen("jugadores.txt","r++");

    crearLista(listaJugadores,listaJugadores.compara);

    while(!feof(f)){
        Jugador *j = new Jugador;

        fscanf(f,"%d;%[^;];%d;%d\n",&j->Id,&j->Nombre,&j->Goles,&j->idEquipo);

        if(listaVacia(listaJugadores)){
            adicionarPrincipio(listaJugadores,j);

        }
        else{
            adicionarFinal(listaJugadores,j);
        }

    }
    fclose(f);
}

void crearJugador(Jugador &nuevoJugador){
    SetJugador(nuevoJugador,0,"a",0);
    setJugadorIdEquipo(nuevoJugador,1);
}
//------------------------------------------------------------------------
void SetJugador(Jugador &Jugador,int _id,char _nombre[40],int _goles){
    Jugador.Id = _id;
    strcpy(Jugador.Nombre,_nombre);
    Jugador.Goles = _goles;
}

void setJugadorId(Jugador &Jugador,int _id){
    Jugador.Id = _id;
}

void setJugadorNombre(Jugador &Jugador,char _nombre[40]){
    strcpy(Jugador.Nombre,_nombre);
}

void setJugadorGoles(Jugador &Jugador,int _goles){
    Jugador.Goles = _goles;
}

void setJugadorIdEquipo (Jugador &Jugador, int _idEquipo){
    Jugador.idEquipo = _idEquipo;
}
//------------------------------------------------------------------------

int getIdJugador(Jugador &jugador){
    return(jugador.Id);
}

int getGolesJugador(Jugador &jugador){
    return(jugador.Goles);
}

char *getNombreJugador(Jugador &jugador){
    return(jugador.Nombre);
}

int getJugadorIdEquipo(Jugador &jugador){
    return (jugador.idEquipo);
}

//------------------------------------------------------------------------

bool BuscarIdExistenteJugador(Lista &listaJugadores,int _id){

    PtrNodoLista cursor = primero(listaJugadores);
    bool encontrado = false;

    while (cursor != fin()){

        if(((Jugador*)cursor->ptrDato)->Id == _id){
            encontrado = true;
        }

        cursor = siguiente(listaJugadores,cursor);
    }
    return(encontrado);
}


bool AltaJugador(Lista &listaJugadores){

    bool exito = true;
    int _id,goles = 0,idEquipo=0;
    char nombre[40];

    Jugador *j = new Jugador;

    cout<<"ingrese el ID del jugador que va a añadir"<<endl;
    cin >> _id;

    if(BuscarIdExistenteJugador(listaJugadores,_id) == true){
        exito = false;                                          //YA EXISTE UNA ID igual
        cout<<"Ya existe la ID ingresado"<<endl;
    }

    else{
        fflush(stdin);

        cout <<"ingrese nombre: " << endl;
        cin.getline(nombre,40);

        SetJugador(*j,_id,nombre,goles);

        adicionarFinal(listaJugadores,j);

        system ("cls");

        exito = true;
    }

    return (exito);
}


bool BajaJugador(Lista &listaJugadores){
    bool exito = false;
    int id,idaux,goles,idEquipo;
    char nombre[40];

    cout << " Estas en baja de Equipo, si el Id del equipo se repite se eliminara todo los id qye sea igualal id que desea dar de baja"<<endl;
    cout << " ingrese id Del Equipo a dar de baja: "<<endl;
    cin >> id;

    if(  BuscarIdExistenteJugador(listaJugadores,id) != true){
        system ("cls");
        cout << "este id no Existe" << endl;
    }

    else {

        PtrNodoLista cursor = primero(listaJugadores);

        while (cursor != fin()) {

            if ( ((Jugador*)cursor->ptrDato)->Id == id){

                eliminarNodo(listaJugadores,cursor);

                exito = true;

            }

            cursor = siguiente(listaJugadores, cursor);
        }
    }

    return exito;
}


bool ModificacionJugador(Lista &listaJugadores){
    int _Goles,_id,_idEquipo;
    char _nombre[40];
    bool exito = false;

    PtrNodoLista cursor = primero(listaJugadores);

    cout << " Estas en Modificacion de Jugador, Ingrese la ID del Jugador que desea modificar"<<endl;
    cin >> _id;

    if(BuscarIdExistenteJugador(listaJugadores,_id) != true){
        system ("cls");
        cout << " No existe id en la lista equipo"<<endl;
        exito = false;
    }

    //si existe hace todo esto para modificarlo
    else{

        fflush(stdin);

        cout << " ingrese nombre: "<<endl;
        cin.getline(_nombre,40);
        cout << " ingrese goles: "<<endl;
        cin >> _Goles;
        cout << " ingrese goles: "<<endl;
        cin >> _idEquipo;

        while (cursor != fin()) {

            if ( ((Jugador*)cursor->ptrDato)->Id == _id){

                strcpy(((Jugador*)cursor->ptrDato)->Nombre,_nombre);
                ((Jugador*)cursor->ptrDato)->Goles = _Goles;
                ((Jugador*)cursor->ptrDato)->idEquipo = _idEquipo;

                exito = true;
            }

            cursor = siguiente(listaJugadores, cursor);

        }

    }

    return exito;
}


bool buscarJugador(Lista &listaJugadores,int idequipo,int idjugador){
    bool encontrado = false;
        PtrNodoLista cursor   = primero(listaJugadores);
        while (cursor != fin()) {
            if(  ((Jugador*)cursor->ptrDato)->Id == idjugador && ((Jugador*)cursor->ptrDato)->idEquipo == idequipo){
                encontrado = true;
            }

            cursor = siguiente(listaJugadores, cursor);
        }

       return encontrado;
}


void remplazardatosdeauxiliarenoriginalJugador(Lista &listajugadores,Lista &listaaux){
PtrNodoLista cursor = primero(listajugadores);
     PtrNodoLista cursor2 = primero(listaaux);
        int i=0;

        while (cursor != fin()) {
           while (cursor2 != fin()) {

               if ( ((Jugador*)cursor->ptrDato)->Id == ((Jugador*)cursor2->ptrDato)->Id) {

                    ((Jugador*)cursor->ptrDato)->Goles = ((Jugador*)cursor2->ptrDato)->Goles;
               }

            cursor2 = siguiente(listaaux, cursor2);
        }
            cursor = siguiente(listajugadores,cursor);
            cursor2 = primero(listaaux);

        }

}


bool buscarIdjugador(Lista &listaJugadores,int id){
    bool encontrado = false;
    PtrNodoLista cursor = primero(listaJugadores);
        while (cursor != fin()) {
                if( ((Jugador*)cursor->ptrDato)->Id == id  ){
                    encontrado = true;
                }

            cursor = siguiente(listaJugadores, cursor);
        }
        return encontrado;
}








//------------------------------------------------------------------------
void ObtenerDatoListaJugadores(Lista &listaJugadores,PtrNodoLista cursor,Jugador &jugador){
    jugador.Id = ((Jugador*)cursor->ptrDato)->Id;
    jugador.Goles = ((Jugador*)cursor->ptrDato)->Goles;
    jugador.idEquipo = ((Jugador*)cursor->ptrDato)->idEquipo;
    strcpy(jugador.Nombre,((Jugador*)cursor->ptrDato)->Nombre);
}


void JugadorMeteGol(Lista &listaJugadores,PtrNodoLista &cursor){
    ((Jugador*)cursor->ptrDato)->Goles = ((Jugador*)cursor->ptrDato)->Goles +1;
}


void GolEnContraJugador(Lista &listaJugadores,PtrNodoLista &cursor){
    ((Jugador*)cursor->ptrDato)->Goles = ((Jugador*)cursor->ptrDato)->Goles - 1;
}


void MeterGolDeJugadorEnEquipo(Lista &listaJugadores,int idjugador){
    PtrNodoLista cursor;
    Jugador jugador;
    cursor = primero(listaJugadores);

    // ACA SUMA LA CANTIDAD DE GOLES EN LA LISTA AUXILIAR para el jugador
    while( cursor != fin()){
        ObtenerDatoListaJugadores(listaJugadores,cursor,jugador);

        if (  getIdJugador(jugador) == idjugador) JugadorMeteGol(listaJugadores,cursor);

        cursor = siguiente(listaJugadores,cursor);
    }

}


void MeterGolEnContraDeJugadorEnEquipo(Lista &listaJugadores,int idjugador){
    PtrNodoLista cursor;
    Jugador jugador;
    cursor = primero(listaJugadores);

    while( cursor != fin()){

        ObtenerDatoListaJugadores(listaJugadores,cursor,jugador);

        if (  getIdJugador(jugador) == idjugador) {
            GolEnContraJugador(listaJugadores,cursor);
        }

        cursor = siguiente(listaJugadores,cursor);
    }

}

void GuardarJugadores(Lista &listaJugadores){

    int idaux,Goles,idEquipo;
    char nombre1[40];

    FILE *faux;
    faux = fopen("jugadoraux.txt","w++");

    PtrNodoLista cursor = primero(listaJugadores);

    while (cursor != fin()){

            idaux = ((Jugador*)cursor->ptrDato)->Id;
            strcpy(nombre1,((Jugador*)cursor->ptrDato)->Nombre);
            Goles = ((Jugador*)cursor->ptrDato)->Goles;
            idEquipo = ((Jugador*)cursor->ptrDato)->idEquipo;

            fprintf(faux,"%d;%s;%d;%d\n",idaux,nombre1,Goles,idEquipo);

            cursor = siguiente(listaJugadores, cursor);
    }
    fclose(faux);
    remove("jugadores.txt");
    rename("jugadoraux.txt","jugadores.txt");

}

