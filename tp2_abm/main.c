#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ePersona.h"
#define SIZEPERSONA 20

int main()
{
    ePersona listaDePersonas[SIZEPERSONA];
    mostrarMenu();
    per_incializarEstado(listaDePersonas, SIZEPERSONA);
    per_harcodearDatos(listaDePersonas);
    per_ordenarPorNombre(listaDePersonas, SIZEPERSONA);
    //per_mostrarLista(listaDePersonas, SIZEPERSONA);
    printf("--------------------------------------\n");
    //per_agregarPersona(listaDePersonas, SIZEPERSONA, "No hay espacio suficiente");
    printf("--------------------------------------\n");
    //per_mostrarLista(listaDePersonas, SIZEPERSONA);
    printf("--------------------------------------\n");
    per_borrarPersona(listaDePersonas, SIZEPERSONA, "No se encuentra la persona\n");
    per_mostrarLista(listaDePersonas, SIZEPERSONA);

    return 0;
}
