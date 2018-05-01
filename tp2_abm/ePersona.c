#ifndef EPERSONA_C_INCLUDED
#define EPERSONA_C_INCLUDED
#include "ePersona.h"
#include <stdio.h>

void mostrarMenu(){
    printf("1- Agregar una persona\n");
    printf("2- Borrar una persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");
    printf("6- Harcodear datos\n");
}

void per_borrarPersona(ePersona personas[], int cantP, char mensajeError[50]){
    int aux;
    char nombre[50];

    per_mostrarLista(personas,cantP);
    printf("Ingrese el nombre a borrar\n");
    gets(nombre);
    fflush(stdin);
    aux = per_buscarNombre(personas,cantP,nombre);
    if(aux==-1){
        printf("%s",mensajeError);
    }else{
        printf("%s fue eliminado\n",nombre);
        personas[aux].estado=0;
    }
}

//busca el nombre, si lo encuentra devuelve el indice donde esta, de lo contrario -1
int per_buscarNombre(ePersona personas[],int cantP,char nombre[50]){
    int i;
    int retorno = -1;

    strlwr(nombre);
    if(nombre[0]>=97 & nombre[0]<=122){ //cambia a mayusculas la primer letra del nombre
        nombre[0]-=32;
    }

    for(i=0;i<cantP;i++){
        if(strcmp(nombre,personas[i].nombre)==0 & personas[i].estado==1){
            retorno = i;
            break;
        }
    }
    return retorno;
}

void per_agregarPersona(ePersona personas[], int cantP, char mensajeError[50]){
    int posicion;
    posicion = per_buscarEntero(personas,cantP,0);
    if(posicion != -1){
        per_mostrarLista(personas,cantP);
        per_pedirDato(personas,cantP,posicion);
    }else{
        printf("%s\n",mensajeError);
    }
}

void per_pedirDato(ePersona personas[],int cantP,int posicion){
    printf("Ingrese el nombre: \n");
    gets(personas[posicion].nombre);
    fflush(stdin);
    printf("Ingrese la edad: \n");
    scanf("%d",&personas[posicion].edad);
    printf("Ingrese el DNI: \n");
    scanf("%d",&personas[posicion].dni);
    personas[posicion].estado=1;
}

// busca un entero en estado, si lo encuentra devuleve el indice
int per_buscarEntero(ePersona personas[], int cantP, int lugar){
    int i;
    int indice = -1;
    for(i=0;i<cantP;i++){
        if(personas[i].estado == lugar){
            indice = i;
            break;
        }
    }
    return indice;
}

void per_incializarEstado(ePersona personas[], int cantP){
    int i;
    for(i=0;i<cantP;i++){
        personas[i].estado=0;
    }
}

void per_ordenarPorNombre(ePersona personas[], int cantP){
    int i;
    int j;
    char auxString[100];
    int auxInt;
    long int auxLongInt;

    for(i=0;i<cantP;i++){
        for(j=i+1;j<cantP;j++){
            if(strcmp(personas[i].nombre,personas[j].nombre)>0 & personas[i].estado==1 & personas[j].estado ==1){
                strcpy(auxString,personas[i].nombre);
                strcpy(personas[i].nombre,personas[j].nombre);
                strcpy(personas[j].nombre,auxString);

                auxInt = personas[i].edad;
                personas[i].edad = personas[j].edad;
                personas[j].edad = auxInt;

                auxLongInt = personas[i].dni;
                personas[i].dni = personas[j].dni;
                personas[j].dni = auxLongInt;
            }
        }
    }

}

void per_mostrarUno(ePersona personas){
    printf("%s\t %d\t %d\t\n", personas.nombre, personas.edad, personas.dni);
}

void per_mostrarLista(ePersona personas[], int cantP){
    int i;
    for(i=0;i<cantP;i++){
        if(personas[i].estado==1){
            per_mostrarUno(personas[i]);
        }
    }
}

void per_harcodearDatos(ePersona personas[]){
    char nombre[][50]={"Fantino","Barreda","Puch","Galarza","Grassi","Memo","Mangieri","Cordera","Jaitt","Barattini"};
    int edad[10]={43,23,58,21,44,32,11,54,42,28};
    long int dni[10]={20144188,26587458,66541259,74584126,21458756,22014568,445520147,60321548,42036548,30140028};

    int i;
    for(i=0;i<10;i++){
        strcpy(personas[i].nombre, nombre[i]);
        personas[i].dni=dni[i];
        personas[i].edad=edad[i];
        personas[i].estado=1;
    }
}



#endif // EPERSONA_C_INCLUDED
