#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "MisFunciones.h"
#define max 20


int main()
{

    system("mode con: cols=80 lines=30");


    Estruc Personas[max];
    //Inicializacion(Personas);
    int Total, Op = 0, cant = 1;


    do
    {

        Menu(),
             scanf("%d", &Op);


        switch(Op)
        {

        case 1 :
            system("cls");
            Total = IngresoPersonas(Personas, cant);
            break;

        case 2 :
            system("cls");
            BorrarPersona(Personas, Total);
            break;

        case 3 :
            system("cls");
            Imprimirlista(Personas, Total);
            break;

        case 4 :
            system("cls");
            OrdenarPersonas(Personas, Total);
            break;

        case 5 :
            system("cls");
            Grafico(Personas, Total);
            break;
        }

     }
    while(Op != 6);




    return 0;
}


