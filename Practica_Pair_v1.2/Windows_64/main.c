#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>
/*
    Vamos a usar esto que es lo que vamos a realizar para el tp4, parcial y final
    - Leer desde un archivo, generar punteros tipo empleado y guardarlos en una lista todo atraves de la array list
    - El ArrayList ya esta compilado y no podemos ver el codigo, solamente usarlo
    -



*/

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    //El arraylist gestiona direcciones de memoria
    //Como utilizar algunas funciones del arraylist
    ArrayList* lista;
    //Lo hago apuntar a una direccion de memoria: Usando la funcion
    // ... le estamos pidiendo memoria al SO para el ArrayList
    lista = al_newArrayList();
    //Creo un empleado
    Employee* e1;
    //Le asigno memoria
    //e1 = malloc(sizeof(Employee));
    e1 = (Employee*)malloc(sizeof(Employee));
    //Cargo valores para el empleado:
    e1->id = 666;
    strcpy( e1->name, "Mengano" );
    strcpy( e1->lastName, "Fulano" );
    e1->isEmpty = 1;

    //Pero esto esta totalmente di-sociado con el arraylist
    //Se lo agrego con la funcion: con la lista creada y el empleado:
    //... lo que hace es guardar la direccion de memoria donde eta en dato en el array
    al_add(lista,e1);

    //Ahora el reserverd size pasa a tener 1, de los 10 reservados. Leo la cantidad de elementos guardados
    // ... con la funcion al_len . La funcion devuelve el size
    int a;
    a = al_len(lista);
    printf("Size a: %d\n",a);

    //No puedo acceder directamente a la lista, hay que usar una funcion que me permita ver un elemento
    //... usamos la funcion al_get,
    Employee * eAux;
    //Lo guardo en una auxiliar
    eAux = (Employee*)al_get(lista,0);
    // Lo muestro usando la funcion
    employee_print(eAux);

    //Crear otro empleado y guardarlo en la lista:

    Employee * e2;

    e2 =  (Employee*)malloc(sizeof(Employee));
    e2->id = 332;
    strcpy( e2->name, "Benito" );
    strcpy( e2->lastName, "Kmela" );
    e2->isEmpty = 1;

    al_add(lista,e2);

    eAux = (Employee*)al_get(lista,1);
    employee_print(eAux);

    a = al_len(lista);
    printf("Size a: %d\n",a);

    //Print con for
    int i;
    for(i=0;i<2;i++){
        eAux=(Employee*)al_get(lista, i);
        employee_print(eAux);
    }


    //Para ordenar:



    return 0;
}
