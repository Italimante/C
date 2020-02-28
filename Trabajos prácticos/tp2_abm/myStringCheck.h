#ifndef MYSTRINGCHECK_H_INCLUDED
#define MYSTRINGCHECK_H_INCLUDED

int comprobarCadena(char * this, int largoMax, int opcion);

/** \brief Comprueba que un string solo contenga letras
 *
 * \param this char*
 * \return int 1 si hay solo letras, de lo contrario NULL
 *
 */
int stringSoloLetras(char * this);

/** \brief Comprueba que un string solo contenga numeros
 *
 * \param this char*
 * \return int 1 si hay solo numeros, de lo contrario NULL
 *
 */
int stringSoloNumeros(char * this);


#endif // MYSTRINGCHECK_H_INCLUDED
