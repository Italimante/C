#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#define TAMSERIE 20
#define TAMUSUARIO 100

int main()
{
    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];
    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);
    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

/*  1. Mostrar el listado de series                                         [V]
    2. Mostrar el listado de usuarios                                       [V]
    3. Mostrar el listado de Usuarios con el nombre de la serie que ve      [V]
    4. Mostrar por cada serie, el nombre de los usuarios que la ven.        [V]
*/
    printf("[1] LISTA DE SERIES:\n \n");
    serie_mostrarListado(listaDeSeries,TAMSERIE);
    printf("\n[2] LISTA DE USUARIOS:\n");
    usuario_mostrarLista(listaDeUsuarios,TAMUSUARIO);
    printf("\n[3] LISTA DE USUARIOS CON SERIE:\n--------------------------------\n");
    usuario_MostrarConSuSerie(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE);
    printf("\n[4] LISTA DE SERIES CON SUS USUARIOS:\n--------------------------------\n");
    serie_MostrarConUsuario(listaDeSeries,TAMSERIE,listaDeUsuarios,TAMUSUARIO);


    return 0;
}
