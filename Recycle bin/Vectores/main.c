#include <stdio.h>
#include <stdlib.h>
void mostrar(int *puntero, int cantidad);

int main()
{
    int numeros[3];
    int *puntero;
    int auxiliar=333;
    puntero = numeros;

    numeros[0]=9;
    numeros[1]=99;
    numeros[2]=999;

    //Para mostrar los valores
    printf("Puntero: \n %d\n",*(puntero));
    printf("Puntero: \n %d\n",*(puntero+1));
    printf("Puntero: \n %d\n",*(puntero+2));
    printf("Puntero: \n %d\n",*(puntero+3));
    printf("Numeros:\n %d\n",numeros);

    /*
    //No importa, sigue dando direcciones de memoria
    //Mostrar las direcciones - - - - - -
    printf("Puntero: \n %d\n",puntero);
    printf("Puntero: \n %d\n",puntero+1);
    printf("Puntero: \n %d\n",puntero+2);
    printf("Puntero: \n %d\n",puntero+3);
    printf("Numeros:\n %d\n",numeros);
    */

    mostrar(numeros, 3);

    return 0;
}
void mostrar(int *puntero, int cantidad){
    int i;
    for(i=0;i<cantidad;i++){
        printf("\nNumero:%d",*(puntero+i));
        printf("\nAsterisco atroden:%d",*puntero+i);
    }
}
