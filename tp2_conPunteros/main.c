#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ePersona.h"
#define SIZEPERSONA 20

int main()
{
    int continuar = 1;
    int opcion;
    int flag = 0;

    ePersona listaDePersonas[SIZEPERSONA];
    ePersona* punteroPersonas;
    punteroPersonas = listaDePersonas;

    if(!per_incializarEstado(punteroPersonas, SIZEPERSONA)){
        printf("|X| - Error: Puntero NULO, o no hay espacio.\n");
    }else{
        printf("|!| - Exito: Se iniciaron correctamente los estados.\n");
    }

    while(continuar==1){
        mostrarMenu();
        scanf("%d",&opcion);
        fflush( stdin );
        switch(opcion){
            case 1: // Agregar una persona
                system("cls");
                printf("[1] - AGREGANDO UNA PERSONA:\n");
                if(!per_agregarPersona(punteroPersonas, SIZEPERSONA, "No hay espacio suficiente.\n")){
                    printf("|X| - Error inesperado: No se puede cargar una persona\n");
                }
                flag = 1;
                break;
            case 2: //Borrar una persona
                if(flag == 1){
                    system("cls");
                    //per_borrarPersona(listaDePersonas, SIZEPERSONA, "No se encuentra la persona.\n");
                }else{
                    system("cls");
                    printf("|X| %c Error: no hay datos que borrar.\n\n",175);
                }
                break;
            case 3: //Mostrar ordenado por nombre
                if(flag == 1){
                    system("cls");
                    if(!per_ordenarPorNombre(punteroPersonas, SIZEPERSONA)){
                        printf("|X| - Error inesperado: No se puede ordenar las listas");
                    }
                    if(!per_mostrarLista(punteroPersonas, SIZEPERSONA)){
                        printf("|X| - Error inesperado: No se puede mostrar lista");
                    }
                }else{
                    system("cls");
                    printf("|X| %c Error: no hay datos que borrar.\n\n",175);
                }
                break;
            case 4: //Grafico de edades
                 if(flag == 1){
                    per_imprimirGraficoHorizontal(listaDePersonas, SIZEPERSONA);
                }else{
                    system("cls");
                    printf("[Ups!] No hay datos que graficar.\n\n");
                }
                break;
            case 5: // Salir
                system("cls");
                printf("Adios :( \n");
                continuar = 0;
                break;
            case 6: //Harcodear 10 datos
                system("cls");
                if(per_harcodearDatos(punteroPersonas)){
                    printf("|!| - Exito: Se han a%cadido 10 personas correctamente.\n\n",164);
                }else{
                    printf("|X| - Error: No se pudo a%cadir.\n\n",164);
                }
                flag = 1;
                break;
            default:
                system("cls");
                printf("[Ups!] Opcion incorrecta\n\n");
                break;
        }
    }
    return 0;
}
