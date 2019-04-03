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

int mov_loadBinFile(sMovie * this, int limit);
int mov_saveBinFile(sMovie * this, int limit);

/** \brief Genera una archivo html con las peliculas cargadas
 *
 * \param pMovies sMovie* Estructura donde estan almacenadas las peliculas
 * \param limit int Cantidad maxima
 * \return int 1 si todo sale bien, 0 si no se pudo generar, -1 si es puntero null
 *
 */
int mov_generateHtml(sMovie * pMovies, int limit);

/** \brief Eliminar una pelicula mediante estado
 *
 * \param pMovies sMovie* Estructura de peliculas
 * \param limit int Cantidad maxima
 * \return int 1 si fue posible, 0 si hubo error
 *
 */
int mov_deleteOne(sMovie * pMovies, int limit);

/** \brief Modificar una pelicula, buscar mediante le nombre
 *
 * \param pMovies sMovie* Estructura donde buscar
 * \param limit int Cantidad maxima
 * \return int 1 si esta todo ok, 0 si paso algo
 *
 */
int mov_changeOne(sMovie * pMovies, int limit);

/** \brief Agregar una nueva pelicula
 *
 * \param pMovies sMovie* Estructura donde se almacena las peliculas
 * \param limit int Cantidad maxima
 * \return int 1 si fue posible, -1 si no
 *
 */
int mov_newOne(sMovie * pMovies, int limit);

/** \brief Harcodea cuatro peliculas
 *
 * \param pMovies sMovie* Estructura donde harcodear
 * \param limit int Limite maximo
 * \return int 1 si todo sale bien, -1 si ta todo mal
 *
 */
int mov_hardData(sMovie * pMovies, int limit);

/** \brief Buscar una entidad por ID
 *
 * \param pMovies sMovie* Estructura a buscar
 * \param limit int Cantidad limite
 * \param id int ID a buscar
 * \return int El indice de cuando lo encuentra, si no existe -1
 *
 */
int mov_searchForId(sMovie * pMovies, int limit, int id);

/** \brief Busca el siguiente ID a utilizar
 *
 * \param pMovies sMovie* Puntero de una estructura
 * \param limit int Cantidad limite
 * \return int Retorna el siguiente ID para poder ser utilizado
 *
 */
int mov_nextId(sMovie * pMovies, int limit);

/** \brief Busca un espacio libre en una estructura
 *
 * \param pMovies sMovie* Puntero de una estructura
 * \param limit int Cantidad limite
 * \return int Retorna el espacio libre (indice) si es que lo encuentra o -1 si no encuentra nada
 *
 */
int mov_findFreePlace(sMovie * pMovies, int limit);

/** \brief Simplemente imprime el menu de la aplicacion
 *
 * \param void
 * \return void
 *
 */
void imprimirMenu(void);


/** \brief Imprime una linea horizontal
 *
 * \param c int Cantidad de lineas a imprimir
 * \return void
 *
 */
void printLine(int c);

/** \brief Para generar el "header" del html, bah, lo de arriba de la zona de las peliculas
 *
 * \param html FILE* Puntero de archivo
 * \return int 1 si esta todo bien, 0 si es null
 *
 */
int webTop(FILE * html);


/** \brief Para generar el "footer" del html
 *
 * \param html FILE* Puntero de archivo
 * \return int 1 si esta todo bien, 0 si es null
 *
 */
int webBottom(FILE * html);


/** \brief Inicializar estructura
 *
 * \param pMovies sMovie* Estructura a inicializar
 * \param limit int Cantidad maxima a inicializar
 * \return int 1 si esta todo ok, 0 si esta todo mal
 *
 */
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

/** \brief Primer letra mayusculas de un string y despues de espacios mayusculas tambien, el resto a minusculas.
 *
 * \param cadena char* Recibe la direccion de memoria de la cadena a convertir &
 * \return int Retorna -1 si el puntero es nulo, retorna 0 si no era necesaria la "convertibilidad", y 1 si salio todo bien
 *
 */
int capitalizeString(char *cadena);
