#ifndef STRUCTEMPLEADO_H_INCLUDED
#define STRUCTEMPLEADO_H_INCLUDED
#include "ArrayList.h"

typedef struct{
    char profesion[10];
    int edad;
    int salario; //salary
    int estado;
    int idEmpleado;
    // -----------------------
    char letra;
    char nombre[21]; //name
    int vocal;
    int consonante;
}sLetra;

//1 si es vocal, 0 si es consonante
int emp_comprobarVocalConsonante(letra);

int emp_getConsonante(sLetra* this);
int emp_getVocal(sLetra* this);
char* emp_getLetra (sLetra* this);

int emp_setLetra (sLetra* this, char letra);
int emp_setConsonante (sLetra* this, int consonante);
int emp_setVocal (sLetra* this, int vocal);

sLetra * emp_newConsonante (sLetra * this);
sLetra * emp_newVocal (sLetra * this);
sLetra * emp_newLetra (sLetra * this);

/** \brief Asigna memoria para la estructura sLetra
 * \return eEmp* Dirección de memoria de la estructura
 */
sLetra * emp_newStruct();

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
 * \param this sLetra* estructura empleado
 * \return int [1] si todo fue un éxito, [0] si recibe NULL (Al pedo porque hasta que no lo ingrese bien va repetir)
 */
int emp_newName(sLetra * this);

/** \brief pide ingresar una edad para empleado, entre 18 y 99.
 *
 * \param this sLetra* estructura empleado
 * \return int [1] si todo fue un éxito, [0] si recibe NULL (Al pedo porque hasta que no lo ingrese bien va repetir)
 */
int emp_newEdad(sLetra * this);

/** \brief pide seleccionar opcion de profesion para empleado
 *
 * \param this sLetra* estructura empleado
 * \return int numero de acuerdo a profesion para poder setear salario, [-1] si recibe NULL
 */
int emp_newProfesion(sLetra * this);

/** \brief setea un salario para empleado de acuerdo a la profesion
 *
 * \param this sLetra* estructura empleado, prof int indicador de profesion
 * \return int [1] si todo fue un éxito, [0] si recibe NULL (Al pedo porque hasta que no lo ingrese bien va repetir)
 */
int emp_newSalary(sLetra * this, int numeroProfesion);

 /*
    SETTERS
 */
/** \brief Setea nombre de empleado
 *
 * \param this sLetra* estructura empleado, nombre char*.
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setName(sLetra* this, char* nombre);

 /** \brief Setea nombre de empleado
 *
 * \param this sLetra* estructura empleado, profesion char*.
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setProfesion(sLetra* this, char* profesion);

/** \brief Setea salario de empleado
 *
 * \param this sLetra* estructura empleado, int salario.
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setSalary (sLetra* this, int salario);

/** \brief Setea salario de empleado
 *
 * \param this sLetra* estructura empleado, int edad.
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setEdad (sLetra* this, int edad);

 /** \brief Setea el id de un empleado
 *
 * \param this sLetra* estructura empleado,  id int* puntero a id autoincremental
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setId(sLetra* this,int* id);

/** \brief Setea el estado de un empleado
 *
 * \param this sLetra*
 * \param st int estado a setear
 * \return int [1] Si sale todo bien, [0] si recibe un puntero NULL
 */
int emp_setState(sLetra* this, int estado);

/*
    GETTERS
*/

/** \brief devuelve el nombre del empleado
 *
 * \param this sLetra* estructura empleado
 * \return char* nombre
 */
char* emp_getName (sLetra* this);

 /** \brief devuelve la profesion del empleado
 *
 * \param this sLetra* estructura empleado
 * \return char* profesion
 */
char* emp_getProfesion (sLetra* this);

/** \brief devuelve el salario del empleado
 *
 * \param this sLetra* estructura empleado
 * \return int salario
 */
int emp_getSalary(sLetra* this);

/** \brief devuelve el estado del empleado
 *
 * \param this sLetra* estructura empleado
 * \return int estado
 */
int emp_getState(sLetra* this);

/** \brief devuelve el id del empleado
 *
 * \param this sLetra* estructura empleado
 * \return int id
 */
int emp_getId(sLetra* this);

/** \brief devuelve la edad del empleado
 *
 * \param this sLetra*
 * \return int edad
 */
 int emp_getEdad(sLetra* this);

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
 * \param sLetra* this estructura a mostrar
 * \return int [1] Todo ok, [0] recibe NULL
 */
int emp_mostrarUno (sLetra* this);

/** \brief muestra una lista
 *
 * \param lista ArrayList*
 * \return int [1] Todo ok, [0] recibe NULL
 */
int main_mostrarLista(ArrayList* lista);


#endif // STRUCTEMPLEADO_H_INCLUDED
