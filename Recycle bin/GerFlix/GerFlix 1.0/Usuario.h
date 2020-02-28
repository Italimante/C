#include "Serie.h"

typedef struct
{
    int idUsuario;
    char nombre[50];
    int idSerie;
    int estado;
}eUsuario;

void serie_MostrarConUsuario(eSerie[], int, eUsuario[], int);

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);

void usuario_mostrarUno(eUsuario);
void usuario_mostrarLista(eUsuario[], int);
void usuario_MostrarConSuSerie(eUsuario[], int, eSerie[], int);
