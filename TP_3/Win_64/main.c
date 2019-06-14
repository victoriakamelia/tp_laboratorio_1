#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option = controller_menuDeOpciones();

        switch(option)
        {
        case 1:
            system("cls");
            if(controller_loadFromText("data.csv",listaEmpleados)==0)
            {
                printf("SE LEYO ARCHIVO CSV CORRECTAMENTE.\n");
            }
            else
            {
                printf("CARGA DE ARCHIVO CSV FALLIDA.\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            if(controller_loadFromBinary("data.bin", listaEmpleados)==0)
            {
                printf("SE LEYO ARCHIVO BIN CORRECTAMENTE.\n");
            }
            else
            {
                printf("CARGA DE ARCHIVO BIN FALLIDA.\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(!controller_addEmployee(listaEmpleados))
            {
                printf("SE CARGO EMPLEADO CORRECTAMENTE.\n");
            }
            else
            {
                printf("NO SE PUDO CARGAR EMPLEADO.\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(!controller_editEmployee(listaEmpleados))
            {
              printf("SE EDITO EMPLEADO CORRECTAMENTE.\n");
            }
            else
            {
            printf("NO SE PUDO EDITAR EMPLEADO.\n");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(!controller_removeEmployee(listaEmpleados))
            {
              printf("SE ELIMINO EMPLEADO CORRECTAMENTE.\n");
            }
            else
            {
                printf("NO SE PUDO ELIMINAR EMPLEADO. \n");
            }

            break;
        case 6:
            system("cls");
            if(!controller_ListEmployee(listaEmpleados))
            {
                printf(" \nLISTA EMPLEADOS.\n");
            }

            else
            {
               printf("HUBO UN INCONVENIENTE AL LISTAR LOS EMPLEADOS.\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(!controller_sortEmployee(listaEmpleados))
            {
               printf("SE ORDENARON EMPLEADOS CORRECTAMENTE.\n");
            }
            else
            {
              printf("NO SE PUDO ORDENAR EMPLEADOS CORRECTAMENTE.\n");
            }
            system("pause");
            break;
        case 8:
            system("cls");
            if(!controller_saveAsText("data.csv",listaEmpleados))
            {
              printf("SE GUARDARON EMPLEADOS EN ARCHIVO CSV.\n");
            }
            else
            {
               printf("NO SE PUDO GUARDAR EMPLEADOS EN ARCHIVO CSV.\n");
            }
            system("pause");
            break;
        case 9:
            system("cls");
            if(!controller_saveAsBinary("data.bin",listaEmpleados))
            {
                printf("SE GUARDARON EMPLEADOS EN ARCHIVO BIN.\n");
            }
            else
            {
               printf("NO SE PUDO GUARDAR EMPLEADOS EN ARCHIVO BIN.\n");
            }
            system("pause");
            break;
        case 10:
            system("cls");
            printf("SALIENDO DEL MENU... \n");
            option=10;
            break;
        default:
            printf("OPCION INGRESADA ES INVALIDA. REINTENTE\n");
            break;
        }

    }
    while(option != 10);
    return 0;
}
