/*  Archivo funciones compara.h
    Manejo de listas en tp final
*/

#ifndef FUNCIONES_COMPARA_H_INCLUDED
#define FUNCIONES_COMPARA_H_INCLUDED



#include "lista.h"

/********************************************************************************************
                          Definicion de funciones de comparacion                        *
********************************************************************************************/
  /*
    ptrDato = puntero void
    (equipo*)ptrDato = puntero a equipo
    *(equipo*)ptrDato = variable de tipo equipo (apuntada por el puntero void casteado)
    */

/* Comparacion de Equipo */
    ResultadoComparacion compararEquipo(PtrDato ptrDato1, PtrDato ptrDato2);

    //-----------------------------------------------------------------------------------
/* Comparacion de Jugador */
    ResultadoComparacion compararJugador(PtrDato ptrDato1, PtrDato ptrDato2);

    //---------------------------------------------------------------------------------------
/* Comparacion de Grupo */
    ResultadoComparacion compararGrupo(PtrDato ptrDato1, PtrDato ptrDato2);
    //---------------------------------------------------------------------------------------------
/* Comparacion de Partido */
    ResultadoComparacion compararPartido(PtrDato ptrDato1, PtrDato ptrDato2);


#endif // FUNCIONES_COMPARA_H_INCLUDED
