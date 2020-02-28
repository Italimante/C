#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

/** \brief Arranca el algoritmo de la calculadora
 *
 * \param void
 * \return void
 *
 */
void startCalculadora(void);

/** \brief La calculadora en si
 *
 * \param void
 * \return void
 *
 */
void showMenu(void);

/** \brief Pide un numero al usuario
 *
 * \param char[] Mensaje a mostrar al usuario
 * \return int El numero que ingreso el usuario
 *
 */
int pedirNumero(char[]);

/** \brief Suma dos valores
 *
 * \param Recibe dos enteros
 * \return Devuelve el resultado de la suma de dos enteros
 *
 */
int suma(int,int);

/** \brief Resta dos valores
 *
 * \param Recibe dos enteros
 * \return Devuelve el resultado de una resta de dos enteros
 *
 */
int resta(int,int);

/** \brief Divide dos enteros
 *
 * \param Recibe dos enteros, no comprueba si recibe un cero, debe realizarse antes de recibir valores
 * \return Devuelve como resultado la division de ambos enteros
 *
 */
float division(int,int);

/** \brief Multiplica dos enteros
 *
 * \param Recibe dos enteros y los multiplica
 * \return  Devuelve como resultado la multiplicacion de ambos enteros como flotante
 *
 */
int multiplicar(int,int);

/** \brief Realiza el factorial de un entero
 *
 * \param Recibe un entero, realiza correctamente el factorial de un numero igual o menor a 12 (los limites del valor que reciba son ajenos a la funcion)
 * \return Devuelve como entero el resultado del factorial
 *
 */
int factorial(int);

/** \brief Comprueba que un string solo contenga numeros
 *
 * \param this char*
 * \return int 1 si hay solo numeros, de lo contrario NULL
 *
 */
int stringSoloNumeros(char * this);

#endif // FUNCTIONS_H_INCLUDED
