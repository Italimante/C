#include "ArrayList.h"

typedef struct{
        int idTramite;
        char dni[10];
}eTramite;

//Un constructor
eTramite * new_Tramite();

//setes y geters
int setId( eTramite*, int );
int getId( eTramite* );

int setDni( eTramite*, char* );
char* getDni(eTramite*);

//una funcion que los muestre

int mostrarTramite(eTramite*);

int compararPorDni(void *, void *);

int mostrarListaTramites(ArrayList*);

//Funcion que me permita crear o cargar un tramite
    // le pasa el arraylist, el id, y el documento
int cargarTramite(ArrayList*, int, char*);

//de donde lo saca y donde lo pone
int atenderTramite( ArrayList*, ArrayList* );
