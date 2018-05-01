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
void mostrarMenu();
void per_mostrarUno(ePersona);
void per_mostrarLista(ePersona [], int );
void per_harcodearDatos(ePersona []);
void per_incializarEstado(ePersona [], int);
void per_ordenarPorNombre(ePersona [], int);
void per_agregarPersona(ePersona [], int, char []);
void per_pedirDato(ePersona[],int,int);
int per_buscarEntero(ePersona [], int, int);
void per_borrarPersona(ePersona [], int , char []);
