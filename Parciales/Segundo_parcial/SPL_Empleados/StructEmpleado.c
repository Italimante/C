#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "inc/StructEmpleado.h"
//#include "inc/ArrayList.h"

sEmpleado * emp_newStruct(){
    return (sEmpleado*)malloc(sizeof(sEmpleado));
}

/*
    FUNCION QUE FILTRA
*/
int funcionQueFiltra(void* empleado){
    int retorno = -1; //test 0028
    sEmpleado* auxEmp;
    auxEmp = (sEmpleado*)empleado;

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

int emp_newName(sEmpleado * this){
    char aux[40];
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

 int emp_newEdad(sEmpleado * this){
    int aux;
    if(this!=NULL){
        do{
            aux=entero_get("edad");
        }while(!entero_validaRango(aux,"edad",18,99));
        this->edad=aux;
        return 1;
    }
    return 0;
 }

int emp_newProfesion(sEmpleado * this){
    int opcion = -1;
    if(this!=NULL){
        printf("\n|!| - Ingrese la profesion del nuevo empleado: \n[1] - Analista\n[2] - Programador\n[3] - Tester\n");
        opcion = entero_get("opcion");

        switch(opcion){
        case 1:
            strcpy(this->profesion,"Analista");
            break;
        case 2:
            strcpy(this->profesion,"Programador");
            break;
        case 3:
            strcpy(this->profesion,"Tester");
            break;
        }

    }
    return opcion;
}

int emp_newSalary(sEmpleado * this, int numeroProfesion){
    if(this!=NULL){
        switch(numeroProfesion){
        case 1:
            this->salario = 15000;
            break;
        case 2:
            this->salario = 20000;
            break;
        case 3:
            this->salario = 10000;
            break;
        }
    }
}

 /*
    SETTERS
 */

int emp_setName(sEmpleado* this, char* nombre){
    if(this!=NULL && nombre!=NULL){
        strcpy(this->nombre,nombre);
        return 1;
    }
    return 0;
}

int emp_setProfesion(sEmpleado* this, char* profesion){
    if(this!=NULL && profesion!=NULL){
        strcpy(this->profesion,profesion);
        return 1;
    }
    return 0;
}

int emp_setSalary (sEmpleado* this, int salario){
    if(this!=NULL){
        this->salario=salario;
        return 1;
    }
    return 0;
}

int emp_setEdad (sEmpleado* this, int edad){
    if(this!=NULL){
        this->edad=edad;
        return 1;
    }
    return 0;
}

int emp_setId(sEmpleado* this,int* id){
    if(this!=NULL && id!=NULL){
        this->idEmpleado=*id;
        return 1;
    }
    return 0;
}

int emp_setState(sEmpleado* this, int estado){
    if(this!=NULL){
        this->estado=estado;
        return 1;
    }
    return 0;
}

/*
    GETTERS
*/

char* emp_getName (sEmpleado* this){
    char* aux=NULL;
    if(this!=NULL){
        aux=this->nombre;
    }
    return aux;
}

char* emp_getProfesion (sEmpleado* this){
    char* aux=NULL; //Test 0025
    if(this!=NULL){
        aux=this->profesion;
    }
    return aux;
}

int emp_getSalary(sEmpleado* this){
    int aux; //Test 0026
    if(this!=NULL){
        aux=this->salario;
    }
    return aux;
}

int emp_getState(sEmpleado* this){
    int estado;
    if(this!=NULL){
        estado=this->estado;
    }
    return estado;
}

int emp_getId(sEmpleado* this){
    int id;
    if(this!=NULL){
        id=this->idEmpleado;
    }
    return id;
}

int emp_getEdad(sEmpleado* this){
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
    printf("\n GESTION DE EMPLEADOS\n");
    printline(60);
    printf("\n|1|. Alta");
    printf("\n|2|. Filtrar programadores mayores de 30 a%cos",164);
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
    sEmpleado * aux = emp_newStruct(); //Test 0027
    int sal;
    system("cls");
    printf("\n|!| - Alta de empleado\n");
    emp_newName(aux);
    emp_newEdad(aux);
    sal=emp_newProfesion(aux);
    emp_newSalary(aux,sal);
    emp_setId(aux,id);
    emp_setState(aux,1);
    printf("\n|?| - Dar de alta empleado? s/n: ");
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

int emp_mostrarUno (sEmpleado* this){
    if(this!=NULL){
        printf("\nID\t| DNI\t| Nombre\t| Apellido");
        printf("\n%d\t| %d\t| %s\t| %s",emp_getId(this),emp_getSalary(this),emp_getName(this),emp_getProfesion(this));
        return 1;
    }
    return 0;
}

int main_mostrarLista(ArrayList* lista){
    int i;
    int len;
    sEmpleado* aux;
    if(lista!=NULL){
        len=lista->len(lista);
        printline(60);
        printf("\nID\t| Salario\t| Profesion\t| Edad\t| Nombre\n");
        printline(60);
        for(i=0; i<len; i++){
            aux=lista->get(lista,i);
            if(emp_getState(aux)!=0){
                printf("\n%d\t| $%d\t| %s\t| %d\t| %s",emp_getId(aux),emp_getSalary(aux),emp_getProfesion(aux),emp_getEdad(aux),emp_getName(aux));
            }
        }
        printf("\n");
        printline(60);
        printf("\n");
    }
}
