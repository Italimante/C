#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20]="MiNombre";
    char *apellido="MiApellido";
    char *puntero;
    puntero = nombre;

    printf("%s\n",nombre);
    printf("%s\n",apellido);

    printf("%s\n",puntero);

    int i;
    for(i=0;*(apellido+i) != '\0';i++){
            //si el contenido es distinto
        //if(*(apellido+i) != '\0'){
            printf("\n %c",*(apellido+i));
        //}
    }



    return 0;
}
