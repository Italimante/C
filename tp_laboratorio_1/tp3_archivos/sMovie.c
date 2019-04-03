#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sMovie.h"
#define FREE 1
#define OCCUPIED 0
#define DELETED -1
#define SIZE_MOVIE 50

void imprimirMenu(void){
    printf("\n");
    printLine(50);
    printf("\n");
    printf("|1| - Agregar una pel%ccula\n",161);
    printf("|2| - Borrar pel%ccula\n",161);
    printf("|3| - Modificar pel%ccula\n",161);
    printf("|4| - Generar p%cgina web\n",160);
    printf("|5| - Harcodear cuatro pel%cculas\n",161);
    printf("|6| - Guardar en archivo BIN\n");
    printf("|7| - Cargar archivo BIN\n");
    printf("|8| - Mostrar peliculas cargadas\n");
    printf("|9| - Salir\n");
    printLine(50);
    printf("\n");
}

void printLine(int c){
    int i;
    for(i=0;i<c;i++){
        printf("%c",196);
    }
}

int webTop(FILE * html){
    int retorno = 0;
    if(html != NULL){
        fprintf(html, "<!DOCTYPE html>\n");
        fprintf(html, "<html lang='es'>\n");
        fprintf(html, "<head>\n");
        fprintf(html, "<meta charset='utf-8'>\n");
        fprintf(html, "<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(html, "<title>TP3 - Lista de peliculas</title>\n");
        fprintf(html, "<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(html, "<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(html, "</head>\n");
        fprintf(html, "<body>\n");
        fprintf(html, "<div class='container'>\n");
        fprintf(html, "<div class='row'>\n");
        retorno = 1;
    }
    return retorno;
}

int webBottom(FILE * html){
    int retorno = 0;
    if(html !=NULL){
        fprintf(html, "</div>\n");
        fprintf(html, "</div>\n");
        fprintf(html, "<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(html, "<script src='js/bootstrap.min.js'></script>\n");
        fprintf(html, "<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(html, "<script src='js/holder.min.js'></script>\n");
        fprintf(html, "</body>\n");
        fprintf(html, "</html>\n");
        retorno = 1;
    }
    return retorno;
}

int mov_loadBinFile(sMovie * this, int limit){
    int retorno = 0;
    int cantLeida;

    sMovie auxMovieList[SIZE_MOVIE];
    sMovie* pAuxMovie;
    pAuxMovie = auxMovieList;

    FILE * binFile;

    binFile = fopen("data//save.dat","rb");

    if(binFile == 0){
        retorno = -1;
    }else{
        while(!feof(binFile)){
            fread(pAuxMovie,sizeof(sMovie),limit,binFile);
        }
        mov_showList(pAuxMovie,limit);
        fclose(binFile);
        retorno = 1;
    }

    return retorno;
}
int mov_saveBinFile(sMovie * this, int limit){
    int retorno = 0;

    FILE * binFile;
    binFile = fopen("data//save.dat", "wb");

    if(binFile == 0){
        retorno = -1;
    }else{
        fwrite(this,sizeof(sMovie),limit,binFile);
        fclose(binFile);
        printf("\n|!| - Guardado exitoso en archivo BIN.");
        retorno = 1;
    }

    return retorno;
}




int mov_generateHtml(sMovie * pMovies, int limit){
    int retorno = 0;
    int i;

    FILE * html;
    html = fopen("web//test.html","w");

    if(html == NULL){
        retorno = -1;
    }else{
        webTop(html);
        for(i=0;i<limit;i++){
            if( (pMovies+i)->status == OCCUPIED ){
                fprintf(html,"<article class='col-md-4 article-intro'>\n");
                fprintf(html,"<a href='#'>\n");
                fprintf(html,"<img class='img-responsive img-rounded' src='%s' alt=''>\n", (pMovies+i)->imgLink );
                fprintf(html,"</a>\n");
                fprintf(html,"<h3><a href='#'>%s</a></h3>\n", (pMovies+i)->title );
                fprintf(html,"<ul>\n<li>Genero: %s</li>\n", (pMovies+i)->genre );
                fprintf(html,"<li>Puntaje: %.2f</li>\n", (pMovies+i)->ratingValue );
                fprintf(html,"<li>Duracion: %.2f</li>\n</ul>\n", (pMovies+i)->duration );
                fprintf(html,"<p>\n%s\n</p>\n</article>\n", (pMovies+i)->description );
            }
        }
        webBottom(html);
        retorno = 1;
        fclose(html);
    }

    return retorno;
}

int mov_deleteOne(sMovie * pMovies, int limit){
    int retorno = 0;
    int id;
    int i;
    int aux = -1;
    char confirm;
    char titulo[50];

    pedirStringConNumerosYcaracteres( &titulo, "|!| - Ingrese el titulo de la pelicula a modificar:", 25, "|X| - Error: El titulo es muy largo" );
    capitalizeString(&titulo);

    for(i=0;i<limit;i++){
        if( strcmp( titulo, (pMovies+i)->title ) == 0 && (pMovies+i)->status == OCCUPIED ){
            aux = (pMovies+i)->id-1;
            break;
        }
    }
    if(aux == -1){
        printf("|X| - No se encontro la pelicula \n");
    }else{
        printf("|?| - Esta seguro que desea borrar %s? [S/N]\n", (pMovies+aux)->title );
        scanf("%c",&confirm);
        if(confirm == 's' || confirm == 'S'){
            (pMovies+i)->status = DELETED;
        }else{
            printf("|X| - Modificacion cancelada\n");
        }
    }
    return retorno;
}

int mov_changeOne(sMovie * pMovies, int limit){
    int retorno = 0;
    int id;
    int i;
    int aux = -1;
    char confirm;
    char auxStr[100];
    char titulo[100];
    char auxTitulo[100];
    char auxDescripcion[100];
    char auxGenero[100];
    char auxImagen[400];
    float auxValoracion;
    float auxDuracion;

    pedirStringConNumerosYcaracteres( &titulo, "|!| - Ingrese el titulo de la pelicula a modificar:", 25, "|X| - Error: El titulo es muy largo" );
    capitalizeString(&titulo);

    for(i=0;i<limit;i++){
        if( strcmp( titulo, (pMovies+i)->title ) == 0 && (pMovies+i)->status == OCCUPIED ){
            aux = (pMovies+i)->id-1;
            break;
        }
    }
    if(aux == -1){
        printf("|X| - No se encontro la pelicula \n");
    }else{
        //Esto deberia ser una funcion de pedirDatos
        pedirStringConNumerosYcaracteres(&auxTitulo, "\n|!| - Encontrado! - Ingrese el nuevo titulo de la pelicula, maxmimo 25 caracteres\n", 25, "\n|X| - Error: Maximo 25 caracteres\n");
        capitalizeString(&auxTitulo);
        pedirStringConNumerosYcaracteres(&auxDescripcion, "\n|!| - Ingrese la descripcion de la pelicula, maximo 200 caracteres.\n", 200, "\n|X| - Error: Maximo 200 caracteres\n");
        capitalizeString(&auxDescripcion);
        pedirStringSoloLetras(&auxGenero, "\n|!| - Ingrese el genero de la pelicula, maximo 25 caracteres\n", 25, "\n|X| - Error: Maximo 25 caracteres y solo letras\n");
        capitalizeString(&auxGenero);
        pedirStringConNumerosYcaracteres(&auxImagen, "\n|!| - Ingrese el link de la portada de la pelicula, maximo 200 caracteres.\n", 200, "\n|X| - Error: Maximo 200 caracteres\n");
        capitalizeString(&auxImagen);
        printf("\n|!| - Ingrese el puntaje de la pelicula\n");
        gets(auxStr);
        fflush(stdin);
        while(atof(auxStr)==0){
            printf("\n|X| - Error: Solo numeros, re ingrese:\n");
            gets(auxStr);
            fflush(stdin);
        }
        auxValoracion = atof(auxStr);
        printf("\n|!| - Ingrese la duracion de la pelicula\n");
        gets(auxStr);
        fflush(stdin);
        while(atof(auxStr)==0){
            printf("\n|X| - Error: Solo numeros, re ingrese:\n");
            gets(auxStr);
            fflush(stdin);
        }
        auxDuracion = atof(auxStr);

        printf("|?| - Esta seguro que desea modificar %s? [S/N]\n", (pMovies+aux)->title );
        scanf("%c",&confirm);
        if(confirm == 's' || confirm == 'S'){
            //Aca deberia copiar una estructura auxiliar, en vez de uno por uno
            strcpy( (pMovies+aux)->title , auxTitulo);
            strcpy( (pMovies+aux)->description , auxDescripcion);
            strcpy( (pMovies+aux)->genre , auxGenero);
            (pMovies+aux)->ratingValue = auxValoracion;
            (pMovies+aux)->duration = auxDuracion;
            strcpy( (pMovies+aux)->imgLink , auxImagen);
        }else{
            printf("|X| - Modificacion cancelada\n");
        }
    }
    return retorno;
}

int mov_newOne(sMovie * pMovies, int limit){
    int retorno = -1;
    int id;
    int index;
    int auxInt;
    char auxStr[500];
    float auxFloat;

    if(limit > 0 && pMovies != NULL){
        retorno = 0;
        index = mov_findFreePlace(pMovies,limit);
        if(index >= 0){
            retorno = 1;
            id = mov_nextId(pMovies,limit);
            (pMovies+index)->id = id;
            (pMovies+index)->status = OCCUPIED;

            pedirStringConNumerosYcaracteres(&auxStr, "\n|!| - Ingrese el titulo de la pelicula, maxmimo 25 caracteres\n", 25, "\n|X| - Error: Maximo 25 caracteres\n");
            capitalizeString(&auxStr);
            strcpy( (pMovies+index)->title , auxStr);

            pedirStringConNumerosYcaracteres(&auxStr, "\n|!| - Ingrese la descripcion de la pelicula, maximo 200 caracteres.\n", 200, "\n|X| - Error: Maximo 200 caracteres\n");
            capitalizeString(&auxStr);
            strcpy( (pMovies+index)->description , auxStr);

            pedirStringSoloLetras(&auxStr, "\n|!| - Ingrese el genero de la pelicula, maximo 25 caracteres\n", 25, "\n|X| - Error: Maximo 25 caracteres y solo letras\n");
            capitalizeString(&auxStr);
            strcpy( (pMovies+index)->genre , auxStr);

            printf("\n|!| - Ingrese el puntaje de la pelicula\n");
            gets(auxStr);
            fflush(stdin);
            while(atof(auxStr)==0){
                printf("\n|X| - Error: Solo numeros, re ingrese:\n");
                gets(auxStr);
                fflush(stdin);
            }
            auxFloat = atof(auxStr);
            (pMovies+index)->ratingValue = auxFloat;

            printf("\n|!| - Ingrese la duracion de la pelicula\n");
            gets(auxStr);
            fflush(stdin);
            while(atof(auxStr)==0){
                printf("\n|X| - Error: Solo numeros, re ingrese:\n");
                gets(auxStr);
                fflush(stdin);
            }
            auxFloat = atof(auxStr);
            (pMovies+index)->duration = auxFloat;

            pedirStringConNumerosYcaracteres(&auxStr, "\n|!| - Ingrese el link de la portada de la pelicula, maximo 200 caracteres.\n", 200, "\n|X| - Error: Maximo 200 caracteres\n");
            strcpy( (pMovies+index)->imgLink , auxStr);

        }
    }

    return retorno;
}

int mov_showOne(sMovie * pMovies){
    int retorno = 0;
    if(pMovies != NULL){
        printf("TIT: %s\n",(pMovies)->title );
        printf("GEN: %s\n",(pMovies)->genre );
        printf("DUR: %.2f hs\n",(pMovies)->duration );
        printf("DES: %s\n",(pMovies)->description );
        printf("RAT: %.2f\n",(pMovies)->ratingValue );
        printf("IMG: %s\n",(pMovies)->imgLink );
        printf("EST: %d\n",(pMovies)->status );
        printf("ID: %d\n\n",(pMovies)->id );
        retorno = 1;
    }
    return retorno;
}

int mov_showList(sMovie * pMovies, int limit){
    int retorno = 0;
    int i;
    if(pMovies != NULL){
        retorno = 1;
        for(i = 0; i<limit; i++){
            if((pMovies+i)->status == OCCUPIED){
                mov_showOne(pMovies+i);
            }
        }
    }
    return retorno;
}

int mov_hardData(sMovie * pMovies, int limit){
    int retorno = -1;

    char titulo[][50]={"The good the bad and the ugly","Dirty Harry","Fargo","The Godfather","The Big Lebowski"};
    char genero[][25]={"Spaghetti western","Policial","Crimen","Drama","Comedia"};
    float duracion[]={3.06,1.43,1.38,2.58,1.59};
    float valoracion[]={8.2,7.3,7.8,9.4,8.1};
    char imgLink[][200]={"img/thegood.jpg","img/dirtyharry.jpg","img/fargo.jpg","img/godfather.jpg","img/lebowski.jpg"};
    char descripcion[][200]={"A bounty hunting scam joins two men in an uneasy alliance against a third in a race to find a fortune in gold buried in a remote cemetery.","When a mad man calling himself 'the Scorpio Killer' menaces the city, tough as nails San Francisco Police Inspector Harry Callahan is assigned to track down and ferret out the crazed psychopath.","Jerry Lundegaard's inept crime falls apart due to his and his henchmen's bungling and the persistent police work of the quite pregnant Marge Gunderson.","The aging patriarch of an organized crime dynasty transfers control of his clandestine empire to his reluctant son.","The Dude Lebowski, mistaken for a millionaire Lebowski, seeks restitution for his ruined rug and enlists his bowling buddies to help get it."};

    int index;
    int id;
    int i;

    for(i=0;i<5;i++){
        index = mov_findFreePlace(pMovies, limit);
        if(index >= 0){
            retorno = 1;
            id = mov_nextId(pMovies,limit);
            (pMovies+index)->id = id;
            (pMovies+index)->status = OCCUPIED;
            strcpy((pMovies+index)->title, titulo[i]);
            strcpy((pMovies+index)->description, descripcion[i]);
            strcpy((pMovies+index)->genre, genero[i]);
            strcpy((pMovies+index)->imgLink, imgLink[i]);
            (pMovies+index)->duration = duracion[i];
            (pMovies+index)->ratingValue = valoracion[i];
        }
    }
    return retorno;
}

int mov_searchForId(sMovie * pMovies, int limit, int id){
    int retorno = -1;
    int i;
    if(limit > 0 && pMovies != NULL){
        retorno = -2;
        for(i=0;i<limit;i++){
            if( (pMovies+i)->status == OCCUPIED && (pMovies+i)->id == id ){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int mov_nextId(sMovie * pMovies, int limit){
    int retorno = 0;
    int i;
    if(limit > 0 && pMovies != NULL){
        for(i=0; i<limit; i++){
            if((pMovies+i)->status == OCCUPIED){
                if((pMovies+i)->id > retorno){
                    retorno = (pMovies+i)->id;
                }
            }
        }
    }
    return retorno+1;
}

int mov_findFreePlace(sMovie * pMovies, int limit){
    int retorno = -1;
    int i;
    if(limit > 0 && pMovies != NULL){
        retorno = -2;
        for(i=0;i<limit;i++){
            if((pMovies+i)->status == FREE){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int mov_init(sMovie * pMovies, int limit){
    int retorno = 0;
    int i;
    if(limit > 0 && pMovies != NULL){
        retorno = 1;
        for(i=0;i<limit;i++){
            (pMovies+i)->status = FREE;
            (pMovies+i)->id = 0;
        }
    }
    return retorno;
}

int capitalizeString(char *cadena){
    int retorno = -1;
    int i;
    if(cadena != NULL){
        retorno = 0;
        strlwr(cadena);
        if(cadena[0]>=97 & cadena[0]<=122){
            retorno = 1;
            cadena[0]-=32;
        }
        //Busca espacios y en el indice siguiente lo pasa a mayusculas
        for(i=0;i<strlen(cadena);i++){
            if(cadena[i]==32){
                cadena[i+1]-=32;
            }
        }
    }
    return retorno;
}

int stringSoloLetras(char * cadena){
    int i;
    int retorno = 0;
    for(i=0;i<strlen(cadena);i++){
        if( !(cadena[i]>96 && cadena[i]<123) & !(cadena[i]>64 && cadena[i]<91) ){
            printf("\n|X| - Error %c, no es una letra, re ingrese solamente letras\n",cadena[i]);
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int pedirStringSoloLetras(char *cadena, char mensaje[], int largo, char mensajeError[]){
    int i;
    int retorno = 0;
    if(cadena != NULL){
        printf("%s\n",mensaje);
        gets(cadena);
        fflush(stdin);
        while(strlen(cadena)>largo || stringSoloLetras(cadena) == 1){
                printf("%s\n",mensajeError);
                gets(cadena);
                fflush(stdin);
        }
    }else{
        printf("\n Error: Puntero cadena NULL\n");
        retorno = -1;
    }
    return retorno;
}


int pedirStringConNumerosYcaracteres(char *cadena, char mensaje[], int largo, char mensajeError[]){
    int i;
    int retorno = 0;
    if(cadena != NULL){
        printf("%s\n",mensaje);
        gets(cadena);
        fflush(stdin);
        while(strlen(cadena)>largo){
            printf("%s\n",mensajeError);
            gets(cadena);
            fflush(stdin);
        }
    }else{
        printf("\n Error: Puntero cadena NULL\n");
        retorno = -1;
    }
    return retorno;
}
