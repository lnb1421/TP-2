#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define max 20
typedef struct
{

    char Nombre[max];
    int Edad;
    double Dni;
    int Estado;

} Estruc;


void Menu()
{
    system("COLOR 02");
    gotoxy(12,5);
    printf(                   "********************************************************\n");
    gotoxy(12,6);
    printf(                   "********************************************************\n");
    gotoxy(12,7);
    printf(                   "********************************************************\n");
    gotoxy(12,8);
    printf(                   "*****                                              *****\n");
    gotoxy(12,9);
    printf(                   "*****           1 - Agregar una persona.           *****\n");
    gotoxy(12,10);
    printf(                   "*****           2 - Borrar persona.                *****\n");
    gotoxy(12,11);
    printf(                   "*****           3 - Imprimir lista.                *****\n");
    gotoxy(12,12);
    printf(                   "*****           4 - Ordenar Lista.                 *****\n");
    gotoxy(12,13);
    printf(                   "*****           5 - Mostrar Grafico.               *****\n");
    gotoxy(12,14);
    printf(                   "*****           6 - Salir.                         *****\n");
    gotoxy(12,15);
    printf(                   "*****                                              *****\n");
    gotoxy(12,16);
    printf(                   "********************************************************\n");
    gotoxy(12,17);
    printf(                   "********************************************************\n");
    gotoxy(12,18);
    printf(                   "********************************************************\n");

}


int IngresoPersonas(Estruc Personas[max], int cant)
{

    int R = 0, Respuesta = 0;


    do
    {
        system("cls");
        printf(" Ingrese Nombre : ");
        fflush(stdin);
        gets(Personas[cant].Nombre);

        printf("\n Ingrese Edad : ");
        scanf("%d", &Personas[cant].Edad);

        printf("\n Ingrese DNI : ");
        scanf("%lf", &Personas[cant].Dni);

        Personas[cant].Estado = 1;
        system("cls");
        printf(" Desea Agregar a otra persona ? \n");
        printf("\n 1. SI \n");
        printf(" 2. NO ");

        scanf("%d", &Respuesta);

        cant++;

    }
    while(Respuesta !=2);


    system("cls");

    return cant;
}








void BorrarPersona(Estruc Personas[max], int cant)
{

    char Busqueda[max];
    int R = 0, flag = 0;


    printf(" Que desea borrar?  \n\n");
    printf(" 1. Una persona \n");
    printf(" 2. Todas las personas \n");
    scanf("%d", &R);

    system("cls");

    if(R == 1)
    {
        Imprimirlista(Personas, cant);

        printf("Ingrese el nombre de la persona que desea borrar : ");
        fflush(stdin);
        gets(Busqueda);
        system("cls");

        for(int i = 1; i <= cant; i++)
        {

            if(strcmp(Personas[i].Nombre, Busqueda)==0)
            {
                strcpy(Personas[i].Nombre, "");
                Personas[i].Edad = 0;
                Personas[i].Dni = 0;

                printf(" Persona encontrada en posicion : [%d] fue borrada!\n\n ", i);
                system("pause");
                flag = 1;

            }

        }

        if(flag == 0)
        {

            printf(" La persona no fue encontrada!\n\n");
            system("pause");
        }

    }
    else if(R == 2)
    {

        Inicializacion(Personas);
        system("cls");
        printf(" Todas las persona han sido borradas! \n\n");
        system("pause");
    }





    system("cls");

}

void Imprimirlista(Estruc Personas[max], int cant)
{
    int R = 0;

    printf(" Que listas desea imprimir? \n\n");
    printf(" 1. lista de Personas \n");
    printf(" 2. listas Estados ");
    scanf("%d", &R);

    system("cls");

    if(R == 1)
    {


        printf("///////// Lista de Personas //////////\n\n");

        for(int i = 1; i <= cant-1; i++)
        {

            printf(" Posicion en la Lista : [%d]\n\n", i);
            printf(" Nombre : %s \n", Personas[i].Nombre);
            printf(" Edad : %d \n", Personas[i].Edad);
            printf(" Dni : %.0lf \n", Personas[i].Dni);
            printf("\n\n");

        }
        printf("\n\n");
        system("pause");
        system("cls");

    }
    else if (R == 2)
    {
        system("cls");
        MostrarEstados(Personas);
    }

}

void Inicializacion(Estruc Personas[max])
{



    for(int i = 1; i <= max; i++)
    {

        strcpy(Personas[i].Nombre, "");
        Personas[i].Edad = 0;
        Personas[i].Dni = 0;
        Personas[i].Estado = 0;
    }

}


void OrdenarPersonas(Estruc Personas[max], int cant)
{

    int Op = 0;


    printf(" Como desea ordenar a las personas?\n\n");
    printf(" 1. Nombre. \n");
    printf(" 2. Edad. \n");
    printf(" 3. Dni. \n");
    scanf("%d", &Op);

    system("cls");
    switch(Op)
    {

    case 1 :
        OrdenarPersonasNombre(Personas, cant);
        break;

    case 2 :
        OrdenarPersonasEdad(Personas, cant);
        break;

    case 3 :
        OrdenarPersonasDni(Personas, cant);
        break;


    }

}

void OrdenarPersonasNombre(Estruc Personas[max], int cant)
{

    Estruc Aux;
    int R = 0;

    printf(" Ordenar de manera : \n\n");
    printf( " 1. Menor a Mayor \n");
    printf( " 2. Mayor a Menor \n");
    scanf("%d", &R);
    system("cls");
    if(R == 1)
    {


        for(int i = 1; i < cant; i++)
        {



            for(int j = 1; j < cant-1; j++ )
            {


                if(strcmp(Personas[j].Nombre, Personas[j+1].Nombre)==1)
                {


                    fflush(stdin);
                    Aux = Personas[j];
                    Personas[j] = Personas[j+1];
                    Personas[j+1] = Aux;


                }


            }


        }

        printf(" La lista fue ordenada de menor a mayor! \n\n");
    }

    else if(R == 2)
    {


        for(int i = 1; i < cant; i++)
        {



            for(int j = 1; j < cant-1; j++ )
            {


                if(strcmp(Personas[j].Nombre, Personas[j+1].Nombre)==-1)
                {


                    fflush(stdin);
                    Aux = Personas[j];
                    Personas[j] = Personas[j+1];
                    Personas[j+1] = Aux;


                }

            }

        }

        printf(" La lista fue ordenada de mayor a menor! \n\n");
    }


    system("pause");
    system("cls");
}

void OrdenarPersonasEdad(Estruc Personas[max], int cant)
{

    Estruc Aux;
    int R = 0;

    printf(" Ordenar de manera : \n\n");
    printf( " 1. Menor a Mayor \n");
    printf( " 2. Mayor a Menor \n");
    scanf("%d", &R);
    system("cls");
    if(R == 1)
    {
        for(int i = 1; i < cant; i++)
        {


            for(int j = 1; j < cant-1; j++ )
            {



                if(Personas[j].Edad > Personas[j+1].Edad)
                {

                    Aux = Personas[j];
                    Personas[j] = Personas[j+1];
                    Personas[j+1] = Aux;

                }

            }

        }
        printf(" La lista fue ordenada de menor a mayor! \n\n");
    }
    else if(R == 2)
    {

        for(int i = 1; i < cant; i++)
        {


            for(int j = 1; j < cant-1; j++ )
            {


                if(Personas[j].Edad < Personas[j+1].Edad)
                {

                    Aux = Personas[j];
                    Personas[j] = Personas[j+1];
                    Personas[j+1] = Aux;

                }

            }

        }
        printf(" La lista fue ordenada de mayor a menor! \n\n");
    }

    system("pause");
    system("cls");
}


void OrdenarPersonasDni(Estruc Personas[max], int cant)
{

    Estruc Aux;
    int R = 0;

    printf(" Ordenar de manera : \n\n");
    printf( " 1. Menor a Mayor \n");
    printf( " 2. Mayor a Menor \n");
    scanf("%d", &R);
    system("cls");
    if(R == 1)
    {
        for(int i = 1; i < cant; i++)
        {

            for(int j = 1; j < cant-1; j++ )
            {

                if(Personas[j].Dni > Personas[j+1].Dni)
                {

                    Aux = Personas[j];
                    Personas[j] = Personas[j+1];
                    Personas[j+1] = Aux;

                }

            }

        }

        printf(" La lista fue ordenada de menor a mayor! \n\n");

    }
    else if(R == 2)
    {


        for(int i = 1; i < cant; i++)
        {

            for(int j = 1; j < cant-1; j++ )
            {


                if(Personas[j].Dni < Personas[j+1].Dni)
                {

                    Aux = Personas[j];
                    Personas[j] = Personas[j+1];
                    Personas[j+1] = Aux;

                }

            }

        }
        printf(" La lista fue ordenada de mayor a menor! \n\n");
    }


    system("pause");
    system("cls");
}

void MostrarEstados(Estruc Personas[max])
{
    printf("///////////// Estados Activos //////////////\n\n");

    for(int i = 1; i <= max; i++)
    {

        printf(" Posicion de la lista : [%d] Estado = %d\n\n\n",i, Personas[i].Estado);

    }

    system("pause");
    system("cls");
}

void Grafico(Estruc Personas[max], int cant)
{

    int Menores18 = 0, Rango19_35 = 0, Mayores35 = 0;

    for(int i = 0; i <= cant; i++)
    {

        if(Personas[i].Edad <= 18)
        {

            Menores18++;

        }
        if(Personas[i].Edad >= 19 && Personas[i].Edad <= 35)
        {

            Rango19_35++;

        }
        if(Personas[i].Edad >= 35)
        {

            Mayores35++;

        }


    }
    printf("Menores 18 : %d Entre 19 y 35 : %d Mayores 35 : %d", Menores18, Rango19_35, Mayores35);


}





void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
