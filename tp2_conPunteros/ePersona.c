#ifndef EPERSONA_C_INCLUDED
#define EPERSONA_C_INCLUDED
#include "ePersona.h"
#include <stdio.h>
#define OCUPADO 1

void mostrarMenu(){
    printf("\n[N] - ELIJA UNA OPCION:\n");
    printf("_________________________\n\n");
    printf("[1] - Agregar una persona\n");
    printf("[2] - Borrar una persona\n");
    printf("[3] - Imprimir lista ordenada por nombre\n");
    printf("[4] - Imprimir gr%cfico de edades\n",160);
    printf("[5] - Salir\n");
    printf("[6] - Harcodear datos\n\n");
}

void per_imprimirGraficoHorizontal(ePersona personas[], int cantP){
    system("cls");
    per_mostrarLista(personas,cantP);
    int i;

    printf("\n\n<18: \t");
    for(i=0;i<cantP;i++){
        if(personas[i].edad<18 & personas[i].estado == 1){
            printf("*");
        }
    }
    printf("\n");

    printf("19-35: \t");
    for(i=0;i<cantP;i++){
        if(personas[i].edad>=18 & personas[i].edad<35 & personas[i].estado == 1){
            printf("*");
        }
    }
    printf("\n");

    printf(">35: \t");
    for(i=0;i<cantP;i++){
        if(personas[i].edad>=35 & personas[i].estado == 1){
            printf("*");
        }
    }
    printf("\n");
}

void per_borrarPersona(ePersona personas[], int cantP, char mensajeError[50]){
    int aux;
    char nombre[50];
    char confirmar;

    per_mostrarLista(personas,cantP);
    printf("Ingrese el nombre a borrar\n");
    gets(nombre);
    fflush(stdin);
    aux = per_buscarNombre(personas,cantP,nombre);
    if(aux==-1){
        printf("%s",mensajeError);
    }else{
        printf("Esta seguro de eliminar? S/N\n");
        scanf("%c",&confirmar);
        fflush(stdin);
        if(confirmar == 'S' || confirmar == 's'){
            printf("%s fue eliminado\n",nombre);
            personas[aux].estado=0;
        }else{
            system("cls");
            printf("Cancelado.\n");
        }
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

int per_agregarPersona(ePersona * personas, int cantP, char mensajeError[50]){
    int posicion;
    int retorno = 0;
    if(personas!=NULL){
        retorno = 1;
        posicion = per_buscarEntero(personas,cantP,0);
        if(posicion != -1){
            per_pedirDato(personas,cantP,posicion);
        }else{
            printf("%s\n",mensajeError);
        }
    }
    return retorno;
}

int per_pedirDato(ePersona * personas,int cantP,int posicion){
    int retorno = 0;

    if(personas!=NULL){
        retorno = 1;
        printf("Ingrese el nombre: \n");
        gets((personas+posicion)->nombre);
        fflush(stdin);
        printf("Ingrese la edad: \n");
        scanf("%d",(personas+posicion)->edad);
        printf("Ingrese el DNI: \n");
        scanf("%d",(personas+posicion)->dni);
        personas[posicion].estado=1;
    }

    return retorno;
}

// busca un entero en estado, si lo encuentra devuleve el indice
int per_buscarEntero(ePersona * personas, int cantP, int lugar){
    int i;
    int indice = -1;
    if(personas != NULL){
        for(i=0;i<cantP;i++){
            if((personas+i)->estado == lugar){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int per_incializarEstado(ePersona * personas, int cantP){
    int i;
    int retorno = 0;

    if(personas!=NULL){
        retorno = 1;
        for(i=0;i<cantP;i++){
            (personas+i)->estado=0;
        }
    }

    return retorno;
}

int per_ordenarPorNombre(ePersona * personas, int cantP){
    int i;
    int j;
    int retorno = 0;
    char auxString[100];
    int auxInt;
    long int auxLongInt;

    if(personas != NULL){
        retorno = 1;
        for(i=0;i<cantP;i++){
            for(j=i+1;j<cantP;j++){
                if(strcmp( (personas+i)->nombre , (personas+j)->nombre ) >0 & (personas+i)->estado == OCUPADO & (personas+j)->estado == OCUPADO){

                    //Esto deberia ser una funcion
                    strcpy(auxString , (personas+i)->nombre);
                    strcpy((personas+i)->nombre, (personas+j)->nombre);
                    strcpy((personas+j)->nombre,auxString);

                    //Esto tambien
                    auxInt = (personas+i)->edad;
                    (personas+i)->edad = (personas+j)->edad;
                    (personas+j)->edad = auxInt;

                    //Esto tambien
                    auxLongInt = (personas+i)->dni;
                    (personas+i)->dni = (personas+j)->dni;
                    (personas+j)->dni = auxLongInt;
                }
            }
        }
    }
    return retorno;
}

//Lo dejo asi a esta funcion o deberia pasarle un puntero?
void per_mostrarUno(ePersona personas){
    printf("%d\t %d\t %s\t\n", personas.edad, personas.dni, personas.nombre);
}

int per_mostrarLista(ePersona * personas, int cantP){
    int i;
    int retorno = 0;
    //(personas+i)->estado=0;
    if(personas != NULL){
        retorno = 1;
        printf("\nEDAD\t DNI\t\t NOMBRE\n______________________________________\n\n");
        for(i=0;i<cantP;i++){
            if((personas+i)->estado == OCUPADO){
                per_mostrarUno(personas[i]); //Aca genera la duda
            }
        }
    }
    return retorno;
}

int per_harcodearDatos(ePersona * personas){
    int retorno = 0;
    char nombre[][50]={"Fantino","Barreda","Puch","Galarza","Grassi","Memo","Mangieri","Cordera","Jaitt","Barattini"};
    int edad[10]={43,23,58,21,44,32,11,54,42,28};
    long int dni[10]={20144188,26587458,66541259,74584126,21458756,22014568,44552014,60321548,42036548,30140028};

    //(personas+i)->estado=0;
    int i;
    if(personas != NULL){
        retorno = 1;
        for(i=0;i<10;i++){
            strcpy((personas+i)->nombre, nombre[i]);
            (personas+i)->dni=dni[i];
            (personas+i)->edad=edad[i];
            (personas+i)->estado=1;
        }
    }
    return retorno;
}



#endif // EPERSONA_C_INCLUDED
