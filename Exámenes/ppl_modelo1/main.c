#include <stdio.h>
#include <stdlib.h>
#include "Tramite.h"
#include "ArrayList.h"

/*
    eTramite * t;
    t = new_Tramite();
    setId(t,5);
    setDni(t,"333333");
    mostrarTramite(t);
*/

int main(){

    int opcion;
    int i;
    int len;

    //Dos contadores:
    int ultimoIdTramiteUrgente = 0;
    int ultimoIdTramiteRegular = 0;

    ArrayList* listaTramitesUrgentes;
    ArrayList* listaTramitesRegulares;

    //Para cuando ya estan atendidos lo guardamos aca
    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;

    eTramite * tramiteActual;
    char dni[10];

    listaTramitesUrgentes = al_newArrayList();
    listaTramitesRegulares = al_newArrayList();

    atendidosUrgentes = al_newArrayList();
    atendidosRegulares = al_newArrayList();

    do{
        printf("1- Tramite urgente\n2- Tramite regular\n3- Proximo\n4- Listar pendientes\n5- Informar atendidos\n6- Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                //Creo el tramite
                //El new tiene que estar dentro del while
                ultimoIdTramiteUrgente++;
                printf("[TU] - Ingrese su DNI:\n");
                fflush(stdin);
                gets(dni);
                cargarTramite(listaTramitesUrgentes,ultimoIdTramiteUrgente,dni);
                break;
            case 2:
                ultimoIdTramiteRegular++;
                printf("[TR] - Ingrese su DNI:\n");
                fflush(stdin);
                gets(dni);
                cargarTramite(listaTramitesRegulares,ultimoIdTramiteRegular,dni);
                break;

            case 3:
                //Si la lista no esta vacia tomamos el primer tramite y lo mostrabamos
                //la de regulares estaria imitada a esta lista
                if(!listaTramitesUrgentes->isEmpty(listaTramitesUrgentes)){
                    printf("Cliente a ser atentido [URGENTE]: \n");
                    atenderTramite(listaTramitesUrgentes, atendidosUrgentes);
                }else{
                    if(!listaTramitesRegulares->isEmpty(listaTramitesRegulares)){
                        printf("Cliente a ser atentido [REGULAR]: \n");
                        atenderTramite(listaTramitesRegulares, atendidosRegulares);
                    }
                    else{
                        printf("No hay clientes por atender!\n");
                    }
                }
                break;

            case 4:
                //Uso la funcion isEmpty) para saber si esta vacio o no, asi no muestro o lo hago entrar al pedo
                if(!listaTramitesUrgentes->isEmpty(listaTramitesUrgentes)){
                    len = listaTramitesUrgentes->len(listaTramitesUrgentes);
                    printf("Tramites urgentes\n");
                    mostrarListaTramites(listaTramitesUrgentes);
                }

                if(!listaTramitesRegulares->isEmpty(listaTramitesRegulares)){
                    len = listaTramitesRegulares->len(listaTramitesRegulares);
                    printf("Tramites regulares\n");
                    mostrarListaTramites(listaTramitesRegulares);
                }

                break;

            case 5:
                if(!atendidosUrgentes->isEmpty(atendidosUrgentes)){
                    len = atendidosUrgentes->len(atendidosUrgentes);
                    atendidosUrgentes->sort(atendidosUrgentes,compararPorDni,0);
                    printf("Tramites urgentes\n");
                    mostrarListaTramites(atendidosUrgentes);
                }

                if(!atendidosRegulares->isEmpty(atendidosRegulares)){
                    len = atendidosRegulares->len(atendidosRegulares);
                    atendidosRegulares->sort(atendidosRegulares,compararPorDni,0);
                    printf("Tramites regulares\n");
                    mostrarListaTramites(atendidosRegulares);
                }

                break;
            }
    }while(1);


    return 0;
}
