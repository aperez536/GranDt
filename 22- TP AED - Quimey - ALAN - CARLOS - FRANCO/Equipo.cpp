#include "Equipo.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <string.h>
#include "Jugador.h"

using namespace std;


void crearEquipo(Equipo &equipo){
    equipo.Id = 1;
    equipo.Nombre[0]='a';
    equipo.Goles_A_Favor=0;
    equipo.Goles_En_Contra=0;
    equipo.Puntos=0;
}


void SetEquipo(Equipo &equipo,int _id,char _nombre[40],int _Goles_a_favor, int _Goles_en_contra, int _puntos){
    equipo.Id = _id;
    strcpy(equipo.Nombre,_nombre);
    equipo.Goles_A_Favor=_Goles_a_favor;
    equipo.Goles_En_Contra= _Goles_en_contra;
    equipo.Puntos = _puntos;
}





int getIdEquipo(Equipo &equipo){
    return(equipo.Id);
}


int getGoles_A_Favor(Equipo &equipo){
    return(equipo.Goles_A_Favor);
}


int getGoles_En_Contra(Equipo &equipo){
    return(equipo.Goles_En_Contra);
}


int getPuntos(Equipo &equipo){
    return(equipo.Puntos);
}


char *getNombreEquipo(Equipo &equipo){
    return equipo.Nombre;
}


//------------------------------------------------------------------------


void cargarListaEquipo(Lista &ListaEquipo){
FILE *f;
f = fopen("equipos.txt","r++");

crearLista(ListaEquipo,ListaEquipo.compara);

while(!feof(f)){
    Equipo *eq = new Equipo;

    fscanf(f,"%d;%[^;];%d;%d;%d\n",&eq->Id,eq->Nombre,&eq->Goles_A_Favor,&eq->Goles_En_Contra,&eq->Puntos);

    if(listaVacia(ListaEquipo)){
        adicionarPrincipio(ListaEquipo,eq);

    }
    else{
        adicionarFinal(ListaEquipo,eq);
    }

}
fclose(f);
}


bool BuscarIdExistenteEquipo(Lista &listaEquipo,int id){

    bool encontrado = false;
        PtrNodoLista cursor = primero(listaEquipo);
        while (cursor != fin()) {
             if ( ((Equipo*)cursor->ptrDato)->Id == id)
                encontrado = true;
            cursor = siguiente(listaEquipo, cursor);
        }
        return encontrado;
}


bool Altaequipo(Lista &listaEquipo){
    bool exito= false;
    Equipo *e = new Equipo;

    int id,golesAFavor=0,GolenEnContra=0,puntos=0;
    char nombre[40];
    cout << "ingrese Id del equipo:"<< endl;
    cin >> id;

    if(  BuscarIdExistenteEquipo(listaEquipo,id) == true){
        cout << "este id ya hiciste" << endl;
    }

    else{
    cout <<"ingrese nombre: " << endl;
    fflush(stdin);
    cin.getline(nombre,40);

    SetEquipo(*e,id,nombre,golesAFavor,GolenEnContra,puntos);

    adicionarFinal(listaEquipo,e);

    exito = true;

    }

    return exito;


}


bool Bajaequipo(Lista &listaEquipo){

    int id;

    bool exito= false;

    cout << " Estas en baja de Equipo, si el Id del equipo se repite se eliminara todo los id qye sea igualal id que desea dar de baja"<<endl;
    cout << " ingrese id Del Equipo a dar de baja: "<<endl;
    cin >> id;

    if(  BuscarIdExistenteEquipo(listaEquipo,id) != true)
        cout << "este id no hiciste" << endl;

    else{

        PtrNodoLista cursor = primero(listaEquipo);

        //cursos punta al primero de la lista lista.primero
        //si el curson es diferente a null

        while (cursor != fin()) {
                //si el valor de la id = id ingresado

            if ( ((Equipo*)cursor->ptrDato)->Id == id){
                eliminarNodo(listaEquipo,cursor);
                //el eliminarNodo ya hace todos los cambios para eliminarlo y reajustarlo como se quiere
                exito = true;

            }
            cursor = siguiente(listaEquipo, cursor);
        }

      }
        return exito;
    }


bool ModificacionEquipo(Lista &listaEquipo,int _id,char _nombre[40],int _GolesAFavor,int _GolesEnContra,int _puntos){

    bool exito= false;

    PtrNodoLista cursor = primero(listaEquipo);

    //cursos punta al primero de la lista lista.primero
    //si el curson es diferente a null

    while (cursor != fin()) {

        //si el valor de la id = id ingresado
        if ( ((Equipo*)cursor->ptrDato)->Id == _id){

            strcpy(((Equipo*)cursor->ptrDato)->Nombre,_nombre);
            ((Equipo*)cursor->ptrDato)->Goles_A_Favor = _GolesAFavor ;
            ((Equipo*)cursor->ptrDato)->Goles_En_Contra = _GolesEnContra;
            ((Equipo*)cursor->ptrDato)->Puntos = _puntos;

            exito = true;
        }

        cursor = siguiente(listaEquipo, cursor);
    }

    return exito;
}



void ObtenerDatoListaEquipo(Lista &listaEquipo,PtrNodoLista cursor,Equipo &equipo){

    equipo.Id= ((Equipo*)cursor->ptrDato)->Id;
    equipo.Goles_A_Favor= ((Equipo*)cursor->ptrDato)->Goles_A_Favor;
    equipo.Goles_En_Contra= ((Equipo*)cursor->ptrDato)->Goles_En_Contra;
    equipo.Puntos= ((Equipo*)cursor->ptrDato)->Puntos;

    strcpy(equipo.Nombre,((Equipo*)cursor->ptrDato)->Nombre );

    //Con esto lleno la estructura con todos los campos de la lista,
    //de tal forma de utilizarla en el main PARA que no sepan como esta armado

}


void GuardarEquipos(Lista &listaEquipo){

    int IDequ,gol_a_favor,gol_contra,puntos;
    char nombreequ [40];

    FILE *faux;
    faux = fopen("equiposaux.txt","w++");

    PtrNodoLista cursor = primero(listaEquipo);

    while (cursor != fin()){

            IDequ = ((Equipo*)cursor->ptrDato)->Id;
            gol_a_favor = ((Equipo*)cursor->ptrDato)->Goles_A_Favor;
            gol_contra = ((Equipo*)cursor->ptrDato)->Goles_En_Contra;
            puntos = ((Equipo*)cursor->ptrDato)->Puntos;
            strcpy(nombreequ,((Equipo*)cursor->ptrDato)->Nombre);

            fprintf(faux,"%d;%s;%d;%d;%d\n",IDequ,nombreequ,gol_a_favor,gol_contra,puntos);

            cursor = siguiente(listaEquipo, cursor);
    }
    fclose(faux);
    remove("equipos.txt");
    rename("equiposaux.txt","equipos.txt");
}

void RemplazarDatosDeAuxiliarEnOriginalEquipo(Lista &listaEquipo,Lista &listaaux){
    PtrNodoLista cursor = primero(listaEquipo);
     PtrNodoLista cursor2 = primero(listaaux);

        while (cursor != fin()) {
           while (cursor2 != fin()) {

               if ( ((Equipo*)cursor->ptrDato)->Id == ((Equipo*)cursor2->ptrDato)->Id) {

                    ((Equipo*)cursor->ptrDato)->Goles_A_Favor = ((Equipo*)cursor2->ptrDato)->Goles_A_Favor;
                    ((Equipo*)cursor->ptrDato)->Goles_En_Contra = ((Equipo*)cursor2->ptrDato)->Goles_En_Contra;
                     ((Equipo*)cursor->ptrDato)->Puntos =  ((Equipo*)cursor2->ptrDato)->Puntos;
               }

                cursor2 = siguiente(listaaux, cursor2);
            }
            cursor = siguiente(listaEquipo,cursor);
            cursor2 = primero(listaaux);

        }

}


