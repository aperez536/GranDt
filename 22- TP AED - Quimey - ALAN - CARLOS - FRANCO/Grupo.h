
#ifdef GRUPO_EXPORTS
#define GRUPO __declspec(dllexport)
#else
#define GRUPO__declspec(dllimport)
#endif
#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED
#include "Lista.h"
 extern "C++"
 {

typedef struct {
    char        Id;                  //(char): campo identificador del grupo (de la A a la H).
    char        Nombre[40];          //(cadena): nombre utilizado para el grupo (“Grupo “ + Id).
    int         IdEquipo1;           //(entero): id del equipo 1.
    int         IdEquipo2;           //(entero): id del equipo 2.
    int         IdEquipo3;           //(entero): id del equipo 3.
    int         IdEquipo4;           //(entero): id del equipo 4.
}Grupo;
/**
pre: se tiene que haber instanciado el  tipo grupo anteriormente
post: se crea el grupo  valores por defecto grupo.id='a', nombre[0]='a', idequipo1=1,idequipo2=1, idequipo3=1, idequipo4=1;
axiomas: idequipo1,idequipo2,idequipo3,IdEquipo4 tienen que haberse creado con anterioridad y tienen que existir en
la lista equipo.

*/
void crearGrupo(Grupo &grupo);
/**
pre: tiene que haberse instanciado el tipo grupo anteriormente.
post: se carga en la instancia grupo los parametros que se pasa.
axiomas: idequipo1,idequipo2,idequipo3 tienen que haberse creado con anterioridad


*/
void SetGrupo(Grupo &grupo,char _id,char _nombre[40],int _IdE1,int _IdE2,int _IdE3, int _IdE4);
/**
pre: tiene que haberse instanciado el tipo grupo anteriormente
post: devuelvo el id del grupo.

*/
char getIdGrupo(Grupo &grupo);
/**
pre: tiene que haberse instanciado el tipo grupo anteriormente
post: devuelvo el nombre del grupo.


*/
char *getNombreGrupo(Grupo &grupo);

//char getNombreGrupo(Grupo &grupo);
/**
pre: tiene que haberse instanciado el tipo grupo anteriormente
post: devuelvo el id del equipo1.


*/
int getIdEquipo1(Grupo &grupo);
/**
pre: tiene que haberse instanciado el tipo grupo anteriormente
post: devuelvo el id del equipo2.


*/
int getIdEquipo2(Grupo &grupo);
/**
pre: tiene que haberse instanciado el tipo grupo anteriormente
post: devuelvo el id del equipo3.


*/
int getIdEquipo3(Grupo &grupo);
/**
pre: tiene que haberse instanciado el tipo grupo anteriormente
post: devuelvo el id del equipo4.
*/
int getIdEquipo4(Grupo &grupo);


//-------------------------------------------------------
/**
pre: se tiene que tener el archivo grupos.txt
post: se carga una lista de grupos.
*/
void cargarGrupos(Lista &listaGrupos);
/**
PRE: se tuvo que haber creado : la lista grupo anteriormente, el cursor que apuntara a los datos en ese momento y el
grupo instanciado anteriormente.
POST: devuelvo lo que apunta el cursor en esa lista en ese momento.

*/
void ObtenerDatoListaGrupo(Lista &listaGrupos,PtrNodoLista cursor,Grupo &grupo);
/**
PRE: se tiene que haber creado la listapartido anteriormente.
POST: devuelve true si estan el equipo1 y equipo2 en el mismo partido y false si no estan en el mismo partido.
*/
bool BuscarPosDeEquipoEnGrupo(Lista &listapartido,int equipol,int equipov);
/**
PRE: se tuvo que haber crado la lista anteriormente.
POST: devuelvo los datos actualizados de la lista grupo al archivo.

*/
void GuardarGrupos (Lista &ListaGrupo);

#endif // GRUPO_H_INCLUDED

 }

