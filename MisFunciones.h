#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
#define max 20

typedef struct
{

    char Nombre[max];
    int Edad;
    double Dni;
    int Estado;

} Estruc;

void Inicializacion(Estruc Personas[max]);
int IngresoPersonas(Estruc Personas[max], int cant);
void BorrarPersona(Estruc Personas[max], int cant);

void OrdenarPersonas(Estruc Personas[max], int cant);
void OrdenarPersonasNombre(Estruc Personas[max], int cant);
void OrdenarPersonasEdad(Estruc Personas[max], int cant);
void OrdenarPersonasDni(Estruc Personas[max], int cant);

void Imprimirlista(Estruc Personas[max], int cant);
void MostrarEstados(Estruc Personas[max]);
void gotoxy(int x, int y);

void Grafico(Estruc Personas[max], int cant);

#endif // MISFUNCIONES_H_INCLUDED
