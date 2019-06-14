#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funciones.h"
#include "Controller.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si OK sino -1
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxiliarPunteroEmployee = NULL;
    int retorno =-1;
    int flag1=1;
    int auxID;
    int contador=0;
    char bufferId[128];
    char bufferNombre[128];
    char bufferHorasTrabajadas[128];
    char bufferSueldo[128];


    if(pFile!= NULL && pArrayListEmployee!=NULL)
    {

        do
        {
            if(flag1)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                       bufferId,
                       bufferNombre,
                       bufferHorasTrabajadas,
                       bufferSueldo);
                flag1 = 0;
            }
            else
            {

                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                          bufferId,
                          bufferNombre,
                          bufferHorasTrabajadas,
                          bufferSueldo) == 4)
                {

                    if(!funciones_ValidIdStr(bufferId,&auxID))
                    {


                        auxiliarPunteroEmployee=(Employee*)employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

                    }


                    if(auxiliarPunteroEmployee != NULL)
                    {
                        ll_add(pArrayListEmployee, auxiliarPunteroEmployee);
                        contador++;
                    }
                    else
                    {
                        printf("\nNO FUE POSIBLE AGREGAR AL EMPLEADO ID %s\n", bufferId);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        while(!feof(pFile));
        fclose(pFile);
        printf("\n SE CARGARON DE FORMA EXITOSA %i DE EMPLEADOS\n",contador);
        retorno = 0;
    }

    return retorno;
}

/** \brief Parsea datos de los empleados desde el archivo csv .
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si logró su cometido o -1 si no lo logró.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int retorno =-1;
    int auxID;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;



    if(pFile!= NULL && pArrayListEmployee!=NULL)
    {
        Employee* auxiliarPunteroEmployee;
        int contador=0;
        do
        {
            auxiliarPunteroEmployee = employee_new();
            fread(auxiliarPunteroEmployee,sizeof(Employee),1,pFile);

            if(!employee_getEmployee(auxiliarPunteroEmployee,&auxID,auxNombre,&auxHorasTrabajadas,&auxSueldo)&& !feof(pFile))
            {
                if( funciones_isID(auxID) == 1 &&
                        funciones_isName(auxNombre) == 1 &&
                        funciones_isHorasTrabajadas(auxHorasTrabajadas) == 1 &&
                        funciones_isSueldo(auxSueldo))
                {
                    ll_add(pArrayListEmployee,auxiliarPunteroEmployee);
                    contador++;

                }

            }


        }
        while(!feof(pFile));
        fclose(pFile);
        printf("\n Se Cargaron: %i Empleados\n",contador);
        retorno = 0;

    }


    return retorno;
}



