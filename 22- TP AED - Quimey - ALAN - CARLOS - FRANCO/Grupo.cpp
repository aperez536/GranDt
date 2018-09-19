#include "Grupo.h"
#include "Equipo.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <string.h>
using namespace std;

void crearGrupo(Grupo &grupo){
    grupo.Id='a';
    grupo.Nombre[0]='a';
    grupo.IdEquipo1=1;
    grupo.IdEquipo2=1;
    grupo.IdEquipo3=1;
    grupo.IdEquipo4=1;
}

void SetGrupo(Grupo &grupo,char _id,char _nombre[40],int _IdE1,int _IdE2,int _IdE3, int _IdE4){
    grupo.Id=_id;
    strcpy(grupo.Nombre,_nombre);
    grupo.IdEquipo1=_IdE1;
    grupo.IdEquipo2=_IdE2;
    grupo.IdEquipo3=_IdE3;
    grupo.IdEquipo4=_IdE4;
}

char getIdGrupo(Grupo &grupo){
    return(grupo.Id);
}

//char getNombreGrupo(Grupo &grupo){
//    return(grupo.Nombre);
//}

int getIdEquipo1(Grupo &grupo){
    return(grupo.IdEquipo1);
}
int getIdEquipo2(Grupo &grupo){
    return(grupo.IdEquipo2);
}
int getIdEquipo3(Grupo &grupo){
    return(grupo.IdEquipo3);
}
int getIdEquipo4(Grupo &grupo){
    return(grupo.IdEquipo4);
}

char *getNombreGrupo(Grupo &grupo){
    return grupo.Nombre;
}

//-----------------------------
void cargarGrupos(Lista &listaGrupos){
    FILE *f;
    f = fopen("grupos.txt","r++");
    crearLista(listaGrupos,listaGrupos.compara);
    while(!feof(f)){
        Grupo *gp = new Grupo;
        fscanf(f,"%[^;];%[^;];%d;%d;%d;%d\n",&gp->Id,&gp->Nombre,&gp->IdEquipo1,&gp->IdEquipo2,&gp->IdEquipo3,&gp->IdEquipo4);
        if(listaVacia(listaGrupos)){
            adicionarPrincipio(listaGrupos,gp);

        }
        else{
            adicionarFinal(listaGrupos,gp);
        }

    }
    fclose(f);
}




// el if me repite las id...  utilizo el for para sacar.....


bool BuscarPosDeEquipoEnGrupo(Lista &listapartido,int equipol,int equipov){

    int i=0,g=0;
    int posi,posg;
    char a;
    char b;
    bool encontrado = false;
        PtrNodoLista cursor = primero(listapartido);
        while (cursor != fin()) {
             if ( ((Grupo*)cursor->ptrDato)->IdEquipo1== equipol ||
                ((Grupo*)cursor->ptrDato)->IdEquipo2== equipol ||
                ((Grupo*)cursor->ptrDato)->IdEquipo3== equipol ||
                ((Grupo*)cursor->ptrDato)->IdEquipo4== equipol){

                a = ((Grupo*)cursor->ptrDato)->Id;


             }
              if ( ((Grupo*)cursor->ptrDato)->IdEquipo1== equipov ||
                ((Grupo*)cursor->ptrDato)->IdEquipo2== equipov ||
                ((Grupo*)cursor->ptrDato)->IdEquipo3== equipov ||
                ((Grupo*)cursor->ptrDato)->IdEquipo4== equipov )
                {
                b = ((Grupo*)cursor->ptrDato)->Id;


             }



            cursor = siguiente(listapartido, cursor);
        }

        if ( a == b){
            encontrado = true;
          //  cout << " COMENZO EL PARTIDO" << endl;
        }
        else {
       //     cout << " NO SE PUEDE COMENZAR DEBIDO QUE NO ESTAN EN EL MISMO GRUPO" << endl;
        }
        return encontrado;
}


void ObtenerDatoListaGrupo(Lista &listaGrupos,PtrNodoLista cursor,Grupo &grupo){

    grupo.Id= ((Grupo*)cursor->ptrDato)->Id;
    grupo.IdEquipo1= ((Grupo*)cursor->ptrDato)->IdEquipo1;
    grupo.IdEquipo2= ((Grupo*)cursor->ptrDato)->IdEquipo2;
    grupo.IdEquipo3= ((Grupo*)cursor->ptrDato)->IdEquipo3;
    grupo.IdEquipo4= ((Grupo*)cursor->ptrDato)->IdEquipo4;
    strcpy(grupo.Nombre,((Grupo*)cursor->ptrDato)->Nombre );

    //Con esto lleno la estructura con todos los campos de la lista,
    //de tal forma de utilizarla en el main PARA que no sepan como esta armado
}



void GuardarGrupos (Lista &ListaGrupo){

    int IDequ1, IDequ2, IDequ3, IDequ4;
    char IDgr;
    char nombregr [40];

    FILE *faux;
    faux = fopen("gruposaux.txt","w++");

    PtrNodoLista cursor = primero(ListaGrupo);

    while (cursor != fin()){

            IDequ1 = ((Grupo*)cursor->ptrDato)->IdEquipo1;
            IDequ2 = ((Grupo*)cursor->ptrDato)->IdEquipo2;
            IDequ3 = ((Grupo*)cursor->ptrDato)->IdEquipo3;
            IDequ4 = ((Grupo*)cursor->ptrDato)->IdEquipo4;
            strcpy(nombregr,((Grupo*)cursor->ptrDato)->Nombre);
            IDgr = ((Grupo*)cursor->ptrDato)->Id;

            fprintf(faux,"%c;%s;%d;%d;%d;%d\n",IDgr,nombregr,IDequ1,IDequ2,IDequ3,IDequ4);

            cursor = siguiente(ListaGrupo, cursor);
    }
    fclose(faux);
    remove("grupos.txt");
    rename("gruposaux.txt","grupos.txt");


}
