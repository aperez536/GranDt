#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "Lista.h"

typedef struct {
    int         Id;                  //(entero): campo identificador del jugador.
    char        Nombre[40];              //(cadena): nombre del jugador.
    int         Goles;               //(entero): Cantidad de goles Convertidos (los goles en contra restan).
    int         idEquipo;
}Jugador;


//------------------------------------------------------------------------
/*
        cargarJugadores
        pre:    Debe recibir por parametros una instancia de Lista
        post:   Copia los registros de Jugadores.txt a la instancia de Lista listaJugadores.
*/
void cargarJugadores(Lista &listaJugadores);
/*
        crearJugador
        pre:    Debe recibir una instancia de Jugador.
        post:   Inicializa los campos con los siguientes valores:
                ID = 0, Nombre = a, Goles = 0, IdEquipo = 0;
*/
void crearJugador(Jugador &nuevoJugador);
//------------------------------------------------------------------------
/*
        SetJugador
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador
                y los valores enteros de cada uno de los campos, exepto IdEquipo.
        post:   Modifica todos los valores de la instancia del tipo Jugador, salvo IdEquipo.
*/
void SetJugador(Jugador &Jugador,int _id,char _nombre[40],int _goles);
/*
        setJugadorId
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador y un valor entero.
        post:   Modifica Id en Jugador
*/
void setJugadorId(Jugador &Jugador,int _id);
/*
        setJugadorNombre
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador
                y una cadena de caracteres.
        post:   Modifica Nombre en Jugador
*/
void setJugadorNombre(Jugador &Jugador,char _nombre[40]);
/*
        setJugadorGoles
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador y un valor entero.
        post:   Modifica Goles en Jugador
*/
void setJugadorGoles(Jugador &Jugador,int _goles);
/*
        setJugadorIdEquipo
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador y un valor entero.
        post:   Modifica IdEquipo en Jugador
*/
void setJugadorIdEquipo (Jugador &Jugador, int _idEquipo);
//------------------------------------------------------------------------
/*
        getIdJugador
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador.
        post:   Devuelve el valor entero de IdJugador en Jugador.
*/
int getIdJugador(Jugador &jugador);
/*
        getNombreJugador
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador.
        post:   Devuelve una cadena la caracteres de Nombre en Jugador.
*/
char *getNombreJugador(Jugador &jugador);
/*
        getGolesJugador
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador.
        post:   Devuelve el valor entero de Goles en Jugador.
*/
int getGolesJugador(Jugador &jugador);
/*
        getJugadorIdEquipo
        pre:    Debe recibir por parametros una instancia del tipo Jugador creada con crearJugador.
        post:   Devuelve el valor entero de IdEquipo en Jugador.
*/
int getJugadorIdEquipo(Jugador &jugador);
//------------------------------------------------------------------------
/*
        BuscarIdExistenteJugador
        pre:    Debe recibir una instancia de Lista y el valor numerico entero de la Id del Jugador a encontrar
        post:   Si el Jugador existe devuelve verdadero, de lo contrario falso.
*/
bool BuscarIdExistenteJugador(Lista &listaJugadores,int id);

//------------------------------------------------------------------------
/*
        AltaJugador
        pre:    Debe recibir una instancia de Lista
        post:   Agrega un nuevo nodo a la lista de Jugadores. Lo inicializa con valores en 0.
*/
bool AltaJugador(Lista &listaJugadores);
/*
        BajaJugador
        pre:    Debe recibir una instancia de Lista
        post:   Ya no se podra utilizar mas ese Jugador
*/
bool BajaJugador(Lista &listaJugadores);
/*
        ModificacionJugador
        pre:    Debe recibir una instancia de Lista
        post:   Permite modificar los valores, uno a uno, de un Jugador.
*/
bool ModificacionJugador(Lista &listaJugadores);
/*
        ObtenerDatoListaJugadores
        pre:    Debe reecibir recibir una instancia de Lista, un punterto a uno de los nodos
                y una instancia de Jugador.
        post:   Los datos del nodo apuntado por el cursor se copiaran en la instancia de Jugador.
*/
void ObtenerDatoListaJugadores(Lista &listaJugadores,PtrNodoLista cursor,Jugador &jugador);

//------------------------------------------------------------------------------------------- NEW!!!!
/*
        buscarJugador
        pre:    Debe Recibir por parametros un Lista, la Id del Equipo del Jugador que se desea encontrar
                y la Id del Jugador mismo.
        post:   Si el Jugador existe devuelve verdadero, de lo contrario falso.
*/
bool buscarJugador(Lista &listaJugadores,int idequipo,int idjugador);
/*
        remplazardatosdeauxiliarenoriginalJugador
        pre:    Debe recibir por parametro dos instancias de Lista
        post:   Copia todos los nodos con el mismo Id de la instancia listaaux a listajugadores.
*/
void remplazardatosdeauxiliarenoriginalJugador(Lista &listajugadores,Lista &listaaux);
/*
        buscarIdjugador
        pre:    Debe Recibir por parametros un Lista y la Id del Jugador.
        post:   Si el Jugador existe devuelve verdadero, de lo contrario falso.
*/
bool buscarIdjugador(Lista &listaJugadores,int id);

//---------------------------------------------------------------------------------------
/*
        JugadorMeteGol
        pre:    Debe recibir por parametros una insancia de Lista y un puntero al Jugador que se desea modificar.
        post:   Aumenta en 1 la cantidad de goles del Jugador.
*/
void JugadorMeteGol(Lista &listaJugadores,PtrNodoLista &cursor);
/*
        GolEnContraJugador
        pre:    Debe recibir por parametros una insancia de Lista y un puntero al Jugador que se desea modificar.
        post:   Decrementa en 1 la cantidad de goles del Jugador.
*/
void GolEnContraJugador(Lista &listaJugadores,PtrNodoLista &cursor);
/*
        MeterGolDeJugadorEnEquipo
        pre:    Debe recibir por parametros una instancia de Lista y la Id del Jugador a modificar
        post:   Aumenta en 1 la cantidad de goles del Jugador.
*/
void MeterGolDeJugadorEnEquipo(Lista &listaJugadores,int idjugador);
/*
        MeterGolEnContraDeJugadorEnEquipo
        pre:    Debe recibir por parametros una instancia de Lista y la Id del Jugador a modificar
        post:   Decrementa en 1 la cantidad de goles del Jugador.
*/
void MeterGolEnContraDeJugadorEnEquipo(Lista &listaJugadores,int idjugador);
/*
        GuardarJugadores
        pre:    Debe recibir por parametros una instancia de Lista.
        post:   Copia a los registros de la instancia de tipo Lista en el archivo Jugadores.txt
*/
void GuardarJugadores(Lista &listaJugadores);



#endif // JUGADOR_H_INCLUDED
