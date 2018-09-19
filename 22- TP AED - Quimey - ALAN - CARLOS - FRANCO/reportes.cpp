/* ARCHIVO REPORTES.CPP */
#include "reportes.h"
#include <iostream>
#include <stdlib.h>
#include "Jugador.h"
#include "Lista.h"
#include "Grupo.h"
#include "Equipo.h"


using namespace std;


/** Procedimientos para procesar reporte de goleadores **/

//--------------------------------------------------------------------------------------------------------
void intercambiarDatosJugadores(Lista &Jugadores, PtrNodoLista nodo1, PtrNodoLista nodo2)
{
    Jugador * datoAux;                                      //variable auxiliar para intercambio
    datoAux = (Jugador*)(getDato(Jugadores, nodo1));        //guardar el dato de nodo1 en aux
    setDato(Jugadores, nodo1, getDato(Jugadores, nodo2));   //copiar dato de nodo2 en nodo1
    setDato(Jugadores, nodo2, datoAux);                     //copiar dato de nodo 1 (aux) en nodo2
}

//--------------------------------------------------------------------------------------------------------
void ordenarListaJugadores(Lista &Jugadores)
{
    PtrNodoLista cursor1,cursor2;
    cursor1 = primero(Jugadores);
    while (siguiente(Jugadores, cursor1) != NULL)           //Mientras haya un nodo a la derecha del cursor con el que comparar
    {
        cursor2 = siguiente(Jugadores, cursor1);
        while (cursor2 != NULL)                             //Mientras el segundo cursor no llegue al final de la lista
        {
            //si la cantidad de goles del cursor 2 es menor a la del cursor1
            if(getGolesJugador(*(Jugador*)(cursor1->ptrDato)) < getGolesJugador(*(Jugador*)(cursor2->ptrDato)))
            {
                intercambiarDatosJugadores(Jugadores, cursor1,cursor2);
            }
            cursor2 = siguiente(Jugadores, cursor2);
        }
        cursor1 = siguiente(Jugadores, cursor1);
    }
}

//--------------------------------------------------------------------------------------------------------

//void reporteGoleadores(Lista Jugadores, Lista Equipos)

void reporteGoleadores(Lista &Jugadores)
{
    ordenarListaJugadores(Jugadores);                       //ordenar la lista por goles de manera descendente

    cout << "\n Reporte de goleadores " << endl;
    cout << "----------------------" << endl;

    Jugador goleador = *(Jugador*)(getDato(Jugadores, primero(Jugadores))); //Obtener dato del primero de la lista

    int maxGoles = getGolesJugador(goleador);               // obtener cantidad de goles del goleador

    int cantJugadores, totalGoles, subtotalJugadores;       //acumuladores
    //int idEquipoJugadorCursor;
    PtrNodoLista cursor = primero(Jugadores);               //cursor para recorrer la lista
    subtotalJugadores = 0;                                  //inicializacion de acumuladores
    cantJugadores = 0;
    totalGoles = 0;

    cout << "\njugadores con " << maxGoles << "goles" << endl;
    cout << "--------------------" << endl;


    //mientras no llegue al final de la lista ni encuentre jugadores sin goles
    while ((cursor != NULL) && (getGolesJugador(*(Jugador*)getDato(Jugadores, cursor)) != 0))
    {
        Jugador * jugadorCursor;                                       //variable puntero para guardar el dato del cursor
        jugadorCursor = (Jugador*)getDato(Jugadores, cursor);          //obtener dato del cursor y castear a ptrJugador

        if (getGolesJugador(*jugadorCursor) != maxGoles)               //si la cantidad de goles es distinta al actual maximo
        {
            cout << "\ncantidad de jugadores: " << subtotalJugadores << endl;   //Imprimir subtotal
            subtotalJugadores = 0;                                              // reiniciar subtotal
            maxGoles = getGolesJugador(*jugadorCursor);                         // Modificar el maximo y avisar por pantalla
            cout << "\n\njugadores con " << maxGoles << "goles" << endl;
            cout << "--------------------" << endl;
        }
        cout << "Id Jugador: " << getIdJugador(*jugadorCursor);
        cout << "  ;  Nombre: " << getNombreJugador(*jugadorCursor) << endl;         //mostrar nombre del jugador

        //idEquipoJugadorCursor = getJugadorIdEquipo(*jugadorCursor);
        //cout << "equipo: << getNombreEquipo()         // ver si hace falta decir en que equipo juega

        subtotalJugadores = subtotalJugadores + 1;                              //sumar subtotal de jugadores por segmento
        cantJugadores = cantJugadores + 1;                                      //sumar cantidad de jugadores con goles
        totalGoles = totalGoles + getGolesJugador(*jugadorCursor);              //sumar total de goles

        cursor = siguiente(Jugadores,cursor);

    }
    cout << "\ncantidad de jugadores: " << subtotalJugadores << endl;           //imprimir totales
    cout << "\n\n\n cantidad de jugadores que hicieron gol: " << cantJugadores << endl;
    cout << "\n\n\n total de goles convertidos hasta el momento en el torneo: " << totalGoles << endl;

}



void OrdenDeEquiposPorGrupo(Lista &ListaGrupo,Lista &listaEquipo){
    Grupo grupo;
    PtrNodoLista cursor = primero(ListaGrupo);

    int idE1=0,idE2=0,idE3=0,idE4=0,GolesParciales=0,TotalDeLosGrupos=0;


    while (cursor != fin()){

        GolesParciales=0;
        ObtenerDatoListaGrupo(ListaGrupo,cursor,grupo);

        cout <<"Id del Grupo: " << getIdGrupo(grupo) <<endl;
        cout <<"Nombre Del Grupo : "<< getNombreGrupo(grupo)<<endl;

        idE1 = getIdEquipo1(grupo);
        idE2 = getIdEquipo2(grupo);
        idE3 = getIdEquipo3(grupo);
        idE4 = getIdEquipo4(grupo);

        ListarEquipoXIdGrupo(listaEquipo,idE1,idE2,idE3,idE4,GolesParciales,TotalDeLosGrupos);

        cout <<"Goles Parciales del grupos: "<< GolesParciales << endl;

        cout<<""<<endl;

        cursor = siguiente(ListaGrupo, cursor);
    }

    cout <<"Goles TOTALES de todos los grupos: "<< TotalDeLosGrupos<<" Goles "<< endl;

    cout <<""<< endl;

    cursor = siguiente(ListaGrupo,cursor);

}


void ListarEquipoXIdGrupo(Lista &listaEquipo,int idE1,int idE2,int idE3,int idE4,int &GolesParciales, int &TotalDeLosGrupos){

    Equipo equipo;
    PtrNodoLista cursor = primero(listaEquipo);

    int idEquipo,Goles_A_Favor,Goles_En_Contra,Puntos;

    while (cursor != fin()){

        ObtenerDatoListaEquipo(listaEquipo,cursor,equipo);

        idEquipo = getIdEquipo(equipo);
        Goles_A_Favor = getGoles_A_Favor(equipo);
        Goles_En_Contra = getGoles_En_Contra(equipo);

        if( idEquipo == idE1 || idEquipo == idE2 || idEquipo == idE3 || idEquipo == idE4 ){

            cout <<"Nombre Equipo: " << getNombreEquipo(equipo);
            cout <<" , Puntos: " << getPuntos(equipo);
            cout <<" , Diferencia de goles: " << ( getGoles_A_Favor(equipo) - getGoles_En_Contra(equipo) ) ;

            cout << endl;

            GolesParciales = GolesParciales + Goles_A_Favor;
            TotalDeLosGrupos = TotalDeLosGrupos + Goles_A_Favor;
        }

        cursor = siguiente(listaEquipo,cursor); //va al siguiente nodo
    }

}

