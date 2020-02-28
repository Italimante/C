
typedef struct
{
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;
}eSerie;

void inicializarSeriesEstado(eSerie[], int);
void inicializarSeriesHardCode(eSerie[]);

/** \brief Muestra una sola serie
 *
 * \param aux eSerie recibe una estructura
 * \return void no retorna nada, sirve para imprimir UNA SOLA serie
 *
 */
void serie_mostrarUno(eSerie);

/** \brief
 *
 * \param eSerie[] eSerie recibe un listado de series, en este caso
 * \param int la cantidad de series que hay
 * \return void no retorna nada, muestra todas las series cargadas, hace uso de la funcion serie_MostrarUno
 *
 */
void serie_mostrarListado(eSerie[], int);

