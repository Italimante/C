#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "localidad.h"
#define SIZE 3

/*
    Para la clase de la semana que viene terminar el ABM

*/

int main()
{
    int i;
    /*
    //creamos la variable llamada: miestructura
    estructuraEjemplo miestructura;
    printf("%s",estructuraEjemplo.nombre);
    */
    eLocalidad nuevaLocalidad;

    nuevaLocalidad.estado = 1;
    nuevaLocalidad.id = 555;
    strcpy(nuevaLocalidad.nombreLocalidad,"Avellaneda");

    //printf("%s",nuevaLocalidad.nombreLocalidad);

    //loc_mostrarUno(nuevaLocalidad);

    //creo un array con un listado de la estructura
    eLocalidad listadoLocalidades[SIZE];

    for(i=0;i<SIZE;i++){
        listadoLocalidades[i].id = i*3;
        listadoLocalidades[i].estado = 1;
        strcpy(listadoLocalidades[i].nombreLocalidad,"Sarandi\n");
    }

    loc_mostrarListado(listadoLocalidades,SIZE);



    return 0;
}
    //mostrarDatos(listaDeUsuarios,listaDeSeries,15,5);
    //mostrarListaSeries(listaDeSeries, 5);

/*
void mostrarListaSeries(eSerie series[], int cantS){
    int i;
        printf("ID\t NOMBRE\t GENERO\n---------------------------\n");
    for(i=0;i<cantS;i++){
        printf("%d\t ",series[i].idSerie);
        printf("%s\t  ",series[i].nombre);
        printf("%s\n",series[i].genero);
    }
}
*/

/*
//ESTO ES DE EJERCICIO, EJEMPLO ETC
void mostrarDatos(eUsuario usuarios[] , eSerie series[], int cantU, int cantS){
    int i;
    printf("ID\t NOMBRE\t GENERO\n---------------------------\n");
    for(i=0;i<cantS;i++){
        printf("%d\t ",series[i].idSerie);
        printf("%s\t  ",series[i].nombre);
        printf("%s\n",series[i].genero);
    }
    printf("\nID\tNOMBRE\n---------------------------\n");
    for(i=0;i<cantU;i++){
        printf("%d\t",usuarios[i].idUsuario);
        printf("%s\n",usuarios[i].nombre);
    }
}
*/

