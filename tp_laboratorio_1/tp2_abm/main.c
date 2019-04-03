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
    per_incializarEstado(listaDePersonas, SIZEPERSONA);
    while(continuar==1){
        mostrarMenu();

        scanf("%d",&opcion);
        fflush( stdin );
        switch(opcion){
            case 1: // Agregar una persona
                //system("cls");
                printf("[1] - AGREGANDO UNA PERSONA:\n");
                per_agregarPersona(listaDePersonas, SIZEPERSONA, "No hay espacio suficiente.\n");
                flag = 1;
                break;
            case 2: //Borrar una persona
                if(flag == 1){
                    //system("cls");
                    per_borrarPersona(listaDePersonas, SIZEPERSONA, "No se encuentra la persona.\n");
                }else{
                    //system("cls");
                    printf("%c [Ups!] No hay datos que borrar.\n\n",175);
                }
                break;
            case 3: //Mostrar ordenado por nombre
                if(flag == 1){
                    //system("cls");
                    per_ordenarPorNombre(listaDePersonas, SIZEPERSONA);
                    per_mostrarLista(listaDePersonas, SIZEPERSONA);
                }else{
                    //system("cls");
                    printf("[Ups!] No hay datos que mostrar.\n\n");
                }
                break;
            case 4: //Grafico de edades
                 if(flag == 1){
                    per_imprimirGraficoHorizontal(listaDePersonas, SIZEPERSONA);
                }else{
                    //system("cls");
                    printf("[Ups!] No hay datos que graficar.\n\n");
                }
                break;
            case 5: // Salir
                //system("cls");
                printf("Adios :( \n");
                continuar = 0;
                break;
            case 6: //Harcodear 10 datos
                //system("cls");
                printf("Se han a%cadido 10 personas correctamente.\n\n",164);
                per_harcodearDatos(listaDePersonas);
                flag = 1;
                break;
            default:
                //system("cls");
                printf("[Ups!] Opcion incorrecta\n\n");
                break;
        }
    }
    return 0;
}
