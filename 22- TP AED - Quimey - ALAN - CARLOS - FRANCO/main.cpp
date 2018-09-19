#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grupo.h"
#include "Equipo.h"
#include "Jugador.h"
#include "Partido.h"
#include "reportes.h"
#include "Llaves.h"
#include "funciones_compara.h"
#include "Validaciones.h"


using namespace std;
void CargarDatos(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos,Lista &listaFechas);
void Administrar_Juego(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos);
void Administrar_Partidos(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos);
void FaseDePartidos(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos);
void FaseDeEliminacion(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos);
void Procesar_reportes(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos);
void Alta_Baja_Modificacion(int option_E_J_G_P,Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos);
void Fin_del_programa(Lista &listaJugadores ,Lista &listaEquipo, Lista &listaPartidos, Lista &ListaGrupo);
void Modificacion_de_equipo(Lista &lista);
void MostrarBienvenida();
void Rusia2018();
void MostrarMenu2();
void MostrarMenuAdPartido();
//-----------------------------------------------------------

void RegistrarInicioPartido(Lista &ListaGrupo,Lista &listaPartidos,Lista &auxPartido);
void RegistrarGolesOcurridos(Lista &listaPartidos,Lista &listaEquipo,Lista &listaJugadores,Lista &auxPartido,Lista &auxEquipo1,Lista &auxEquipo2,Lista &auxJugadorEquipo1,Lista &auxJugadorEquipo2);
void FinDelPartido(Lista &listaPartidos,Lista &listaEquipo,Lista &listaJugadores,Lista &auxPartido,Lista &auxEquipo1,Lista &auxEquipo2,Lista &auxJugadorEquipo1,Lista &auxJugadorEquipo2);

//-----------------------------------------------------------
void recorrerJugadores(Lista &listaJugadores);
void recorrerListaEquipo(Lista &listaEquipo);
void recorrerGrupos(Lista &listaGrupos);
void recorrerPartidos(Lista &listaPartidos);
void recorrerJugadoresEnEquipo(Lista &listaJugadores,int id);
//-----------------------------------------------------------

int main(int argc, char *argv[]){

    Lista listaEquipo;
    Lista ListaGrupo;
    Lista listaJugadores;
    Lista listaPartidos;
    Lista listaFechas;

    CargarDatos(listaEquipo,ListaGrupo,listaJugadores,listaPartidos,listaFechas);

    int option=99;
    Rusia2018();
    while (option != 0){

        MostrarBienvenida();

        cin >> option;
        system ("cls");

        switch (option){
            case 1: Administrar_Juego(listaEquipo,ListaGrupo,listaJugadores,listaPartidos);
                    break;
            case 2: Administrar_Partidos(listaEquipo,ListaGrupo,listaJugadores,listaPartidos);
                    break;
            case 3: Procesar_reportes(listaEquipo,ListaGrupo,listaJugadores,listaPartidos);
                    break;
            case 0: Fin_del_programa(listaJugadores,listaEquipo,listaPartidos,ListaGrupo);
                    break;
            default:cout<<"Error!!, valor ingresado no valido"<<endl;
                    break;
        }
    }

    return 0;
}


void CargarDatos(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos,Lista &listaFechas){

        cout << "errores detectados en carga de archivos" << endl;
        cargarListaEquipo(listaEquipo);
        //recorrerListaEquipo(listaEquipo);
        BuscarErroresIdEquipo(listaEquipo);

        cargarGrupos(ListaGrupo);
        //recorrerGrupos(ListaGrupo);
        BuscarErroresGrupo(ListaGrupo,listaEquipo);


        cargarJugadores(listaJugadores);
        //recorrerJugadores(listaJugadores);

        BuscarErroresIdJugador(listaJugadores);


        cargarPartidos(listaPartidos,"partidos.txt");
        //recorrerPartidos(listaPartidos);

        BuscarErroresIdPartidos(listaPartidos);
        BuscarEnPartidoEquiposEnfrentados(listaPartidos);

}


void Rusia2018(){
    int i;
    for(i=1; i<=67;i++){
        cout<<"*";
    }
    cout<<""<<endl;

    cout<<"* *****   *    *   *****  *   ****     *****    ****   *   *****  *"<<endl;
    cout<<"* *    *  *    *  *          *    *         *  *    *  *  *     * *"<<endl;
    cout<<"* *    *  *    *  *       *  *    *         *  *    *  *  *     * *"<<endl;
    cout<<"* *    *  *    *  *       *  *    *         *  *    *  *  *     * *"<<endl;
    cout<<"* *****   *    *  *****   *  ******     ****   *    *  *   *****  *"<<endl;
    cout<<"* *  *    *    *       *  *  *    *    *       *    *  *  *     * *"<<endl;
    cout<<"* *   *   *    *       *  *  *    *    *       *    *  *  *     * *"<<endl;
    cout<<"* *    *  *    *       *  *  *    *    *       *    *  *  *     * *"<<endl;
    cout<<"* *    *   ****   *****   *  *    *     *****   ****   *   *****  *"<<endl;

    for(i=1; i<=67;i++){
        cout<<"*";
    }
    cout<<""<<endl;
    cout<<""<<endl;
}


void MostrarBienvenida(){
        cout<<"Bienvenido a la aplicacion de administracion, elija una de las siguientes opciones"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        cout<<"1 - Administrar equipos, jugadores, grupos y partidos "<<endl;
        cout<<"2 - Administrar Partidos"<<endl;
        cout<<"3 - Procesar reportes"<<endl;
        cout<<"0 - Salir de la aplicacion "<<endl;  //(se deberán grabar los datos en los archivos).
        cout<<"----------------------------------------------------------------------------------"<<endl;
}


void Administrar_Juego(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos){
    int option=99;
    while (option != 0){
        cout<<"Has escojido: Administrar equipos, jugadores, grupos y partidos,escoje que deseas modificar"<<endl;
        cout<<"-------------------------------------------------------------------------------------------"<<endl;
        cout<<"1 - Equipos"<<endl;
        cout<<"2 - Jugadores"<<endl;
        cout<<"3 - Grupos"<<endl;
        cout<<"4 - Partidos"<<endl;
        cout<<"0 - Salir del menu"<<endl;
        cout<<"-------------------------------------------------------------------------------------------"<<endl;
        cin >> option;
        system ("cls");
        if(option>=1 && option<=4){
                Alta_Baja_Modificacion(option,listaEquipo,ListaGrupo,listaJugadores,listaPartidos);
        }

    }
}


void Alta_Baja_Modificacion(int option_E_J_G_P,Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos){
    int option=99;

    while (option != 0){
        if(option_E_J_G_P == 1)
        cout<<"Has elegido /Equipos/,elije alguna de las siguientes opciones:"<<endl;

        if(option_E_J_G_P == 2)
        cout<<"Has elegido /Jugadores/,elije alguna de las siguientes opciones:"<<endl;

        if(option_E_J_G_P == 3)
        cout<<"Has elegido /Grupos/,elije alguna de las siguientes opciones:"<<endl;

        if(option_E_J_G_P == 4)
        cout<<"Has elegido /Partidos/,elije alguna de las siguientes opciones:"<<endl;

        cout<<"-------------------------------------------------------------------------------------------"<<endl;
        cout<<"1 - Alta"<<endl;
        cout<<"2 - Baja"<<endl;
        cout<<"3 - Modificacion"<<endl;
        cout<<"0 - Salir del Menu"<<endl;
        cout<<"-------------------------------------------------------------------------------------------"<<endl;
        cin >> option;
        system ("cls");
        if(option == 0) break;  //para salir del while automaticamente

        if(option_E_J_G_P == 1){

            switch(option){
            case 1: recorrerListaEquipo(listaEquipo);
                    if (Altaequipo(listaEquipo) == 1){
                    recorrerListaEquipo(listaEquipo);
                    }
                    break;

            case 2: recorrerListaEquipo(listaEquipo);
                    if(Bajaequipo(listaEquipo)== 1){
                    recorrerListaEquipo(listaEquipo);
                     cout<<"Id eliminada"<<endl;
                  }
                   break;
            case 3: recorrerListaEquipo(listaEquipo);
                    Modificacion_de_equipo(listaEquipo);
                    break;
            default:cout << "error  "<< endl;
                    break;
            }
        }

        if(option_E_J_G_P == 2){
            switch(option){
                case 1: if(AltaJugador(listaJugadores) == 1)
                        recorrerJugadores(listaJugadores);
                        break;

                case 2: if(BajaJugador(listaJugadores) == 1)
                        recorrerJugadores(listaJugadores);
                        break;

                case 3: if(ModificacionJugador(listaJugadores))
                        recorrerJugadores(listaJugadores);
                        break;

                default: cout << "error  "<< endl;
                         break;
            }
        }

        if(option_E_J_G_P == 3){
            cout<<"Va el switch de la ALTA BAJA Y MODIF del Grupos"<<endl;
        }

        if(option_E_J_G_P == 4){
            cout<<"Va el switch de la ALTA BAJA Y MODIF del Partidos"<<endl;
        }
    }
}


void MostrarMenuAdPartido(){
    cout<<"Has escojido: Administrar Partido"<<endl;
    cout<<"Escoje entre administrar los partidos de la fase actual o cuando termine elegir la siguiente fase"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"1 - Fase De Grupos"<<endl;
    cout<<"2 - Fase De Eliminacion"<<endl;                             // (con puntos y diferencia de gol)
    cout<<"0 - Salir del menu"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
}


void Administrar_Partidos(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos){
    int option=99;

    while (option != 0){

        MostrarMenuAdPartido();

        cin >> option ;
        system ("cls");

        switch(option){
                case 1: if(!PasarFaseEliminacion(listaPartidos))
                        FaseDePartidos(listaEquipo,ListaGrupo,listaJugadores,listaPartidos);
                        else cout<<"Ya terminaron todos los partidos, ir a la prox fase"<<endl;
                        break;
                case 2: if(PasarFaseEliminacion(listaPartidos))
                        FaseDeEliminacion(listaEquipo,ListaGrupo,listaJugadores,listaPartidos);
                        else cout<<"Aun no terminaron los partidos de la fase actual"<<endl;
                        break;
                case 0: ///salir
                        break;
        }
    }
}


void FaseDePartidos(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos){

   int option=99;
    //---------------------------------------------------------------
    Lista auxPartido;
    crearLista(auxPartido,auxPartido.compara);
    //---------------------------------------------------------------
    Lista auxEquipo1;
    Lista auxEquipo2;
    Lista auxJugadorEquipo1;
    Lista auxJugadorEquipo2;
    //---------------------------------------------------------------
    crearLista(auxEquipo1,auxEquipo1.compara);
    crearLista(auxEquipo2,auxEquipo2.compara);
    crearLista(auxJugadorEquipo1,auxJugadorEquipo1.compara);
    crearLista(auxJugadorEquipo2,auxJugadorEquipo2.compara);
    //---------------------------------------------------------------

    while (option != 0){
        cout<<"Estas en Fase De Partidos,escoge que deseas elegir"<<endl;
        cout<<"ALERTA: NO SALGA DE ESTE MENU HASTA QUE HAYA FINALIZADO EL PARTIDO"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        cout<<"1 - Registrar el inicio de un partido"<<endl;                //(identificado por id)
        cout<<"2 - Registrar los goles ocurridos en cada partido"<<endl;    //(identificando equipo y jugador)
        cout<<"3 - Registrar el fin de un partido"<<endl;                   //A que se refiere con esto???????????????????????
        cout<<"0 - Salir del menu"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        cin >> option;
        system ("cls");

          //MIENTRAS SEA FALSE, !FALSE = TRUE , HACE LO DEL PARTIDO DE GRUPOS // HASTA QUE TERMINE LOS PARTIDOS
                                                    //Y DE AHI, PASARFASE ESTARA EN TRUE, COMO SE LO NIEGO !TRUE = FALSE, POR ENDE, PASA AL ELSE
        switch(option){
            case 1: RegistrarInicioPartido(ListaGrupo,listaPartidos,auxPartido);
                    break;
            case 2: RegistrarGolesOcurridos(listaPartidos,listaEquipo,listaJugadores,auxPartido,auxEquipo1,auxEquipo2,auxJugadorEquipo1,auxJugadorEquipo2);
                    break;
            case 3: FinDelPartido(listaPartidos,listaEquipo,listaJugadores,auxPartido,auxEquipo1,auxEquipo2,auxJugadorEquipo1,auxJugadorEquipo2);
                    break;
            case 0: //salir
                    break;
        }

    }

}


void FaseDeEliminacion(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos){

    int option=99;
    //---------------------------------------------------------------
    Lista Octavos,Cuartos,Semis,Finales;
    //---------------------------------------------------------------
    crearLista(Octavos,compararPartido);
    crearLista(Cuartos,compararPartido);
    crearLista(Semis,compararPartido);
    crearLista(Finales,compararPartido);
    //---------------------------------------------------------------

    while (option != 0){
        cout<<"Has escoggido: Fase De Eliminacion, A que fase quiere pasar?"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        cout<<"1 - Octavos"<<endl;                //(identificado por id)
        cout<<"2 - Cuartos"<<endl;    //(identificando equipo y jugador)
        cout<<"3 - Semis"<<endl;                   //A que se refiere con esto???????????????????????
        cout<<"4 - Finales"<<endl;
        cout<<"0 - Salir del menu"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        cin >> option;
        system ("cls");

          //MIENTRAS SEA FALSE, !FALSE = TRUE , HACE LO DEL PARTIDO DE GRUPOS // HASTA QUE TERMINE LOS PARTIDOS
                                                    //Y DE AHI, PASARFASE ESTARA EN TRUE, COMO SE LO NIEGO !TRUE = FALSE, POR ENDE, PASA AL ELSE
        switch(option){
            case 1: if (!verificarFinalFase(listaPartidos))             //ver si termino la fase anterior
                    {
                        cout << "fase de grupos aun no finalizo" << endl;   //
                    }
                    else
                    {
                    if (verificarExistenciaDeArchivo("octavos.txt"))    //Ver si el archivo fue creado
                    {
                        cargarPartidos(Octavos,"octavos.txt");          //Carga la lista del archivo
                    }
                    else{                                               //si no
                        generarListaOctavos(listaEquipo,Octavos);       //carga la lista y guarda el archivo
                        }
                    cout << "lista de partidos octavos de final" << endl;

                    recorrerPartidos(Octavos);
                    FaseDePartidos(listaEquipo,ListaGrupo,listaJugadores,Octavos);
                    GuardarPartidos(Octavos,"octavos.txt");
                    }

                    break;
            case 2: if (!verificarExistenciaDeArchivo("octavos.txt"))             //ver si termino la fase anterior
                    {
                        cout << "fase de grupos aun no finalizo" << endl;   //
                    }
                    else
                    {
                    if((!verificarFinalFase(Octavos))||(!verificarFinalFase(listaPartidos)))
                    {
                        cout << "octavos de final aun no finalizo" << endl;
                    }
                    else{

                        if (verificarExistenciaDeArchivo("cuartos.txt"))
                        {
                            cargarPartidos(Cuartos,"cuartos.txt");
                        }
                        else{
                            cargarPartidos(Octavos,"octavos.txt");
                            generarListaCuartos(Octavos,Cuartos);
                        }

                        cout << "lista de partidos cuartos de final" << endl;
                        recorrerPartidos(Cuartos);
                        FaseDePartidos(listaEquipo,ListaGrupo,listaJugadores,Octavos);
                        GuardarPartidos(Cuartos,"cuartos.txt");
                    }
                    }
                    break;
            case 3: if (!verificarExistenciaDeArchivo("Cuartos.txt"))             //ver si termino la fase anterior
                    {
                        cout << "Cuartos de final aun no finalizo" << endl;   //
                    }
                    else
                    {
                    if((!verificarFinalFase(Cuartos))||(!verificarFinalFase(Octavos))||(!verificarFinalFase(listaPartidos)))
                    {
                        cout << "cuartos de final aun no finalizo" << endl;
                    }
                    else{
                        if (verificarExistenciaDeArchivo("semifinales.txt"))
                        {
                            cargarPartidos(Semis,"semifinales.txt");
                        }
                        else{
                            cargarPartidos(Cuartos,"cuartos.txt");
                            generarListaSemis(Cuartos, Semis);
                        }

                        cout << "lista de partidos de semifinal" << endl;
                        recorrerPartidos(Semis);
                        FaseDePartidos(listaEquipo,ListaGrupo,listaJugadores,Octavos);
                        GuardarPartidos(Semis,"semifinales.txt");
                    }
                    }

                    break;
            case 4: if (!verificarExistenciaDeArchivo("semifinales.txt"))             //ver si termino la fase anterior
                    {
                        cout << "Semifinal aun no finalizo" << endl;   //
                    }
                    else
                    {
                    if((!verificarFinalFase(Semis))||(!verificarFinalFase(Cuartos))||(!verificarFinalFase(Octavos))||(!verificarFinalFase(listaPartidos)))
                    {
                        cout << "Semifinales aun no finalizo" << endl;
                    }
                    else{
                        if (verificarExistenciaDeArchivo("finales.txt"))
                        {
                            cargarPartidos(Finales,"finales.txt");
                        }
                        else{
                            cargarPartidos(Semis,"semifinales.txt");
                            generarListaFinales(Semis, Finales);
                        }
                        cout << "partidos tercer puesto y final" << endl;
                        recorrerPartidos(Finales);
                        FaseDePartidos(listaEquipo,ListaGrupo,listaJugadores,Octavos);
                        GuardarPartidos(Finales,"finales.txt");
                    }
                    }

                    break;
            case 0:
                    break;
        }
    }
}


void RegistrarInicioPartido(Lista &ListaGrupo,Lista &listaPartidos,Lista &auxPartido){

        int id;
        bool encontrado = false;
        Partido partido;
        PtrNodoLista cursor;

        cout << "ingrese id del Partido a iniciar" << endl;
        cin >> id;

        if (BuscarIdExistentePartido(listaPartidos ,id)){
                //SI EXISTE
                if(!BuscarIdExistentePartido(auxPartido,id)){
                    //ESTA LISTA SIRVE PARA INICIAR PARTIDOS NO INICIADOS ANTERIORMENTE

                    cursor = primero(listaPartidos);

                    while(cursor != fin()){

                        ObtenerDatoListaPartido(listaPartidos,cursor,partido);

                        if ( getIdPartido(partido) == id ){

                                // ACA VALIDA SI LOS 2 EQUIPOS ESTAN EN EL MISMO GRUPO PARA QUE COMIENCE EL PARTIDO


                                if(BuscarIdEquipoEnPartido(auxPartido,getIdEquipoLPartido(partido) ) == false  &&
                                    BuscarIdEquipoEnPartido(auxPartido,getIdEquipoVPartido(partido)) == false  )

                                {

                                        if ( getGolesLPartido(partido) == -1 && ( getGolesVPartido(partido)  == -1) ){
                                            cout << "comenzo el partido: "<< endl;

                                            ResetGolesDeLaListaPartido(listaPartidos,cursor);

                                            if(listaVacia(auxPartido))
                                                adicionarPrincipio(auxPartido,getDato(listaPartidos,cursor));
                                            else
                                                adicionarFinal(auxPartido,getDato(listaPartidos,cursor));
                                    }

                                }
                                else encontrado = true;


                        }
                        cursor = siguiente(listaPartidos, cursor);
                    }

                }
                else{
                        cout << "ya comenzo anteriormente el partido "<< endl;
                    }
                    if(encontrado == true){
                        cout << "un equipo ya esta jugando "  << endl;
                    }



        }
        else cout << " no  existe el partido " << endl;

        recorrerPartidos(auxPartido);
}


void RegistrarGolesOcurridos(Lista &listaPartidos,Lista &listaEquipo,Lista &listaJugadores,Lista &auxPartido,Lista &auxEquipo1,Lista &auxEquipo2,Lista &auxJugadorEquipo1,Lista &auxJugadorEquipo2){

    //---------------------------------------------------------------
    Partido partido;
    Equipo equipo;
    Jugador jugador;

    //---------------------------------------------------------------
    int idjugador;
    int idequipo;

    int equipo1=999;
    int equipo2=999;
    int id;
    PtrNodoLista cursor;

    //---------------------------------------------------------------

    //---------------------------------------------------------------

    //---------------------------------------------------------------
    recorrerPartidos(auxPartido);

    cout << " ingrese id del partido " << endl;
    cin >> id;

    if(BuscarIdExistentePartido(auxPartido,id)){

        cursor = primero(auxPartido);

        while(cursor != fin()){

                ObtenerDatoListaPartido(auxPartido,cursor,partido);

                // GUARDO LOS ID DE EQUIPOS LOCAL Y VISITANTE
                // EQUIPO 1 = LOCAL
                // EQUIPO 2 = VISITANTE

            if( getIdPartido(partido) == id  ){
                equipo1 = getIdEquipoLPartido(partido);
                equipo2 = getIdEquipoVPartido(partido);

            }

            cursor = siguiente(auxPartido,cursor);
        }


        cursor = primero(listaEquipo);

        while (cursor  != fin()){
            ObtenerDatoListaEquipo(listaEquipo,cursor,equipo);

                // SI LOS ENCUENTRA LOS GUARDO EN UNA LISTA AUXILIAR SEPARADO
            if(  getIdEquipo(equipo) == equipo1 )
            {
                if (BuscarIdExistenteEquipo(auxEquipo1,equipo1) == false){

                    if(listaVacia(auxEquipo1)){
                        adicionarPrincipio( auxEquipo1,getDato(listaEquipo,cursor) );
                    }
                    else{
                        adicionarFinal( auxEquipo1,getDato(listaEquipo,cursor) );
                    }
                }
            }


             if(  getIdEquipo(equipo) == equipo2 )
             {
                if (BuscarIdExistenteEquipo(auxEquipo2,equipo2) == false)
                    {
                    if(listaVacia(auxEquipo2)){
                        adicionarPrincipio(auxEquipo2,getDato(listaEquipo,cursor));
                        }
                    else{
                        adicionarFinal(auxEquipo2,getDato(listaEquipo,cursor));
                        }
                    }
            }

            cursor = siguiente(listaEquipo,cursor);
        }
        //FIN DEL WHILE

        cursor = primero(listaJugadores);

        while( cursor != fin()){
            //SI ENCUENTRO EL ID EQUIPO 1 LOS JUGADORES LO GUARDO EN UNA LISTA AUXILIAR
            ObtenerDatoListaJugadores(listaJugadores,cursor,jugador);

            if (  getJugadorIdEquipo(jugador) == equipo1 ){

               if( buscarIdjugador(auxJugadorEquipo1, getIdJugador(jugador) ) == false ){

                    if(listaVacia(auxJugadorEquipo1)){
                        adicionarPrincipio(auxJugadorEquipo1,getDato(listaJugadores,cursor) );
                    }
                    else{
                        adicionarFinal(auxJugadorEquipo1,getDato(listaJugadores,cursor));
                        }
                }
            }

            //SI ENCUENTRO EL ID EQUIPO 2 LOS JUGADORES LO GUARDO EN UNA LISTA AUXILIAR
             if (  getJugadorIdEquipo(jugador) == equipo2 ){

                if( buscarIdjugador(auxJugadorEquipo2, getIdJugador(jugador) ) == false ){

                    if(listaVacia(auxJugadorEquipo2)){
                        adicionarPrincipio(auxJugadorEquipo2,getDato(listaJugadores,cursor));
                        }
                    else{
                        adicionarFinal(auxJugadorEquipo2,getDato(listaJugadores,cursor));
                    }
                }

            }

            cursor = siguiente(listaJugadores,cursor);

        }


        cout <<"-------//-------"<< endl;
        cout << "EQUIPO LOCAL : "<< endl;
        cout <<"-------//-------"<< endl;

        recorrerJugadoresEnEquipo(auxJugadorEquipo1,equipo1);

        cout <<"--------//--------"<< endl;
        cout << "EQUIPO VISITANTE : "<< endl;
        cout <<"--------//--------"<< endl;

        recorrerJugadoresEnEquipo(auxJugadorEquipo2,equipo2);

        cout << " ingrese idEquipo a dar el gol:" << endl;
        cin >> idequipo;


        //-----------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------

        if (idequipo == equipo1){

            cout << " id de jugador : "<< endl;
            cin >> idjugador;

           if( buscarJugador(auxJugadorEquipo1,idequipo,idjugador) == true){

                // corro la lista auxiliar de partido para agregarle el gol
                //aca busco el id del equipo que esta jugando en el partido "lista auxpartido"
                BuscarIdPartidoParaGolesL(auxPartido,id);

                //------------------------------------------------

                MeterGolDeJugadorEnEquipo(auxJugadorEquipo1,idjugador);

           }
           else if( buscarJugador(auxJugadorEquipo2,equipo2,idjugador) == true ){

                // corro la lista auxiliar de partido para agregarle el gol

                BuscarIdPartidoParaGolesL(auxPartido,id);

                // ACA SUMA EL GOL QUE SE HISO EN CONTRA DE GOLES EN LA LISTA AUXILIAR para el jugador
                //ESTO PUEDE SER UNA FUNCION 2---------------------------------------------------

                MeterGolEnContraDeJugadorEnEquipo(auxJugadorEquipo2,idjugador);

            }
            else cout << "\n El jugador no existe en ninguno de los 2 equipos \n" << endl;

        }


        //-----------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------
        //-----------------------------------------------------------------------------------
        // borre un else que tenia de mas

        if (idequipo == equipo2){

            cout << " id de jugador : "<< endl;
            cin >> idjugador;

           if( buscarJugador(auxJugadorEquipo2,idequipo,idjugador) == true){

                // corro la lista auxiliar de partido para agregarle el gol

                BuscarIdPartidoParaGolesV(auxPartido,id);

                MeterGolDeJugadorEnEquipo(auxJugadorEquipo2,idjugador);

           }
           else if( buscarJugador(auxJugadorEquipo1,equipo1,idjugador) == true ){

                // corro la lista auxiliar de partido para agregarle el gol

                //ESTO PUEDE SER UNA FUNCION 1---------------------------------------------------

                BuscarIdPartidoParaGolesV(auxPartido,id);

                // ACA RESTA LA CANTIDAD DE GOLES YA QUE SE LE METIO EN CONTRA EN LA LISTA AUXILIAR para el jugador
                MeterGolEnContraDeJugadorEnEquipo(auxJugadorEquipo1,idjugador);

            }
            else cout << " \nEl jugador no existe en ninguno de los 2 equipos\n" << endl;

        }

            // remplazo los datos que tengo en la listas auxiliares en lista principal



            }
            else{ cout << "\n no esta inicializado el partido \n" << endl;}

         //   recorrerJugadores(listaJugadores);

         //   recorrerPartidos(listaPartidos);


}


void FinDelPartido(Lista &listaPartidos,Lista &listaEquipo,Lista &listaJugadores,Lista &auxPartido,Lista &auxEquipo1,Lista &auxEquipo2,Lista &auxJugadorEquipo1,Lista &auxJugadorEquipo2){

    //---------------------------------------------------------------
    int id;
    if (listaVacia(auxPartido)){
        cout << " no hay partidos iniciados para darle fin de partida "<< endl;
    }
    else{

        recorrerPartidos(auxPartido);

        do{
        cout << "-----------//-----------" << endl;
        cout << " ingrese id del partido " << endl;
        cin >> id;
        }while(BuscarIdExistentePartido(listaPartidos,id) == false);

            if(BuscarIdExistentePartido(auxPartido,id)){

                // EQUIPO LOCAL PUNTAJE Y EQUIPO VISITANTE PUNTAJE
                //----------------------------------------------------------------------------------------------------------------------------
                RepartirPuntaje(auxPartido,auxEquipo1,auxEquipo2,id);
                //----------------------------------------------------------------------------------------------------------------------------
                RemplazarDatosDeAuxiliarEnOriginalEquipo(listaEquipo,auxEquipo1);
                RemplazarDatosDeAuxiliarEnOriginalEquipo(listaEquipo,auxEquipo2);
                remplazardatosdeauxiliarenoriginalJugador(listaJugadores,auxJugadorEquipo1);
                remplazardatosdeauxiliarenoriginalJugador(listaJugadores,auxJugadorEquipo2);
                remplazardatosdeauxiliarenoriginalPartido(listaPartidos,auxPartido);


                recorrerListaEquipo(listaEquipo);
            }
        }
}


/*
Listado de goleadores: Ordenado en forma descendente por cantidad de goles. El reporte se deberá segmentar por cantidad
de goles (por ejemplo, si el máximo de goles es 10, deberá figurar “10 goles” y todos los jugadores con 10 goles, después 9,
y todos los que convirtieron 9 goles, etc).Se deberá poner un subtotal indicando la cantidad de jugadores en cada segmento
y un total final con cantidad de jugadores y cantidad de goles.
*/

/*
Orden de equipos por grupo (con puntos y diferencia de gol).Es decir, Grupo A, equipos del Grupo A, Grupo B, equipos del Grupo B,
etc. Además, se deben informar los goles parciales por grupos y el total de todos los grupos.
*/

void Procesar_reportes(Lista &listaEquipo, Lista &ListaGrupo, Lista &listaJugadores, Lista &listaPartidos){
    int option=99;
    while (option != 0){

        MostrarMenu2();

        cin >> option;
        system ("cls");

        switch(option){
            case 1: reporteGoleadores(listaJugadores);
                    break;

            case 2: OrdenDeEquiposPorGrupo(ListaGrupo,listaEquipo);
                    break;

            case 0: break;

            default:cout<<"Error"<<endl;
                    break;
        }

    }

}


void MostrarMenu2(){
cout<<"Has escojido: Procesar reportes,escoje que deseas modificar"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"1 - Listado de goleadores"<<endl;
        cout<<"2 - Orden de equipos por grupo"<<endl;                             // (con puntos y diferencia de gol)
        cout<<"0 - Salir del menu"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
}


void Fin_del_programa(Lista &listaJugadores ,Lista &listaEquipo, Lista &listaPartidos, Lista &ListaGrupo){

    GuardarJugadores(listaJugadores);
    GuardarEquipos(listaEquipo);
    GuardarPartidos(listaPartidos,"partidos.txt");
    GuardarGrupos(ListaGrupo);

    cout<<"Gracias por usar nuestra aplicacion, creditos a los alumnos:"<<endl;
    cout<<"Perez Quimey"<<endl;
    cout<<"Perez Alan"<<endl;
    cout<<"Ribas Franco"<<endl;
    cout<<"Martinez Carlos"<<endl;
}


//---------------------------------------------

void Modificacion_de_equipo(Lista &listaEquipo){
    int GolesAFavor,GolesEnContra,puntos,id;
    char nombre[40];

    cout << " Estas en Modificacion de Equipo, Ingrese la ID del equipo que desea modificar"<<endl;
    cin >> id;

    if(BuscarIdExistenteEquipo(listaEquipo,id) != true){

        system ("cls");
        cout << " No existe id en la lista equipo"<<endl;
    }
    else{
        fflush(stdin);

        cout << " ingrese nombre: "<<endl;
        cin.getline(nombre,40);
        cout << " ingrese goles a favor: "<<endl;
        cin >> GolesAFavor;
        cout << " ingrese goles en contra: "<<endl;
        cin >> GolesEnContra;
        cout << " ingrese Puntos: "<<endl;
        cin >> puntos;

        ModificacionEquipo(listaEquipo,id,nombre,GolesAFavor,GolesEnContra,puntos);

        system ("cls");
        recorrerListaEquipo(listaEquipo);
    }

}


//---------------------------------------------
//---------------RECORRERLISTAS----------------
//---------------------------------------------
void recorrerJugadores(Lista &listaJugadores){
    Jugador jugador;
    PtrNodoLista cursor = primero(listaJugadores);

    while (cursor != fin()) {

        ObtenerDatoListaJugadores(listaJugadores,cursor,jugador);

        cout <<"Id: " << getIdJugador(jugador)<<endl;
        cout <<"Nombre Jugador : "<< getNombreJugador(jugador)<<endl;
        cout <<"Goles metidos: " << getGolesJugador(jugador)<<endl;
        cout <<"Id Equipo: " << getJugadorIdEquipo(jugador)<<endl;
        cout <<""<<endl;
        cursor = siguiente(listaJugadores, cursor);
    }
    cout << endl;

}


void recorrerListaEquipo(Lista &listaEquipo){
    PtrNodoLista cursor = primero(listaEquipo);
    Equipo equipo;
    while (cursor != fin()) {
        ObtenerDatoListaEquipo(listaEquipo,cursor,equipo);

        cout <<"Id: " << getIdEquipo(equipo)<<endl;
        cout <<"Nombre Equipo : "<< getNombreEquipo(equipo)<<endl;
        cout <<"Goles a favor : "<< getGoles_A_Favor(equipo)<<endl;
        cout <<"Goles en contra : "<< getGoles_En_Contra(equipo)<<endl;
        cout <<"Puntos : "<< getPuntos(equipo)<<endl;
        cout <<""<<endl;
        cursor = siguiente(listaEquipo, cursor);
    }
    cout << endl;
}


void recorrerGrupos(Lista & listaGrupos){

    Grupo grupo;
    PtrNodoLista cursor = primero(listaGrupos);

    while (cursor != fin()) {

        ObtenerDatoListaGrupo(listaGrupos,cursor,grupo);

        cout <<"Id: " << getIdGrupo(grupo)<<endl;
        cout <<"Nombre Equipo : "<< getNombreGrupo(grupo)<<endl;
        cout <<"Equipo 1 : "<< getIdEquipo1(grupo)<<endl;
        cout <<"Equipo 2: "<<  getIdEquipo2(grupo)<<endl;
        cout <<"Equipo 3 : "<< getIdEquipo3(grupo)<<endl;
        cout <<"Equipo 4 : "<< getIdEquipo4(grupo)<<endl;
        cout <<""<<endl;
        cursor = siguiente(listaGrupos, cursor);
    }
    cout << endl;
}


void recorrerPartidos(Lista &listaPartidos){
    Partido partido;
    PtrNodoLista cursor = primero(listaPartidos);
        while (cursor != fin()) {

            ObtenerDatoListaPartido(listaPartidos,cursor,partido);

            cout <<"Id: " << getIdPartido(partido)<<endl;
            cout <<"Equipo L : "<< getIdEquipoLPartido(partido)<<endl;
            cout <<"Equipo V: " << getIdEquipoVPartido(partido)<<endl;
            cout <<"Goles L: "<< getGolesLPartido(partido)<<endl;
            cout <<"Goles v: " << getGolesVPartido(partido)<<endl;
            cout <<""<<endl;

            cursor = siguiente(listaPartidos, cursor);
        }
        cout << endl;

}


void recorrerJugadoresEnEquipo(Lista &listaJugadores,int id){
    Jugador jugador;
    PtrNodoLista cursor = primero(listaJugadores);

        while (cursor != fin()) {
            ObtenerDatoListaJugadores(listaJugadores,cursor,jugador);

            if( ((Jugador*)cursor->ptrDato)->idEquipo == id ){
                cout <<"Id: " << getIdJugador(jugador)<<endl;
                cout <<"Nombre Jugador : "<< getNombreJugador(jugador)<<endl;
                cout <<"Goles metidos: " << getGolesJugador(jugador)<<endl;
                cout <<"Id Equipo: " << getJugadorIdEquipo(jugador)<<endl;
                cout <<""<<endl;
            }

            cursor = siguiente(listaJugadores, cursor);
        }
}















































