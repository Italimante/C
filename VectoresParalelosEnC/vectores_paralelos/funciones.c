#include "funciones.h"

void modificarAlumno(char nombre[][50], int legajo[]){


}

void mostrarAlumnos(char nombre[][50], int notaA[], int notaB[], float promedio[], int legajo[], int largo){
    int i;
    for(i=0;i<largo;i++){
        if(legajo[i]!=0){
            printf("\nLegajo: %d \nNombre: %s \nNota uno: %d \nNota dos: %d \nPromedio: %2.f \n", legajo[i],nombre[i],notaA[i],notaB[i],promedio[i]);
        }
    }
}

/*
void cargarAlumno(char nombre[][50], int notaA[], int notaB[], float promedio[], int legajo[], int largo){
    int indice;
    indice = buscarLugar(legajo,SIZE);
    legajo[1]=666;
}*/

int buscarEnLegajo(int legajo[],int arraySize, int indiceDeseado){
    int indice = -1;
    int i;
    for(i=0; i<arraySize; i++){
        if(legajo[i]==indiceDeseado){
            indice = i;
            break;
        }
    }
    return indice;
}

/*
int buscarLugar(int legajo[], int largo){
    int i;
    int indiceRetornado =-1;

    for(i=0; i<largo; i++){
        if(legajo[i]==0){ //encontro un lugar vacio
                indiceRetornado = i;
                break;
            }
    }
    return indiceRetornado;
}
*/

void imprimirMenu(){
    printf("\n-- Ingrese una opcion: \n");
    printf("1- Hacer alta de alumno \n");
    printf("2- Modificar alumno \n");
    printf("3- Dar de baja alumno \n");
    printf("4- Ver lista de alumnos \n");
    printf("5- Salir\n\n");
}

