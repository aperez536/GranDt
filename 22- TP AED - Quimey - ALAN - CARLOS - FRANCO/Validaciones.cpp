#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validaciones.h"
#include "Lista.h"
#include "Grupo.h"
#include "Equipo.h"
#include "Jugador.h"
#include "Partido.h"

using namespace std;

void BuscarErroresGrupo(Lista & listagrupos,Lista & listaEquipo){

    int i=0,j=0,z=0;
    int contador;               //FOR
    char errores[300];
    char erroresaux[300];      //FOR
    char erroresfinal[300];   //FOR
    char erroresId[300];
    char valor;
    bool encontrado1=false,encontrado2=false;
    bool encontrado3 = false;
    Grupo grupo;
    Grupo grupo2;

    PtrNodoLista cursor = primero(listagrupos);

    PtrNodoLista cursor2 = siguiente(listagrupos,cursor);

        while (cursor != fin()) {

            ObtenerDatoListaGrupo(listagrupos,cursor,grupo);



            if (BuscarIdExistenteEquipo(listaEquipo,getIdEquipo1(grupo)) == 0 )

                     cout << " el equipo :  " << getIdEquipo1(grupo) << " no existe en la lista equipo" << endl;

            if (BuscarIdExistenteEquipo(listaEquipo,getIdEquipo2(grupo)) == 0)

                    cout << " el equipo :  " << getIdEquipo2(grupo) << " no existe en la lista equipo" << endl;

            if (BuscarIdExistenteEquipo(listaEquipo,getIdEquipo3(grupo)) == 0)

                    cout << " el equipo :  " << getIdEquipo3(grupo) << " no existe en la lista equipo" << endl;

            if (BuscarIdExistenteEquipo(listaEquipo,getIdEquipo4(grupo)) == 0)
                    cout << " el equipo :  " << getIdEquipo4(grupo) << " no existe en la lista equipo" << endl;

                //-------------------------------------------------------------------------------------------------
            if (
                    (((Grupo*)cursor->ptrDato)->IdEquipo1 == ((Grupo*)cursor->ptrDato)->IdEquipo2)  ||
                    (((Grupo*)cursor->ptrDato)->IdEquipo1 == ((Grupo*)cursor->ptrDato)->IdEquipo3 ) ||
                    (((Grupo*)cursor->ptrDato)->IdEquipo1 == ((Grupo*)cursor->ptrDato)->IdEquipo4 ) ||
                    (((Grupo*)cursor->ptrDato)->IdEquipo2 == ((Grupo*)cursor->ptrDato)->IdEquipo3 ) ||
                    (((Grupo*)cursor->ptrDato)->IdEquipo2 == ((Grupo*)cursor->ptrDato)->IdEquipo4 ) ||
                    (((Grupo*)cursor->ptrDato)->IdEquipo3 == ((Grupo*)cursor->ptrDato)->IdEquipo4 )

            ){

                    errores[j]=((Grupo*)cursor->ptrDato)->Id;
                    encontrado2 = true;
                    j++;
                }
                //-------------------------------------------------------------------------------------------------
           while (cursor2 != fin()) {

            //ObtenerDatoListaGrupo(listagrupos,cursor2,grupo2);

               if ( ((Grupo*)cursor->ptrDato)->Id == ((Grupo*)cursor2->ptrDato)->Id){

                    erroresId[i]= ((Grupo*)cursor2->ptrDato)->Id;

                    encontrado1 = true;

                    i++;
               }

                cursor2 = siguiente(listagrupos, cursor2);
            }

            //-------------------------------------------------------------------------------------------------



            //-------------------------------------------------------------------------------------------------
            if ( ((Grupo*)cursor->ptrDato)->IdEquipo1  == 0 || ((Grupo*)cursor->ptrDato)->IdEquipo2 == 0 ||
            ((Grupo*)cursor->ptrDato)->IdEquipo3 == 0 || ((Grupo*)cursor->ptrDato)->IdEquipo4 == 0){

                cout << "EN EL GRUPO : " << ((Grupo*)cursor->ptrDato)->Id  <<"  HAY EQUIPOS / POCOS EQUIPOS O NINGUN EQUIPO "<< endl;
            }
            //-------------------------------------------------------------------------------------------------

        cursor = siguiente(listagrupos,cursor);
        cursor2 = siguiente(listagrupos,cursor);

    }

        if( encontrado1 == true || encontrado2 == true){

            cout<< " IDs de grupos repetidos :  ";

        for (z=0;z<i;z++){
               cout<<erroresId[z]<<" ";
        }

        cout << endl;

        cout<< " equipos repetidos en grupos :  ";

        for (z=0;z<j;z++){
               cout<<errores[z]<<" ";
        }
        cout << endl;

        }

    if(BuscarEquiposRepetidosEnDiferentesGrupos(listagrupos)){
        cout <<" Hay Equipos iguales en diferentes Grupos "<< endl;
    }
    cout << endl;
}


bool BuscarEquiposRepetidosEnDiferentesGrupos(Lista & listagrupos){

    PtrNodoLista cursor = primero(listagrupos);

    PtrNodoLista cursor2 = siguiente(listagrupos,cursor);
    Grupo grupo,grupo2;

    bool Encontrado = false;

    while(cursor != fin()){

        ObtenerDatoListaGrupo(listagrupos,cursor,grupo);

        while(cursor2 != fin()){

            ObtenerDatoListaGrupo(listagrupos,cursor2,grupo2);

            if (
                getIdEquipo1(grupo)  ==  getIdEquipo1(grupo2) ||
                getIdEquipo1(grupo)  ==  getIdEquipo2(grupo2) ||
                getIdEquipo1(grupo)  ==  getIdEquipo3(grupo2) ||
                getIdEquipo1(grupo)  ==  getIdEquipo4(grupo2)

            )   Encontrado = true;

            if (
                getIdEquipo2(grupo)  ==  getIdEquipo1(grupo2) ||
                getIdEquipo2(grupo)  ==  getIdEquipo2(grupo2) ||
                getIdEquipo2(grupo)  ==  getIdEquipo3(grupo2) ||
                getIdEquipo2(grupo)  ==  getIdEquipo4(grupo2)

            )   Encontrado = true;

            if (
                getIdEquipo3(grupo)  ==  getIdEquipo1(grupo2) ||
                getIdEquipo3(grupo)  ==  getIdEquipo2(grupo2) ||
                getIdEquipo3(grupo)  ==  getIdEquipo3(grupo2) ||
                getIdEquipo3(grupo)  ==  getIdEquipo4(grupo2)

            )   Encontrado = true;

            if (
                getIdEquipo4(grupo)  ==  getIdEquipo1(grupo2) ||
                getIdEquipo4(grupo)  ==  getIdEquipo2(grupo2) ||
                getIdEquipo4(grupo)  ==  getIdEquipo3(grupo2) ||
                getIdEquipo4(grupo)  ==  getIdEquipo4(grupo2)

            )   Encontrado = true;


        cursor2 = siguiente(listagrupos,cursor2);
        }

        cursor = siguiente(listagrupos,cursor);
        cursor2 = siguiente(listagrupos,cursor);
    }

    return (Encontrado);
}


void BuscarErroresIdJugador(Lista &listaJugadores){
    bool encontrado;
    PtrNodoLista cursor = primero(listaJugadores);

    PtrNodoLista cursor2 = siguiente(listaJugadores,cursor);

    while(cursor != fin()){

        encontrado = false;

        while(cursor2 != fin()){

            if(((Jugador*)cursor->ptrDato)->Id == ((Jugador*)cursor2->ptrDato)->Id){
                encontrado = true;
            }

            cursor2 = siguiente(listaJugadores,cursor2);
        }

        if(encontrado == true){
            cout<<"ID de jugadores repetido: " << ((Jugador*)cursor->ptrDato)->Id <<endl;
        }

        cursor = siguiente(listaJugadores,cursor);
        cursor2 = siguiente(listaJugadores,cursor);
    }


}


void BuscarErroresIdEquipo(Lista &listaEquipos){
    PtrNodoLista cursor = primero(listaEquipos);
    PtrNodoLista cursor2 = siguiente(listaEquipos,cursor);

        while (cursor != fin()) {
           while (cursor2 != fin()) {
               if ( ((Equipo*)cursor->ptrDato)->Id == ((Equipo*)cursor2->ptrDato)->Id){
                    cout << "en la lista equipo se repite el id: " << ((Equipo*)cursor->ptrDato)->Id << endl;

               }
                 cursor2 = siguiente(listaEquipos, cursor2);

            }

            cursor = siguiente(listaEquipos,cursor);
            cursor2 = siguiente(listaEquipos,cursor);

        }

}


void BuscarErroresIdPartidos(Lista &listaPartidos){

PtrNodoLista cursor = primero(listaPartidos);
    PtrNodoLista cursor2 = siguiente(listaPartidos,cursor);

        while (cursor != fin()) {
           while (cursor2 != fin()) {
               if ( ((Partido*)cursor->ptrDato)->Id == ((Partido*)cursor2->ptrDato)->Id){
                    cout << "en la lista Partidos se repite el id: " << ((Partido*)cursor->ptrDato)->Id << endl;

               }
                 cursor2 = siguiente(listaPartidos, cursor2);

            }

            cursor = siguiente(listaPartidos,cursor);
            cursor2 = siguiente(listaPartidos,cursor);

        }

}

void BuscarEnPartidoEquiposEnfrentados(Lista &listaPartidos){

    PtrNodoLista cursor = primero(listaPartidos);
    PtrNodoLista cursor2 = siguiente(listaPartidos,cursor);

        while (cursor != fin()) {

               if ( ((Partido*)cursor->ptrDato)->idEquipoL == ((Partido*)cursor->ptrDato)->idEquipoV){
                    cout << "en el id del partido : " << ((Partido*)cursor->ptrDato)->Id ;
                    cout << "   El equipo se enfreta a si mismo. El id del equipo es:  " <<
                    ((Partido*)cursor->ptrDato)->idEquipoL
                    <<endl;


            }
            cursor = siguiente(listaPartidos,cursor);

        }

}






