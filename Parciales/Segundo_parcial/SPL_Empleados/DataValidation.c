#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "inc/DataValidation.h"
//#include "inc/ArrayList.h"

/*
    GET STRING
*/
void string_get(char mensaje[],char input[]){
    fflush(stdin);
    printf("%s",mensaje);
    gets(input);
}

int string_getNumerico(char mensaje[],char input[]){
    char aux[256];
    string_get(mensaje,aux);
    if(string_esNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int string_getLetras(char mensaje[],char input[]){
    char aux[256];
    string_get(mensaje,aux);
    if(string_esSoloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/*
    VALIDAR STRING
*/
int string_isNull (char value){
    if(value=='\0' || value ==' '){
        return 1;
    }
    return 0;
}

int string_esNumerico(char array[]){
    int i=0;
    if(string_isNull(array[0])){
        return 0;
    }else{
        while(array[i] != '\0'){
            if((!isdigit(array[i]))){
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int string_esSoloLetras(char array[]){
    int i=0;
    if(string_isNull(array[0])){
        return 0;
    }else{
        while(array[i] != '\0'){
            if( (!isspace(array[i])) && (!isalpha(array[i])) ){
                return 0;
            }
            i++;
        }
    }
    return 1;
}

int string_validaRango(char str[], int min, int max){
    int aux;
    aux = atoi(str);
    if(aux>=min&&aux<=max)
        return 1;
    else{
        printf("|X| - Error, el numero ingresado esta fuera de rango. MIN: %d MAX: %d",min,max);
        return 0;
    }
}

/*
    ENTEROS
*/
int entero_get(char mensaje[]){
    char auxDato[20];
    int dato;
    printf("\n|#| - Ingrese %s:",mensaje);
    while(!string_getNumerico(" ",auxDato)){
        printf("|X| - Error, *%s* solo puede estar compuesto por numeros. Reingrese %s:",mensaje,mensaje);
    }
    dato = atoi(auxDato);
    return dato;
}

int entero_validaRango(int dato, char mensaje[], int min, int max){
    if(dato >= min && dato <= max){
        return 1;
    }else{
        printf("|X| Error: El item *%s* debe estar entre %d y %d.\n",mensaje,min,max);
        return 0;
    }
}
