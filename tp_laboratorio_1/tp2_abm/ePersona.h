#ifndef EPERSONA_H_INCLUDED
#define EPERSONA_H_INCLUDED
typedef struct{
    char nombre[50];
    int edad;
    long int dni;
    int estado;
}ePersona;

#endif // EPERSONA_H_INCLUDED

//aca declaro los funciones
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
void per_harcodearDatos(ePersona []);


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
int per_buscarEntero(ePersona [], int, int);


/** \brief Modifica el estado a 0 de una persona
 *
 * \param [] ePersona
 * \param int
 * \param [] char
 * \return void
 *
 */
void per_borrarPersona(ePersona [], int , char []);


/** \brief Imprime el grafico de edades en horizontal, en vertical hasta ahora no lo pude hacer y si estas leyendo esto es porque no me salio :(
 *
 * \param [] ePersona
 * \param int
 * \return void
 *
 */
void per_imprimirGraficoHorizontal(ePersona [], int);
