#include "Serie.h"
#include <string.h>
/*
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;

*/

void serie_mostrarUno(eSerie aux){
        printf("%s\t\t %d\t %d\t %s\n",aux.nombre,aux.idSerie, aux.cantidadTemporadas, aux.genero);
}

void serie_mostrarListado(eSerie aux[],int cantSeries){
    int i;
    printf("NOMBRE\t\t\t ID\t TEMPS\t GENERO\n--------------------------------------------------\n");
    for(i=0;i<cantSeries;i++){
        if(aux[i].estado==1){
            serie_mostrarUno(aux[i]);
        }
    }
}

void inicializarSeriesEstado(eSerie series[], int cant){
    int i;
    for(i=0; i<cant; i++){
        series[i].estado = 0;
    }
}

void inicializarSeriesHardCode(eSerie series[]){
    int id[5] = {100,101,102,103,104};
    char nombre[][50]={"Los Simuladores","Silicon Valley","Game of Trhones","Breaking Bad","Bojack Horseman"};
    char genero[][50]={"Satira","Comedia","Suspenso","Policial","Drama"};
    int cantidad[5] = {10,9,7,5,2};
    int i;
    for(i=0; i<5; i++){
        series[i].idSerie=id[i];
        series[i].cantidadTemporadas=cantidad[i];
        series[i].estado = 1;
        strcpy(series[i].nombre, nombre[i]);
        strcpy(series[i].genero, genero[i]);
    }
}
