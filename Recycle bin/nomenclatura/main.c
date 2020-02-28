#include <stdio.h>
#include <stdlib.h>

int main()
{
    //PUNTEROS:
    /*
        Direcciones de donde se enceuntra el dato
        - Accedo a la posicion de memoria ram donde esta guardado
        - Si los punteros apuntan a algo que no inicializamos pincha todo
        -
    */

    int *punteroNumero;
    int numero;
    int numeroDos;

    numero = 66;
    numeroDos=&numero;
    //Guarda la direccion de memoria de numero1:
    punteroNumero = &numero;

    numeroDos = *punteroNumero;

    /*
    numeroDos=&numero;//asignacion de memoria
    numeroDos=*punteroNumero;//asignacion de valor
    */

    //*punteroNumero = &numero;
    //*punteroNumero=55;
    printf("Numero dos:\n %d -- %d\n",numeroDos, &punteroNumero);

    printf("Valor de la variable entera:\n %d\n",numero);
    printf("Direccion de la variable entera:\n %d\n",&numero);
    printf("Valor del puntero:\n %d\n",punteroNumero);
    printf("Direccion donde esta guardado el puntero:\n %d\n",&punteroNumero);

    printf("\n\nConnotacion de puntero: \n");
    //Connotacion de puntero:
    printf("Valor de la variable entera:\n %d\n",numero);
    printf("Direccion de la variable entera:\n %d\n",&numero);
    printf("Valor del puntero:\n %p\n",punteroNumero);
    printf("Direccion donde esta guardado el puntero:\n %p\n",&punteroNumero);

    printf("\n\nContenido del puntero:\n %d\n",*punteroNumero);


    return 0;
}
