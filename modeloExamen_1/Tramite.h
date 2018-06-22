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
