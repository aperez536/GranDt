/*  Archivo funciones compara.cpp
    Manejo de listas en tp final
*/

#include "funciones_compara.h"
#include "lista.h"
#include "Equipo.h"
#include "Partido.h"
#include "Jugador.h"


/********************************************************************************************
                          Implementacion de funciones de comparacion                        *
********************************************************************************************/
  /*
    ptrDato = puntero void
    (equipo*)ptrDato = puntero a equipo
    *(equipo*)ptrDato = variable de tipo equipo (apuntada por el puntero void casteado)
    */

    ResultadoComparacion compararEquipo(PtrDato ptrDato1, PtrDato ptrDato2)
    {
        int idUno,idDos;

        idUno = getIdEquipo(*((Equipo*)ptrDato1));
        idDos = getIdEquipo(*((Equipo*)ptrDato2));


    if (idUno > idDos)
        {
        return MAYOR;
        }
    else if (idUno < idDos)
        {
        return MENOR;
        }
    else
    {
        return IGUAL;
    }

    }

    //-----------------------------------------------------------------------------------

    ResultadoComparacion compararjugador(PtrDato ptrDato1, PtrDato ptrDato2)
    {
        int idUno,idDos;

        idUno = getIdJugador(*((Jugador*)ptrDato1));
        idDos = getIdJugador(*((Jugador*)ptrDato2));

    if (idUno > idDos)
        {
        return MAYOR;
        }
    else if (idUno < idDos)
        {
        return MENOR;
        }
    else
    {
        return IGUAL;
    }

    }

    //---------------------------------------------------------------------------------------

    ResultadoComparacion comparargrupo(PtrDato ptrDato1, PtrDato ptrDato2)
    {
        char idUno,idDos;
        ResultadoComparacion comparacion = MAYOR;       //Lo inicializo en algo distinto a igual
        idUno = getIdEquipo(*((Equipo*)ptrDato1));
        idDos = getIdEquipo(*((Equipo*)ptrDato2));


    if (idUno == idDos)
        {
            return IGUAL;
        }
    }

    //---------------------------------------------------------------------------------------------

    ResultadoComparacion compararPartido(PtrDato ptrDato1, PtrDato ptrDato2)
    {
        int idUno,idDos;

        idUno = getIdPartido(*((Partido*)ptrDato1));
        idDos = getIdPartido(*((Partido*)ptrDato2));


    if (idUno > idDos)
        {
        return MAYOR;
        }
    else if (idUno < idDos)
        {
        return MENOR;
        }
    else
    {
        return IGUAL;
    }
    }
