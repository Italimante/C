#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    //Primero castear ambos emleados de void
    Employee * a;
    Employee * b;
    //Los convierto a empleados
    a = (Employee*)pEmployeeA;
    b = (Employee*)pEmployeeB;

    /*
    //Ordeno por ID
    if( a->id > b->id ){
        return 1;
    }
    if( a->id < b->id ){
        return -1;
    }*/

    //Ordeno por nombre
    int retorno;
    retorno = strcmp( a->name, b->name );

    return retorno;
}


void employee_print(Employee* this)
{
    printf("%s %s %d\n", this->name, this->lastName, this->id);
}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    //El malloc deberia ir aca

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


