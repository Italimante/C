#include "ePersona.h"
#include <string.h>

int comprobarCadena(char * this, int largoMax, int opcion){
    if(this != NULL) //Chequeo que el puntero a cadena no sea NULL
    {
        int largoCadena = strlen(this); //Guardo la longitud de la cadena

        if(largoCadena <= largoMax) //Chequeo que el largo de la cadena no sea mayor al maximo permitido
        {

            switch(opcion)
            {
                case 1: //Comprobar que solo haya numeros naturales
                    if(stringSoloNumeros(this)){
                        return 1;
                    }else{
                        return -1;
                    }
                    break;
                case 2: //Comprobar que solo haya letras
                    if(stringSoloLetras(this)){
                        return 1;
                    }else{
                        return -1;
                    }
                    break;
                case 3: //Comprobar que solo haya letras y numeros, sin caracteres especiales
                    break;
                default: //No hace nada
                    printf("[ERROR] Opcion incorrecta\n");
                    return -3;
                    break;
            }

        }
        else{
            printf("[ERROR] String excede el max size\n");
            return -2;
        }

    }
}

int stringSoloLetras(char * this){
    int retorno = NULL;

    if(this != NULL){
        int len = strlen(this);

        for(int i = 0; i<len; i++){
            this[i] = tolower(this[i]);
        }

        for(int i = 0; i<len; i++){
            if(this[i] >= 97 && this[i] <= 122){
                retorno = 1;
            }else{
                return NULL;
            }
        }

    }

    this[0] = this[0] - 32;

    return retorno;
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
