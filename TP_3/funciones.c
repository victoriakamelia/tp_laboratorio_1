#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"


/** \brief valida que un valor sea numerico
 *
 * \param str char*  string a validar
 * \return int retorna 1 si el valor es numerico y 0 si no lo es.
 *
 */
int funciones_isNumericInteger(char *str)
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && str[i] != '-')
            return 0;
        i++;
    }
    return 1;
}

/** \brief verifica si el entero recibido es un id
 *
 * \param int id con el entero a validar
 * \return int retorna 1 si un id valido y 0 si no lo es.
 *
 */
int funciones_isID(int id)
{
    int retorno =0;

    if(id >=-1 && id <= 10000)
    {
       retorno = 1;
    }else
    {
        printf("ID INVALIDO\n");
    }

    return retorno;
}

/** \brief verifica si una cadena es un Id Valido
 *
 * \param str char*  cadena con el id a validar
 * \param id int*      valor de id a validar
 * \return int retorna 1 si es valida y 0 si no lo es.
 *
 */
int funciones_ValidIdStr(char *str, int* id)
{
    int retorno= -1;
    if(str!=NULL && id !=NULL)
    {

        if(funciones_isNumericInteger(str)==1)
        {
            *id =  atoi(str);

            if(funciones_isID(*id)==1)
            {
                retorno = 0;
            }
        }
    }
    if(retorno ==-1)
    {
        printf("ID INVALIDO\n");
    }

    return retorno;
}
/** \brief verifica si el valor recibido es numerico y esta dentro del rango
 *
 * \param str char*  horas a validar
 * \return int retorna 1 si es numerico y 0 si no lo es.
 *
 */
int funciones_isHorasTrabajadas(int horas)
{
    int retorno =-1;

    if(horas >=1 && horas <= 600)
    {
    retorno = 1;
    }else
    {
       printf("ERROR EN HORAS TRABAJADAS\n");
    }


    return retorno;
}

int funciones_isSueldo(int sueldo)
{
    int retorno =-1;

    if(sueldo >=10 && sueldo <= 600000)
        retorno = 1;

    return retorno;
}

/** \brief verifica si el valor recibido es numerico
 *
 * \param str char*  entrada a validar
 * \return int retorna 1 si es numerico y 0 si no.
 *
 */
int funciones_ValidHorasTrabajadasStr(char *str, int* auxHora)
{
    int retorno= -1;
    if(str!=NULL && auxHora !=NULL)
    {

        if(funciones_isNumericInteger(str))
        {
            *auxHora =  atoi(str);

            if(funciones_isHorasTrabajadas(*auxHora)==1)
            {
                retorno = 0;
            }
        }
    }
    if(retorno==-1)
        printf("ERROR EN HORAS TRABAJADAS\n");

    return retorno;
}

/** \brief valida sueldo
 *
 * \param str char*
 * \param sueldo int*
 * \return int retona 0 si lo logro o -1 si no lo logro.
 *
 */
int funciones_ValidSueldoStr(char *str, int* sueldo)
{
    int retorno= -1;
    if(str!=NULL && sueldo !=NULL)
    {

        if(funciones_isNumericInteger(str))
        {
            *sueldo =  atoi(str);
            if(funciones_isSueldo(*sueldo)==1)
            {
                retorno = 0;
            }
        }
    }
    if(retorno ==-1)
        printf("ERROR EN SUELDO\n");

    return retorno;
}

/** \brief verifica si el valor recibido es solo letras
 *
 * \param str char* entrada a validar
 * \return int retorna 1 si la cadena contiene solo letras y 0 si no.
 *
 */
int funciones_isOnlyLetters(char *str)
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }

        i++;
    }
    return 1;
}

/** \brief verifica si cadena es un nombre valido.
 *
 * \param name char* cadena a analizar
 * \return int retorna 1 si es nombre valido y 0 si no.
 *
 */
int funciones_isName(char *name)
{
    int retorno=-1;
    if(name!=NULL)
    {
        if(funciones_isOnlyLetters(name)==1 && strlen(name)>=2 && strlen(name)<25)
        {
            retorno= 1;

        }
        else
        {
            printf("\nNOMBRE NO ES VALIDO.");
        }
    }
    else
        printf("\nEL NOMBRE ES NULO.");

    return retorno;

}

/** \brief verifica si cadena es alfanumerica
 *
 * \param str char* cadena a analizar
 * \return int retorna 1 si cadena contiene numeros y letras y 0 si no.
 *
 */
int funciones_isAphaNumeric(char *str)
{
    int i=0;
    int retorno = -1;

    int a = 0 ;
    int numero = 0 ;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')  )
        {
            if((str[i] < '0' || str[i] > '9'))
            {
                retorno = 0;
                break;
            }
            else
            {
                numero=1;
            }
        }
        else
        {
            a=1;
        }
        i++;
    }
    if(numero+a==2)
    {
       retorno=1;
    }


    return retorno;
}


/** \brief obtiene los  datos ingresados por teclado
 *
 * \param message char* mensaje a mostrar al usuario
 * \param limite int limite de caracteres maximos a ser capturados y almacenados
 * \param outputString char* array con caracteres capturados se le quita el '\n' y se inserta en el ultimo caracter '\0'
 * \return int retorna 0 si se capturo exitosamente y -1 en caso de error
 *
 */
int funciones_getStringInput(char *message,int limite, char *outputString)
{
    char bufferString [1000];
    int retorno = -1;
    if(outputString != NULL && limite > 0)
    {
        printf("%s", message);
        fflush(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);

        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString) <= limite)
        {
            strncpy(outputString,bufferString,limite);
            retorno = 0;
        }
    }
    return retorno;

}

/** \brief funcion que solicita al usuario dato tipo entero mediante consola en un rango determinado limitado por intentos
 *
 * \param message char* mensaje inicial para el usuario
 * \param messageError char* mensaje de error en caso de ingreso de datos invalidos
 * \param reintentos int numero de intentos maximos que se tienen para ingresar dato valido
 * \param minimum int tope minimo de valor solicitado
 * \param maximum int tope maximo de valor solicitado
 * \param resultInteger int* variable con el valor entero en rango correcto
 * \return int retorna 0 si el usuario ingreso correctamente dato en rango solicitado
 *
 */
int funciones_getIntFromString(char *message, char *messageError, int reintentos, int minimum, int maximum, int *resultInteger)
{
    int retorno = -1;
    long auxiliarLong;
    char auxStr[1024];

    do
    {
        reintentos--;
        funciones_getStringInput(message, sizeof(auxStr), auxStr);

        if (funciones_isNumericInteger(auxStr) == 1)
        {
            auxiliarLong = atoi(auxStr);

            if (auxiliarLong >= minimum && auxiliarLong <= maximum)
            {
                *resultInteger = (int) auxiliarLong;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s\n", messageError);
            }

        }
        else
        {

            printf("%s\n", messageError);
        }

    }
    while (reintentos >= 0);

    return retorno;

}




/** \brief Solicita al usuario ingresar nombre limitado por numero de intentos
 *
 * \param message char* mensaje inicial para usuario
 * \param messageError char* mensaje para usiario en caso de ingresar caracteres invalidos
 * \param reintentos int munero de intentos validos
 * \param nombre char* array donde se almacena cadena de cararacterres correcta
 * \return int
 *
 */
int funciones_getName(char *message, char *messageError, int reintentos, char *nombre)
{
    int retorno = -1;
    char auxiliarChar[1024];

    do
    {
        reintentos--;
        funciones_getStringInput(message, sizeof(auxiliarChar), auxiliarChar);
        if(funciones_isName(auxiliarChar) == 1 )
        {

            strncpy(nombre,auxiliarChar,strlen(auxiliarChar)+1);
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", messageError);
        }

    }
    while (reintentos >= 0);

    return retorno;
}


/** \brief intercambia el orden de dos numeros enteros
 *
 * \param primerEntero int* Numero 1
 * \param segundoEntero int* numero 2
 * \return int int retorna 0 en caso de OK.
 *
 */
int swapInt(int* primerEntero,int* segundoEntero)
{
    int auxiliar;
    auxiliar = *primerEntero;
    *primerEntero = *segundoEntero;
    *segundoEntero = auxiliar;
    return 0;
}

/** \brief ordena ascend o desce array  de enteros mediante algoritmo burbuuja
 *
 * \param array int* array de entrada
 * \param cantidadElementos int cantidad de elementos del array
 * \param flagOrden int bandera si es 0 ordena ascendente si es 1 descendente.
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_ordenarArrayEnterosBubble(int *array, int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<cantidadElementos-1; i++)
            {
                if((array[i] < array[i+1] && flagOrden)||(array[i] > array[i+1] && !flagOrden))
                {
                    swapInt(&array[i],&array[i+1]);
                    flagSwap = 1;
                }
            }
        }
        while(flagSwap);
    }
    return retorno;
}


/** \brief intercambia el contenido de dos cadenas de caracteres
 *
 * \param primerArray char* cadena 1
 * \param segundoArray char* cadena 2
 * \return int retorna 0 si intercambio OK y -1 en caso de error
 *
 */
int funciones_swapArrayChars(char *primerArray,char *segundoArray)
{
    char auxiliar[50];
    strcpy(auxiliar,primerArray);
    strcpy(primerArray,segundoArray);
    strcpy(segundoArray,auxiliar);

    return 0;
}

/** \brief ordena cadenas dentro de array
 *
 * \param array[][50] char array de entrada a ordenar
 * \param cantidadElementos int cantidad de cadenas a ordenar
 * \param flagOrden int  badera en 1 para orden ascendente y 0 para descendente
 * \return int retorna 0 en caso de OK y -1 en caso de error
 *
 */
int funciones_sort_ordenarArrayChars(char array[][50],int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<cantidadElementos-1; i++)
            {
                if((strcmp(array[i],array[i+1])==1 && flagOrden) || ((strcmp(array[i],array[i+1])==-1 && !flagOrden)))
                {
                    funciones_swapArrayChars(array[i],array[i+1]);
                    flagSwap = 1;
                }
            }

        }
        while(flagSwap);
    }
    return retorno;
}





