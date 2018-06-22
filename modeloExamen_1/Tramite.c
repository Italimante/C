#include <stdio.h>
#include <stdlib.h>
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
