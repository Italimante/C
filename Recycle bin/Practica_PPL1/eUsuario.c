#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eUsuario.h"
#define LIBRE 0

/*
    char nombre[30];
    char password[30];
    int id;
    int estado;

*/

void eUsua_harcodearDatos(eUsuario listado[]){
    char nombre[][50]={"Fantino","Barreda","Puch","Galarza","Grassi","Memo","Mangieri","Cordera","Jaitt","Barattini"};
    int id[10]={43,23,58,21,44,32,11,54,42,28};
    char password[][10]={"A5xa2","ques123","cieloVerde","569juj","aEf65","solluna01","philips23","56sd87","zkj22","prupru2"};

    int i;
    for(i=0;i<10;i++){
        strcpy(listado[i].nombre, nombre[i]);
        strcpy(listado[i].password, password[i]);
        listado[i].id=id[i];
        listado[i].estado=1;
    }
}

int eUsua_init(eUsuario listado[],int limite){
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL){
        retorno = 0;
        for(i=0; i<limite; i++){
            listado[i].estado= LIBRE;
            listado[i].id= 0;
        }
    }
    return retorno;
}
