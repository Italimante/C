#include "Usuario.h"
/*
    int idUsuario;
    char nombre[50];
    int idSerie;
    int estado;

*/
void serie_MostrarConUsuario(eSerie series[], int cantS, eUsuario usuarios[], int cantU){
    int i;
    int j;
    for(i=0;i<cantS;i++){
        if(series[i].estado==1){
            printf("[+] %s esta siendo vista por:\n",series[i].nombre);
        }
        for(j=0;j<cantU;j++)
        {
            if(series[i].idSerie == usuarios[j].idSerie & usuarios[j].estado==1){
                printf("- %s\n",usuarios[j].nombre);

            }
        }
    }
}

void usuario_MostrarConSuSerie(eUsuario usuarios[], int cantU, eSerie series[], int cantS){
    int i;
    int j;
    for(i=0;i<cantU;i++){
        if(usuarios[i].estado==1){
            for(j=0;j<cantS;j++){
                if(usuarios[i].idSerie == series[j].idSerie & series[j].estado==1){
                    printf("- %s esta viendo:\t %s\n",usuarios[i].nombre, series[j].nombre);
                    break;
                }
            }
        }
    }
}

void usuario_mostrarUno(eUsuario aux){
    printf("%d\t %s\t\n",aux.idUsuario,aux.nombre);
}

void usuario_mostrarLista(eUsuario aux[], int cantU){
    int i;
    printf("\nID\t NOMBRE\t\n-------------------------\n");
    for(i=0; i<cantU; i++){
        if(aux[i].estado==1){
            usuario_mostrarUno(aux[i]);
        }
    }
}

void inicializarUsuariosEstado(eUsuario usuarios[], int cant){
    int i;
    for(i=0; i<cant; i++){
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[]){
    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};
    int serie[15] = {100,100,101,101,102,100,104,103,101,102,103,101,100,100,101};
    int i;
    //Despues de harcodear los datos se 'suben' a la estructura de la siguiente manera:
    for(i=0; i<15; i++){
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);
    }
}
