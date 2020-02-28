#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tramite.h"

//Un constructor
eTramite * new_Tramite(){
    eTramite * aux;
    aux = (eTramite*) malloc(sizeof(eTramite));
    return aux;
}

//setes y geters
int setId( eTramite* this, int id){
    int seteo = -1;
    if(this!=NULL){
        this->idTramite = id;
        seteo = 0;
    }
    return seteo;
}

int getId( eTramite* this ){
    int id=-1;
    if(this!=NULL){
        id = this->idTramite;
    }
    return id;
}

int setDni( eTramite* this, char* dni ){
    int seteo = -1;
    if(this!=NULL && dni!=NULL){
        strcpy( this->dni , dni );
        seteo = 0;
    }
    return seteo;
}

//Aca devuelvo la direccion de memoria y en el anterior el valor
//(Aca donde esta la direccion de memoria del dni)
char* getDni( eTramite* this ){
    char* dni = NULL;
    if(this!=NULL){
        dni = this->dni;
    }
    return dni;
}

int mostrarTramite(eTramite* this){
    int mostro = -1;
    if(this!=NULL){
        printf("%d - - - %s\n", getId(this), getDni(this));
    }
    return mostro;
}

int compararPorDni(void * tramiteA, void * tramiteB){
    eTramite* tramite1;
    eTramite* tramite2;

    //Lo tengo que castear a eTramite, porque es un puntero a VOID
    tramite1 = (eTramite*) tramite1;
    tramite2 = (eTramite*) tramite2;

    return strcmp(tramite1->dni, tramite2->dni);
}

int mostrarListaTramites(ArrayList* listado){
    int listo = -1;
    int i;
    int len;
    eTramite * tramiteActual;

    if(listado!=NULL){
            //mientras sea menor al len
            // el len afuera
        for(i=0;i<listado->len(listado);i++){
            tramiteActual = (eTramite*) listado->get(listado, i);
            mostrarTramite(tramiteActual);
        }
        listo = 0;
    }

    return listo;
}

int cargarTramite(ArrayList* listado, int id, char* dni){
    int cargo = -1;
    eTramite* tramiteActual;
    if(listado != NULL && id>0 && dni!=NULL){
        tramiteActual = new_Tramite();
        setId( tramiteActual,  id);
        setDni(tramiteActual, dni);
        listado->add(listado,tramiteActual);
        cargo = 0;
    }
    return cargo;
}

int atenderTramite( ArrayList* listaPendientes, ArrayList* listaAtendidos ){
    int atendio = -1;
    eTramite * tramiteActual;

    if(listaPendientes!=NULL && listaAtendidos!=NULL){

        tramiteActual = (eTramite*) listaAtendidos->pop(listaPendientes, 0);
        listaAtendidos->add(listaAtendidos,tramiteActual);
        mostrarTramite(tramiteActual);


        atendio = 0;
    }


    return atendio;
}
