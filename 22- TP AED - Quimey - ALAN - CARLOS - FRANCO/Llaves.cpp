/*  Archivo llaves.cpp
    Implementacion de funciones para definicion de partidos de rondas finales
    TP: Rusia 2018 - Algoritmos y Estructuras de datos, UNLa
*/

#include "Llaves.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//------------------------------------------------------------------------------------------------------------
bool verificarFinalFase(Lista &Fase)
{
    PtrNodoLista cursor = primero(Fase);
    bool finalizado = true;
    int golesL, golesV;

    while (cursor != NULL)
    {
        golesL = getGolesLPartido(*(Partido*)getDato(Fase, cursor));
        golesV = getGolesVPartido(*(Partido*)getDato(Fase, cursor));  //obtener goles de cada equipo

        if ((golesL != -1) && (golesV != -1))               //si algunoo vale -1 es que no se procesó el partido
        {
            finalizado = true;
        }
        else
        {
            finalizado = false;                     // si encuentra un partido  no procesado deja de recorrer
            break;
        }
        cursor = siguiente(Fase, cursor);
    }
    return finalizado;
}

//------------------------------------------------------------------------------------------------------------
void ordenarVector (Equipo grupo[])
{
    Equipo aux;

    for (int i=0; i<3 ; i++)
        {
            for (int j=1 ; j<4 ; j++)
            {
                if(grupo[j].Puntos > grupo[j-1].Puntos)         //Comparo por puntos para ordenar
                {
                   aux = grupo[j];
                   grupo[j] = grupo[j-1];
                   grupo[j-1]=aux;
                }
                //si estan igualados en puntos comparo por diferencia de goles
                else if(grupo[j].Puntos == grupo[j-1].Puntos)
                {
                    if ((grupo[j].Goles_A_Favor-grupo[j].Goles_En_Contra) > (grupo[j-1].Goles_A_Favor-grupo[j-1].Goles_En_Contra))
                        {
                            aux = grupo[j];
                            grupo[j] = grupo[j-1];
                            grupo[j-1]=aux;
                        }
                }
            }
        }
}

//------------------------------------------------------------------------------------------------------------
void mostrarGrupoOrdenado(Equipo grupo[])
{
    cout << "_____________________________________________________________________________" << endl;
        for (int i=0;i<4;i++)
        {
            cout << " id equipo: " << grupo[i].Id << " ; puntos: " << grupo[i].Puntos <<
             " ; diferencia de goles: " << grupo[i].Goles_A_Favor-grupo[i].Goles_En_Contra << endl;
        }
}

void generarListaOctavos(Lista &Equipos, Lista &Octavos)
{

    // Aca estoy haciendo la suposicion de que la lista de equipos esta ordenada por id en forma ascendente
    // Sino tendria que hacer un procedimiento para ordenarla o ir localizando datos segun tda grupo

    Equipo grupo[4];                                    //array para guardar 4 equipos
    Partido octavos[8];                                     //array para generar los partidos de octavos
    int idPartido = 49;                                     //indice para asignar id a partidos

    //Creo una lista de 8 partidos vacios
    for (int i=0 ; i<8 ; i++)
    {
        Partido* partido = new Partido;

        crearPartido(*partido);
        setPartidoId(*partido,idPartido);
        adicionarFinal(Octavos,partido);
        idPartido = idPartido+1;
    }

    //Cursores para recorrer la lista
    PtrNodoLista cursorOctavos1 = primero (Octavos);    //cursor para enpezar en el primer partido
    PtrNodoLista cursorOctavos2;                        //cursor para empezar desde el quinto
    cursorOctavos2 = siguiente(Octavos, cursorOctavos1);//apunta al segundo nodo de la lista octavos
    cursorOctavos2 = siguiente(Octavos,cursorOctavos2); //tercero
    cursorOctavos2 = siguiente(Octavos,cursorOctavos2); //cuarto
    cursorOctavos2 = siguiente(Octavos,cursorOctavos2); //quinto

    PtrNodoLista cursorEquipos = primero(Equipos);
    while (cursorEquipos != NULL)
    {
        int primero,segundo;

        //obtener los dos primeros de un grupo
        grupo[0] = *(Equipo*)(getDato(Equipos,cursorEquipos));
        cursorEquipos = siguiente(Equipos, cursorEquipos);
        grupo[1] = *(Equipo*)(getDato(Equipos,cursorEquipos));
        cursorEquipos = siguiente(Equipos, cursorEquipos);
        grupo[2] = *(Equipo*)(getDato(Equipos,cursorEquipos));
        cursorEquipos = siguiente(Equipos, cursorEquipos);
        grupo[3] = *(Equipo*)(getDato(Equipos,cursorEquipos));
        cursorEquipos = siguiente(Equipos, cursorEquipos);      //Obtener equipos de la lista de a 4
        ordenarVector (grupo);                                  //ordenar vector por puntos y dif de goles
        primero = getIdEquipo(grupo[0]);
        segundo = getIdEquipo(grupo[1]);                        //obtener los dos primeros del grupo

        //mostrarGrupoOrdenado(grupo);
        /*En la primer vuelta del while el primero del grupo es local del partido 1 y el segundo
        es visitante del partido 5*/
        setPartidoIdEquipoL(*(Partido*)getDato(Octavos,cursorOctavos1),primero);
        setPartidoIdEquipoV(*(Partido*)getDato(Octavos,cursorOctavos2),segundo);

        //obtener los dos primeros del siguiente grupo
        grupo[0] = *(Equipo*)(getDato(Equipos,cursorEquipos));
        cursorEquipos = siguiente(Equipos, cursorEquipos);
        grupo[1] = *(Equipo*)(getDato(Equipos,cursorEquipos));
        cursorEquipos = siguiente(Equipos, cursorEquipos);
        grupo[2] = *(Equipo*)(getDato(Equipos,cursorEquipos));
        cursorEquipos = siguiente(Equipos, cursorEquipos);
        grupo[3] = *(Equipo*)(getDato(Equipos,cursorEquipos));
        cursorEquipos = siguiente(Equipos, cursorEquipos);      //Obtener equipos de la lista de a 4
        ordenarVector (grupo);                                  //ordenar vector por puntos y dif de goles
        primero = getIdEquipo(grupo[0]);
        segundo = getIdEquipo(grupo[1]);                        //obtener los dos primeros del grupo

        //mostrarGrupoOrdenado(grupo);
        /*En la primer vuelta del while el primero del grupo es local del partido 5 y el segundo
        es visitante del partido 1*/

        setPartidoIdEquipoL(*(Partido*)getDato(Octavos,cursorOctavos2),primero);
        setPartidoIdEquipoV(*(Partido*)getDato(Octavos,cursorOctavos1),segundo);

        cursorOctavos1 = siguiente(Octavos,cursorOctavos1);
        cursorOctavos2 = siguiente(Octavos,cursorOctavos2);
    }
    GuardarPartidos(Octavos,"octavos.txt");

}

//------------------------------------------------------------------------------------------------------------
void generarListaCuartos(Lista &Octavos, Lista &Cuartos)
{
    //crear una lista de 4 partidos con id (57-60)
    int idPartido = 57;
    for(int i=0;i<4;i++)
    {
        Partido *partido = new Partido;
        crearPartido(*partido);
        setPartidoId(*partido,idPartido);
        adicionarFinal(Cuartos,partido);
        idPartido = idPartido + 1;
    }

    PtrNodoLista cursor;                        //Cursores para recorrer lista de octavos
    PtrNodoLista siguienteCursor;
    cursor = primero(Octavos);
    siguienteCursor = siguiente(Octavos,cursor);
    PtrNodoLista cursorCuartos;                 //cursor para recorrer partidos de cuartos
    cursorCuartos = primero(Cuartos);
    int idGanadorUno,idGanadorDos;              //variables para guardar id de ganadores de partidos de octavos
    while (siguienteCursor != NULL)
    {
        //Definicion del primer jugador de un partido de cuartos
        //si gana equipoL el primer partido de octavos
        if((getGolesLPartido(*(Partido*)getDato(Octavos,cursor))) > (getGolesLPartido(*(Partido*)getDato(Octavos,cursor))) )
        {
            idGanadorUno = getIdEquipoLPartido(*(Partido*)getDato(Octavos,cursor));
        }
        else //si gana equipoV
        {
            idGanadorUno = getIdEquipoVPartido(*(Partido*)getDato(Octavos,cursor));
        }
        //NOTA: Si la canodad de goles es igual es setea como ganador el idEquipoV por definicion del if
        //      La unica condicion en que queden igual en goles es que esten en -1 porque no se procesó el partido


        //definicion del segundo Jugador de un partido de cuartos
        //si gana equipoL
        if((getGolesLPartido(*(Partido*)getDato(Octavos,siguienteCursor))) > (getGolesLPartido(*(Partido*)getDato(Octavos,siguienteCursor))) )
        {
            idGanadorDos = getIdEquipoLPartido(*(Partido*)getDato(Octavos,siguienteCursor));
        }
        else //si gana equipoV
        {
            idGanadorDos = getIdEquipoVPartido(*(Partido*)getDato(Octavos,siguienteCursor));
        }

        //Seteo del partido de cuartos

        setPartidoIdEquipoL(*(Partido*)getDato(Cuartos,cursorCuartos),idGanadorUno);
        setPartidoIdEquipoV((*(Partido*)getDato(Cuartos,cursorCuartos)),idGanadorDos);

        cursorCuartos = siguiente(Cuartos,cursorCuartos);       //pasar al siguiente partido de cuartos
        cursor = siguiente(Octavos, siguienteCursor);           //pasar al tercer partido de octavos (en primer vuelta de loop)
        siguienteCursor = siguiente(Octavos, cursor);           //Pasar al cuarto partido de octavos
    }
    GuardarPartidos(Cuartos,"cuartos.txt");
}

void generarListaSemis(Lista &Cuartos, Lista &Semis)
{
    //crear una lista de dos partidos con id 61 y 62
    int idPartido = 61;
    for (int i=0;i<2;i++)
    {
        Partido *partido = new Partido;
        crearPartido(*partido);
        setPartidoId(*partido, idPartido);
        adicionarFinal(Semis, partido);
        idPartido = idPartido + 1;
    }
     PtrNodoLista cursor;
     PtrNodoLista siguienteCursor;              //cursores para recorrer lista cuartos
     cursor = primero(Cuartos);
     siguienteCursor = siguiente(Cuartos, cursor);
     PtrNodoLista cursorSemis = primero(Semis);//cursor para recorrer lista semis
     int idGanadorUno,idGanadorDos;              //variables para guardar id de ganadores de partidos de cuartos

     while (siguienteCursor != NULL)
     {
         //Obtener primer equipo para un partido de semis
        if(getGolesLPartido(*(Partido*)getDato(Cuartos,cursor)) > getGolesVPartido(*(Partido*)getDato(Cuartos,cursor)))
        {
            idGanadorUno = getIdEquipoLPartido(*(Partido*)getDato(Cuartos,cursor));
        }
        else
        {
             idGanadorUno = getIdEquipoVPartido(*(Partido*)getDato(Cuartos,cursor));
        }

        //Obtener segundo equipo para un partido de semis
        if(getGolesLPartido(*(Partido*)getDato(Cuartos,siguienteCursor)) > getGolesVPartido(*(Partido*)getDato(Cuartos,siguienteCursor)))
        {
            idGanadorDos = getIdEquipoLPartido(*(Partido*)getDato(Cuartos,siguienteCursor));
        }
        else
        {
             idGanadorDos = getIdEquipoVPartido(*(Partido*)getDato(Cuartos,siguienteCursor));
        }

        //setear un partido de semis
        setPartidoIdEquipoL(*(Partido*)getDato(Semis, cursorSemis),idGanadorUno);
        setPartidoIdEquipoV(*(Partido*)getDato(Semis, cursorSemis),idGanadorDos);

        cursor = siguiente(Cuartos, siguienteCursor);
        siguienteCursor = siguiente(Cuartos, cursor);
        cursorSemis = siguiente(Semis, cursorSemis);
     }


    GuardarPartidos(Semis,"semifinales.txt");
}

void generarListaFinales(Lista &Semis, Lista &Finales)
{
    int idPartido = 63;
    for (int i=0; i<2; i++)
    {
        Partido *partido = new Partido;
        crearPartido(*partido);
        setPartidoId(*partido, idPartido);
        adicionarFinal(Finales, partido);
        idPartido = idPartido + 1;
    }

    PtrNodoLista cursor, siguienteCursor;           //cursores para recorrer semis
    cursor = primero(Semis);
    siguienteCursor = siguiente(Semis,cursor);
    int idGanadorUno, idGanadorDos, idPerdedorUno, idPerdedorDos;

    //Obtener primeros equipos de final y tercer puesto
        if(getGolesLPartido(*(Partido*)getDato(Semis,cursor)) > getGolesVPartido(*(Partido*)getDato(Semis,cursor)))
        {
            idGanadorUno = getIdEquipoLPartido(*(Partido*)getDato(Semis,cursor));
            idPerdedorUno = getIdEquipoVPartido(*(Partido*)getDato(Semis,cursor));
        }
        else
        {
             idGanadorUno = getIdEquipoVPartido(*(Partido*)getDato(Semis,cursor));
             idPerdedorUno = getIdEquipoLPartido(*(Partido*)getDato(Semis,cursor));
        }

        //Obtener segundos equipos de final y tercer puesto
        if(getGolesLPartido(*(Partido*)getDato(Semis,siguienteCursor)) > getGolesVPartido(*(Partido*)getDato(Semis,siguienteCursor)))
        {
            idGanadorDos = getIdEquipoLPartido(*(Partido*)getDato(Semis,siguienteCursor));
            idPerdedorDos = getIdEquipoVPartido(*(Partido*)getDato(Semis,siguienteCursor));
        }
        else
        {
             idGanadorDos = getIdEquipoVPartido(*(Partido*)getDato(Semis,siguienteCursor));
             idPerdedorDos = getIdEquipoLPartido(*(Partido*)getDato(Semis,siguienteCursor));
        }

        PtrNodoLista tercerPuesto = primero(Finales);
        PtrNodoLista Final = siguiente(Finales,tercerPuesto);       //Punteros para definir partidos de finales
        //definir partidos de finales
        setPartidoIdEquipoL(*(Partido*)getDato(Finales,Final),idGanadorUno);
        setPartidoIdEquipoV(*(Partido*)getDato(Finales,Final),idGanadorDos);
        setPartidoIdEquipoL(*(Partido*)getDato(Finales,tercerPuesto),idPerdedorUno);
        setPartidoIdEquipoV(*(Partido*)getDato(Finales,tercerPuesto),idPerdedorDos);

        GuardarPartidos(Finales,"finales.txt");
}

bool verificarExistenciaDeArchivo(char direccion[])
{
    FILE *archivo;
    archivo = fopen(direccion,"r++");
    if (archivo == NULL)
    {
        fclose(archivo);
        return false;
    }
    else
    {
        fclose(archivo);
        return true;
    }
}
