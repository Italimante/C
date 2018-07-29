#include <stdio.h>
#include <stdlib.h>
#include "inc/ArrayList.h"
#include "inc/StructEmpleado.h"
#include "inc/DataValidation.h"

int main(){

    ArrayList* letras = al_newArrayList();
    //ArrayList* programadores = al_newArrayList();

    int opcion, salir=0;
    int id = parseIn(letras,"datos_2.csv");
    do{
        opcion = generic_menu();
        switch(opcion)
        {
        case 1:
            main_mostrarLista(letras);
            generic_finFuncion();
            /*
            id++;
            generic_alta(letras,&id);
            */
            break;
        case 2: //Completar - 1 y 0
            system("cls");
            completarLista(letras);
            //lista_completar(letras,"datos_2.csv");
            main_mostrarLista(letras);
            break;
        case 3:
            id++;
            generic_alta(letras,&id);
            break;
        case 0:
            printf("Adios! :( \n");
            salir = 1;
            break;
        default:
            printf("\n|X| - Opcion invalida. Intente otra vez.\n");
            system("pause");
            system("cls");
            break;
        }
    }while(salir==0);

    return 0;
}

/*
    Escribir una funcion para ver si se trata de una vocal o una consonante
*/
