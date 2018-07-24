#include <stdio.h>
#include <stdlib.h>
#include "inc/ArrayList.h"
#include "inc/StructEmpleado.h"
#include "inc/DataValidation.h"

int main(){

    ArrayList* empleados = al_newArrayList();
    ArrayList* programadores = al_newArrayList();

    int opcion, salir=0;
    int id = parseIn(empleados,"data.csv");
    do{
        opcion = generic_menu();
        switch(opcion)
        {
        case 1:
            id++;
            generic_alta(empleados,&id);
            break;
        case 2:
            programadores = al_filter(empleados,funcionQueFiltra);
            main_mostrarLista(programadores);
            parseOut(programadores,"out.csv");

            generic_finFuncion();
            break;
        case 3:
            main_mostrarLista(empleados);
            generic_finFuncion();
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
