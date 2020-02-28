#include <stdio.h>
#include <stdlib.h>
/*
    PUNTERO A FUNCION
    - La coma divide los parametros.
    - PunteroFuncion es una variable que guarda la direccion de memoria de la funcion
    void funciondelegada(void(*punteroFuncion)(char* eldato),char* nombre);
    - A la funcio nle pasamos la funcion con la firma y el parametro con la firma (??????????)
    - El nombre en vez de psarselo directo a bienvenida se lo pasa a delegada y le llega igual
*/

void funciondelegada(void(*punteroFuncion)(char*eldato),char*nombre);
void funcionBienvenida(char * nombre);
void funcionDespedida(char * nombre);

int main(){
    funciondelegada(funcionBienvenida,"fulana");
    printf("\n------------------------------\n");
    funciondelegada(funcionDespedida,"mengana");
    return 0;
}

void funcionBienvenida(char * nombre){
    printf("Bienvenida %s, a la empresa.\n",nombre);
}
void funcionDespedida(char * nombre){
    printf("%s estas despedida\n",nombre);
}
void funciondelegada(void(*punteroFuncion)(char*eldato),char*nombre){
    punteroFuncion(nombre);
}
