#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "string.h"

void startCalculadora(){
    showMenu();
}

void showMenu(){
    int continuar = 1;
    int flagA = 0;
    int flagB = 0;
    int opcion;
    int numA = 0;
    int numB = 0;

    do{

        printMenu(numA, numB);
        fflush(stdin);
        scanf("%d",&opcion);


        switch(opcion){
        case 1: //Ingresar primer operando
            numA = pedirNumero("[1] - Ingrese primer numero, recuerde ingresar solo numeros\n");
            flagA = 1;
            break;
        case 2:
            numB = pedirNumero("[2] - Ingrese el segundo numero, recuerde ingresar solo numeros\n");
            flagB = 1;
            break;
        case 3:
            if(flagA && flagB){
                printf("[3] - Resultado de la suma: %d", suma(numA,numB));
            }else{
                printf("[!] - Debe ingresar los valores primero");
            }
            break;
        case 4:
            if(flagA && flagB){
                printf("[4] - Resultado de la resta: %d", resta(numA,numB));
            }else{
                printf("[!] - Debe ingresar los valores primero");
            }
            break;
        case 5:
            if(flagA && flagB){
                if(numB != 0){
                    printf("[5] - Resultado de la division: %.1f", division(numA,numB));
                }else{
                    printf("[!] - No se puede divir por cero");
                }
            }else{
                printf("[!] - Debe ingresar los valores primero");
            }
            break;
        case 6:
            if(flagA && flagB){
                printf("[6] - Resultado de la multiplicacion: %d", multiplicar(numA,numB));
            }else{
                printf("[!] - Debe ingresar los valores primero");
            }
            break;
        case 7:
            if(flagA && flagB){
                printf("[7] - Resultado del factorial: %d", factorial(numA));
            }else{
                printf("[!] - Debe ingresar los valores primero");
            }
            break;
        case 8:
            if(flagA && flagB){
                printf("[3] - Resultado de la suma: %d\n", suma(numA,numB));
                printf("[4] - Resultado de la resta: %d\n", resta(numA,numB));
                if(numB != 0){
                    printf("[5] - Resultado de la division: %.1f", division(numA,numB));
                }else{
                    printf("[!] - No se puede divir por cero\n");
                }
                printf("[6] - Resultado de la multiplicacion: %d\n", multiplicar(numA,numB));
                printf("[7] - Resultado del factorial: %d\n", factorial(numA));

            }else{
                printf("[!] - Debe ingresar los valores primero");
            }
            break;
        case 9:
            continuar = 0;
            break;
        default:
            printf("Opcion invalida\n");
            break;

        }

    }while(continuar);
}

int pedirNumero(char mensaje[]){
    char buf[5] = "";
    int numeroConvertido;
    int check;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s", &buf);

    while(stringSoloNumeros(buf) == NULL){
        printf("[X] - Error, solo numeros, vuelva a intentar.\n%s\n", mensaje);
        fflush(stdin);
        scanf("%s", &buf);
    }

    numeroConvertido = atoi(buf);

    return numeroConvertido;
}

void printMenu(int valorA, int valorB){
    printf("\n----------------------------------------------\n");
    printf("[1]- Ingresar primer operando\t\t| %d |\n",valorA);
    printf("[2]- Ingresar segundo operando\t\t| %d |\n",valorB);
    printf("[3]- Calcular la suma\t\t\t|%d+%d|\n",valorA,valorB);
    printf("[4]- Calcular la resta\t\t\t|%d-%d|\n",valorA,valorB);
    printf("[5]- Calcular la division\t\t|%d/%d|\n",valorA,valorB);
    printf("[6]- Calcular la multiplicacion\t\t|%d*%d|\n",valorA,valorB);
    printf("[7]- Calcular el factorial\t\t|%d! |\n",valorA);
    printf("[8]- Calcular todas las operaciones\t|ALL|\n");
    printf("[9]- Salir\t\t\t\t|BYE|\n");
    printf("----------------------------------------------\n");
}

int suma(int a, int b){
    int resultado;
    return resultado = a + b;
}

int resta(int a, int b){
    int resultado;
    return resultado = a - b;
}

float division(int a, int b){
    double resultado;
    return resultado = (double)a/(double)b;
}

int multiplicar(int a, int b){
    int resultado;
    return resultado = a*b;
}

int factorial(int a){
    int i;
    int contador = 0;
    int resultado = 1;

    for(i=+1; i<=a; i++)
    {
        contador ++;
        resultado = resultado * contador;
    }
    return resultado;
}

int stringSoloNumeros(char * this)
{
    int retorno = NULL;

    if(this != NULL)
    {
        int len = strlen(this);
        for(int i = 0; i< len; i++ )
        {
            if(this[i] >= 48 && this[i] <= 57 || this[0] == 45)
            {
                retorno = 1;
            }
            else{
                return NULL;
            }
        }
    }

    return retorno;
}
