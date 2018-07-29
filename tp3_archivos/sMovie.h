#ifndef EMOVIE_H_INCLUDED
#define EMOVIE_H_INCLUDED
typedef struct{
    char title[50];
    char genre[25];
    float duration;
    char description[200];
    float ratingValue;
    char imgLink[200];
    int status;
    int id;
}sMovie;
#endif // EMOVIE_H_INCLUDED


void imprimirMenu(void);
void printLine(int c);
int webTop(FILE * html);
int webBottom(FILE * html);
int mov_init(sMovie * pMovies, int limit);


/** \brief Pide un string al usuario, no importa si ingresa numeros o caracteres especiales
 *
 * \param cadena char* Direccion de memoria donde guardar los datos &
 * \param mensaje[] char Mensaje a mostrar al usuario para que ingrese dato
 * \param largo int Limite maximo de la cadena
 * \param mensajeError[] char Mensaje de error cuando encuentra numeros o letras
 * \return int
 *
 */
int pedirStringConNumerosYcaracteres(char *cadena, char mensaje[], int largo, char mensajeError[]);

/** \brief Pide un string de solo letras al usuario, hace uso de las funciones stringSoloLetras y capitalizeString
 *
 * \param cadena char* Direccion de memoria donde guardar los datos &
 * \param mensaje[] char Mensaje a mostrar al usuario para que ingrese dato
 * \param largo int Limite maximo de la cadena
 * \param mensajeError[] char Mensaje de error cuando encuentra numeros o letras
 * \return int
 *
 */
int pedirStringSoloLetras(char *cadena, char mensaje[], int largo, char mensajeError[]);

/** \brief Comprueba que solo hayan letras a-z y A-Z en el string, no importa si es mayuscula o minuscula
 *
 * \param cadena[] char Recibe la cadena a revisar
 * \return int Retorna 1 si encontro algun numero o caracter distinto a a-z, y 0 si hay solo letras
 *
 */
int stringSoloLetras(char cadena[]);

/** \brief Primer letra mayusculas de un string, el resto a minusculas.
 *
 * \param cadena char* Recibe la direccion de memoria de la cadena a convertir &
 * \return int Retorna -1 si el puntero es nulo, retorna 0 si no era necesaria la "convertibilidad", y 1 si salio todo bien
 *
 */
int capitalizeString(char *cadena);
