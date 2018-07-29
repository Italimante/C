#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

//el archivo este .h deberia tener el mismo nombre que la estructura: eLocalidad
typedef struct{
    int id;
    int estado;
    char nombreLocalidad[50];
}eLocalidad;
#endif // LOCALIDAD_H_INCLUDED


//aca quedan todas las funciones con loc_
void loc_mostrarUno(eLocalidad aux);
void loc_mostrarListado(eLocalidad listados[],int cantE);
