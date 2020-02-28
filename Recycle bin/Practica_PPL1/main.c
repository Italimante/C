#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eUsuario.h"
#include "eProducto.h"
#include "eVenta.h"
#define CANT 50

int main()
{
    eUsuario listaDeUsuarios[CANT];
    eUsua_init(listaDeUsuarios,CANT);
    eUsua_harcodearDatos(listaDeUsuarios);










    return 0;
}
