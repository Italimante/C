#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
typedef struct{
    char patente[4];
    int marca;
    int idAuto;
    int idProp;
    int estado;
    int horas; //Nota arriba ^
}eAuto;
#endif // AUTO_H_INCLUDED

/*
    Problema:
    - Tuve que comentar varias funciones que utilizan la estructura de Propietarios, ya que no las reconoce como existente.
*/

/** \brief Imprime un mini cuadro de marcas
 *
 * \return void
 *
 */
void auto_cuadroMarcas();
/** \brief Ordena por patente los vehiculos
 *
 * \param listadoA[] eAuto - Array de estructura auto
 * \param cantA int - Cantidad maxima de auto
 * \return int 1 si todo bien, 0 si no se pudo
 *
 */
int ordenarPorPatente(eAuto listadoA[], int cantA);
/** \brief Muestra una lista de vehiculos con sus propietarios
 *
 * \param listadoA[] eAuto - Array de estructuras auto
 * \param cantA int - Cantidad maxima de la estructura auto
 * \param listadoP[] eProp - Array de estructura propietario
 * \param cantP int - Cantidad maxima de autos
 * \return int 1 si todo bien, 0 si todo mal
 *
 */
//int auto_mostrarListaConPropietarios(eAuto listadoA[],int cantA, eProp listadoP[], int cantP);
/** \brief Muestra la recaudacion total dependiendo de la marca
 *
 * \param listaA[] - eAuto Array de estructura auto
 * \param cantA int - Cantidad maxima de autos
 * \return int 1 si todo bien, 0 si todo mal
 *
 */
int auto_recaudacionTotalMarca(eAuto listaA[], int cantA);
/** \brief Muestra la recaudacion total, tomando las horas de la estructura de los autos
 *
 * \param listaA[] eAuto - Array de estructura auto
 * \param cantA int - Cantidad maxima de autos
 * \return int - 1 si todo bien, 0 si todo mal
 *
 */
int auto_recaudacionTotal(eAuto listaA[], int cantA);
/** \brief Cuando un auto egresa del estacionamiento,
 *
 * \param listaA[] eAuto - Array de estructura auto
 * \param cantA int - Cantidad maxima de propietarios
 * \param listadoP[] eProp - Array de estructura propietario
 * \param cantP int - Cantidad maxima de autos
 * \return int - 1 si todo bien, 0 si todo mal
 *
 */
//int auto_egresoAuto(eAuto listaA[], int cantA, eProp listadoP[], int cantP);
/** \brief Para ingresar un nuevo auto al sistema
 *
 * \param listadoA[] eAuto - Array de estructura auto
 * \param cantA int - Cantidad maxima de autos
 * \param listadoP[] eProp - Array de estructura propietario
 * \param cantP int - Cantidad maxima de propietarios
 * \return void
 *
 */
//void auto_ingresarNuevo(eAuto listadoA[], int cantA, eProp listadoP[], int cantP);
/** \brief Muestra un solo vehiculo
 *
 * \param listado eAuto
 * \return void
 *
 */
void auto_mostrarUno(eAuto listado);
/** \brief Muestra una lista de vehiculos
 *
 * \param listado[] eAuto
 * \param cant int
 * \return void
 *
 */
void auto_mostrarLista(eAuto listado[], int cant);
/** \brief Agrega 10 vehiculos, incrementable
 *
 * \param listado[] eAuto
 * \param cant int
 * \return void
 *
 */
void auto_harcodearDatos(eAuto listado[], int cant);
/** \brief Busca un entero en .estado de una estructura
 *
 * \param listado[] eAuto
 * \param cantP int
 * \param lugar int
 * \return int
 *
 */
int auto_buscarEnteroEnEstado(eAuto listado[], int cantP, int lugar);
/** \brief Siguiente ID libre de una estructura
 *
 * \param listado[] eAuto
 * \param cant int
 * \return int
 *
 */
int auto_siguienteId(eAuto listado[],int cant);
/** \brief Iniciar estados del arrayE
 *
 * \param listado[] eAuto
 * \param cant int
 * \return int
 *
 */
int auto_iniciarEstados(eAuto listado[], int cant);
/** \brief Para buscar un ID en una estructura
 *
 * \param listado[] eAuto
 * \param cant int
 * \param entero int
 * \return int
 *
 */
int auto_buscarEnteroId(eAuto listado[], int cant, int entero);
