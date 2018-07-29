#include <stdio.h>
#include <stdlib.h>

void cargarArray(int *, int);
void mostrarArray(int *, int);

int main()
{
    /*
        Una variable que guarda la direccion de memoria de otra variable
        - Eficencia, adminitrar los recursos
        - Movemos menos datos en memoria
        -
        -----
        Ejemplo: vector[3]; este vector siempre va tener tres valores, en cambio
        con punteros podemos hacer que sea dinamico. Se puede hacer que crezca
        o reduzca de tamanio.
        Hasta que no haya mas memoria.
        -----
        - vector[3]; ya estaria en la pila, ocupando 12bit
        - En cambio al mover los punteros, son 4bit, y cada valor del vector puede pesar exageradamente mucho
        -----
        - El vector es una direccion de memoria, guarda una direccion de memoria.
        - printf("%d",vector); //Muestra una direccion de memoria
        - printf("%d",&vector[0]); //Muestra la misma direccion de memoria
        - printf("%d",&vector); //Muestra tambien la misma direccion de memoria
        ----
        Esto lo mande en una funcion:
        //Pedirle a un usuario que ingrese datos atraves del array por puntero:
        for(i=0; i<3; i++){
            printf("Ingresar numero:");
            scanf("%d",puntero+i);//hay que obtener una direccion de memoria atraves de un puntero para pasarle aca
        }
        //Mostrar lo del vector:
        for(i=0; i<3; i++){
            printf("\n%d\n", *(puntero+i)); //Si pongo *puntero+i va tomar el primer valor y sumarle i (+1)
        }

    */

    int vector[3];
    int* puntero; //va ser el puntero que apunte al vector
    int i;
    //Como asociarlo: No es necesario el &
    puntero = vector;

    cargarArray(vector,3);
    mostrarArray(vector,3);



    return 0;
}

void cargarArray(int *array, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("Ingresar numero:");
        scanf("%d",array+i);
    }
}

void mostrarArray(int *array, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d\n",*(array+i));
    }
}
