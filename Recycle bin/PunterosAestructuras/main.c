#include <stdio.h>
#include <stdlib.h>
/*
    - En las estructuras redondea para que el sizeof seria multiplo de 8
    - El sizeof existe para saber cuanta memoria vamos a necesitar, y asi hacerlo en multiplataforma:
    - - no es lo mismo decirle dame 4 bit que decirle dame el sizeof de tal cosa, que puede variar dependeindo del so
    //Permite saber el tamanio de una variable como de un tipo de dato
    //El entero y entero long valen lo mismo para arquitecturas 64
    printf("TAM: %d\n",sizeof(dato));
    printf("%d -- %c",d.a,d.b);
    ---------
    // Agarrar el TP 2 y hacer una version nueva con punterosC

*/

typedef struct{
    int a;//4
    char b;//1
    // por logia el sizeof da 5, pero como no es multiplo de 8 le suma una cantidad de bites para que sea multiplo
    // de ocho
}eDato;

int main()
{

    eDato listadoD;
    listadoD.a=5;
    listadoD.b='<';

    eDato* pDato;
    pDato = &listadoD;

    //Operador flecha:
    printf("%d - - %c", pDato->a, pDato->b );


    /*
    dato d;
    d.a=5;
    d.b='<';

    dato* pDato; // <- creo un puntero de estructuras

    pDato = &d; // < - le mando la direccion de la estructura al puntero

    //acceder a los datos atraves de los punteros
    printf("%d - - %c", (*pDato).a, (*pDato).b);

    //muestra lo mismo porque es donde empieza la estructura
    //printf("%d - - %d",&d, &(d.a));
    */

    /*
    // Puntero a vector
    int i;

    dato l[2] = { {1,'a'},{1,'b'} };
    dato * pLista;
    pLista = l; //< - si no fura array va el uppersand


    for(i=0; i<2; i++){
        printf("%d - - %c\n", (*(pLista+i)).a , (*(pLista+i)).b );
    }
    */

    /*
    // Puntero a vector con flechita
    int i;

    dato l[2] = { {1,'a'},{1,'b'} };
    dato * pLista;
    pLista = l; //< - si no fura array va el uppersand


    for(i=0; i<2; i++){
        //printf("%d - - %c\n", (*(pLista+i)).a , (*(pLista+i)).b );
        printf("%d - - %c\n", (pLista+i)->a , (pLista+i)->b );
    }
    */

    return 0;
}
