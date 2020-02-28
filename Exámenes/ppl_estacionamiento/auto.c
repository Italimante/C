#ifndef AUTO_C_INCLUDED
#define AUTO_C_INCLUDED
#include "auto.h"
#include "prop.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1
#define EGRESADO -2
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

/*
propiedades estructura:
    - asignacion positiva, tengan los mismos campos

    - ventajas de la utilizacion:
    -- organizacion del codigo, si hay que agregar algo mas, lo agrego sobre le tipo de dato, no sobre vectores
    o variables.
    --

*/

void auto_cuadroMarcas(){
    printf("#\t MARCA\t\n");
    printf("1\t Alpha Romeo\n2\t Ferrari\n3\t Audi\n4\t Otro\n\n");
    printline(70);printf("\n");
}

int ordenarPorPatente(eAuto listadoA[], int cantA){
    int i;
    int j;
    int retorno = 0;
    //Para ordenar deberia crear una estructura auxiliar, no por cada dato
    // para eso sigo con vectores paralelos
    eAuto auxAuto;

    for(i=0;i<cantA-1;i++){
        for(j=i+1;j<cantA;j++){
            if(strcmp(listadoA[i].patente, listadoA[j].patente) >0 & listadoA[j].estado == OCUPADO & listadoA[i].estado == OCUPADO){
                auxAuto = listadoA[i];
                listadoA[i] = listadoA[j];
                listadoA[j] = auxAuto;
                retorno = 1;
            }
        }
    }
    return retorno;
}


int auto_mostrarListaConPropietarios(eAuto listadoA[],int cantA, eProp listadoP[], int cantP){
    int i;
    int j;
    int retorno = 0;

    if(!ordenarPorPatente(listadoA, cantA)){
        printf("|X| - Error al intentar ordenar por patente\n");
    }

    printf("\nPATENTE\t\tMARCA\t\tNOMBREPROP\tIDPRO\tIDAU\n");
    printline(70);printf("\n");
    for(i=0;i<cantA;i++){
        if(listadoA[i].estado == OCUPADO){
            printf("%s\t\t",listadoA[i].patente);
            if(listadoA[i].marca == 1){
                printf("ARomero\t\t");
            }else if(listadoA[i].marca == 2){
                printf("Ferrari\t\t");
            }else if(listadoA[i].marca == 3){
                printf("Audi\t\t");
            }else{
                printf("Otro\t\t");
            }

            for(j=0;j<cantP;j++){
                if(listadoA[i].idProp == listadoP[j].idProp & listadoP[j].estado == OCUPADO){
                    printf("%s\t\t", listadoP[j].nombre);
                    printf("%d\t", listadoP[j].idProp);
                    printf("%d\t\n", listadoA[i].idAuto);
                    retorno = 1; //Se que esto aca tampoco deberia ir
                }
            }
        }
    }
    printline(70);printf("\n");

    return retorno;
}

int auto_recaudacionTotalMarca(eAuto listaA[], int cantA){
    int retorno = 0;
    int i;
    int horas;
    int acuTarifaRomeo = 0;
    int acuTarifaFerrari = 0;
    int acuTarifaAudi = 0;
    int acuTarifaOtro = 0;

    for(i=0;i<cantA;i++){
        if(listaA[i].estado==OCUPADO){
            if(listaA[i].marca == ALPHA_ROMEO){
                //horas = devolverHorasEstadia();
                //printf("Hora en Alpha Romeo: %d\n",horas);
                //horas = horas * 150;
                horas = listaA[i].horas * 150;
                acuTarifaRomeo = acuTarifaRomeo + horas;
            }else if(listaA[i].marca == FERRARI){
                //horas = devolverHorasEstadia();
                //horas = horas * 175;
                horas = listaA[i].horas *175;
                acuTarifaFerrari = acuTarifaFerrari + horas;
            }else if(listaA[i].marca == AUDI){
                //horas = devolverHorasEstadia();
                //horas = horas * 200;
                horas = listaA[i].horas * 200;
                acuTarifaAudi = acuTarifaAudi + horas;
            }else if(listaA[i].marca == OTRO){
                //horas = devolverHorasEstadia();
                //horas = horas * 250;
                horas = listaA[i].horas * 250;
                acuTarifaOtro = acuTarifaOtro + horas;
            }
        retorno = 1;
        }
    }

    printf("\n|$| - Recaudacion Alpha Romeo: $%d",acuTarifaRomeo);
    printf("\n|$| - Recaudacion Ferrari: $%d",acuTarifaFerrari);
    printf("\n|$| - Recaudacion Audi: $%d",acuTarifaAudi);
    printf("\n|$| - Recaudacion Otro: $%d\n",acuTarifaOtro);

    return retorno;
}


int auto_recaudacionTotal(eAuto listaA[], int cantA){
    int i;
    int horas;
    int acuTarifa = 0;
    int retorno = 0;

    for(i=0;i<cantA;i++){
        if(listaA[i].estado==OCUPADO){
            if(listaA[i].marca == ALPHA_ROMEO){
                //horas = devolverHorasEstadia();
                //horas = horas * 150;
                horas = listaA[i].horas * 150;
                acuTarifa = acuTarifa + horas;
            }else if(listaA[i].marca == FERRARI){
                //horas = devolverHorasEstadia();
                //horas = horas * 175;
                horas = listaA[i].horas * 175;
                acuTarifa = acuTarifa + horas;
            }else if(listaA[i].marca == AUDI){
                //horas = devolverHorasEstadia();
                //horas = horas * 200;
                horas = listaA[i].horas * 200;
                acuTarifa = acuTarifa + horas;
            }else if(listaA[i].marca == OTRO){
                //horas = devolverHorasEstadia();
                //horas = horas * 250;
                horas = listaA[i].horas * 250;
                acuTarifa = acuTarifa + horas;
            }
        retorno = 1;
        }
    }

    printf("\n|$| - Recaudacion total: $%d\n",acuTarifa);

    return retorno;
}

int auto_egresoAuto(eAuto listaA[], int cantA, eProp listadoP[], int cantP){
    int auxA;
    int horas;
    int acuTarifa = 0;
    int i;
    int auxI;
    int retorno = 0;

    printf("|!| - Ingresa el ID del auto a egresar:\n");
    scanf("%d",&auxA);
    fflush(stdin);
    auxA = auxA;
    auxA = auto_buscarEnteroId(listaA,cantA,auxA);
    //auxA = auxA +1; //Alambre para un bug que no le encontre la vuelta
    while(auxA == 0){
        printf("|X| - Error: el ID del auto no existe, vuelva a intentar:\n");
        scanf("%d",&auxA);
        auxA = auto_buscarEnteroId(listaA,cantA,auxA);
        //auxA = auxA +1; //Alambre para un bug que no le encontre la vuelta
    }
    if(listaA[auxA].estado == OCUPADO){
        if(listaA[auxA].marca == ALPHA_ROMEO){
            //horas = devolverHorasEstadia();
            //horas = horas * 150;
            horas = listaA[auxA].horas * 150;
            acuTarifa = acuTarifa + horas;
        }else if(listaA[auxA].marca == FERRARI){
            //horas = devolverHorasEstadia();
            //horas = horas * 175;
            horas = listaA[auxA].horas * 175;
            acuTarifa = acuTarifa + horas;
        }else if(listaA[auxA].marca == AUDI){
            //horas = devolverHorasEstadia();
            //horas = horas * 200;
            horas = listaA[auxA].horas * 200;
            acuTarifa = acuTarifa + horas;
        }else if(listaA[auxA].marca == OTRO){
            //horas = devolverHorasEstadia();
            //horas = horas * 250;
            horas = listaA[auxA].horas * 250;
            acuTarifa = acuTarifa + horas;
        }

        for(i=0;i<cantP;i++){
            if(listaA[auxA].idProp == listadoP[i].idProp & listadoP[i].estado == OCUPADO){
                auxI = i;
            }
        }

        //system("cls");

        printline(30);
        printf("\n-----------TICKET-------------\n");
        printline(30);
        printf("\n|i| - %s %s",listadoP[auxI].nombre,listadoP[auxI].apellido);
        printf("\n|#| - Patente: %s",listaA[auxA].patente);
        printf("\n|m| - Marca: ");
        if(listaA[auxA].marca == ALPHA_ROMEO){
            printf("Alpha Romeo\n");
        }else if(listaA[auxA].marca == FERRARI){
            printf("Ferrari\n");
        }else if(listaA[auxA].marca == AUDI){
            printf("Audi\n");
        }else if(listaA[auxA].marca == OTRO){
            printf("Otro\n");
        }
        printline(30);
        printf("\n|$| - Estadia: $%d\n",acuTarifa);
        printf("|H| - Horas: %d\n",horas);
        printline(30);
        printf("\n\n");

        //listaA[auxA].estado = LIBRE;
        listaA[auxA].estado = EGRESADO;

        retorno = 1;

    }else{
        printf("\n|X| - Error: Lo siento, el veh%cculo no se encuentra, acaba de egresar o no existe\n",161);
    }

    return retorno;
}

void auto_ingresarNuevo(eAuto listadoA[], int cantA, eProp listadoP[], int cantP){
    char auxString[100];
    int auxMarca;
    int auxIdProp;
    int posicion;
    int loop = 1;
    int auxHorarios;

    auxHorarios = devolverHorasEstadia();
    posicion = auto_buscarEnteroEnEstado(listadoA,cantA,LIBRE);
    listadoA[posicion].idAuto = auto_siguienteId(listadoA,cantA);

    if(posicion != -1){
        printf("|N| - Ingrese la patente: (3 caracteres) \n");
        gets(auxString);
        fflush(stdin);
        while(strlen(auxString)>3){
            printf("\n|X| - Error: La patente es muy larga, maximo 3 caracteres. Re-ingrese la patente:");
            gets(auxString);
            fflush(stdin);
        }
        strupr(auxString);
        strcpy(listadoA[posicion].patente,auxString);

        auto_cuadroMarcas();
        printf("\n|N| - Ingrese el numero que representa la marca: [1-4] \n");
        scanf("%d",&auxMarca);
        while(loop == 1){
            switch(auxMarca){
            case ALPHA_ROMEO:
                loop = 0;
                break;
            case FERRARI:
                loop = 0;
                break;
            case AUDI:
                loop = 0;
                break;
            case OTRO:
                loop = 0;
                break;
            default:
                printf("|X| - Error: Marca inexistente, vuelva intentar: \n");
                scanf("%d",&auxMarca);
                fflush(stdin);
                break;
            }
        }
        listadoA[posicion].marca = auxMarca;

        prop_mostrarLista(listadoP, cantP);
        printf("|N| - Ingrese el ID del propietario del vehiculo: \n");
        scanf("%d",&auxIdProp);
        fflush(stdin);
        auxIdProp = prop_buscarId(listadoP,cantP,auxIdProp);
        //printf("Que hay en auxIdProp %d\n",auxIdProp);
        auxIdProp = auxIdProp +1;
        //printf("Que hay despues de sumar %d\n",auxIdProp);
        while(auxIdProp == 0){
            printf("|X| - Error: ID del propietario inexistente, vuelva a intentar: \n");
            scanf("%d",&auxIdProp);
            fflush(stdin);
            auxIdProp = prop_buscarId(listadoP,cantP,auxIdProp);
            auxIdProp = auxIdProp +1; //Alambre para un bug que no le encontre la vuelta, ocultar este, y el de la linea 85
        }
        listadoA[posicion].idProp = auxIdProp;

        listadoA[posicion].estado = OCUPADO;

        listadoA[posicion].horas = auxHorarios;

        printf("|!| Exito: Se agrego sastifactoriamente: \n");
        auto_mostrarUno(listadoA[posicion]);

    }else{
        printf("|X| - Lo sentimos, no hay mas espacio para estacionar.");
    }
}

void auto_mostrarUno(eAuto listado){
    //OLD: printf("     %d\t\t %d\t\t %s\t\t %d\t\n",listado.idAuto, listado.idProp, listado.patente, listado.marca);
    printf("     %d\t\t    %d\t\t   %s\t\t ",listado.idAuto, listado.idProp, listado.patente);
    if(listado.marca == ALPHA_ROMEO){
        printf("Alpha Romeo\t\n");
    }else if(listado.marca == FERRARI){
        printf("Ferrari\t\n");
    }else if(listado.marca == AUDI){
        printf("Audi\t\n");
    }else if(listado.marca == OTRO){
        printf("Otro\t\n");
    }
}

void auto_mostrarLista(eAuto listado[], int cant){
    int i;
    printf("\n  ID|AUTO\t ID|PROP\t PATENTE\t MARCA\t\n");printline(70); printf("\n");
    for(i=0;i<cant;i++){
        if(listado[i].estado == OCUPADO){
            auto_mostrarUno(listado[i]);
        }
    }
}

void auto_harcodearDatos(eAuto listado[], int cant){
    //int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    //int posicion;
    int i;
    int indice;
    int id;
    int horas;
    for(i=0;i<10;i++){
        id = auto_siguienteId(listado,cant);
        //printf("Harcodea la ID: %d\n",id);
        indice = auto_buscarEnteroEnEstado(listado,cant,LIBRE);
        horas = devolverHorasEstadia();

        //printf("Harcodea el indice: %d\n",indice);
        if(indice >= 0){
                //printf("Entra aca\n");
                strcpy(listado[indice].patente, patente[i]);
                listado[indice].idProp = propietario[i];
                listado[indice].marca = marca[i];
                listado[indice].horas = horas;
                listado[indice].idAuto = id;
                listado[indice].estado=1;
        }
    }
}

int auto_buscarEnteroEnEstado(eAuto listado[], int cantP, int lugar){
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

int auto_siguienteId(eAuto listado[],int cant){
    int retorno = 0;
    int i;
    if(cant > 0 && listado != NULL){
        for(i=0; i<cant; i++){
            if(listado[i].estado == OCUPADO){
                if(listado[i].idAuto>retorno){
                    retorno=listado[i].idAuto;
                }
            }
        }
    }
    return retorno+1;
    //return retorno+1;
}

int auto_iniciarEstados(eAuto listado[], int cant){
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

int auto_buscarEnteroId(eAuto listado[], int cant, int entero){
    int i;
    int indice = -1;
    for(i=0;i<cant;i++){
        if(listado[i].idAuto == entero){
            indice = i;
            break;
        }
    }
    return indice;
}

#endif // AUTO_C_INCLUDED
