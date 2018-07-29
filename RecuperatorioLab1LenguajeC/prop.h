#ifndef PROP_H_INCLUDED
#define PROP_H_INCLUDED
typedef struct{
    char nombre[20];
    char apellido[20];
    char direccion[20];
    char tarjeta[20];
    int estado;
    int idProp;
    int edad;
}eProp;
#endif // PROP_H_INCLUDED

//int prop_borrarPropietario(eProp listado[], int cant);

/*
    NOTA EGRESO:
    - Le pongo de estado EGRESADO, asi no tengo que crear otra estructura donde copiar los egresados


*/

/** \brief Ordena los propietarios de manera descendente
 *
 * \param listadoP[] eProp - Recibe un array de estructuras
 * \param cantP int - Tamanio limite del array
 * \return int 1 si hubo exito, 0 si no hubo exito
 *
 */
int prop_ordenarPorNombreD(eProp listadoP[], int cantP);

/** \brief Da de baja un propietario e imprime el ticket
 *
 * \param listado[] eProp - Recibe un array de estructuras
 * \param cant int - Recibe la cantidad limite de propietarios
 * \param listadoA[] eAuto - Recibe un array de estructuras
 * \param cantA int - Recibe la cantidad limite de autos
 * \return int 1 si todo salio bien, 0 si todo salio mal
 *
 */
//int prop_borrarPropietario(eProp listado[], int cant, eAuto listadoA[], int cantA);
/** \brief Devuelve una hora al azar
 *
 * \return int La hora al azar
 *
 */
int devolverHorasEstadia();
/** \brief Muestra todos los autos y sus propietarios
 *
 * \param listadoP[] eProp - Recibe un array de estructuras
 * \param cantP int - Cantidad maxima de propietarios
 * \param listadoA[] eAuto - Recibe un array de estructuras
 * \param cantA int - Cantidad maxima de autos
 * \return int 1 si todo sale bien, 0 si esta todo mal
 *
 */
//int prop_informarAutos(eProp listadoP[], int cantP, eAuto listadoA[], int cantA);
/** \brief Muestra solamente los autos de marca Audi y su propietario
 *
 * \param listadoP[] eProp - Recibe un array de estructuras
 * \param cantP int - Cantidad maxima de propietarios
 * \param listadoA[] eAuto - Recibe un array de estructuras
 * \param cantA int - Cantidad maxima de autos
 * \return int 1 si todo sale bien, 0 si todo sale mal
 *
 */
//int prop_todosAudi(eProp listadoP[], int cantP, eAuto listadoA[], int cantA);
/** \brief Imprime una carita triste, si, en vez de validar input's me puse a desperdiciar tiempo en una carita
 *
 * \param void
 * \return void
 *
 */
void printSadFace(void);
/** \brief Muestra la lista de todos los propietarios disponibles
 *
 * \param listado[] eProp - Recibe un array de estructuras
 * \param cant int - Cantidad maxima de propietarios
 * \return void
 *
 */
void prop_mostrarLista(eProp listado[], int cant);
/** \brief Muestra un solo propietario
 *
 * \param listado eProp - Recibe una estructura
 * \return void
 *
 */
void prop_mostrarUno(eProp listado);
/** \brief Pide datos que va enviar en la estructura
 *
 * \param listado[] eProp - Recibe un array de estructuras
 * \param cant int
 * \param posicion int
 * \return void
 *
 */
void prop_pedirDatos(eProp listado[],int cant,int posicion);
/** \brief Para agregar datos de propietario
 *
 * \param listado[] eProp
 * \param cant int
 * \param mensajeError[50] char
 * \return void
 *
 */
void prop_agregarPropietario(eProp listado[], int cant, char mensajeError[50]);
/** \brief Busca un id en una estructura
 *
 * \param listado[] eProp
 * \param cant int
 * \param auxId int
 * \return int
 *
 */
int prop_buscarId(eProp listado[], int cant, int auxId);
/** \brief Para modificar la tarjeta de un propietario
 *
 * \param listado[] eProp
 * \param cant int
 * \return int
 *
 */
int prop_modificarTarjetaPropietario(eProp listado[], int cant);
/** \brief Inicia los estados del array estructura
 *
 * \param listado[] eProp
 * \param cant int
 * \return int
 *
 */
int prop_iniciarEstados(eProp listado[], int cant);
/** \brief Siguiente ID disponible en la estructura
 *
 * \param listado[] eProp
 * \param cant int
 * \return int
 *
 */
int prop_siguienteId(eProp listado[],int cant);

/** \brief Busca un entero en estado, en este caso esta para buscar un estado libre
 *
 * \param listado[] eProp
 * \param cantP int
 * \param lugar int
 * \return int
 *
 */
int prop_buscarEnteroEnEstado(eProp listado[], int cantP, int lugar);
/** \brief Agrega 10 propietarios, es incrementable
 *
 * \param listado[] eProp Estructura donde enviar los datos
 * \param cant int Limite del array
 * \return void
 *
 */
void prop_harcodearDatos(eProp listado[], int cant);
/** \brief Imprime una linea horizontal
 *
 * \param cant int El largo de la linea
 * \return void
 *
 */
void printline(int cant);
/** \brief Muestra simplemente un menu
 *
 * \return void
 *
 */
void mostrarMenu();

