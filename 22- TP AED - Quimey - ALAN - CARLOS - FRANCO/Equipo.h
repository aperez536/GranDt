#ifndef EQUIPO_H_INCLUDED
#define EQUIPO_H_INCLUDED
#include "Lista.h"


typedef struct {
    int         Id;                 //(entero): campo identificador del equipo.
    char        Nombre[40];             //(cadena): nombre del equipo.
    int         Goles_A_Favor;      //(entero): cantidad de goles convertidos por el equipo.
    int         Goles_En_Contra;    //(entero): cantidad de goles recibidos por el equipo.
    int         Puntos;             //(entero): Cantidad de puntos obtenidos por el equipo.
                               //hay que poner una lista de jugadores
}Equipo;
/**
pre: se tiene que haber instanciado el  tipo equipo anteriormente
post: se crea el equipo  valores por defecto en equipo  Id = 1, Nombre[0]='a',Goles_A_Favor=0,Goles_En_Contra=0,Puntos=0
*/

void crearEquipo(Equipo &equipo);
/**
pre: se tiene que haber instanciado el equipo con anterioridad

post: se carga los datos que se pasa por paramentro en la instancia equipo

*/
void SetEquipo(Equipo &equipo,int _id,char _nombre[40],int _Goles_a_favor, int _Goles_en_contra, int _puntos);

/**
pre: se tiene que haber instanciado el equipo con anterioridad

post:devuelve el id del equipo

*/
int getIdEquipo(Equipo &equipo);
/**
pre: se tiene que haber instanciado el equipo con anterioridad

post:devuelve el goles a favor del equipo

*/
int getGoles_A_Favor(Equipo &equipo);
/**
pre: se tiene que haber instanciado el equipo con anterioridad

post:devuelve el nombre del equipo

*/
char *getNombreEquipo(Equipo &equipo);
/**
pre: se tiene que haber instanciado el equipo con anterioridad

post:devuelve goles en contra del equipo

*/
int getGoles_En_Contra(Equipo &equipo);
/**
pre: se tiene que haber instanciado el equipo con anterioridad

post:devuelve puntos del equipo

*/
int getPuntos(Equipo &equipo);

/**
pre: se tiene que tener el archivo equipos.txt
post: se carga una lista de equipos.
*/

void cargarListaEquipo(Lista &listaEquipo);
/**
pre: se tuvo que haber instanciado la lista equipo con anterioridad.
post: devuelve true si existe el equipo en la lista, devuelve false si no existe.

*/

bool BuscarIdExistenteEquipo(Lista &listaEquipos,int id);
/**
pre: se tuvo que haber instanciado la lista equipo con anterioridad.
post: devuelve true si se cumplio la modificacion en la lista, devuelve false si no tiene valores
*/

bool ModificacionEquipo(Lista &listaEquipo,int _id,char _nombre[40],int _GolesAFavor,int _GolesEnContra,int _puntos);

/**
pre: se tuvo que haber instanciado la lista equipo con anterioridad.
post: devuelve true si se cumplio la Alta en la lista, devuelve false si ya existe ese equipo
*/

bool Altaequipo(Lista &listaEquipo);

/**
pre: se tuvo que haber instanciado la lista equipo con anterioridad.
post: devuelve true si se cumplio la BAJA en la lista, devuelve false si no existe el equipo
*/

bool Bajaequipo(Lista &listaEquipo);

//void ListarEquipoXIdGrupo(Lista &listaEquipo,int idE1,int idE2,int idE3,int idE4,int &GolesParciales, int &TotalDeLosGrupos);

/**
PRE: se tuvo que haber creado : la lista grupo anteriormente, el cursor que apuntara a los datos en ese momento y el
grupo instanciado anteriormente.
POST: devuelvo lo que apunta el cursor en esa lista en ese momento.

*/
void ObtenerDatoListaEquipo(Lista &listaEquipo,PtrNodoLista cursor,Equipo &equipo);

/**
PRE: se tuvo que haber crado la lista anteriormente.
POST: Remplaza los valores de la lista Aux a la lista original

*/
void RemplazarDatosDeAuxiliarEnOriginalEquipo(Lista &listaEquipo,Lista &listaaux);

/**
PRE: se tuvo que haber crado la lista anteriormente.
POST: devuelvo los datos actualizados de la lista grupo al archivo.

*/
void GuardarEquipos(Lista &listaEquipo);

#endif // EQUIPO_H_INCLUDED
