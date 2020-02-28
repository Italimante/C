#ifndef EPERSONA_H_INCLUDED
#define EPERSONA_H_INCLUDED
typedef struct{
    char nombre[50];
    int edad;
    long int dni;
    int estado;
    int id;
}ePersona;

#endif // EPERSONA_H_INCLUDED

//aca declaro los funciones
int per_modificarNombre(ePersona listado[],int limite); //funciona, pero esta mal hecha, no hace uso de return
int per_buscarEnteroEnEdad(ePersona personas[], int cantP, int entero);
int per_mostrarListadoConBorrados(ePersona listado[],int limite);
int per_buscarPorId(ePersona [] ,int , int);
int per_siguienteId(ePersona [],int);
void per_ordenarPorEdad(ePersona [], int);
void per_ordenarPorId(ePersona [], int);

/** \brief Solamente contiene print's para mostrar el menu
 *
 * \return void
 *
 */
void mostrarMenu();

/** \brief Mustra una sola persona de una estructura
 *
 * \param ePersona
 * \return void
 *
 */
void per_mostrarUno(ePersona);


/** \brief Imprime una lista de personas, hace uso de la funcion mostrar_Uno
 *
 * \param [] ePersona
 * \param int
 * \return void
 *
 */
void per_mostrarLista(ePersona [], int );


/** \brief Se que no era necesario, y deberia borrarlo, pero lo deje, harcodea 10 personas. No acumulativo. Y sobre-pisa otros datos
 *
 * \param [] ePersona
 * \return void
 *
 */
void per_harcodearDatos(ePersona [], int);


/** \brief Inicializa el estado del array personas en 0
 *
 * \param [] ePersona
 * \param int
 * \return void
 *
 */
void per_incializarEstado(ePersona [], int);


/** \brief Ordena alfabeticamente la estructura
 *
 * \param [] ePersona
 * \param int
 * \return void
 *
 */
void per_ordenarPorNombre(ePersona [], int);


/** \brief Busca una posicion libre para agregar una persona, hace uso de la funcion pedirDato si encuentra un lugar
 *
 * \param [] ePersona
 * \param int
 * \param [] char
 * \return void
 *
 */
void per_agregarPersona(ePersona [], int, char []);


/** \brief Pide datos al usuario para agregarlos en la estructura de persona
 *
 * \param ePersona[]
 * \param int
 * \param int
 * \return void
 *
 */
void per_pedirDato(ePersona[],int,int);


/** \brief Busca un entero dentro de una estructura, en este caso lo uso para buscar un estado
 *
 * \param [] ePersona
 * \param int
 * \param int
 * \return int Devuelve el indice donde esta el entero a buscar, si es que lo encuentra, de lo contrario -1
 *
 */
int per_buscarEnteroEnEstado(ePersona [], int, int);


/** \brief Modifica el estado a 0 de una persona, TIENE UN ERROR: Si hay dos personas con el mismo nombre, elimina el primero en encontrar,
medio burocratico fixear esto, pero va ser un buen ejercicio para hacer
 *
 * \param [] ePersona
 * \param int
 * \param [] char
 * \return void
 *
 */
void per_borrarPersonaPorNombre(ePersona [], int , char []);


/** \brief Imprime el grafico de edades en horizontal, en vertical hasta ahora no lo pude hacer y si estas leyendo esto es porque no me salio :(
 *
 * \param [] ePersona
 * \param int
 * \return void
 *
 */
void per_imprimirGraficoHorizontal(ePersona [], int);
