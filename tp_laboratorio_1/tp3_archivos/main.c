#include <stdio.h>
#include <stdlib.h>
#include "sMovie.h"
#define SIZE_MOVIE 50

int main(){
    sMovie movieList[SIZE_MOVIE];
    sMovie* pMovies;
    pMovies = movieList;

    if(!mov_init(pMovies, SIZE_MOVIE)){
        printf("\n|X| - Error: Puntero nulo o no hay espacio.\n\n");
    }else{
        printf("\n|!| - Exito: Se inici%c correctamente la estructura.\n",162);
    }

    int loop = 1;
    int opcion;
    int flag = 1;

    do{
        imprimirMenu();
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion){
        case 1: //Agregar pelicula
            mov_newOne(pMovies, SIZE_MOVIE);
            flag = 0;
            break;
        case 2: //Borrar pelicula
            if(flag){
                printf("\n|X| - Error: No hay nada que borrar.\n\n");
            }else{
                mov_deleteOne(pMovies, SIZE_MOVIE);
            }
            break;
        case 3: //Modificar pelicula
            if(flag){
                printf("\n|X| - Error: No hay nada que modificar.\n\n");
            }else{
                mov_changeOne(pMovies, SIZE_MOVIE);
            }
            break;
        case 4: //Generar pagina web
            if(flag){
                printf("\n|X| - Error: No hay nada que generar.\n\n");
            }else{
                printf("\n|!| - Exito: Pagina web generada en el subdirectorio: /web.\n\n");
                mov_generateHtml(pMovies, SIZE_MOVIE);
            }
            break;
        case 5: // Hardcodea 4 peliculas
            if(mov_hardData(pMovies, SIZE_MOVIE) == -1){
                printf("\n|X| - Error: Puntero nulo o no hay espacio.\n\n");
            }else{
                printf("\n|!| - Exito: Se cargaron cuatro peliculas correctamente la estructura.\n\n");
                flag = 0;
            }
            break;
        case 6: //Guardar archivo BIN
            if(flag){
                printf("\n|X| - Error: No hay nada que guardar.\n");
            }else{
                mov_saveBinFile(pMovies, SIZE_MOVIE);
            }
            break;
        case 7: //Cargar archivo BIN
            mov_loadBinFile(pMovies,SIZE_MOVIE);
            if(flag){
                printf("\n|X| - Error: No hay nada que cargar.\n"); //Esto se tiene que hacer si el archivo no existe
            }else{
                mov_loadBinFile(pMovies,SIZE_MOVIE);
            }
            break;
        case 8: //Mostrar cargadas
            if(flag){
                printf("\n|X| - Error: No hay nada que mostrar");
            }else{
                mov_showList(pMovies,SIZE_MOVIE);
            }
            break;
        case 9:
            printf("Adios\n");
            loop = 0;
            break;
        default:
            printf("\n|X| - Error: Opcion incorrecta, vuelva a intentar.\n");
            break;
        }
    }while(loop == 1);

    return 0;
}
