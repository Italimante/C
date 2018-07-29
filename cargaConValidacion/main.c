#include <stdio.h>
#include <stdlib.h>

int cargarArray(int *, int);
void mostrarArray(int *, int);

int main()
{
    /*
        Inicializar un puntero:
        int* P; //Apuntaria a cualquier lado y haria macana, entonces hay que pedirle al sistema memoria
        - Si el sistema no tiene nada da NULL
    */

    int vector[3];
    int* puntero;
    puntero = vector;
    int *P = NULL;

    // - - - -- - - P o vector, si le pasa P va tirar que es nulo que se rompio todo
    // No hace falta el == 1, cualquier valor distinto de 0 da verdadero
    if(!cargarArray(vector,3)){
        printf("Error al cargar\n");
    }else{
        printf("Exito al cargar\n");
    }
    //mostrarArray(vector,3);

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

void mostrarArray(int *array, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n",*(array+i));
    }
}
