#include <stdio.h>
#include <stdlib.h>
/*
    TAREA: Del TP2 guardar los datos en archivos
    ---------
    Importante a tener en cuenta:
    - Abrir el archivo
    - Obtener datos o guardar en el archivo
    - Cerrarlo
    ----------
    Para trabajar con archivos hay que declarar un puntero que apunte a ese archivo
    ----------
    Cada vez que entra al archivo ese senialador queda marcando el final de la lectura con el fget
    entonces el proximo va leer de donde se haya quedado el anterior
    ---------
    fseek
    para poner texto entre tal y tal, pero es un lio y capaz ni lo vemos
*/
int main(){
    FILE * fp; //Hay que declarar un puntero que apunte a ese archivo
    //Se pueden crear dos tipos de archivos, texto que se va interpretar por texto por mas que haya numeros
    // y los archivos binarios que tienen la capacidad de guardar bloques de informacion
    char buffer[100]="Esto es un texto dentro de un fichero.\nY esto en la segunda linea";
    char bufferIn[100];
    //Abrimos el archivo
    //Funcion fopn: recibe primero el nombre con direccion del archivo. Y "w" que es modo escritura.
    //"W" = Si no existe lo va crear, si existe, lo va sobreescribir
    //En la direccion la "\" hay que repetirta: ej: D:\\lugar\\fichero.txt
    // El PATH generalmente se usa con DEFINE
    fp = fopen ("test.txt","w");
    //Imprime en el archivo, a que archivo y que texto
    fprintf(fp, buffer);
    fprintf(fp,"%s","\nEsto es oto texto dentro del fichero.");
    fprintf(fp,"\nMas lineas en el archivo.");
    //Lo cierro con la funcion fclose
    fclose(fp);
    //Si el PATH no existe, tira error R = LEER
    fp = fopen ("test.txt","r");
    if(fp==NULL){
        printf("Archivo inexistente\n");
    }else{
        //Lo que hay en el archivo lo guarda en la variable bufferIn, el 100 cuanto va leer
        //Esta funcion lee solamente una linea, por eso hay que hacer una estructura repetitiva
        //Hay una funcion que permite saber si llegue al final del archivo:
        //-- feof() find end of file
        while(!feof(fp)){
            //Lee
            fgets(bufferIn,100,fp);
            //Muestra
            puts(bufferIn);
        }
    }

    //remove(url) y lo borra

    return 0;
}
