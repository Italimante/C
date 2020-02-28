#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define SIZE 5

/*
    Objetivo principal:
        Ordenamiento de vectores paralelos, sin importar si los datos son harcodeados,
        - 1: Hacer el alta
        - 2: Hacer la baja (poner todo en cero)
        - 3: Modificar todos menos el legajo

        --------------------------------------------------------------------------------

        al float promedio no se puede jarcodear
        y definir una funcion sacar promedio que devuelva un float y recibe dos enteros
*/

int main()
{
    // Harcodeo un espacio vacio
    char nombre[SIZE][50]={"Juan","Carlos","Gabriel","Falso vacio","Maria"};
    int notaUno[SIZE]={4,10,2,0,2};
    int notaDos[SIZE]={4,8,7,0,8,3};
    float promedios[SIZE]={4,9.5,4.5,0,3.50};
    int legajo[SIZE]={111,222,333,444,555};
    int continuar = 1;
    int opcion;
    int auxInt;

    do{
        imprimirMenu();
        scanf("%d",&opcion);

        switch(opcion){
        case 1://Hacer alta
            auxInt = buscarEnLegajo(legajo,SIZE,0); //Le paso el 0, porque si hay un legajo en 0 es porque estaria vacio
            if(auxInt!=-1){
                printf("Encontro lugar\n");
                //Funcion que cargue alumno manualmente
            }else{
                printf("No hay espacio suficiente\n");
            }
            break;
        case 2://Modificar alumno // esto deberia ir dentro de la funcion modificar:
            printf("Ingrese legajo a buscar: \n");
            scanf("%d",&auxInt);
            auxInt = buscarEnLegajo(legajo,SIZE,auxInt);
            if(auxInt==-1){
                printf("El legajo no existe \n", auxInt);
            }else{
                printf("- Alumno encontrado: \nNombre: %s | Legajo: %d\n", nombre[auxInt], legajo[auxInt]);
            }
            break;
        case 3:
            printf("Caso 3");
            break;
        case 4:
            system("cls");
            mostrarAlumnos(nombre,notaUno,notaDos,promedios,legajo,SIZE);
            break;
        case 5:
            continuar=0;
        }
    }while(continuar==1);

    //cargarAlumno(nombre,notaUno,notaDos,promedios,legajo,SIZE);

    return 0;
}
