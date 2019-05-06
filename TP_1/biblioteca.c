#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"

void menuPrincipal()
{
    int opcion;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int flag4=0;
    int flag5=0;
    int numero1;
    int numero2;
    char seguir='S';

    while(seguir=='S')
    {
        system ("COLOR 3B");
        system("cls");
        printf("\n         ////////////////////////////////////////////////////////////////");
        printf("\n         /                                                              /");
        printf("\n         /                 M E N U  P R I N C I P A L                   /");
        printf("\n         /                                                              /");
        printf("\n         ////////////////////////////////////////////////////////////////");
        printf("\n         /                                                              /");
        printf("\n                                Elija una opcion:                        ");
        printf("\n         /                                                              /");
        if(flag1==0)
        {
            printf("\n                       1) Ingresar 1er operando: (A=X).                  ");
        }
        else
        {
            printf("\n                       1) Ingresar 1er operando: (A= %d).              ",numero1);
        }

        printf("\n         /                                                              /");
        if(flag2==0)
        {
            printf("\n                       2) Ingresar 2do operando: (B=Y).                  ");
        }
        else
        {
            printf("\n                       2) Ingresar 2do operando: (B= %d).            ",numero2);
        }

        printf("\n         /                                                              /");
        printf("\n                       3) Calcular todas las operaciones.                ");
        printf("\n         /                                                              /");
        printf("\n                       4) Informar resultados.                           ");
        printf("\n         /                                                              /");
        printf("\n                       5) Salir.                                         ");
        printf("\n         /                                                              /");
        printf("\n         ////////////////////////////////////////////////////////////////");
        printf("\n");
        printf("\n         ///////////////////////////////INGRESE OPCION SELECCIONADA:  ");

        scanf("%d",&opcion);




        switch(opcion)
        {
        case 1:
            system ("COLOR B5");

            system("cls");

            numero1=ingresarNumero();

            seguir=validarSeguir();

            flag1=1;
            flag3=1;

            break;
        case 2:
            system ("COLOR B5");

            system("cls");

            numero2=ingresarNumero();

            seguir=validarSeguir();

            flag2=1;
            flag4=1;

            break;
        case 3:
            system("cls");
            if(flag3==0 || flag4==0)
            {
                system("cls");
                printf("\n         ////////////////////////////////////////////////////////////////");
                printf("\n         /                                                              /");
                printf("\n         /   PARA CALCULAR PRIMERO DEBE INGRESAR LOS OPERANDOS...       /");
                printf("\n         /                                                              /");
                printf("\n         ////////////////////////////////////////////////////////////////");
                seguir=validarSeguir();
            }
            else
            {
                primerSubmenu(numero1, numero2);

                seguir=validarSeguir();

                flag5=1;

            }

            break;

        case 4:
            system("cls");
            if(flag5==0)
            {
                printf("\n         ////////////////////////////////////////////////////////////////");
                printf("\n         /                                                              /");
                printf("\n         /PARA VER LOS RESULTADOS PRIMERO DEBE INGRESAR LOS OPERANDOS.../");
                printf("\n         /                                                              /");
                printf("\n         ////////////////////////////////////////////////////////////////");
                seguir=validarSeguir();
            }
            else if(flag3==0 && flag4==0)
            {
                printf("\n         ////////////////////////////////////////////////////////////////");
                printf("\n         /                                                              /");
                printf("\n         /      PARA VER LOS RESULTADOS PRIMERO DEBE CALCULAR...        /");
                printf("\n         /                                                              /");
                printf("\n         ////////////////////////////////////////////////////////////////\n");
                seguir=validarSeguir();
            }
            else
            {
                segundoSubmenu(numero1, numero2);

                seguir=validarSeguir();
            }


            break;
        case 5:
            system("cls");
            printf("\n         /////////////////////////////////////////////////////////////");
            printf("\n         /                                                           /");
            printf("\n         /       C E R R A N D O    C A L C U L A D O R A . . .      /");
            printf("\n         /                                                           /");
            printf("\n         /////////////////////////////////////////////////////////////\n\n");

            seguir='n';
            break;

        default:
            system("cls");

            printf("\n         /////////////////////////////////////////////////////////////");
            printf("\n         /                                                           /");
            printf("\n         /              LA OPCION INGRESADA NO ES VALIDA.            /");
            printf("\n         /                                                           /");
            printf("\n         /////////////////////////////////////////////////////////////\n\n");
            seguir=validarSeguir();

            break;

        }




    }
}

int ingresarNumero()
{
    int numero;

    printf("\n         ////////////////////////////////////////////////////////////////");
    printf("\n         /                                                              /");
    printf("\n         /                                                              /");
    printf("\n         /     I N G R E S E   U N   N U M E R O: ");
    scanf("%d",&numero);

    return numero;
}


void primerSubmenu(int x, int y)
{
    system ("COLOR 2E");
    system("cls");
    printf("\n         /////////////////////////////////////////////////////////////");
    printf("\n         /                                                           /");
    printf("\n         /        C A L C U L O S     A     R E A L I Z A R          /");
    printf("\n         /                                                           /");
    printf("\n         /////////////////////////////////////////////////////////////");
    printf("\n         /                                                           /");
    printf("\n                    A) Calcular la suma de (%d+%d)               ",x,y);
    printf("\n         /                                                           /");
    printf("\n                    B) Calcular la resta de (%d-%d)              ",x,y);
    printf("\n         /                                                           /");
    if(y != 0)
    {
        printf("\n                    C) Calcular la division de (%d/%d)           ",x,y);
    }
    else
    {
        printf("\n                    C) No se puede dividir por cero.                ");
    }

    printf("\n         /                                                           /");
    printf("\n                    D) Calcular la multiplicacion de (%d*%d)     ",x,y);
    printf("\n         /                                                           /");
    if (x<0)
    {
        printf("\n                    E) No se puede obtener el factorial de: %d    ",x);
    }
    else if(y<0)
    {
        printf("\n                    E) No se puede obtener el factorial de: %d    ",y);
    }
    else
    {
        printf("\n                    E) Calcular el factorial de (%d!) y (%d!)    ",x,y);
    }

    printf("\n         /                                                           /");
    printf("\n         /////////////////////////////////////////////////////////////");
    printf("\n");
}
void segundoSubmenu(int x, int y)
{
    system ("COLOR 2E");
    system("cls");
    printf("\n         /////////////////////////////////////////////////////////////");
    printf("\n         /                                                           /");
    printf("\n         /   R E S U L T A D O S   D E    L O S   C A L C U L O S    /");
    printf("\n         /                                                           /");
    printf("\n         /////////////////////////////////////////////////////////////");
    printf("\n         /                                                           /");
    printf("\n                    A) La suma de           %d+%d  = %d     ",x,y,sumar(x, y));
    printf("\n         /                                                           /");
    printf("\n                    B) La resta de          %d-%d  = %d     ",x,y, restar(x, y));
    if(y==0)
    {
        printf("\n         /                                                           /");
        printf("\n                    C) No se puede dividir por cero.                 ");
    }
    else
    {
        printf("\n         /                                                           /");
        printf("\n                    C) La division de       %d/%d  = %.2f     ",x,y, dividir(x, y));
    }

    printf("\n         /                                                           /");
    printf("\n                    D) La multiplicacion de %d*%d  = %d    ",x,y,multiplicar(x, y));
    printf("\n         /                                                           /");

    if (x<0)
    {
        printf("\n                    E) No se puede obtener el factorial de: %d    ",x);
    }
    else if(y<0)
    {
        printf("\n                    E) No se puede obtener el factorial de: %d    ",y);
    }
    else
    {
        printf("\n                    E) El factorial de (%d!) es (%d!)   ",x, calcularFactorial(x));
        printf("\n                       El factorial de (%d!) es (%d!)   ",y, calcularFactorial(y));
    }
    printf("\n         /                                                           /");
    printf("\n         /////////////////////////////////////////////////////////////");
    printf("\n");
}

int sumar(int x, int y)
{
    int resultado;
    resultado= x+y;
    return resultado;
}
int restar(int x, int y)
{
    int resultado;

    resultado= x-y;

    return resultado;
}
float dividir(int x, int y)
{
    float resultado;
    resultado= (float)x/y;
    return resultado;
}
int multiplicar(int x, int y)
{
    int resultado;
    resultado= x*y;
    return resultado;
}

int calcularFactorial(int x)
{
    int factorX;
    int factorialDeX;
    factorX=1;
    for (factorialDeX = x; factorialDeX >= 1; factorialDeX--)
    {
        factorX = factorX * factorialDeX;
    }
    return factorX;
}

char validarSeguir()
{
    char seguir='S';
    printf("\n         /D E S E A    C O N T I N U A R ?   S/N: ");
    scanf("%s", &seguir);
    seguir=toupper(seguir);

    while(seguir != 'N' && seguir != 'S')
    {
        printf("\n          /LA OPCION INGRESADA ES INVALIDA.");
        printf("\n         /D E S E A    C O N T I N U A R ?   S/N: ");
        scanf("%s", &seguir);
        seguir=toupper(seguir);

    }

    return seguir;

}


