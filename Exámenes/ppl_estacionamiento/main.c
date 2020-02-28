#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prop.h"
#include "auto.h"
#define SIZE_PROP 20
#define SIZE_AUTO 20
#define SIZE_ESTACIONAMIENTO 20

int main()
{
    int loop = 1;
    int opcion;
    int flag = 0;
    int flagB = 0;
    char auxC;

    //Iniciar lista de propietarios
    eProp listadoProp[SIZE_PROP];
    prop_iniciarEstados(listadoProp,SIZE_PROP);

    //Iniciar lista de autos
    eAuto listaAuto[SIZE_AUTO];
    auto_iniciarEstados(listaAuto,SIZE_AUTO);
    /*
    ///TEST:
    prop_harcodearDatos(listadoProp,SIZE_PROP);
    prop_harcodearDatos(listaAuto,SIZE_PROP);
    int test;
    test = prop_buscarId(listadoProp, SIZE_PROP, 1);
    printf("- - - [TEST] Que ID devuelve buscarID si le entrego '1': %d\n",test);
    test = prop_buscarId(listadoProp, SIZE_PROP, 2);
    printf("- - - [TEST] Que ID devuelve buscarID si le entrego '2': %d\n",test);


    ///END TEST
    */
    do{
        mostrarMenu();
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion){
            case 1: //Agregar un propietario
                system("cls");
                prop_agregarPropietario(listadoProp, SIZE_PROP, "\n |X| - Error: Espacio insuficiente\n");
                flag = 1;
                break;
            case 2://Borrar un propietario
                system("cls");
                if(flag == 0){
                    printf("|X| - Error: No hay propietarios cargadados para borrar\n");
                }else{
                    prop_mostrarLista(listadoProp,SIZE_PROP);
                    prop_borrarPropietario(listadoProp, SIZE_PROP,listaAuto,SIZE_AUTO);
                }
                break;
            case 3://Modificar un propietario
                system("cls");
                if(flag == 0){
                    printf("|X| - Error: No hay propietarios cargadados para modificar\n");
                }else{
                    prop_mostrarLista(listadoProp,SIZE_PROP);
                    prop_modificarTarjetaPropietario(listadoProp,SIZE_PROP);
                }
                break;
            case 4://Mostrar propietarios
                system("cls");
                if(flag == 0){
                    printf("|X| - Error: No hay propietarios cargados para mostrar\n");
                }else{
                    printf("|!| - En que orden lo quiere ordenar? [1/2]\n [1] - Ascendente\n [2] - Descendente\n");
                    scanf("%c",&auxC);
                    fflush(stdin);
                    if(auxC == '1'){
                        prop_ordenarPorNombreA(listadoProp,SIZE_PROP);
                        prop_mostrarLista(listadoProp,SIZE_PROP);
                    }else if(auxC == '2'){
                        prop_ordenarPorNombreD(listadoProp,SIZE_PROP);
                        prop_mostrarLista(listadoProp,SIZE_PROP);
                    }else{
                        printf("|X| - Error: Opcion incorrecta\n");
                    }
                }
                break;
            case 5://Ingreso de automovil
                system("cls");
                if(flag == 0){
                    printf("|X| - Error: No hay propietarios cargados para agregarle un auto\n");
                }else{
                    auto_ingresarNuevo(listaAuto, SIZE_AUTO, listadoProp, SIZE_PROP);
                    flagB = 1;
                }
                break;
            case 6://Egreso de automovil
                system("cls");
                if(flagB == 0){
                    printf("|X| - Error: No hay autos ingresados para que puedan egresar\n");
                }else{
                    auto_mostrarLista(listaAuto,SIZE_AUTO);
                    auto_egresoAuto(listaAuto, SIZE_AUTO, listadoProp, SIZE_PROP);
                }
                break;
            case 7://Recaudacion total
                system("cls");
                if(flagB == 0){
                    printf("|X| - Error: No hay datos suficientes para calcular la recaudacion total\n");
                }else{
                    auto_recaudacionTotal(listaAuto, SIZE_AUTO);
                }
                break;
            case 8://Recaudacion total por marca
                system("cls");
                if(flagB == 0){
                    printf("|X| - Error: No hay datos suficientes para calcular la recaudacion total por marca\n");
                }else{
                    auto_recaudacionTotalMarca(listaAuto, SIZE_AUTO);
                }
                break;
            case 9://Buscar vehiculos de un propietario
                system("cls");
                if(flagB == 0){
                    printf("|X| - Error: No hay datos suficientes para mostrar los vehiculos de un propietario\n");
                }else{
                    auto_mostrarLista(listaAuto,SIZE_AUTO);
                    prop_informarAutos(listadoProp,SIZE_PROP,listaAuto,SIZE_AUTO);
                }
                break;
            case 10://Listar propietarios con vehiculos Audi
                system("cls");
                if(flagB == 0){
                    printf("|X| - Error: No hay datos suficientes para mostrar los propietarios de vehiculos Audi\n");
                }else{
                    prop_todosAudi(listadoProp, SIZE_PROP, listaAuto, SIZE_AUTO);
                }
                break;
            case 11://Listar vehiculos estacionados, ordenado por patente
                system("cls");
                if(flagB == 0){
                    printf("|X| - Error: No hay datos suficientes para mostrar vehiculos estacionados, ordenados por patente\n");
                }else{
                    auto_mostrarListaConPropietarios(listaAuto,SIZE_AUTO,listadoProp,SIZE_AUTO);
                }
                break;
            case 12: //Listar por "X" edad
                system("cls");
                if(flag == 0){
                    printf("|!| - Error: No hay datos para mostrar\n");
                }else{
                    prop_mostrarLista(listadoProp,SIZE_PROP);
                    prop_mostrarDeXedad(listadoProp, SIZE_PROP);
                }
                break;
            case 98://Harcodear propietarios
                system("cls");
                printf("|!| - Exito: Se a%cadieron 4 personas m%cs\n",164,160);
                prop_harcodearDatos(listadoProp,SIZE_PROP);
                flag = 1;
                break;
            case 99:
                system("cls");
                if(flag == 0){
                    printf("|X| - Error: No hay propietarios cargados para harcodearles veh%cculos\n",161);
                }else{
                    auto_harcodearDatos(listaAuto,SIZE_AUTO);
                    printf("|!| - Exito: Se a%cadieron 10 veh%cculos m%cs\n",164,161,160);
                    flagB = 1;
                }
                break;
            case 0:
                system("cls");
                printSadFace();
                printf("\n|!| - Adi%cs",162);
                loop = 0;
                break;
            default:
                system("cls");
                printf("|X| - Opci%cn incorrecta\n",162);
                break;
        }
    }while(loop == 1);




    /*
    int aux;
    //Creo e inicio lista de propietarios
    eProp listadoProp[SIZE_PROP];
    prop_iniciarEstados(listadoProp,SIZE_PROP);
    //Creo e inicio lista de autos
    eAuto listaAuto[SIZE_AUTO];
    auto_iniciarEstados(listaAuto,SIZE_AUTO);

    prop_harcodearDatos(listadoProp,SIZE_PROP);
    auto_harcodearDatos(listaAuto,SIZE_AUTO);

    prop_mostrarLista(listadoProp,SIZE_PROP);
    //prop_borrarPropietario(listadoProp, SIZE_PROP,listaAuto,SIZE_AUTO);
    auto_mostrarLista(listaAuto,SIZE_AUTO);
    //auto_egresoAuto(listaAuto, SIZE_AUTO, listadoProp, SIZE_PROP);
    //prop_informarAutos(listadoProp, SIZE_PROP, listaAuto, SIZE_AUTO);
    //prop_todosAudi(listadoProp, SIZE_PROP, listaAuto, SIZE_AUTO);
    auto_mostrarListaConPropietarios(listaAuto,SIZE_AUTO,listadoProp,SIZE_AUTO);
    */
    /*
    // PROPIETARIO:
    //prop_agregarPropietario(listadoProp, SIZE_PROP, "\n [UPS!] - Espacio insuficiente\n");
    prop_harcodearDatos(listadoProp,SIZE_PROP);
    prop_harcodearDatos(listadoProp,SIZE_PROP);
    prop_mostrarLista(listadoProp,SIZE_PROP);
    //prop_modificarTarjetaPropietario(listadoProp,SIZE_PROP);
    prop_borrarPropietario(listadoProp, SIZE_PROP,listaAuto,SIZE_AUTO);
    prop_mostrarLista(listadoProp,SIZE_PROP);
    */

    /*
    // AUTO:
    prop_harcodearDatos(listadoProp,SIZE_PROP);
    auto_harcodearDatos(listaAuto,SIZE_AUTO);
    auto_mostrarLista(listaAuto,SIZE_AUTO);
    auto_ingresarNuevo(listaAuto, SIZE_AUTO, listadoProp, SIZE_PROP);
    auto_mostrarLista(listaAuto,SIZE_AUTO);
    */


    return 0;
}
