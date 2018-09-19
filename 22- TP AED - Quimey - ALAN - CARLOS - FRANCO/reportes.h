/*  ARCHIVO REPORTES.H
    Declaracion de procedimientos necesarios para procesar reportes
    TP final AyED - 2018
*/

#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

#include "lista.h"

/** Procedimientos para procesar reporte de goleadores **/

void ordenarListaJugadores(Lista &Jugadores);


void intercambiarDatosJugadores(Lista &Jugadores, PtrNodoLista nodo1, PtrNodoLista nodo2);


void reporteGoleadores(Lista &Jugadores);


void ListarEquipoXIdGrupo(Lista &listaEquipo,int idE1,int idE2,int idE3,int idE4,int &GolesParciales, int &TotalDeLosGrupos);


void OrdenDeEquiposPorGrupo(Lista &ListaGrupo,Lista &listaEquipo);

#endif // REPORTES_H_INCLUDED
