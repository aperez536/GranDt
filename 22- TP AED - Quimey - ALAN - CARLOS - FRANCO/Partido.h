#ifndef PARTIDO_H_INCLUDED
#define PARTIDO_H_INCLUDED
#include "Lista.h"

typedef struct {
    int         Id;                  //(entero): campo de identificación del partido.
    int         idEquipoL;           //(entero): Id del equipo Local.
    int         idEquipoV;           //(entero): Id del equipo Visitante.
    int         golesL;              //(entero): goles a favor equipo Local.
    int         golesV;              //(entero): goles a favor equipo Visitante.
}Partido;
/*
        cargarPartidos
        pre:    Debe recibir por parametros una instancia de Lista y
                una cadena de caracteres.
        post:   Copia los registros del archivo .txt especificado en la instancia direccion
                en la instancia del tipo Lista.
*/
void cargarPartidos(Lista &listaPartidos,char direccion[]);
/*
        crearPartido
        pre:    Debe recibir por parametros una instancia del tipo Partido.
        post:   Inicializa la instancia partido con los siguientes valores:
                Id = 0, idEquipoL = 0, idEquipoV = 0, partido.golesL = -1, partido.golesV = -1.
*/
void crearPartido(Partido &partido);
/*
        SetPartido
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido
                y los valores enteros de cada uno de los campos, sin faltar ninguno.
        post:   Modifica todos los valores de la instancia del tipo Partido.
*/
void SetPartido(Partido &partido, int _id, int _idEL, int _idEV, int _golesL, int _golesV);
/*
        setPartidoId
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido y un valor entero.
        post:   Modifica Id en partido
*/
void setPartidoId(Partido &partido, int id);
/*
        setPartidoIdEquipoL
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido y un valor entero.
        post:   Modifica idEquipoL en partido
*/
void setPartidoIdEquipoL (Partido &partido, int idEquipoL);
/*
        setPartidoIdEquipoV
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido y un valor entero.
        post:   Modifica idEquipoV en partido
*/
void setPartidoIdEquipoV (Partido &partido, int idEquipoV);
/*
        setPartidoGolesL
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido y un valor entero.
        post:   Modifica golesL en partido
*/
void setPartidoGolesL (Partido &partido, int golesL);
/*
        setPartidoGolesV
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido y un valor entero.
        post:   Modifica golesV en partido
*/
void setPartidoGolesV (Partido &partido, int golesV);
/*
        getIdPartido
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido.
        post:   Devuelve el valor entero de Id en partido
*/
int getIdPartido(Partido &partido);
/*
        getIdEquipoLPartido
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido.
        post:   Devuelve el valor entero de IdEquipoL en partido
*/
int getIdEquipoLPartido(Partido &partido);
/*
        getIdEquipoVPartido
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido.
        post:   Devuelve el valor entero de IdEquipoV en partido
*/
int getIdEquipoVPartido(Partido &partido);
/*
        getGolesLPartido
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido.
        post:   Devuelve el valor entero de GolesL en partido
*/
int getGolesLPartido(Partido &partido);
/*
        getGolesVPartido
        pre:    Debe recibir por parametros una instancia del tipo Partido creada con crearPartido.
        post:   Devuelve el valor entero de GolesV en partido
*/
int getGolesVPartido(Partido &partido);
/*
        ObtenerDatoListaPartido
        pre:    Debe reecibir recibir una instancia de Lista, un punterto a uno de los nodos
                y una instancia de Partido.
        post:   Los datos del nodo apuntado por el cursor se copiaran en la instancia de Partido.
*/
void ObtenerDatoListaPartido(Lista &listaPartidos,PtrNodoLista cursor,Partido &partido);
/*
        ResetGolesDeLaListaPartido
        pre:    Debe recibir una instancia de Lista y un puntero a uno de los nodos.
        post:   Fija en 0 los valores de golesL y golesV en el nodo apuntado por el cursor.
*/
void ResetGolesDeLaListaPartido(Lista &listaPartidos,PtrNodoLista cursor);
//---------------------------------------------------------------------------------------
/*
        BuscarIdExistentePartido
        pre:    Debe recibir una instancia de Lista y el valor numerico entero de la Id del partido a encontrar
        post:   Si el partido existe devuelve verdadero, de lo contrario falso.
*/
bool BuscarIdExistentePartido(Lista &listapartido,int id);
//---------------------------------------------------------------------------------------
/*
        MeterGolesL
        pre:    Debe recibir una instancia de Lista y un puntero a uno de los nodos.
        post:   Suma 1 al valor numerico entero de GolesL en el nodo apuntado
*/
void MeterGolesL(Lista &listapartido,PtrNodoLista &cursor);
/*
        MeterGolesV
        pre:    Debe recibir una instancia de Lista y un puntero a uno de los nodos.
        post:   Suma 1 al valor numerico entero de GolesV en el nodo apuntado
*/
void MeterGolesV(Lista &listapartido,PtrNodoLista &cursor);
//---------------------------------------------------------------------------------------
/*
        remplazardatosdeauxiliarenoriginalPartido
        pre:    Debe recibir por parametro dos instancias de Lista
        post:   Copia todos los nodos con el mismo Id de la instancia listaaux a listaPartido
*/
void remplazardatosdeauxiliarenoriginalPartido(Lista &listaPartido,Lista &listaaux);
/*
        BuscarIdEquipoEnPartido
        pre:    Debe recibir una instancia de Lista y el valor numerico entero de la Id del equipo a encontrar
        post:   Si el equipo esta jugando devuelve verdadero, de lo contrario falso.
*/
bool BuscarIdEquipoEnPartido(Lista &listapartido,int id);
/*
        PasarFaseEliminacion
        pre:    Debe Recibir una instancia de Lista
        post:   Devuelve verdadero en caso de que el equipo pueda avanzar de fase por cantidad de partidos jugados
                y por la cantidad de puntos. Si no cumple las condiciones devuelve falso.
*/
bool PasarFaseEliminacion(Lista &listaPartido);
/*
        BuscarIdPartidoParaGolesL
        pre:    Debe recibir una instancia de Lista y el valor numerico entero de la Id del partido a encontrar
        post:
*/
void BuscarIdPartidoParaGolesL(Lista &listaPartido,int id);
/*
        BuscarIdPartidoParaGolesV
        pre:    Debe recibir una instancia de Lista y el valor numerico entero de la Id del partido a encontrar
        post:   Guarda los goles realizados por ambos equipos en el partido con la Id ingresada por parametro.
*/
void BuscarIdPartidoParaGolesV(Lista &listaPartido,int id);
/*
        GuardarPartidos
        pre:    Debe recibir por parametros una instancia de Lista creada con crearPartido y
                una cadena de caracteres.
        post:   Copia a los registros de la instancia de tipo Lista en el archivo .txt
                especificado en la instancia direccion.
*/
void GuardarPartidos (Lista &listaPartidos,char direccion[]);
/*
        RepartirPuntaje
        pre:    Debe recibir por parametro 3 instancias de Lista, una en la que sus nodos sean Partidos
                y dos en las que sus nodos sean Equipos. Ademas se nesecita la Id del partido.
        post:   Asignara los puntos a cada Equipo en dependiendo el resultado del Partido.
*/
void RepartirPuntaje(Lista &auxPartido,Lista &auxEquipo1,Lista &auxEquipo2,int id);


#endif // PARTIDO_H_INCLUDED
