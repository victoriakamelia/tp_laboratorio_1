#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
#include "controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivoEmpleados;
    int retorno=-1;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivoEmpleados=fopen(path,"r");
        if(!parser_EmployeeFromText(pArchivoEmpleados,pArrayListEmployee))
        {
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivoEmpleados;
    int retorno =-1;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivoEmpleados = fopen(path,"rb");
        if(!parser_EmployeeFromBinary(pArchivoEmpleados,pArrayListEmployee))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    Employee* auxiliarPunteroEmployee =NULL;

    char bufferNombre[128];
    char bufferHorasTrabajadas[128];
    char bufferSueldo[128];
    int varTemporal;

    printf("A L T A   E M P L E A D O.");
    if(pArrayListEmployee!=NULL)
    {

        if( !funciones_getStringInput("INGRESE NOMBRE EMPLEADO: ",128,bufferNombre) &&
                !funciones_getStringInput("INGRESE HORAS TRABAJADAS DEL EMPLEADO: ",128,bufferHorasTrabajadas) &&
                !funciones_getStringInput("INGRESE SUELDO DEL EMPLEADO: ",128,bufferSueldo))
        {
            if( funciones_isName(bufferNombre) == 1 &&
                    !funciones_ValidHorasTrabajadasStr(bufferHorasTrabajadas,&varTemporal)&&
                    !funciones_ValidSueldoStr(bufferSueldo,&varTemporal))
            {
                auxiliarPunteroEmployee = (Employee*)employee_newParametros("-1",bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            }
            else
            {
                printf("/nDATOS INGRESADOS NO SON CORRECTOS.");
            }
        }
        else
        {
            printf("/nDATOS INGRESADOS NO SON CORRECTOS.");
        }

        if(auxiliarPunteroEmployee != NULL)
        {
            if(!ll_add(pArrayListEmployee,auxiliarPunteroEmployee))
            {
                retorno = 0;
            }


        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    Employee* auxiliarPunteroEmployee =NULL;
    auxiliarPunteroEmployee = employee_new();
    int AuxID;
    int flagFoundEmployee= 0;
    char bufferNombre[128];
    char bufferHorasTrabajadas[128];
    char bufferSueldo[128];
    int auxHorasInt;
    int auxSueldoInt;
    int AuxPosArrayListEmployee;

    if(pArrayListEmployee!=NULL)
    {
        if(!funciones_getIntFromString("INGRESE EL ID DEL EMPLEADO A MODIFICAR: ","ID NO VALIDO",3,0,10000,&AuxID))
        {

            AuxPosArrayListEmployee = controller_findEmployeeByID(pArrayListEmployee,AuxID);

            if(AuxPosArrayListEmployee>=0)
            {
                auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,AuxPosArrayListEmployee);

                if(auxiliarPunteroEmployee != NULL)
                {
                    flagFoundEmployee = 1;
                }
            }
            else
            {
                printf("\nID NO ENCONTRADO.\n");
            }
        }

        if(flagFoundEmployee == 1)
        {
            employee_printEmployee(auxiliarPunteroEmployee);
            printf("E D I T A R   E M P L E A D O.");
            if( !funciones_getStringInput("INGRESE NOMBRE DEL EMPLEADO A MODIFICAR: ",128,bufferNombre) &&
                    !funciones_getStringInput("INGRESE HORAS DEL EMPLEADO A MODIFICAR: ",128,bufferHorasTrabajadas) &&
                    !funciones_getStringInput("INGRESE SUELDO DEL EMPLEADO A MODIFICAR:",128,bufferSueldo))
            {

                if( funciones_isName(bufferNombre) == 1 &&
                        !funciones_ValidHorasTrabajadasStr(bufferHorasTrabajadas,&auxHorasInt)&&
                        !funciones_ValidSueldoStr(bufferSueldo,&auxSueldoInt))
                {
                    if( !employee_setNombre(auxiliarPunteroEmployee, bufferNombre)&&
                            !employee_setHorasTrabajadas(auxiliarPunteroEmployee,auxHorasInt)&&
                            !employee_setSueldo(auxiliarPunteroEmployee, auxSueldoInt))
                    {
                        retorno = 0;
                    }


                }
                else
                {
                    printf("\nError! en validacion de parametros");
                }
            }
            else
            {
                printf("\nError! en ingreso de parametros");
            }


        }

    }



    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int AuxID;
    int AuxPosArrayListEmployee;

    int retorno =  -1;

    if(pArrayListEmployee!= NULL)
    {
        if(!funciones_getIntFromString("INGRESE ID DEL EMPLEADO A ELIMINAR","\nID NO VALIDO",3,0,10000,&AuxID))
        {
            AuxPosArrayListEmployee = controller_findEmployeeByID(pArrayListEmployee,AuxID);

            if(AuxPosArrayListEmployee>=0)
            {
                if(!ll_remove(pArrayListEmployee,AuxPosArrayListEmployee))
                {
                    retorno = 0;
                }
            }
        }

    }


    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int lenList;
    int i;
    int retorno = -1;

    if(pArrayListEmployee !=NULL)
    {
        Employee* auxiliarPunteroEmployee;

        auxiliarPunteroEmployee = employee_new();

        lenList = ll_len(pArrayListEmployee);
        printf("ID:  - NOMBRE:               - HORAS: - SUELDO:");
        for(i=0; i<lenList; i++)
        {
            if(i%200==0)
            {
                printf("\n");

                auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);
                system("pause");

                if(auxiliarPunteroEmployee != NULL)
                {
                    employee_printEmployee(auxiliarPunteroEmployee);
                    retorno = 0;
                }
            }
            else
            {
                auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);

                if(auxiliarPunteroEmployee != NULL)
                {
                    employee_printEmployee(auxiliarPunteroEmployee);
                    retorno = 0;
                }


            }
        }
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(!ll_sort(pArrayListEmployee,employee_compareEmployee,1))
            retorno = 0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    int i;
    int lenArrayList;

    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        lenArrayList = ll_len(pArrayListEmployee);
        FILE* pArchivoEmpleados;
        Employee* auxiliarPunteroEmployee = NULL;
        auxiliarPunteroEmployee = employee_new();
        pArchivoEmpleados = fopen(path,"w");

        if(pArchivoEmpleados!=NULL )
        {
            fprintf(pArchivoEmpleados, "%s,%s,%s,%s\n", "id", "nombre", "horasTrabajadas", "sueldo");
            for(i=0; i<lenArrayList; i++)
            {
                auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);

                if(auxiliarPunteroEmployee != NULL)
                {

                    if(!employee_getEmployee(auxiliarPunteroEmployee,&bufferId,bufferNombre,&bufferHorasTrabajadas,&bufferSueldo))
                    {
                        fprintf(pArchivoEmpleados, "%i,%s,%i,%i\n", bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
                    }
                    else
                    {
                        printf("Error\n");
                    }
                    retorno = 0;
                }
            }

            fclose(pArchivoEmpleados);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno =-1;
    int i;
    int lenArrayList;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        lenArrayList = ll_len(pArrayListEmployee);
        FILE* pArchivoEmpleados;
        Employee* auxiliarPunteroEmployee;
        auxiliarPunteroEmployee =employee_new();
        pArchivoEmpleados = fopen(path,"wb");

        if(pArchivoEmpleados!=NULL )
        {
            for(i=0; i<lenArrayList; i++)
            {
                auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);

                if(auxiliarPunteroEmployee != NULL)
                {
                    fwrite(auxiliarPunteroEmployee,sizeof(Employee),1,pArchivoEmpleados);
                    retorno = 0;
                }
            }

            fclose(pArchivoEmpleados);
        }
    }
    return retorno;
}

/** \brief busca un empleado dentro del linkedllist por ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
int controller_findEmployeeByID(LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    int i;
    int lenList;
    int AuxID;
    Employee* auxiliarPunteroEmployee=NULL;

    if( pArrayListEmployee != NULL)
    {
        lenList = ll_len(pArrayListEmployee);
        retorno = -2;
        for(i=0; i<lenList; i++)
        {

            auxiliarPunteroEmployee = (Employee*)ll_get(pArrayListEmployee,i);

            if(auxiliarPunteroEmployee != NULL)
            {
                if(employee_getId(auxiliarPunteroEmployee,&AuxID) == 0)
                    if(AuxID == id)
                    {
                        retorno = i;

                        break;
                    }
            }
        }
    }
    return retorno;
}

/** \brief Imprime en pantalla menu de Opciones Principal
 *
 * \param void
 * \return int
 *
 */
int controller_menuDeOpciones(void)
{
    int opcion;
    system("color 3b");
    printf("OoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO\n");
    printf("8               M E N U    P R I N C I P A L                      8\n");
    printf("O  1)Cargar los datos de los empleados desde el archivo data.csv  O\n");
    printf("8                                                                 8\n");
    printf("O  2)Cargar los datos de los empleados desde el archivo data.bin  O\n");
    printf("8                                                                 8\n");
    printf("O  3)Alta de empleado.                                            O\n");
    printf("8                                                                 8\n");
    printf("O  4)Modificar datos de empleado.                                 O\n");
    printf("8                                                                 8\n");
    printf("O  5)Baja de empleado.                                            O\n");
    printf("8                                                                 8\n");
    printf("O  6)Listar empleados.                                            O\n");
    printf("8                                                                 8\n");
    printf("O  7)Ordenar empleados.                                           O\n");
    printf("8                                                                 8\n");
    printf("O  8)Guardar los datos de los empleados en el archivo data.csv    O\n");
    printf("8                                                                 8\n");
    printf("O  9)Guardar los datos de los empleados en el archivo data.bin    O\n");
    printf("8                                                                 8\n");
    printf("O  10) Salir.                                                     O\n");
    printf("8                                                                 8\n");
    printf("OoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoO\n");
    printf("OoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOo Seleccione opcion: ");
    scanf("%d", &opcion);
    return opcion;

}



