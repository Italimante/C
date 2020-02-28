#include <stdio.h>
#include <stdlib.h>

/*Determina si un caracter esta o no esta dentro del array, retorna
-1 si no lo encuentra o el indicedel valor encontrado */

int buscarChar(char array[], int cantidad, char datoabuscar);

int main(){
        int cantidad;
        int indexLetra;
        int vector[5]={5,2,9,6,5};
        char letras[5]={'f','g','i','m','q'};

        indexLetra = buscarChar(letras, 5, 'f');
        if(indexLetra==-1){
            printf("No se encuentra el caracter \n");
        }else{
            printf("El caracter se encuentra en el indice: %d \n", indexLetra);
        }
    return 0;
}

int buscarChar(char array[], int cantidad, char datoabuscar){
    int index = -1;
    int i;
    for(i=0; i<cantidad; i++){
        if(array[i]==datoabuscar){
            index = i; /* Cuando lo encuentra, guarda el indice en index y lo devuelve*/
            break;
        }
    }
    return index;
}
