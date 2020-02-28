#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"

/** \brief ingresa datos desde un archivo hacia un array de estructuras
 * \param lista ArrayList*
 * \return int ultimo id de empleado para poder igresar uno nuevo en caso de que sea necesario
 */ int parseIn(ArrayList* lista,char nombreArchivo[]);

 /** \brief egresa datos desde un array de estructura hacia un archivo .csv
 * \param lista ArrayList*
 * \return void
 */ void parseOut(ArrayList* lista,char nombreArchivo[]);

#endif // PARSER_H_INCLUDED
