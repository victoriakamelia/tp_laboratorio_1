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

int main()
{
    Employee list[TAM]=
    {
        {1234, "Juan", "TERRAZAS", 30000,5,1},
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
    char seguir2;
    int flag1=0;
    int idBaja;
    int idModificar;
    char idStr[20];

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
            if(flag1==0 || hayEmpleados(list, TAM)==0)
            {
                printf("\n");
                printf("PARA MODIFICAR EMPLEDOS, PRIMERO DEBE DAR DE ALTA.");
                system("pause");
                break;
            }
            else
            {
                system("cls");
                printf("\n________________________________________________________________\n\n");

                printf("INGRESE EL ID DEL EMPLEADO A MODIFICAR: ");
                fflush(stdin);
                scanf("%s", idStr);
                while(esNumerico(idStr)==0)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID DEBE SER NUMERICO.\n");
                    printf("INGRESE EL ID DEL EMPLEADO A MODIFICAR: ");
                    fflush(stdin);
                    scanf("%s", idStr);
                }
                idModificar=atoi(idStr);

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
                    printf("DESEA MODIFICAR ESTE EMPLEADO?:");
                    seguir2=validarSeguir();


                    if(seguir2=='S')
                    {
                        switch(menuDos())
                        {
                        case 1:
                            getText("I N G R E S E   N O M B R E:", "NOMBRE INGRESADO EXCEDE EL PERMITIDO.\n", list[idModificar].name, 50);
                            break;
                        case 2:
                            getText("I N G R E S E   A P E L L I D O: ", "APELLIDO INGRESADO EXCEDE EL PERMITIDO.\n", list[idModificar].lastName, 50);
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
                    else
                    {
                        break;
                    }



                }


            }
            seguir=validarSeguir();
            break;
        case 3:
            system("cls");
            if(hayEmpleados(list, TAM)==0)
            {
                printf("\n");
                printf("PARA DAR DE BAJA EMPLEDOS, PRIMERO DEBE DAR DE ALTA.");
                system("pause");
                break;
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
            }
            else
            {


                printf("\n________________________________________________________________\n\n");
                printf("INGRESE EL ID DEL EMPLEADO A DAR DE BAJA:");
                fflush(stdin);
                scanf("%s", idStr);

                while(esNumerico(idStr)==0)
                {
                    printf("\n________________________________________________________________\n\n");
                    printf("EL ID DEBE SER NUMERICO.\n");
                    printf("INGRESE EL ID DEL EMPLEADO A DAR DE BAJA:");
                    fflush(stdin);
                    scanf("%s", idStr);
                }
                idBaja=atoi(idStr);

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
                    printf("ESTE EMPLEADO SE DARA DE BAJA DE FORMA PERMANENTE.");
                    seguir2=validarSeguir();
                    if(seguir2=='S')
                    {
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
                    else
                    {

                        printf("\n________________________________________________________________\n\n");
                        printf("BAJA EMPLEADO CANCELADA.\n");
                        system("pause");
                        break;
                    }


                }

            }


            seguir=validarSeguir();
            break;
        case 4:
            system("cls");
            if(hayEmpleados(list, TAM)==0)
            {
                printf("\n________________________________________________________________\n\n");
                printf("PARA VER INFORMES PRIMERO DEBE DAR DE ALTA.\n");
                system("pause");
                break;

            }
            else
            {
                system("cls");
                formatoTexto(list, TAM);
                listarDos(list, TAM, sectores,TAMSEC);
                listarUno(list, TAM, sectores,TAMSEC, aux);


                mostrarEmpleados(list, TAM, sectores,TAMSEC);
            }

            seguir=validarSeguir();
            break;
        default:
            system("cls");
            printf("\n________________________________________________________________\n\n");
            printf("LA OPCION INGRESADA NO ES VALIDA.");
            break;
        }


    }
    while(seguir=='S');

    return 0;
}









