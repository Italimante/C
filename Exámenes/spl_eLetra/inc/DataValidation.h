#ifndef DATAVALIDATION_H_INCLUDED
#define DATAVALIDATION_H_INCLUDED

/*
    GET STRING
*/
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
 void string_get(char mensaje[],char input[]);

  /**
 * \brief Solicita un texto numerico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */
 int string_getNumerico(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return [1] si cumple, [0] si no
 */
 int string_getLetras(char mensaje[],char input[]);

/*
    VALIDAR STRING
*/
/** \brief verifica si un dato ingresado está vacío o no
 * \param char value es el valor a analizar
 * \return [1] si cumple, [0] si no
 */
 int string_isNull (char value);

 /**
 * \brief Verifica si el valor recibido es numérico
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */
 int string_esNumerico(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param array Array con la cadena a ser analizada
 * \return [1] si cumple, [0] si no
 */
 int string_esSoloLetras(char array[]);

 /** \brief Valida un string dentro de un rango
 *
 * \param str[] String a evaluar
 * \param min int Valor minimo, max int Valor maximo
 * \return int [1] Si está dentro del rango, [0] Si está fuera del rango
 */
 int string_validaRango(char str[], int min, int max);

 /*
    ENTEROS
 */
 /**
 * \brief Verifica si la cadena ingresada es numerica y de no serlo muestra mensaje de error
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 */
 int entero_get(char mensaje[]);

/** \brief Valida un entero dentro de un rango
 *
 * \param int Dato a evaluar
 * \param mensaje[] char Muestra el dato ingresado
 * \param min int Valor minimo, max int Valor maximo
 * \return int [1] Si está dentro del rango, [0] Si está fuera del rango
 */
 int entero_validaRango(int dato, char mensaje[], int min, int max);




#endif // DATAVALIDATION_H_INCLUDED
