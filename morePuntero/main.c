#include <stdio.h>
#include <stdlib.h>
int cargarArray(int *, int);
int mostrarArray(int *, int);

int main()
{
    /*

    */

    int vector[3];
    int* puntero;
    puntero = vector;
    int *P = NULL;

    if(cargarArray(vector,3)){
        printf("Carga exitosa\n");
    }else{
        printf("Error al cargar\n");
    }

    return 0;
}

int cargarArray(int *array, int tam){
    int i;
    int retorno = 0;
    if(array!=NULL){
        retorno = 1;
        for(i=0; i<tam; i++){
            printf("Ingresar numero:");
            scanf("%d",array+i);
        }
    }
    return retorno;
}

int mostrarArray(int *array, int tam){
    int i;
    int retorno = 0;
    if(array!=NULL){
    retorno = 1;
    for(i=0; i<tam; i++){
        printf("%d\n",*(array+i));
    }
    }
    return retorno;
}
