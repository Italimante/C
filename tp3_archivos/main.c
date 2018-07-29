#include <stdio.h>
#include <stdlib.h>
#include "sMovie.h"
#define SIZE_MOVIE 50

int main()
{
    sMovie movieList[SIZE_MOVIE];
    sMovie* pMovies;
    pMovies = movieList;

    if(!mov_init(pMovies, SIZE_MOVIE)){
        printf("\n|X| - Error: Puntero nulo o no hay espacio.\n\n");
    }else{
        printf("\n|!| - Exito: Se inici%c correctamente la estructura.\n\n",162);
    }

    //mov_newOne(pMovies, SIZE_MOVIE);
    mov_hardData(pMovies, SIZE_MOVIE);
    mov_showList(pMovies, SIZE_MOVIE);
    mov_newOne(pMovies, SIZE_MOVIE);
    mov_showList(pMovies, SIZE_MOVIE);



/*
    FILE * web;
    web = fopen("web\\index.html","w");
    int i;
    if(web != NULL){
        webTop(web);

        for(i=0;i<SIZE_MOVIE;i++){
            fprintf(web,"%s",(pMovies+i)->imgLink);
            fprintf(web,"%s",(pMovies+i)->title);
            fprintf(web,"%s",(pMovies+i)->genre);
            fprintf(web,"%d",(pMovies+i)->ratingValue);
            fprintf(web,"%f",(pMovies+i)->duration);
            fprintf(web,"%s",(pMovies+i)->description);
        }

        webBottom(web);
    }
*/


    imprimirMenu();
    return 0;
}
