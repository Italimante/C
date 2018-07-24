#ifndef STRUCTEMPLEADO_H_INCLUDED
#define STRUCTEMPLEADO_H_INCLUDED
#include "ArrayList.h"

typedef struct{
    char nombre[40]; //name
    char profesion[10];
    int edad;
    int salario; //salary
    int estado;
    int idEmpleado;
}sEmpleado;

/** \brief Asigna memoria para la estructura sEmpleado
 * \return eEmp* Dirección de memoria de la estructura
 */
sEmpleado * emp_newStruct();

/*
    FUNCION QUE FILTRA
*/
/** \brief Evalua empleado en base a un criterio (Mayor de 30, programador)
 *
 * \param empleado void*
 * \return int [1] si pasa el filtro, [0] si no, [-1] si es null
 */
int funcionQueFiltra(void* empleado);

 /*
    INGRESOS: PEDIR AL USUARIO
 */

/** \brief Pide al usuario el ingreso del nombre del empleado
 *
 * \param this sEmpleado* estructura empleado
 * \return int [1] si todo fue un éxito, [0] si recibe NULL (Al pedo porque hasta que no lo ingrese bien va repetir)
 */
int emp_newName(sEmpleado * this);

/** \brief pide ingresar una edad para empleado, entre 18 y 99.
 *
 * \param this sEmpleado* estructura empleado
 * \return int [1] si todo fue un éxito, [0] si recibe NULL (Al pedo porque hasta que no lo ingrese bien va repetir)
 */
int emp_newEdad(sEmpleado * this);

/** \brief pide seleccionar opcion de profesion para empleado
 *
 * \param this sEmpleado* estructura empleado
 * \return int numero de acuerdo a profesion para poder setear salario, [-1] si recibe NULL
 */
int emp_newProfesion(sEmpleado * this);

/** \brief setea un salario para empleado de acuerdo a la profesion
 *
 * \param this sEmpleado* estructura empleado, prof int indicador de profesion
 * \return int [1] si todo fue un éxito, [0] si recibe NULL (Al pedo porque hasta que no lo ingrese bien va repetir)
 */
int emp_newSalary(sEmpleado * this, int numeroProfesion);

 /*
    SETTERS
 */
/** \brief Setea nombre de empleado
 *
 * \param this sEmpleado* estructura empleado, nombre char*.
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setName(sEmpleado* this, char* nombre);

 /** \brief Setea nombre de empleado
 *
 * \param this sEmpleado* estructura empleado, profesion char*.
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setProfesion(sEmpleado* this, char* profesion);

/** \brief Setea salario de empleado
 *
 * \param this sEmpleado* estructura empleado, int salario.
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setSalary (sEmpleado* this, int salario);

/** \brief Setea salario de empleado
 *
 * \param this sEmpleado* estructura empleado, int edad.
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setEdad (sEmpleado* this, int edad);

 /** \brief Setea el id de un empleado
 *
 * \param this sEmpleado* estructura empleado,  id int* puntero a id autoincremental
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setId(sEmpleado* this,int* id);

/** \brief Setea el estado de un empleado
 *
 * \param this sEmpleado*
 * \param st int estado a setear
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setState(sEmpleado* this, int estado);

/*
    GETTERS
*/

/** \brief devuelve el nombre del empleado
 *
 * \param this sEmpleado* estructura empleado
 * \return char* nombre
 */
char* emp_getName (sEmpleado* this);

 /** \brief devuelve la profesion del empleado
 *
 * \param this sEmpleado* estructura empleado
 * \return char* profesion
 */
char* emp_getProfesion (sEmpleado* this);

/** \brief devuelve el salario del empleado
 *
 * \param this sEmpleado* estructura empleado
 * \return int salario
 */
int emp_getSalary(sEmpleado* this);

/** \brief devuelve el estado del empleado
 *
 * \param this sEmpleado* estructura empleado
 * \return int estado
 */
int emp_getState(sEmpleado* this);

/** \brief devuelve el id del empleado
 *
 * \param this sEmpleado* estructura empleado
 * \return int id
 */
int emp_getId(sEmpleado* this);

/** \brief devuelve la edad del empleado
 *
 * \param this sEmpleado*
 * \return int edad
 */
 int emp_getEdad(sEmpleado* this);

 /*
    GENERICO
 */

 /** \brief Imprime una linea horizontal
 *
 * \param cant int El largo de la linea
 * \return void
 *
 */
void printline(int cant);

 /** \brief muestra un menu principal generico
 * \param void
 * \return int opcion ingresada
 */
int generic_menu (void);

/** \brief agrega un "\n", pausa la aplicacion,
 * y limpia la pantalla al finalizar un case en el main
 * \param void
 * \return void
 */
void generic_finFuncion (void);

 /** \brief pide respuesta por si o por no
 * \param void
 * \return int [1] por si, [0] por no.
 */
int generic_confirmar(void);

/** \brief pide los datos para dar de alta un nuevo empleado
 *
 * \param socio ArrayList* lista de empleados
 * \param id int* puntero a id auto-incremental
 * \return void
 */
void generic_alta(ArrayList* lista, int* id);

/*
    MOSTRAR
*/

/** \brief muestra una estructura de empleado
 *
 * \param sEmpleado* this estructura a mostrar
 * \return int [1] Todo ok, [0] recibe NULL
 */
int emp_mostrarUno (sEmpleado* this);

/** \brief muestra una lista
 *
 * \param lista ArrayList*
 * \return int [1] Todo ok, [0] recibe NULL
 */
int main_mostrarLista(ArrayList* lista);


#endif // STRUCTEMPLEADO_H_INCLUDED
