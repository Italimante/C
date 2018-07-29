#ifndef PROP_C_INCLUDED
#define PROP_C_INCLUDED
#include "prop.h"
#include "auto.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

void mostrarMenu(){
    printf("\n");
    printline(70);
    printf("\n| #| - ELIJA UNA OPCION:\n");
    printline(70);
    printf("\n");
    printf("| 1| - Agregar un propietario\n");
    printf("| 2| - Borrar un propietario\n");
    printf("| 3| - Modificar propietario\n");
    printf("| 4| - Listar propietarios\n");
    printf("| 5| - Ingreso de autom%cvil\n",162);
    printf("| 6| - Egreso de autom%cvil\n",162);
    printf("| 7| - Recaudaci%cn total\n",162);
    printf("| 8| - Recaudaci%cn total por marca\n",162);
    printf("| 9| - Buscar veh%cculos de un propietario\n",161);
    printf("|10| - Listar propietarios con veh%cculos Audi\n",161);
    printf("|11| - Lista veh%cculos estacionados, ordenados por patente\n",161);
    printf("|12| - Listar propietarios de 'X' edad\n");
    printline(70);
    printf("\n");
    printf("| 0| - Salir del programa\n");
    printf("|98| - Harcodear propietarios\n");
    printf("|99| - Harcodear veh%cculos\n",161);
    printline(70);
    printf("\n\n");
}

void printSadFace(void){
    printf("\n");
    printf("     .-''''''-.\n");
    printf("   .'          '.\n");
    printf("  /   O      O   \\\n");
    printf(" :           `    :\n");
    printf(" |                |\n");
    printf(" :    .------.    :\n");
    printf("  \\  '        '  /\n");
    printf("   '.          .'\n");
    printf("     '-......-'\n");
}

void printline(int cant){int i;for(i=0;i<cant;i++){printf("%c",196);}}

int prop_mostrarDeXedad(eProp listadoP[], int cantP){
    int auxEdad;
    int i;
    int retorno = 0;

    printf("|!| - Ingresar edad para ver sus propietarios mayores: \n\n");
    scanf("%d",&auxEdad);
    fflush(stdin);

    //printf("|!| - Los siguientes propietarios son mayores a %d\n", auxEdad);
    for(i=0;i<cantP;i++){
        if(listadoP[i].edad > auxEdad && listadoP[i].estado == OCUPADO){
            prop_mostrarUno(listadoP[i]);
            retorno = 1;
        }
    }

    return retorno;
}

int prop_ordenarPorNombreA(eProp listadoP[], int cantP){
    int i;
    int j;
    int retorno = 0;
    eProp auxP;

    for(i=0;i<cantP-1;i++){
        for(j=i+1;j<cantP;j++){
            if(strcmp(listadoP[i].nombre, listadoP[j].nombre) >0 & listadoP[j].estado == OCUPADO & listadoP[i].estado == OCUPADO){
                auxP = listadoP[i];
                listadoP[i] = listadoP[j];
                listadoP[j] = auxP;
                retorno = 1;
            }
        }
    }
    return retorno;
}

int prop_ordenarPorNombreD(eProp listadoP[], int cantP){
    int i;
    int j;
    int retorno = 0;
    eProp auxP;

    for(i=0;i<cantP-1;i++){
        for(j=i+1;j<cantP;j++){
            if(strcmp(listadoP[i].nombre, listadoP[j].nombre) <0 & listadoP[j].estado == OCUPADO & listadoP[i].estado == OCUPADO){
                auxP = listadoP[i];
                listadoP[i] = listadoP[j];
                listadoP[j] = auxP;
                retorno = 1;
            }
        }
    }
    return retorno;
}

int prop_todosAudi(eProp listadoP[], int cantP, eAuto listadoA[], int cantA){
    int retorno = 0;
    int i;
    int j;
    printf("\n\nLos siguientes propietarios propietarios tienen veh%cculo Audi\n\n",161);
    printline(70);
    printf("\nPAT  ID  TARJETA\t NOMBRE\t\t APELLIDO\t DIRECCION\n");
    printline(70);
    printf("\n");
    for(i=0;i<cantA;i++){
        if(listadoA[i].marca == AUDI && listadoA[i].estado == OCUPADO){
            for(j=0;j<cantP;j++){
                if(listadoA[i].idProp == listadoP[j].idProp && listadoP[j].estado == OCUPADO){
                    printf("%s",listadoA[i].patente);
                    prop_mostrarUno(listadoP[j]);
                    retorno = 1; //Se que no deberia ir aca
                }
            }
        }
    }

    return retorno;
}

int prop_informarAutos(eProp listadoP[], int cantP, eAuto listadoA[], int cantA){
    int retorno = 0;
    int aux;
    int auxA;
    int i;
    char auxS[100];

    printf("\n|#| - Ingrese el ID del propietario a mostrar: \n");
    gets(auxS);
    fflush(stdin);
    aux = atoi(auxS);
    while(aux==0){
        printf("|X| - Error: ingrese solo numeros para encontrar el ID, por favor: \n");
        gets(auxS);
        fflush(stdin);
        aux = atoi(auxS);
    }
    aux = prop_buscarId(listadoP, cantP, aux); //DEVUELVE UN NUMERO MENOS DEL QUE LE DOY A LA FUNCION, PERO SI PONOGO UNO MAYOR A 1 FUNCIONA BIEN O.O
    printf("que hay en aux: %d\n", aux);

    if(aux == 0){
        printf("|X| - Lo siento, ID del propietario no encontrado \n\n");
    }else{
        //system("cls");
        printf("|!| - El propietario %s %s tiene los siguientes vehiculos: \n",listadoP[aux].nombre,listadoP[aux].apellido);
        for(i=0;i<cantA;i++){
           if(listadoA[i].idProp == listadoP[aux].idProp){
                printf("\n|#| - Patente: %s",listadoA[i].patente);
                printf("\n|m| - Marca: ");
                if(listadoA[i].marca == ALPHA_ROMEO){
                    printf("Alpha Romeo\n");
                }else if(listadoA[i].marca == FERRARI){
                    printf("Ferrari\n");
                }else if(listadoA[i].marca == AUDI){
                    printf("Audi\n");
                }else if(listadoA[i].marca == OTRO){
                    printf("Otro\n");
                }
            }
        retorno = 1;
        }
    }

    return retorno;
}

int devolverHorasEstadia(){
    int horas;
    srand(time(NULL));
    horas = (rand()%24)+1;
    return horas ;
}

int prop_borrarPropietario(eProp listado[], int cant, eAuto listadoA[], int cantA){
    int retorno = -1;
    int aux;
    char auxS[100];
    char confirmar;
    int i;
    int j;
    int acuTarifa = 0;
    int horas;

    printf("\n|#| - Ingrese el ID del propietario a borrar: \n");
    gets(auxS);
    fflush(stdin);
    aux = atoi(auxS);
    printf("- -  - [TEST]: Que hay en aux despues del ingreso: %d\n",aux);

    while(aux == 0){
        printf("|X| - Error: ingrese solo numeros para encontrar el ID, por favor: \n");
        gets(auxS);
        fflush(stdin);
        aux = atoi(auxS);
    }

    aux = prop_buscarId(listado, cant, aux);
    printf("- -  - [TEST]: Que devuelve prop_buscarId: %d\n",aux);

    if(aux == 0){
        printf("|X| - Lo siento, ID del propietario no encontrado \n\n");
    }else{
        //system("cls");
        printf("|!| - Propietario encontrado: \n\n");
        prop_mostrarUno(listado[aux]);

        printf("\n|?| - Esta seguro que desea dar de baja a %s %s? [S/N]\n\n",listado[aux].nombre,listado[aux].apellido);
        scanf("%c",&confirmar);
        if(confirmar == 's' || confirmar == 'S'){
            for(i=0;i<cantA;i++){
                if(listado[aux].idProp == listadoA[i].idProp & listadoA[i].estado == OCUPADO){
                    listadoA[i].estado = ELIMINADO;
                    if(listadoA[i].marca == ALPHA_ROMEO){
                        //horas = devolverHorasEstadia();
                        //horas = horas * 150;
                        horas = listadoA[i].horas * 150;
                        acuTarifa = acuTarifa + horas;
                    }else if(listadoA[i].marca == FERRARI){
                        //horas = devolverHorasEstadia();
                        //horas = horas * 175;
                        horas = listadoA[i].horas * 175;
                        acuTarifa = acuTarifa + horas;
                    }else if(listadoA[i].marca == AUDI){
                        //horas = devolverHorasEstadia();
                        //horas = horas * 200;
                        horas = listadoA[i].horas * 200;
                        acuTarifa = acuTarifa + horas;
                    }else if(listadoA[i].marca == OTRO){
                        //horas = devolverHorasEstadia();
                        //horas = horas * 250;
                        horas = listadoA[i].horas * 250;
                        acuTarifa = acuTarifa + horas;
                    }
                }
            }

            listado[aux].estado = ELIMINADO;

            printf("|!| - %s %s ha sido dado de baja con exito:\n\n",listado[aux].nombre,listado[aux].apellido);
            printf("|$| - Y debe pagar un total de: $%d\n", acuTarifa);

            retorno = 1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}


int prop_modificarTarjetaPropietario(eProp listado[], int cant){
    int retorno = -1;
    int aux;
    int auxEntero;
    char auxCharA;
    char auxCharB;
    char auxCharC;
    char auxS[100];
    char confirmar;

    printf("\n|#| - Ingrese el ID del propietario a modificar: \n");
    gets(auxS);
    fflush(stdin);
    aux = atoi(auxS);
    while(aux==0){
        printf("|X| - Error: ingrese solo numeros para encontrar el ID, por favor: \n");
        gets(auxS);
        fflush(stdin);
        aux = atoi(auxS);
    }

    aux = prop_buscarId(listado, cant, aux);

    if(aux == 0){
        printf("|X| - Lo siento, ID del propietario no encontrado \n\n");
    }else{
        system("cls");
        printf("|!| - Propietario encontrado: \n\n");
        prop_mostrarUno(listado[aux]);

        //----------------

        printf("|#| - Ingrese el nuevo numero de la tarjeta de credito: \n");
        gets(auxS);
        auxEntero = atoi(auxS);
        fflush(stdin);
        while(strlen(auxS)>6 || strlen(auxS)<6 || auxEntero == 0){
            printf("\n|X| - Error: La tarjeta debe contener solo seis numeros. Re-ingrese: \n");
            gets(auxS);
            auxEntero = atoi(auxS);
            fflush(stdin);
        }

        ///Agrego un guion medio al string: (Metodo muy manual)
        auxCharA = auxS[3];
        auxCharB = auxS[4];
        auxCharC = auxS[5];
        auxS[3] = '-';
        auxS[4] = auxCharA;
        auxS[5] = auxCharB;
        auxS[6] = auxCharC;
        auxS[7] = '\0';

        //----------------

        printf("|?| - Esta seguro de modificar a %s %s? [S/N]\n\n",listado[aux].nombre,listado[aux].apellido);
        scanf("%c",&confirmar);
        if(confirmar == 's' || confirmar == 'S'){
            strcpy(listado[aux].tarjeta,auxS);
            printf("|!| - %s %s modificado con exito:\n\n",listado[aux].nombre,listado[aux].apellido);
            prop_mostrarUno(listado[aux]);
            retorno = 1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}

int prop_buscarId(eProp listado[], int cant, int auxId){
    int retorno = 0;
    int i;

    for(i=0;i<cant;i++){
        if(listado[i].estado == OCUPADO && listado[i].idProp == auxId){
            retorno = i;
            break;
        }
    }
    ///Aca deberia retornar +1 o retorno solo? ????????
    return retorno;
}

void prop_agregarPropietario(eProp listado[], int cant, char mensajeError[50]){
    int posicion;
    posicion = prop_buscarEnteroEnEstado(listado,cant,LIBRE);
    if(posicion != -1){
        prop_pedirDatos(listado,cant,posicion);
    }else{//Mensaje de que no hay espacio disponible
        printf("%s\n",mensajeError);
    }
}

void prop_pedirDatos(eProp listado[],int cant,int posicion){
    char auxString[100];
    char auxCharA;
    char auxCharB;
    char auxCharC;
    int auxEntero;
    int i;

    listado[posicion].idProp = prop_siguienteId(listado,cant);

    printf("|N| - Ingrese el nombre: \n");
    gets(auxString);
    fflush(stdin);
    while(strlen(auxString)>20){
        printf("\n|X| - Error: El nombre es muy largo, maximo 20 caracteres\n Re-ingrese el nombre:");
        gets(auxString);
        fflush(stdin);
    }
    strlwr(auxString); //Pasa la cadena a minusculas
    if(auxString[0]>=97 & auxString[0]<=122){ //Modifica la primer letra a mayusculas
        auxString[0]-=32;
    }
    strcpy(listado[posicion].nombre,auxString);
    fflush(stdin);

    // ---------
    printf("|A| - Ingrese el apellido \n");
    gets(auxString);
    fflush(stdin);
    while(strlen(auxString)>20){
        printf("\n|X| - Error: El apellido es muy largo, maximo 20 caracteres\n Re-ingrese: \n");
        gets(auxString);
        fflush(stdin);
    }
    strlwr(auxString); //Pasa la cadena a minusculas
    if(auxString[0]>=97 & auxString[0]<=122){ //Modifica la primer letra a mayusculas
        auxString[0]-=32;
    }
    strcpy(listado[posicion].apellido,auxString);
    fflush(stdin);

    // ---------
    printf("|D| - Ingrese la direccion \n");
    gets(auxString);
    fflush(stdin);
    while(strlen(auxString)>20){
        printf("\n|X| - Error: La direccion es muy larga, maximo 20 caracteres\n Re-ingrese:: \n");
        gets(auxString);
        fflush(stdin);
    }
    strlwr(auxString); //Pasa la cadena a minusculas
    if(auxString[0]>=97 & auxString[0]<=122){ //Modifica la primer letra a mayusculas
        auxString[0]-=32;
    }
    strcpy(listado[posicion].direccion,auxString);
    fflush(stdin);

    // ---------
    printf("|#| - Ingrese la edad del propietario: \n");
    gets(auxString);
    auxEntero = atoi(auxString);
    fflush(stdin);
    while(auxEntero<18 || auxEntero>100 || auxEntero == 0){
        printf("\n\n|X| - Error: No parece que este en una edad apta para conducir o ingreso letras en vez de numeros. Re-ingrese: \n");
        gets(auxString);
        auxEntero = atoi(auxString);
        fflush(stdin);
    }
    listado[posicion].edad = auxEntero;


    // ---------
    printf("|#| - Ingrese el numero de la tarjeta de credito: \n");
    gets(auxString);
    auxEntero = atoi(auxString);
    fflush(stdin);
    while(strlen(auxString)>6 || strlen(auxString)<6 || auxEntero == 0){
        printf("\n|X| - Error: La tarjeta debe contener solo seis numeros. Re-ingrese: \n");
        gets(auxString);
        auxEntero = atoi(auxString);
        fflush(stdin);
    }

    ///Agrego un guion medio al string: (Metodo muy manual)
    auxCharA = auxString[3];
    auxCharB = auxString[4];
    auxCharC = auxString[5];
    auxString[3] = '-';
    auxString[4] = auxCharA;
    auxString[5] = auxCharB;
    auxString[6] = auxCharC;
    auxString[7] = '\0';

    strcpy(listado[posicion].tarjeta,auxString);
    fflush(stdin);

    listado[posicion].estado = OCUPADO;
}

void prop_mostrarUno(eProp listado){
    printf("  %d\t %s\t %s\t %s\t %s\t\t %d\n",listado.idProp, listado.tarjeta, listado.nombre, listado.apellido,listado.direccion,listado.edad);
}

void prop_mostrarLista(eProp listado[], int cant){
    int i;
    printf("\n  ID\t TARJETA\t NOMBRE\t APELLIDO\t DIRECCION\tEDAD\n");printline(70); printf("\n\n");
    for(i=0;i<cant;i++){
        if(listado[i].estado == OCUPADO){
            prop_mostrarUno(listado[i]);
        }
    }
}

void prop_harcodearDatos(eProp listado[], int cant){
    char apellido[][50]={"Fantino","Barreda","Puchila","Galarza"};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"Mitre","Urqui","Belgr","Alsina"};
    int edad[] = {21,18,22,33};

    //int posicion;
    int i;
    int indice;
    int id;
    for(i=0;i<4;i++){
        id = prop_siguienteId(listado,cant);
        //printf("Harcodea la ID: %d\n",id);
        indice = prop_buscarEnteroEnEstado(listado,cant,LIBRE);
        if(indice >= 0){
                strcpy(listado[indice].nombre, nombre[i]);
                strcpy(listado[indice].apellido, apellido[i]);
                strcpy(listado[indice].tarjeta, tarjeta[i]);
                strcpy(listado[indice].direccion, direccion[i]);
                listado[indice].edad = edad[i];
                listado[indice].idProp = id;
                listado[indice].estado=1;
        }
    }
}

int prop_buscarEnteroEnEstado(eProp listado[], int cantP, int lugar){
    int i;
    int indice = -1;
    for(i=0;i<cantP;i++){
        if(listado[i].estado == lugar){
            indice = i;
            break;
        }
    }
    return indice;
}

int prop_siguienteId(eProp listado[],int cant){
    int retorno = 0;
    int i;
    if(cant > 0 && listado != NULL){
        for(i=0; i<cant; i++){
            if(listado[i].estado == OCUPADO){
                if(listado[i].idProp>retorno){
                    retorno=listado[i].idProp;
                }
            }
        }
    }
    return retorno+1;
    //return retorno;
}

int prop_iniciarEstados(eProp listado[], int cant){
    int retorno = -1;
    int i;
    if(cant > 0 && listado != NULL){
        retorno = 0;
        for(i=0;i<cant;i++){
            listado[i].estado = LIBRE;
            listado[i].idProp = 0;
        }
    }
    return retorno;
}

#endif // PROP_C_INCLUDED
