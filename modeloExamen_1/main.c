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

    eTramite * tramiteActual;
    char dni[10];

    listaTramitesUrgentes = al_newArrayList();
    listaTramitesRegulares = al_newArrayList();

    do{
        printf("1- Tramite urgente\n2- Tramite regular\n3- Proximo\n4- Listar pendientes\n5- Informar atendidos\n6- Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
        case 1:
            //Creo el tramite
            //El new tiene que estar dentro del while
            tramiteActual = new_Tramite();
            ultimoIdTramiteUrgente++;
            //Seteo los valores
            setId( tramiteActual,  ultimoIdTramiteUrgente);
            printf("Ingrese su DNI\n");
            fflush(stdin);
            gets(dni);
            setDni(tramiteActual, dni);
            //mostrarTramite(tramiteActual);
            listaTramitesUrgentes->add(listaTramitesUrgentes,tramiteActual);
            break;
        case 2:
            tramiteActual = new_Tramite();
            ultimoIdTramiteRegular++;
            //Seteo los valores
            setId( tramiteActual,  ultimoIdTramiteRegular);
            printf("Ingrese su DNI\n");
            fflush(stdin);
            gets(dni);
            setDni(tramiteActual, dni);
            //mostrarTramite(tramiteActual);
            listaTramitesRegulares->add(listaTramitesRegulares,tramiteActual);
            break;

        case 3:
            if(!listaTramitesUrgentes->isEmpty(listaTramitesUrgentes)){
                //le hago un pop del primer elemento, siempre del primer elemento
                tramiteActual = (eTramite*) listaTramitesUrgentes->pop(listaTramitesUrgentes, 0);
                printf("Cliente a ser atentido: \n");
                mostrarTramite(tramiteActual);
            }


            break;

        case 4:
            //Uso la funcion isEmpty) para saber si esta vacio o no, asi no muestro o lo hago entrar al pedo
            if(!listaTramitesUrgentes->isEmpty(listaTramitesUrgentes)){
                len = listaTramitesUrgentes->len(listaTramitesUrgentes);
                printf("Tramites urgentes\n");
                for(i=0; i<len; i++){
                    tramiteActual = (eTramite*) listaTramitesUrgentes->get(listaTramitesUrgentes,i);
                    mostrarTramite(tramiteActual);
                }
            }

            if(!listaTramitesRegulares->isEmpty(listaTramitesRegulares)){
                len = listaTramitesRegulares->len(listaTramitesRegulares);
                printf("Tramites regulares\n");
                for(i=0; i<len; i++){
                    tramiteActual = (eTramite*) listaTramitesRegulares->get(listaTramitesRegulares,i);
                    mostrarTramite(tramiteActual);
                }
            }

            break;
            }
            //system("pause");
            //system("cls");
    }while(1);


    return 0;
}
