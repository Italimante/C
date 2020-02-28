#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "inc/StructEmpleado.h"
//#include "inc/ArrayList.h"

sLetra * emp_newStruct(){
    return (sLetra*)malloc(sizeof(sLetra));
}

/*
    FUNCION QUE FILTRA
*/
int funcionQueFiltra(void* empleado){
    int retorno = -1; //test 0028
    sLetra* auxEmp;
    auxEmp = (sLetra*)empleado;

    if(empleado!=NULL){
        if(emp_getEdad(auxEmp)>30){
            if(strcmp(emp_getProfesion(auxEmp),"Programador")==0){
                retorno=1;
            }
        }else{
            retorno=0;
        }
    }
    return retorno;
}

 /*
    INGRESOS PEDIR AL USUARIO
 */

 /*
 sLetra * emp_newConsonante (sLetra * this){
    int aux;
    if(this!=NULL){
        do{
            aux=entero_get("consonante [0 || 1]");
        }while(!entero_validaRango(aux,"consonante [0 || 1]",0,1));
        this->consonante=aux;
        return 1;
    }
    return 0;
 }*/

/*
sLetra * emp_newVocal (sLetra * this){
    int aux;
    if(this!=NULL){
        do{
            aux=entero_get("vocal");
        }while(!entero_validaRango(aux,"vocal",0,1));
        this->vocal=aux;
        return 1;
    }
    return 0;
 }*/

int emp_comprobarVocalConsonante(letra){
    if(letra==97 || letra==101 || letra==105 || letra == 111 || letra == 117 ){
        return 1;
    }else{
        return 0;
    }
}

sLetra * emp_newLetra (sLetra * this){
    char letra;
    int comprobar;
    if(this!=NULL){
        //while() VALIDAR
        char_get("Ingrese letra por favor \n",letra); //falta validar
        tolower(letra);
        this->letra = letra;
        comprobar = emp_comprobarVocalConsonante(letra);
        if(comprobar){
            this->vocal = 1;
            this->consonante = 0;
        }else{
            this->consonante = 1;
            this->vocal = 0;
        }
    }
 }

int emp_newName(sLetra * this){
    char aux[21];
    if(this!=NULL){
        while(!string_getLetras("\n|!| - Ingrese el nombre: \n",aux)){
            printf("\n|X| - Error: El nombre solo puede ser letras.\n [!] - Re-ingrese el nombre:\n");
        }
        strlwr(aux);
        *(aux+0)=toupper(*aux+0);
        strcpy(this->nombre,aux);
        return 1;
    }
    return 0;
}

 /*
    SETTERS
 */

 int emp_setLetra (sLetra* this, char letra){
    if(this!=NULL){
        this->letra=letra;
        return 1;
    }
    return 0;
}

int emp_setConsonante (sLetra* this, int consonante){
    if(this!=NULL){
        this->consonante=consonante;
        return 1;
    }
    return 0;
}

int emp_setVocal (sLetra* this, int vocal){
    if(this!=NULL){
        this->vocal=vocal;
        return 1;
    }
    return 0;
}

int emp_setName(sLetra* this, char* nombre){
    if(this!=NULL && nombre!=NULL){
        strcpy(this->nombre,nombre);
        return 1;
    }
    return 0;
}

int emp_setProfesion(sLetra* this, char* profesion){
    if(this!=NULL && profesion!=NULL){
        strcpy(this->profesion,profesion);
        return 1;
    }
    return 0;
}

int emp_setSalary (sLetra* this, int salario){
    if(this!=NULL){
        this->salario=salario;
        return 1;
    }
    return 0;
}

int emp_setEdad (sLetra* this, int edad){
    if(this!=NULL){
        this->edad=edad;
        return 1;
    }
    return 0;
}

int emp_setId(sLetra* this,int* id){
    if(this!=NULL && id!=NULL){
        this->idEmpleado=*id;
        return 1;
    }
    return 0;
}

int emp_setState(sLetra* this, int estado){
    if(this!=NULL){
        this->estado=estado;
        return 1;
    }
    return 0;
}

/*
    GETTERS
*/
int emp_getConsonante(sLetra* this){
    int consonante;
    if(this!=NULL){
        consonante=this->consonante;
    }
    return consonante;
}

int emp_getVocal(sLetra* this){
    int vocal;
    if(this!=NULL){
        vocal=this->vocal;
    }
    return vocal;
}

char* emp_getLetra (sLetra* this){
    char* aux=NULL;
    if(this!=NULL){
        aux=this->letra;
    }
    return aux;
}


char* emp_getName (sLetra* this){
    char* aux=NULL;
    if(this!=NULL){
        aux=this->nombre;
    }
    return aux;
}

char* emp_getProfesion (sLetra* this){
    char* aux=NULL; //Test 0025
    if(this!=NULL){
        aux=this->profesion;
    }
    return aux;
}

int emp_getSalary(sLetra* this){
    int aux; //Test 0026
    if(this!=NULL){
        aux=this->salario;
    }
    return aux;
}

int emp_getState(sLetra* this){
    int estado;
    if(this!=NULL){
        estado=this->estado;
    }
    return estado;
}

int emp_getId(sLetra* this){
    int id;
    if(this!=NULL){
        id=this->idEmpleado;
    }
    return id;
}

int emp_getEdad(sLetra* this){
    int edad;
    if(this!=NULL){
        edad=this->edad;
    }
    return edad;
}

/*
    GENERICO
*/

int generic_menu (void){
    fflush(stdin);
    printline(60);
    printf("\n GESTION DE LETRAS\n");
    printline(60);
    printf("\n|1|. Alta");
    printf("\n|2|. Filtrar",164);
    printf("\n|3|. Listar\n");
    printline(60);
    printf("\n0. Salir\n");
    printline(60);

    int opcion = entero_get("opcion");

    return opcion;
}

void generic_finFuncion (void){
    printf("\n");
    system("pause");
    system("cls");
}

int generic_confirmar(void){
    char respuesta;
    int flag = 0;
    do{
        if(flag){
            printf("\n|X| - Respuesta incorrecta, ingrese s por SI o n por NO: ");
        }
        respuesta = getche();
        respuesta = tolower(respuesta);
        flag = 1;
    }while(respuesta!='s'&&respuesta!='n');

    if(respuesta=='s'){
        return 1;
    }else{
        printf("\nAccion cancelada.");
    }
    return 0;
}

void generic_alta(ArrayList* lista, int* id){
    sLetra * aux = emp_newStruct(); //Test 0027
    int sal;
    system("cls");
    printf("\n|!| - Generar alta:\n");
    emp_newName(aux);
    emp_newLetra(aux);
    //emp_newVocal(aux);
    //emp_newConsonante(aux);
    //emp_newEdad(aux);
    //sal = emp_newProfesion(aux);
    //emp_newSalary(aux,sal);
    emp_setId(aux,id);
    emp_setState(aux,1);
    printf("\n|?| - Dar de alta la letra s/n: ");
    if(generic_confirmar()){
        lista->add(lista,aux);
        parseOut(lista,"out.csv"); //test 0026
    }
    generic_finFuncion();
}

void printline(int cant){int i;for(i=0;i<cant;i++){printf("%c",196);}}

/*
    MOSTRAR
*/

int emp_mostrarUno (sLetra* this){
    if(this!=NULL){
        //printf("\nID\t| DNI\t| Nombre\t| Apellido");
        //printf("\n%d\t| %d\t| %s\t| %s",emp_getId(this),emp_getSalary(this),emp_getName(this),emp_getProfesion(this));
        printf("\nLETRA\t| NOMBRE\t| VOCAL\t| CONSONANTE\n");
        printf("\n%c\t| %s\t| %d\t| %d\n",emp_getLetra(this),emp_getName(this),emp_getVocal(this),emp_getConsonante(this));
        return 1;
    }
    return 0;
}

int main_mostrarLista(ArrayList* lista){
    int i;
    int len;
    sLetra* aux;
    if(lista!=NULL){
        len=lista->len(lista);
        printline(60);
        printf("\nLETRA\t| NOMBRE\t| VOCAL\t| CONSONANTE\n");
        printline(60);
        for(i=0; i<len; i++){
            aux=lista->get(lista,i);
            if(emp_getState(aux)!=0){
                printf("\n%c\t| %s\t\t| %d\t| %d\n",emp_getLetra(aux),emp_getName(aux),emp_getVocal(aux),emp_getConsonante(aux));
            }
        }
        printf("\n");
        printline(60);
        printf("\n");
    }
}
