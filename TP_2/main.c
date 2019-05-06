#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "employee.h"
#define TAM 15
#define TAMSEC 5
#define OCUPADO 1
#define VACIO 0


int addEmployee(Employee list[], int tam, eSector sector[], int tamSec);
int generarId();
void getName(Employee list[],int indice, char texto[], char textoError[]);
void getLastName(Employee list[],int indice, char texto[], char textoError[]);
void getFloat(Employee list[],int indice, char texto[], char textoError[]);
void getInt(Employee list[], int indice,char message[],char eMessage[], int lowLimit, int hiLimit);
void mostrarSectores(eSector sector[], int tamSec);
int bajaEmpleado(Employee emp[],int tam, int id);
int buscarId(Employee emp[], int tam, int id);
int buscarIndiceSector(eSector list[], int tam,int id);
int mostrarEmpleados(Employee list[], int tam, eSector sector[], int tamSec);
void mostrarEmpleado(Employee emp, eSector sec[], int tamSec);
void formatoTexto(Employee list[], int tam);
void listarUno(Employee list[], int tam, eSector sector[], int tamSec, Employee aux);
void listarDos(Employee list[], int tam, eSector sector[], int tamSec);


int main()
{
    Employee list[TAM]=
    {
        {1234, "Juan", "TERRAZAS ", 30000,5,1},
        {2222, "Ana", "SORIA", 32000,2,1},
        {2211, "Jorge", "meza", 28000,2,1},
        {3241, "Alberto", "VALDES", 35000,1,1},
        {8944, "Sonia", "meza", 39000,3,1},
        {2231, "Miguel", "SOSA", 29700,2,1},
        {6578, "Adrian", "PEREZ", 43200,5,1},
        {3425, "Lucia", "JIMENEZ", 32300,2,1},
        {5546, "Gaston", "meza", 29760,4,1},
        {7654, "Diego", "CASAS", 35000,1,1},
        {9040, "Viviana", "meza", 1000000,1,0},
        {7439, "Gustavo", "MEZA", 25000,4,1},
        {7654, "Diego", "MENDEZ", 35000,1,1},
        {9040, "Viviana", "MEZA", 47000,1,1},
        {7439, "Gustavo", "meza", 25000,4,1}
    };

    Employee aux;

    eSector sectores[] =
    {
        {1, "SISTEMAS"},
        {2, "RRHH"},
        {3, "COMPRAS"},
        {4, "VENTAS"},
        {5, "LEGALES"},

    };
    char seguir='S';
    int flag1=0;
    int idBaja;
    int idModificar;

    //initEmployees(list,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(addEmployee(list, TAM, sectores, TAMSEC)==0)
            {
                flag1=1;
            };
            seguir=validarSeguir();
            break;
        case 2:
            system("cls");
            if(flag1==0)
            {
                printf("\n");
                printf("PARA MODIFICAR EMPLEDOS, PRIMERO DEBE DAR DE ALTA.");
            }
            else
            {
                system("cls");
                printf("\n________________________________________________________________\n\n");

                printf("INGRESE EL ID DEL EMPLEADO A MODIFICAR");
                scanf("%d", &idModificar);
                if(buscarId(list, TAM, idModificar)==-1)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID NO PERTENECE A NINGUNO DE LOS EMPLEADOS EXISTENTES.\n");
                }
                else
                {
                    system("cls");
                    formatoTexto(list, TAM);
                    mostrarEmpleado(list[idModificar],sectores, TAMSEC);


                    switch(menuDos())
                    {
                    case 1:
                        getName(list,idModificar, "I N G R E S E   N O M B R E:", "NOMBRE INGRESADO EXCEDE EL PERMITIDO.\n");
                        break;
                    case 2:
                        getLastName(list,idModificar, "I N G R E S E   A P E L L I D O: ", "APELLIDO INGRESADO EXCEDE EL PERMITID.\n");
                        break;
                    case 3:
                        getFloat(list,idModificar, "I N G R E S E   S A L A R I O: ", "SALARIO DEBE SER MAYOR A CERO.\n");
                        break;
                    case 4:
                        getInt(list,idModificar, "I N G R E S E   S E C T O R: ", "SECTOR DEBE SER ENTRE 1 Y 5.\n", 1, 5);
                        break;
                    default:
                        break;

                    }

                }


            }
            seguir=validarSeguir();
            break;
        case 3:
            system("cls");
            printf("\n________________________________________________________________\n\n");
            printf("INGRESE EL ID DEL EMPLEADO A DAR DE BAJA:");
            scanf("%d", &idBaja);
            if(buscarId(list, TAM, idBaja)==-1)
            {
                printf("\n________________________________________________________________\n\n");
                printf("EL ID NO PERTENECE A NINGUNO DE LOS EMPLEADO EXISTENTES\n");
            }
            else
            {
                printf("\n________________________________________________________________\n\n");
                printf("EMPLEADO A DAR DE BAJA: \n");
                mostrarEmpleados(list, TAM, sectores, TAMSEC);

                if(bajaEmpleado(list, TAM, idBaja)==-1)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("NO SE PUDO DAR DE BAJA EL EMPLEADO SOLICITADO.\n");
                }
                else
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EMPLEADO ID %d DADO DE BAJA EXITOSAMENTE.", idBaja);
                }
            }

            seguir=validarSeguir();
            break;
        case 4:
            system("cls");
            formatoTexto(list, TAM);
            listarUno(list, TAM, sectores,TAMSEC, aux);
            listarDos(list, TAM, sectores,TAMSEC);

            mostrarEmpleados(list, TAM, sectores,TAMSEC);
            seguir=validarSeguir();
            break;
        default:
            system("cls");
            break;
        }

    }
    while(seguir=='S');

    return 0;
}

int addEmployee(Employee list[], int tam, eSector sector[], int tamSec)
{
    int retorno=-1;
    int id=generarId();

    if(buscarLibre(list, tam)==-1)
    {
        printf("\n________________________________________________________________\n\n");
        printf("NO QUEDA LUGAR DISPONIBLE PARA GENERAR EMPLEADOS.\n");
    }
    else
    {
        getName(list,id, "I N G R E S E   N O M B R E:", "NOMBRE INGRESADO EXCEDE EL PERMITIDO.\n");
        getLastName(list,id, "I N G R E S E   A P E L L I D O: ", "APELLIDO INGRESADO EXCEDE EL PERMITIDO.\n");
        getFloat(list,id, "I N G R E S E   S A L A R I O: ", "SALARIO DEBE SER MAYOR A CERO.\n");

        printf("\n________________________________________________________________\n\n");
        printf("S E C T O R E S\n");
        mostrarSectores(sector,tamSec);
        getInt(list,id, "I N G R E S E   S E C T O R: ", "SECTOR DEBE SER ENTRE 1 Y 5.\n", 1, 5);
        printf("\n________________________________________________________________\n\n");
        printf("Empleado id %d generado exitosamente.", id);

        list[id].isEmpty=OCUPADO;

        retorno=0;

    }

    return retorno;
}

int generarId()
{
    static int id=0;

    return id++;
}

void getName(Employee list[],int indice, char texto[], char textoError[])
{
    char auxChar[100];
    printf("\n________________________________________________________________\n\n");
    printf("\n%s", texto);
    fflush(stdin);
    gets(auxChar);
    while(strlen(auxChar)>51)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", texto);
        printf("\n%s", textoError);
        gets(auxChar);

    }
    strcpy(list[indice].name, auxChar);

}



/*getName2("Ingrese nombre empleado", "Nombre demasiado largo. Reingrese", lista[3].nombre, 20);

int getName2(char texto[], char textoError[], char cadena[], int largo)
{
    int todoOk = 0;
    char auxChar[100];
    printf("\n________________________________________________________________\n\n");
    printf("\n%s", texto);
    fflush(stdin);
    gets(auxChar);
    while(strlen(auxChar)>= largo)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", texto);
        printf("\n%s", textoError);
        gets(auxChar);

    }
    strcpy(cadena, auxChar);
}*/
void getLastName(Employee list[],int indice, char texto[], char textoError[])
{
    char auxChar[100];
    printf("\n________________________________________________________________\n\n");
    printf("\n%s", texto);
    fflush(stdin);
    gets(auxChar);
    while(strlen(auxChar)>51)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", texto);
        printf("\n%s", textoError);
        gets(auxChar);

    }
    strcpy(list[indice].lastName, auxChar);
}

void getFloat(Employee list[],int indice, char texto[], char textoError[])
{
    float sueldo;
    printf("\n________________________________________________________________\n\n");
    printf("\n%s", texto);
    scanf("%f", &sueldo);

    while(sueldo<=0)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", textoError);

    }

    list[indice].salary=sueldo;
}

void getInt(Employee list[], int indice,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int auxNum;

    printf("\n________________________________________________________________\n\n");
    printf("\n%s", message);
    scanf("%d",&auxNum);
    while((auxNum<lowLimit || auxNum>hiLimit))
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", eMessage);
        scanf("%d", &auxNum);

    }


    list[indice].sector=auxNum;

}

void mostrarSectores(eSector sector[], int tamSec)
{
    int i;
    printf("\n________________________________________________________________\n\n");
    printf("ID SECTOR  -  DESCRIPCION\n\n");
    for(i=0; i<tamSec; i++)
    {
        printf("%5d         %10s\n", sector[i].idSector, sector[i].nameSector);
    }
}

int bajaEmpleado(Employee emp[],int tam, int id)
{
    int retorno = -1;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(emp[i].id == id)
        {
            emp[i].isEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;
}
int buscarId(Employee emp[], int tam, int id)
{
    int i;
    int retorno=-1;
    for(i=0; i<tam; i++)
    {
        if(emp[i].id==id && emp[i].isEmpty == OCUPADO)
        {
            retorno=i;

            break;
        }

    }

    return retorno;
}


void mostrarEmpleado(Employee emp, eSector sec[], int tamSec)
{

    int idSector=emp.sector;
    int indiceSector=buscarIndiceSector(sec, tamSec, idSector);


    printf("%2d     %10s        %10s       %.2f %8d    %10s\n\n", emp.id, emp.name, emp.lastName, emp.salary, emp.sector, sec[indiceSector].nameSector );
}
int mostrarEmpleados(Employee emp[], int tam, eSector sector[], int tamSec)
{
    int i;
    int retorno=-1;
    printf("\n________________________________________________________________\n\n");
    printf("ID           NOMBRE          APELLIDO        SALARIO       ID-S       SECTOR\n");
    for(i=0; i<tam; i++)
    {
        if(emp[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(emp[i], sector, tamSec);
            retorno=0;
        }
    }

    return retorno;

}

int buscarIndiceSector(eSector list[], int tam,int id)
{
    int i;
    int retorno=-1;

    for(i=0; i<tam; i++)
    {
        if(list[i].idSector==id)
        {
            retorno=i;
        }
    }

    return retorno;
}

void formatoTexto(Employee list[], int tam)
{
    char nombre[51];
    char apellido[51];
    int cantidadLetras;
    int i;
    int j;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            strcpy(nombre, list[i].name);
            strlwr(nombre);
            nombre[0]=toupper(nombre[0]);
            cantidadLetras=strlen(nombre);
            for(j=0; j<cantidadLetras; j++)
            {
                if(nombre[j]==' ')
                {
                    nombre[j+1]=toupper(nombre[j+1]);
                }
            }

            strcpy(apellido, list[i].lastName);
            strlwr(apellido);
            apellido[0]=toupper(apellido[0]);
            cantidadLetras=strlen(apellido);
            for(j=0; j<cantidadLetras; j++)
            {
                if(apellido[j]==' ')
                {
                    apellido[j+1]=toupper(apellido[j+1]);
                }
            }

            strcpy(list[i].name, nombre);
            strcpy(list[i].lastName, apellido);



        }


    }
}

void listarUno(Employee list[], int tam, eSector sector[], int tamSec, Employee aux)
{
    int i;
    int j;

    for(i=0; i < TAM-1;  i++)
    {
        for(j=i+1; j < TAM;  j++)
        {
            if((strcmp(list[i].lastName,list[j].lastName))>0)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;



            }
            if((list[i].lastName==list[j].lastName && strcmp(list[i].name,list[j].name))>0)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;



            }

            if(list[i].sector>list[j].sector)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;

            }
        }
    }
}

void listarDos(Employee list[], int tam, eSector sector[], int tamSec)
{
    int i;

    float total=0;
    float promedio;
    int contador=0;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            total=total+list[i].salary;
            contador++;
        }

    }
    printf("\n________________________________________________________________\n\n");
    printf("EL TOTAL DE LOS SUELDOS ES: %.2f\n\n", total);
    promedio=total/contador;
    printf("\n________________________________________________________________\n\n");
    printf("EL PROMEDIO DE LOS SUELDOS ES: %.2f\n\n", promedio);
    printf("\n________________________________________________________________\n\n");
    printf("LOS EMPLEADOS QUE SU SUELDO SUPERA EL PROMEDIO SON:\n\n");

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO && list[i].salary>promedio)
        {
            mostrarEmpleado(list[i], sector, tamSec);
        }

    }
}
