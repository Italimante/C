#ifndef LOCALIDAD_C_INCLUDED
#define LOCALIDAD_C_INCLUDED
#include "localidad.h"
//el archivo este .c deberia tener el mismo nombre que la estructura: eLocalidad.c

void loc_mostrarUno(eLocalidad aux){
    printf("\nEstado: %d ID: %d Nombre: %s",aux.estado, aux.id, aux.nombreLocalidad);
}

void loc_mostrarListado(eLocalidad listados[],int cantE){
    int i;
    for(i=0;i<cantE;i++){
        loc_mostrarUno(listados[i]);
    }
}
#endif // LOCALIDAD_C_INCLUDED
