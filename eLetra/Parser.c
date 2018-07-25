#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "inc/Parser.h"
#include "inc/ArrayList.h"
#include "inc/StructEmpleado.h"

int parseIn(ArrayList* lista,char nombreArchivo[]){
    FILE* archivo;
    sLetra* empAux;
    int id=0;
    char letra;
    int vocal;
    int consonante;
    char nombre[21];
    int comprobar;
    //int estado, edad, salario;
    //char profesion[40];
    archivo = fopen(nombreArchivo,"r");
    if(archivo!=NULL && lista!=NULL){
        do{
            empAux=emp_newStruct();
            //fscanf(archivo,"%d,%d,%d,%d,%[^,],%[^\n]\n",&id,&estado,&salario,&edad,profesion,nombre);
            fscanf(archivo,"%c,%[^,],%d,%d\n",&letra,nombre,&vocal,&consonante);
            emp_setId(empAux,&id);
            emp_setState(empAux,1);
            emp_setName(empAux,nombre);
            //emp_setVocal(empAux,vocal);
            //emp_setConsonante(empAux,consonante);
            emp_setLetra(empAux,letra);

            comprobar = emp_comprobarVocalConsonante(letra){
                if(comprobar){
                    emp_setVocal(empAux,vocal);
                }else{
                    emp_setConsonante(empAux,consonante);
                }
            }


            //emp_setProfesion(empAux,profesion);
            //emp_setSalary(empAux,salario);
            //emp_setEdad(empAux,edad);
            lista->add(lista,empAux);
        }while(!feof(archivo));
        //printf("\n|!| - Exito: Se pudo leer el archivo con exito\n");
    }else{
        printf("\n|X| - Error: No se pudo leer el archivo o esta vacio\n");
    }
    fclose(archivo);

    return id;
}

void parseOut(ArrayList* lista,char nombreArchivo[]){
    sLetra* auxEmp;
    FILE* archivo;
    int i;
    if(lista!=NULL){
        archivo=fopen(nombreArchivo,"w");
        if(archivo!=NULL){
            for(i=0; i<lista->len(lista); i++){
                auxEmp = (sLetra*) lista->get(lista,i);
                fprintf(archivo,"%c,%s,%d,%d\n",emp_getLetra(auxEmp),emp_getName(auxEmp),emp_getVocal(auxEmp),emp_getConsonante(auxEmp));
                //fprintf(archivo,"%d,%d,%d,%d,%s,%s\n",emp_getId(auxEmp),emp_getState(auxEmp),emp_getSalary(auxEmp),emp_getEdad(auxEmp),emp_getProfesion(auxEmp),emp_getName(auxEmp));
            }
        }
        printf("|!| - Exito: Se pudo generar el archivo con exito\n");
        fclose(archivo);
    }else{
        printf("|X| - Error: No se pudo generar un archivo.");
    }
    fclose(archivo);
}
