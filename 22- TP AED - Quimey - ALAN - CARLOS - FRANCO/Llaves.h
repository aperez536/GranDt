/*  Archivo llaves.cpp
    Definicion de funciones para definicion de partidos de rondas finales
    TP: Rusia 2018 - Algoritmos y Estructuras de datos, UNLa
*/

#ifndef LLAVES_H_INCLUDED
#define LLAVES_H_INCLUDED
#include "Lista.h"
#include "Equipo.h"
#include "Partido.h"

bool verificarFinalFase(Lista &Fase);


void ordenarVector (Equipo grupo[]);


void mostrarGrupoOrdenado(Equipo grupo[]);


void generarListaOctavos(Lista &Equipos, Lista &Octavos);


void generarListaCuartos(Lista &Octavos, Lista &Cuartos);


void generarListaSemis(Lista &Cuartos, Lista &Semis);


void generarListaFinales(Lista &Semis, Lista &Finales);


bool verificarExistenciaDeArchivo(char direccion[]);

/*  NOTA: Por cómo está definida la condición para generar partidos de siguiente ronda, si el partido
    no fue procesado la lista se genera igual tomando el equipo visitante como ganador. En todo caso esto solo
    se ve en el main de prueba, no se llega a ver en el programa ejecutable ya que hay una funcion para corroborar
    que la fase anterior haya terminado antes de poder procesar la actual.
*/

#endif // LLAVES_H_INCLUDED
