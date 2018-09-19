#include "Partido.h"
#include "Equipo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

/**
typedef struct {
    int         Id;                  //(entero): campo de identificación del partido.
    int         idEquipoL;           //(entero): Id del equipo Local.
    int         idEquipoV;           //(entero): Id del equipo Visitante.
    int         golesL;              //(entero): goles a favor equipo Local.
    int         golesV;              //(entero): goles a favor equipo Visitante.
}Partido;

*/
void cargarPartidos(Lista &listaPartidos,char direccion[]){
    FILE *f;
    f = fopen(direccion,"r++");
    crearLista(listaPartidos,listaPartidos.compara);
    while(!feof(f)){
        Partido *p = new Partido;
        fscanf(f,"%d;%d;%d;%d;%d\n",&p->Id,&p->idEquipoL,&p->idEquipoV,&p->golesL,&p->golesV);
        if(listaVacia(listaPartidos)){
            adicionarPrincipio(listaPartidos,p);

        }
        else{
            adicionarFinal(listaPartidos,p);
        }

    }
    fclose(f);
}


void crearPartido(Partido &partido)
{
    partido.Id = 0;
    partido.idEquipoL = 0;
    partido.idEquipoV = 0;
    partido.golesL = -1;
    partido.golesV = -1;
}

void SetPartido(Partido &partido, int _id, int _idEL, int _idEV, int _golesL, int _golesV){
    partido.Id = _id;
    partido.idEquipoL = _idEL;
    partido.idEquipoV = _idEV;
    partido.golesL = _golesL;
    partido.golesV = _golesV;
}


void setPartidoId(Partido &partido, int id)
{
    partido.Id = id;
}

void setPartidoIdEquipoL (Partido &partido, int idEquipoL)
{
    partido.idEquipoL = idEquipoL;
}

void setPartidoIdEquipoV (Partido &partido, int idEquipoV)
{
    partido.idEquipoV = idEquipoV;
}

void setPartidoGolesL (Partido &partido, int golesL)
{
    partido.idEquipoL = golesL;
}

void setPartidoGolesV (Partido &partido, int golesV)
{
    partido.golesV = golesV;
}

int getIdPartido(Partido &partido){
    return(partido.Id);
}


int getIdEquipoLPartido(Partido &partido){
    return(partido.idEquipoL);
}


int getIdEquipoVPartido(Partido &partido){
    return(partido.idEquipoV);
}


int getGolesLPartido(Partido &partido){
    return(partido.golesL);
}


int getGolesVPartido(Partido &partido){
    return(partido.golesV);
}


void ObtenerDatoListaPartido(Lista &listaPartidos,PtrNodoLista cursor,Partido &partido){
    partido.Id =        ((Partido*)cursor->ptrDato)->Id;
    partido.idEquipoL = ((Partido*)cursor->ptrDato)->idEquipoL;
    partido.idEquipoV = ((Partido*)cursor->ptrDato)->idEquipoV;
    partido.golesL =    ((Partido*)cursor->ptrDato)->golesL;
    partido.golesV =    ((Partido*)cursor->ptrDato)->golesV;
}



void ResetGolesDeLaListaPartido(Lista &listaPartidos,PtrNodoLista cursor){
    ((Partido*)cursor->ptrDato)->golesV = 0;
    ((Partido*)cursor->ptrDato)->golesL = 0;
}

//----------------------------------------------------------------------------
bool BuscarIdExistentePartido(Lista &listapartido,int id){

    bool encontrado = false;
        PtrNodoLista cursor = primero(listapartido);
        while (cursor != fin()) {
             if ( ((Partido*)cursor->ptrDato)->Id == id)
                encontrado = true;
            cursor = siguiente(listapartido, cursor);
        }
        return encontrado;
}


void remplazardatosdeauxiliarenoriginalPartido(Lista &listaPartido,Lista &listaaux){
PtrNodoLista cursor = primero(listaPartido);
     PtrNodoLista cursor2 = primero(listaaux);
        int i=0;

        while (cursor != fin()) {
           while (cursor2 != fin()) {

               if ( ((Partido*)cursor->ptrDato)->Id == ((Partido*)cursor2->ptrDato)->Id) {

                    ((Partido*)cursor->ptrDato)->golesL = ((Partido*)cursor2->ptrDato)->golesL;
                    ((Partido*)cursor->ptrDato)->golesV = ((Partido*)cursor2->ptrDato)->golesV;
               }

            cursor2 = siguiente(listaaux, cursor2);
        }
            cursor = siguiente(listaPartido,cursor);
            cursor2 = primero(listaaux);

        }

}


bool BuscarIdEquipoEnPartido(Lista &listapartido,int id){
 bool encontrado = false;
        PtrNodoLista cursor = primero(listapartido);
        while (cursor != fin()) {
             if ( ((Partido*)cursor->ptrDato)->idEquipoL == id || ((Partido*)cursor->ptrDato)->idEquipoV == id){
                encontrado = true;
             }
            cursor = siguiente(listapartido, cursor);
        }
        return encontrado;

}


bool PasarFaseEliminacion(Lista &listaPartido){
    bool PasarFase = false;

    int CantDePartidosJugados = 0;
    int CantDePartidosDisponibles = longitud(listaPartido); //cantidad de partidos

    Partido partido;

    PtrNodoLista cursor = primero(listaPartido);

        while (cursor != fin()) {

            ObtenerDatoListaPartido(listaPartido,cursor,partido);

            if( ( getGolesLPartido(partido) != -1 ) || (getGolesVPartido(partido) != -1)){
                CantDePartidosJugados++;
            }

            cursor = siguiente(listaPartido, cursor);
        }


    if( CantDePartidosDisponibles == CantDePartidosJugados){
        PasarFase = true;
    }

    return(PasarFase);
}


void MeterGolesL(Lista &listapartido,PtrNodoLista &cursor){
    ((Partido*)cursor->ptrDato)->golesL = ((Partido*)cursor->ptrDato )->golesL + 1 ;
}


void MeterGolesV(Lista &listapartido,PtrNodoLista &cursor){
    ((Partido*)cursor->ptrDato)->golesV = ((Partido*)cursor->ptrDato )->golesV + 1 ;
}


void BuscarIdPartidoParaGolesL(Lista &listaPartido,int id){
    PtrNodoLista cursor;
    Partido partido;
    cursor = primero(listaPartido);

    while(cursor != fin()){
                // GUARDO LOS ID DE EQUIPOS LOCAL Y VISITANTE
        ObtenerDatoListaPartido(listaPartido,cursor,partido);

        if( getIdPartido(partido) == id ){
            MeterGolesL(listaPartido,cursor);
        }

        cursor = siguiente(listaPartido,cursor);
    }
}


void BuscarIdPartidoParaGolesV(Lista &listaPartido,int id){
    PtrNodoLista cursor;
    Partido partido;
    cursor = primero(listaPartido);

    while(cursor != fin()){
        // GUARDO LOS ID DE EQUIPOS LOCAL Y VISITANTE
        ObtenerDatoListaPartido(listaPartido,cursor,partido);

        if( getIdPartido(partido) == id  ) MeterGolesV(listaPartido,cursor);

        cursor = siguiente(listaPartido,cursor);
    }

}


void RepartirPuntaje(Lista &auxPartido,Lista &auxEquipo1,Lista &auxEquipo2,int id){
    int equipo1;
    int equipo2;
    PtrNodoLista cursor,cursor2;

    cursor = primero(auxPartido);
    cursor2 = primero(auxEquipo1);

    while(cursor != fin()){

        if ( ((Partido*)cursor->ptrDato)->Id == id ){

            equipo1 = ((Partido*)cursor->ptrDato)->idEquipoL;
            equipo2 = ((Partido*)cursor->ptrDato)->idEquipoV;

            while ( cursor2 != fin()){

                if( ((Equipo*)cursor2->ptrDato)->Id == equipo1 ){

                    if(  ((Partido*)cursor->ptrDato)->golesL > ((Partido*)cursor->ptrDato)->golesV  ){
                        ((Equipo*)cursor2->ptrDato)->Puntos = ((Equipo*)cursor2->ptrDato)->Puntos + 3;
                    }
                    else  if(((Partido*)cursor->ptrDato)->golesL == ((Partido*)cursor->ptrDato)->golesV){
                        ((Equipo*)cursor2->ptrDato)->Puntos = ((Equipo*)cursor2->ptrDato)->Puntos + 1;
                    }

                    //Reparte los goles de la lista auxpartido a auxEquipo
                    ((Equipo*)cursor2->ptrDato)->Goles_A_Favor = ((Equipo*)cursor2->ptrDato)->Goles_A_Favor + ((Partido*)cursor->ptrDato)->golesL;
                    ((Equipo*)cursor2->ptrDato)->Goles_En_Contra = ((Equipo*)cursor2->ptrDato)->Goles_En_Contra + ((Partido*)cursor->ptrDato)->golesV;
                }


            cursor2 = siguiente(auxEquipo1,cursor2);
            }
        }

        cursor = siguiente(auxPartido,cursor);
    }


    cursor = primero(auxPartido);
    cursor2 = primero(auxEquipo2);

    while(cursor != fin()){

            if ( ((Partido*)cursor->ptrDato)->Id == id ){

                equipo1 = ((Partido*)cursor->ptrDato)->idEquipoL;
                equipo2 = ((Partido*)cursor->ptrDato)->idEquipoV;

                while ( cursor2 != fin()){

                    if( ((Equipo*)cursor2->ptrDato)->Id == equipo2 ){

                        if(  ((Partido*)cursor->ptrDato)->golesL < ((Partido*)cursor->ptrDato)->golesV){
                            ((Equipo*)cursor2->ptrDato)->Puntos = ((Equipo*)cursor2->ptrDato)->Puntos + 3;
                        }
                        else  if(((Partido*)cursor->ptrDato)->golesL == ((Partido*)cursor->ptrDato)->golesV){
                            ((Equipo*)cursor2->ptrDato)->Puntos = ((Equipo*)cursor2->ptrDato)->Puntos + 1;
                        }

                        //Reparte los goles de la lista auxpartido a auxEquipo
                        ((Equipo*)cursor2->ptrDato)->Goles_A_Favor = ((Equipo*)cursor2->ptrDato)->Goles_A_Favor + ((Partido*)cursor->ptrDato)->golesV;
                        ((Equipo*)cursor2->ptrDato)->Goles_En_Contra = ((Equipo*)cursor2->ptrDato)->Goles_En_Contra + ((Partido*)cursor->ptrDato)->golesL;
                    }

                    cursor2 = siguiente(auxEquipo2,cursor2);
                }
            }

            cursor = siguiente(auxPartido,cursor);
        }

}



void GuardarPartidos (Lista &listaPartidos,char direccion[]){

    int ID,Local,Visita,GolL,GolV;

    FILE *faux;
    faux = fopen("partidosAux.txt","w++");

    PtrNodoLista cursor = primero(listaPartidos);

    while (cursor != fin()){

            ID = ((Partido*)cursor->ptrDato)->Id;
            Local = ((Partido*)cursor->ptrDato)->idEquipoL;
            Visita = ((Partido*)cursor->ptrDato)->idEquipoV;
            GolL = ((Partido*)cursor->ptrDato)->golesL;
            GolV = ((Partido*)cursor->ptrDato)->golesV;

            fprintf(faux,"%d;%d;%d;%d;%d\n",ID,Local,Visita,GolL,GolV);

            cursor = siguiente(listaPartidos, cursor);
    }
    fclose(faux);
    remove(direccion);
    rename("partidosAux.txt",direccion);

}

