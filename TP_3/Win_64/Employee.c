


#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


/** \brief Busca lugar en memoria para guardar un empleado.
 *
 * \return Employee* retorna un empleado.
 *
 */
Employee* employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

/** \brief Libera el espacio utilizado por un empleado.
 *
 * \param this Employee* recibe un empleado.
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    free(this);
}

/** \brief Carga un nuevo empleado.
 *
 * \param idStr char* carag el id de un empleado.
 * \param nombreStr char* carga el nombre de un empleado.
 * \param horasTrabajadasStr char* caraga las horas trabajadas de un empleado.
 * \param sueldoStr char* cargar el sueldo de un empleado.
 * \return Employee* Si logró su proposito devuelve un puntero con la direc del empleado, caso contrario devuelve NULL
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr, char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=employee_new();
    int auxId;
    int auxHoras;
    int auxSueldo;

    if(!funciones_ValidIdStr(idStr,&auxId) &&
            funciones_isName(nombreStr) == 1 &&
            !funciones_ValidHorasTrabajadasStr(horasTrabajadasStr,&auxHoras)&&
            !funciones_ValidSueldoStr(sueldoStr,&auxSueldo))
    {

        if(
            !employee_setId(this,auxId)&&
            !employee_setNombre(this,nombreStr)&&
            !employee_setHorasTrabajadas(this,auxHoras)&&
            !employee_setSueldo(this,auxSueldo))
            return this;
    }
    else
    {
        printf("ERROR EN LOS DATOS INGRESADOS.");
    }

    employee_delete(this);
    return NULL;
}

/** \brief setea el id de un empleado.
 *
 * \param this Employee* con el empleado cuyo id se debe setear
 * \param id int con el id a setear.
 * \return int devuelve -1 si no lo logró o 0 si lo logró.
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/** \brief Imprime en pantalla todos los empleados dentro del linkedList
 *
 * \param pEmployee Employee*
 * \return void
 *
 */
void employee_printEmployee(Employee* pEmployee)
{
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;

    if(pEmployee!= NULL)
    {
        if( !employee_getEmployee(pEmployee,&bufferId,bufferNombre,&bufferHorasTrabajadas,&bufferSueldo))
        {
            printf("\n%4d - %-20s - %-6d  - $%6d", bufferId,bufferNombre, bufferHorasTrabajadas,bufferSueldo);

        }
    }
}

/** \brief hace un get de todos los campos y los carga al elemento this
 *
 * \param this Employee*
 * \param id int*
 * \param nombre char*
 * \param horasTrabajadas int*
 * \param Sueldo int*
 * \return int
 *
 */
int employee_getEmployee(Employee* this,int* id,char* nombre, int* horasTrabajadas, int* Sueldo)
{

    int retorno =-1;


    if(this!= NULL)
    {
        if( !employee_getId(this,id)&&
                !employee_getNombre(this, nombre) &&
                !employee_getHorasTrabajadas(this,horasTrabajadas)&&
                !employee_getSueldo(this, Sueldo))
        {

            retorno =0;

        }
    }
    return retorno;
}

/** \brief compara dos empleados por nombre
 *
 * \param pEmployeeA void*
 * \param pEmployeeB void*
 * \return int
 *
 */
int employee_compareEmployee(void* pEmployeeA,void* pEmployeeB)
{
    if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre)>0)
    {
        return 1;
    }
    else if(strcmp(((Employee*)pEmployeeA)->nombre,((Employee*)pEmployeeB)->nombre)<0)
    {
        return -1;
    }
    else

    return 0;

}
