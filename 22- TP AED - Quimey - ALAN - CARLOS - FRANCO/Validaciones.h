#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "Lista.h"

/**
pre: se tiene que haber instanciado el listagrupos con anterioridad

post: Informara los errores que se encuentren en la lista grupo

*/

void BuscarErroresGrupo(Lista & listagrupos,Lista & listaEquipo);

/**
pre: se tiene que haber instanciado el listagrupos con anterioridad

post: devolvera true o false, dependiendo de que si tiene repetitods equipos en diferentes grupos

*/
bool BuscarEquiposRepetidosEnDiferentesGrupos(Lista & listagrupos);

/**
pre: se tiene que haber instanciado el listaJugadores con anterioridad

post: Informara los errores que se encuentren en la listaJugadores

*/
void BuscarErroresIdJugador(Lista &listaJugadores);

/**
pre: se tiene que haber instanciado el listaEquipos con anterioridad

post: Informara los errores que se encuentren en la listaEquipos

*/

void BuscarErroresIdEquipo(Lista &listaEquipos);

/**
pre: se tiene que haber instanciado el listaPartidos con anterioridad

post: Informara los errores que se encuentren en la listaPartidos

*/
void BuscarErroresIdPartidos(Lista &listaPartidos);

/**
pre: se tiene que haber instanciado el listaPartidos con anterioridad

post: Informara los errores que se encuentren en la listaPartidos donde un equipo se enfrente a si mismo

*/
void BuscarEnPartidoEquiposEnfrentados(Lista &listaPartidos);





#endif // VALIDACIONES_H_INCLUDED
