#ifndef EPERSONA_C_INCLUDED
#define EPERSONA_C_INCLUDED
#include "ePersona.h"
#include <stdio.h>
#define OCUPADO 1
#define LIBRE 0

void mostrarMenu(){
    printf("\n[N] - ELIJA UNA OPCION:\n");
    printline(50);
    printf("\n\n");
    printf("[1]  - Agregar una persona\n");
    printf("[2]  - Borrar una persona\n");
    printf("[3]  - Imprimir lista ordenada por nombre\n");
    printf("[4]  - Imprimir gr%cfico de edades\n",160);
    printf("[5]  - Salir\n");
    printf("[6]  - Harcodear datos\n");
    printf("[7]  - Imprimir lista ordenada por ID\n");
    printf("[8]  - Imprimir lista ordenada por edad\n");
    printf("[9]  - Mostrar usuarios dados de baja\n");
    printf("[10] - Modificar nombre\n");
    printf("[11] - Modificar edad\n\n");
    printline(50);
    printf("\n");
}

int per_modificarNombre(ePersona listado[],int limite){
    char nombre[50];
    char respuesta;
    int indice;

    printf("\n\nIngrese nombre a modificar\n");
    fflush(stdin);
    gets(nombre);
    indice = per_buscarNombre(listado,limite,nombre);
    if(indice == -1)
    {
        printf("\n- [ERROR] - Nombre no encontrado\n");
    }else{
        //printf("\n- Persona encontrada:\n");
        per_mostrarUno(listado[indice]);
        printf("\n- Ingrese el nuevo nombre: \n");
        fflush(stdin);
        gets(nombre);
        printf("\n[MMM] - Esta seguro que desea modificar? [S/N]\n");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta == 'S' || respuesta == 's'){
            system("cls");
            printf("\n[EXITO]\n Persona modificada\n");
            strcpy(listado[indice].nombre,nombre);
            per_mostrarUno(listado[indice]);
        }
    }

}

int per_buscarEnteroEnEdad(ePersona personas[], int cantP, int entero){
    int i;
    int indice = -1;
    for(i=0;i<cantP;i++){
        if(personas[i].edad == entero){
            indice = i;
            break;
        }
    }
    return indice;
}

void printline(int cant){int i;for(i=0;i<cant;i++){printf("%c",196);}}

int per_siguienteId(ePersona listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL){
        for(i=0; i<limite; i++){
            if(listado[i].estado == OCUPADO){
                if(listado[i].id>retorno){
                    retorno=listado[i].id;
                }
            }
        }
    }
    return retorno+1;
}

int per_buscarPorId(ePersona listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//deberia mostrar hasta el ultimo estado que cargue, para que no desborde
int per_mostrarListadoConBorrados(ePersona listado[],int limite)
{
    int retorno = -1;
    int i;
    int auxId;
    auxId = per_siguienteId(listado,limite);
    auxId -1;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        printf("\nESTADO\t ID\t EDAD\t DNI\t\t NOMBRE\n"); printline(50); printf("\n\n");
        for(i=0; i<auxId-1; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("LIBRE\t");
                per_mostrarUno(listado[i]);
            }
            //per_mostrarUno(listado[i]);
        }
    }
    return retorno;
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

void per_borrarPersonaPorNombre(ePersona personas[], int cantP, char mensajeError[50]){
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

void per_agregarPersona(ePersona personas[], int cantP, char mensajeError[50]){
    int posicion;
    posicion = per_buscarEnteroEnEstado(personas,cantP,LIBRE);
    if(posicion != -1){
        //per_mostrarLista(personas,cantP);
        per_pedirDato(personas,cantP,posicion);
    }else{
        printf("%s\n",mensajeError);
    }
}

void per_pedirDato(ePersona listado[],int cantP,int posicion){
    int id;
    char auxString[100];
    id = per_siguienteId(listado,cantP);
    listado[posicion].id = id;

    printf("Ingrese el nombre: \n");
    gets(auxString);
    fflush(stdin);
    while(strlen(auxString)>10){
        printf("\n Error: El nombre es muy largo, maximo 10 caracteres\n Re-ingrese el nombre: \n");
        gets(auxString);
        fflush(stdin);
    }
    strcpy(listado[posicion].nombre,auxString);
    fflush(stdin);

    printf("Ingrese la edad: \n");
    scanf("%d",&listado[posicion].edad);
    fflush(stdin);

    printf("Ingrese el DNI: \n");
    scanf("%d",&listado[posicion].dni);
    fflush(stdin);

    listado[posicion].estado=1;
}

// busca un entero en estado, si lo encuentra devuleve el indice
int per_buscarEnteroEnEstado(ePersona personas[], int cantP, int lugar){
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

void per_ordenarPorId(ePersona personas[], int cantP){
    int i;
    int j;
    char auxString[100];
    int auxInt;
    long int auxLongInt;

    for(i=0;i<cantP;i++){
        for(j=i+1;j<cantP;j++){
            if(personas[i].id>personas[j].id & personas[i].estado==1 & personas[j].estado ==1){
                strcpy(auxString,personas[i].nombre);
                strcpy(personas[i].nombre,personas[j].nombre);
                strcpy(personas[j].nombre,auxString);

                auxInt = personas[i].edad;
                personas[i].edad = personas[j].edad;
                personas[j].edad = auxInt;

                auxLongInt = personas[i].dni;
                personas[i].dni = personas[j].dni;
                personas[j].dni = auxLongInt;

                auxInt = personas[i].id;
                personas[i].id = personas[j].id;
                personas[j].id = auxInt;
            }
        }
    }
}

void per_ordenarPorEdad(ePersona personas[], int cantP){
    int i;
    int j;
    char auxString[100];
    int auxInt;
    long int auxLongInt;

    for(i=0;i<cantP;i++){
        for(j=i+1;j<cantP;j++){
            if(personas[i].edad>personas[j].edad & personas[i].estado==1 & personas[j].estado ==1){
                strcpy(auxString,personas[i].nombre);
                strcpy(personas[i].nombre,personas[j].nombre);
                strcpy(personas[j].nombre,auxString);

                auxInt = personas[i].edad;
                personas[i].edad = personas[j].edad;
                personas[j].edad = auxInt;

                auxLongInt = personas[i].dni;
                personas[i].dni = personas[j].dni;
                personas[j].dni = auxLongInt;

                auxInt = personas[i].id;
                personas[i].id = personas[j].id;
                personas[j].id = auxInt;
            }
        }
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

                auxInt = personas[i].id;
                personas[i].id = personas[j].id;
                personas[j].id = auxInt;
            }
        }
    }

}

void per_mostrarUno(ePersona personas){
    printf("%d\t %d\t %d\t %s\t\n",personas.id, personas.edad, personas.dni, personas.nombre);
}

void per_mostrarLista(ePersona personas[], int cantP){
    int i;
    printf("\nID\t EDAD\t DNI\t\t NOMBRE\n");printline(50); printf("\n\n");
    for(i=0;i<cantP;i++){
        if(personas[i].estado==1){
            per_mostrarUno(personas[i]);
        }
    }
}

void per_harcodearDatos(ePersona personas[], int limite){
    char nombre[][50]={"Fantino","Barreda","Puch","Galarza","Grassi","Memo","Mangieri","Cordera","Jaitt","Barattini"};
    int edad[10]={43,23,58,21,44,32,11,54,42,28};
    long int dni[10]={20144188,26587458,66541259,74584126,21458756,22014568,44552014,60321548,42036548,30140028};
    //int posicion;
    int i;
    int indice;
    int id;
    for(i=0;i<10;i++){
        id = per_siguienteId(personas,limite);
        indice = per_buscarEnteroEnEstado(personas,limite,LIBRE);
        if(indice >= 0){
                strcpy(personas[indice].nombre, nombre[i]);
                personas[indice].dni=dni[i];
                personas[indice].edad=edad[i];
                personas[indice].id = id;
                personas[indice].estado=1;
        }
    }
}



#endif // EPERSONA_C_INCLUDED
