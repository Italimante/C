#include <stdio.h>
#include <stdlib.h>

void intercambiar(int numUno, int numDos);
void intercambiarPunteros(int *numUno, int *numDos);
void ponerEnCero(int *num);
int capitalizeString(char *cadena);

/*
    Hay que validar siempre al recibir punteros
*/

int main()
{
   /*
    int edadUno;
    int edadDos;

    edadUno=22;
    edadDos=99;

    ponerEnCero(&edadDos);

    //intercambiar(edadUno, edadDos);
    intercambiarPunteros(&edadUno, &edadDos);
        printf("\n Edad 1: %d",edadUno);
        printf("\n Edad 2: %d",edadDos);



    char nombre[10]="aNdReS";


    printf("%s\n",nombre);
    capitalizeString(&nombre);
    printf("%s\n",nombre);
*/
    //int i;
    //char nombre[10]="AndRes";


    /*

    */
    //comprobarString(&nombre, 3, "\nNombre muy largo, re-ingrese:\n");

    /*

    */
    /*
    if(stringSoloLetras(nombre)){
        printf("ERROR: solo letras porfavor\n");
    }else{
        printf("Todo joya\n");
    }*/


    //printf("%s\n",nombre);


    //char nombre[10];

    //pedirString(&nombre, "Ingrese nombre porfavor\n",3,"Solo letras, max 3 caracteres\n");

    //printf("%s",nombre);

    char aux[]="3.2";

    if(atof(aux)){
        printf("Se pudo convertir\n");
    }else{
        printf("No\n");
    }



    return 0;
}

int pedirString(char *cadena, char mensaje[], int largo, char mensajeError[]){
    int i;
    int retorno = 0;
    int loop = 1;
    if(cadena != NULL){
        while(loop == 1){
            printf("%s",mensaje);
            gets(cadena);
            fflush(stdin);
            if(strlen(mensaje)>largo && stringSoloLetras(cadena)==1){
                printf("%s",mensajeError);
                gets(cadena);
                fflush(stdin);
            }else{
                loop = 0;
                retorno = 1;
            }
        }
    }else{
        printf("\n Error: Puntero cadena NULL\n");
        retorno = -1;
    }
    return retorno;
}

int stringSoloLetras(char cadena[]){
    int i;
    int retorno = 0;
    for(i=0;i<strlen(cadena);i++){
        if( !(cadena[i]>96 && cadena[i]<123) & !(cadena[i]>64 && cadena[i]<91) ){
            //printf("\n|X| - Error %c, no es una letra, re ingrese solamente letras\n",cadena[i]);
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int capitalizeString(char *cadena){
    int retorno = -1;
    if(cadena != NULL){
        retorno = 0;
        strlwr(cadena);
        if(cadena[0]>=97 & cadena[0]<=122){
            retorno = 1;
            cadena[0]-=32;
        }
    }
    return retorno;
}

void intercambiar(int numUno, int numDos){
    int aux;
    aux = numUno;
    numUno = numDos;
    numDos = aux;
}

void intercambiarPunteros(int *numUno, int *numDos){
    int aux;
    aux = *numUno;
    *numUno = *numDos;
    *numDos = aux;
}

void ponerEnCero(int *num){
    *num = 0;
}


