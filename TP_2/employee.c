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


/**********************************************************************************************************/

/** \brief Imprime un mensaje consultando al usuario si desea continuar
 *
 * \return Retorna un char, 'S' o 'N'.
 *
 */
char validarSeguir()
{
    char seguir='S';
    printf("\n________________________________________________________________\n\n");
    printf("\nDESEA CONTINUAR? S/N: ");
    scanf("%s", &seguir);
    seguir=toupper(seguir);

    while(seguir != 'N' && seguir != 'S')
    {
        printf("\n________________________________________________________________\n\n");
        printf("\nLA OPCION INGRESADA ES INVALIDA.");
        printf("\nDESEA CONTINUAR? S/N: ");
        scanf("%s", &seguir);
        seguir=toupper(seguir);

    }

    return seguir;

}

/**********************************************************************************************************/

/** \brief genera automaticamente un id y solicita por pantalla datos para dar de alta un empleado.
 *
 * \param list[] Employee con el array de empleados a cargar.
 * \param tam int con el tamaño del array a cargar.
 * \param sector[] eSector con el tamaño del array a recorrer.
 * \param tamSec int con el tamaño del array a recorrer.
 * \return int retorna -1 si pudo dar de alta o 0 si lo logró.
 *
 */
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
        getText("I N G R E S E   N O M B R E:", "NOMBRE INGRESADO EXCEDE EL PERMITIDO.\n", list[id].name, 50);
        getText("I N G R E S E   A P E L L I D O: ", "APELLIDO INGRESADO EXCEDE EL PERMITIDO.\n", list[id].lastName, 50);
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

/**********************************************************************************************************/

/** \brief Recorre un array para hacer una baja lógica en el indice solicitado.
 *
 * \param emp[] Employee con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param id int el indice a dar de baja.
 * \return int -1 si no pudo lograr el objetivo o 0 si lo logró.
 *
 */
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

/**********************************************************************************************************/

/** \brief recorre un array buscando el indice del id solicitado.
 *
 * \param emp[] Employee con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param id int con el id del sector cuyo indice se desea conocer.
 * \return int retorna -1 si no encontro el indice y el numero del indice si lo encontró.
 *
 */
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

/**********************************************************************************************************/

/** \brief busca el índice del sector con el id solicitado.
 *
 * \param list[] eSector con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \param id int con el id del sector cuyo indice se desea conocer.
 * \return int retorna -1 si no encontro el indice y el numero del indice si lo encontró.
 *
 */
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

/**********************************************************************************************************/

/** \brief busca en el array si hay lugar disponible.
 *
 * \param list[] Employee con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \return int -1 si no pudo lograr el objetivo o 0 si lo logró.
 *
 */
int buscarLibre(Employee list[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && list != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(list[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**********************************************************************************************************/

/** \brief valida que la cadena que recibe solo contenga numeros.
 *
 * \param str[] char con la cadena a validar.
 * \return int retorna 0 si no es solo numeros o 1 si es solo numeros.
 *
 */
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/**********************************************************************************************************/

/** \brief valida que la cadena que recibe solo contenga letras o espacios.
 *
 * \param str[] char con la cadena a validar.
 * \return int retorna 0 si no es solo letras/espacios o 1 si es solo letras/espacios.
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

/**********************************************************************************************************/

/** \brief Recorre un array para verificar si al menos hay un registro ocupado,
 *
 * \param list[] Employee con el array a recorrer.
 * \param tam int con el tamaño del array a recorrer.
 * \return int 0 si no pudo lograr el objetivo o 1 si lo logró.
 *
 */
int hayEmpleados(Employee list[], int tam)
{
    int retorno=0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}

/**********************************************************************************************************/

/** \brief genera un id incremental desde el numero cero.
 *
 * \return int el id incrementado.
 *
 */
int generarId()
{
    static int id=0;

    return id++;
}

/**********************************************************************************************************/

/** \brief Inicializa un array
 *
 * \param list[] Employee con el array a ser recorrido.
 * \param tam int con el tamaño del array a recorrer.
 * \return int -1 si no pudo inicializar o 0 si lo logró.
 *
 */
int initEmployees(Employee list[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            list[i].isEmpty=0;
            list[i].id=0;
        }
    }
    return retorno;
}

/**********************************************************************************************************/

/** \brief Imprime un menú de opciones para que el usuario seleccione.
 *
 * \return int seleccionado por el usuario, validado.
 *
 */
int menu()
{
        int opcion;
        char opcionStr[20];

        system("cls");
        system("color 57");
        printf("   .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-. \n");
        printf(" .'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `.\n");
        printf("(    .     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .    )\n");
        printf(" `.   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   .'\n");
        printf("   )    )                                                       (    (\n");
        printf(" ,'   ,'             M E N U   D E   O P C I O N E S.            `.   `.\n");
        printf("(    (                                                             )    )\n");
        printf(" `.   `.                   1)ALTA EMPLEADO.                      .'   .' \n");
        printf("   )    )                                                      (    (\n");
        printf(" ,'   ,'                   2)MODIFICAR EMPLEADO.                `.   `.\n");
        printf("(    (                                                            )    )\n");
        printf(" `.   `.                   3)BAJA EMPLEADO.                      .'   .' \n");
        printf("   )    )                                                      (    (\n");
        printf(" ,'   ,'                   4)INFORMES.                          `.   `.\n");
        printf("(    (                                                            )    )\n");
        printf(" `.   `.                   5)SALIR.                              .'   .' \n");
        printf("   )    )       _       _       _       _       _       _       (    (\n");
        printf(" ,'   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   `.\n");
        printf("(    '  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `    )\n");
        printf("`.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .'\n");
        printf("  `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'\n");
        printf("->->->->->->->->->->->->->->->->-->->->-INGRESE OPCION SELECCIONADA: ");
        scanf("%s", opcionStr);
        printf("\n\n\n");
        while(esNumerico(opcionStr)==0)
        {
        printf("->->->->->->->->->->->->->-LA OPCION SELECCIONADA DEBE SER NUMERICA: ");
        fflush(stdin);
        scanf("%s", opcionStr);
        }
        opcion=atoi(opcionStr);

        return opcion;
}

/**********************************************************************************************************/

/** \brief Imprime un menú de opciones pra que el usuario elija.
 *
 * \return int seleccionado por el usuario.
 *
 */
int menuDos()
{
    int opcion;
        system("cls");
        system("color 57");
        printf("   .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .-. \n");
        printf(" .'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `.\n");
        printf("(    .     .-.     .-.     .-.     .-.     .-.     .-.     .-.     .    )\n");
        printf(" `.   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   .'\n");
        printf("   )    )                                                       (    (\n");
        printf(" ,'   ,'       M E N U   D E   M O D I F I C A C I O N E S.      `.   `.\n");
        printf("(    (                                                             )    )\n");
        printf(" `.   `.                   1)Modificar Nombre.                   .'   .' \n");
        printf("   )    )                                                      (    (\n");
        printf(" ,'   ,'                   2)Modificer apellido.                `.   `.\n");
        printf("(    (                                                            )    )\n");
        printf(" `.   `.                   3)Modificar salario.                 .'   .' \n");
        printf("   )    )                                                      (    (\n");
        printf(" ,'   ,'                   4)Modificer sector.                  `.   `.\n");
        printf("(    (                                                            )    )\n");
        printf(" `.   `.                                                         .'   .' \n");
        printf("   )    )       _       _       _       _       _       _       (    (\n");
        printf(" ,'   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   `.\n");
        printf("(    '  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `-'  _  `    )\n");
        printf("`.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .' `.   .'\n");
        printf("  `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'     `-'\n");
        printf("->->->->->->->->->->->->->->->->-->->->-INGRESE OPCION SELECCIONADA: ");
        scanf("%d",&opcion);

        return opcion;


}

/**********************************************************************************************************/

/** \brief muestra la totalidad de los empleados que esten activos.
 *
 * \param emp[] Employee con el array de empleados a recorrer.
 * \param tam int con el tamaño de del array de empleados a recorrer.
 * \param sector[] eSector con el array de sectores a recorrer.
 * \param tamSec int con el tamaño del array de sectores a recorrer.
 * \return int retorna -1 si no logró su objetivo y 0 si pudo lograrlo.
 *
 */
int mostrarEmpleados(Employee emp[], int tam, eSector sector[], int tamSec)
{
    int i;
    int retorno=-1;
    formatoTexto(emp, tam);
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

/**********************************************************************************************************/

/** \brief Cambia la primera letra de cada palabra a mayúscula, dejando el resto en minuscula.
 *
 * \param list[] Employee con el array de empleados a recorrer.
 * \param tam int con el tamaño del array de empleados a recorrer.
 * \return void
 *
 */
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

/**********************************************************************************************************/

/** \brief solicita por pantalla un numero flotante al usuario.
 *
 * \param list[] Employee con el array de empleados en donde se guardará el dato solicitado,¿,
 * \param indice int con el indice en donde se guardara el dato solicitado.
 * \param texto[] char con el tecto para pedir al usuario el ingreso.
 * \param textoError[] char con el texto en caso de que el usuario ingrese un dato que no cumpla con las condiciones.
 * \return void
 *
 */
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

/**********************************************************************************************************/

/** \brief Solicita al usuario por pantalla  y valida un entero.
 *
 * \param list[] Employee con el array de empleados en donde se guardará el dato.
 * \param indice int con el indice en donde se guardará el dato.
 * \param message[] char con el mensaje que se le mostrará por pantalla al usuario.
 * \param eMessage[] char con el mensaje que se le mostrará por pantalla al usuario en caso de error.
 * \param lowLimit int con el menor dato que puede ingresar.
 * \param hiLimit int con el mayor dato que puede ingresar.
 * \return void
 *
 */
void getInt(Employee list[], int indice,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int auxNum;
    char numStr[20];

    printf("\n________________________________________________________________\n\n");
    printf("\n%s", message);
    fflush(stdin);
    scanf("%s",numStr);
    while(esNumerico(numStr)==0)
    {
        printf("\n________________________________________________________________\n\n");
        printf("SOLO SE PERMITE EL INGRESO DE NUMERICOS, REINTENTE.");
        printf("\n%s", message);
        fflush(stdin);
        scanf("%s",numStr);
    }
    auxNum=atoi(numStr);
    while((auxNum<lowLimit || auxNum>hiLimit))
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", eMessage);
        scanf("%d", &auxNum);

    }


    list[indice].sector=auxNum;

}

/**********************************************************************************************************/

/** \brief Solicita un texto por pantalla al usuario y lo valida.
 *
 * \param texto[] char con el mensaje a mostrar para solicitar el dato por pantalla.
 * \param textoError[] char con el mensaje a mostrar en caso de error.
 * \param cadena[] char con la cadena en donde se guardará el texto.
 * \param largo int con el tamaño de la cadena en donde se guardará el texto.
 * \return void
 *
 */
void getText(char texto[], char textoError[], char cadena[], int largo)
{
    char auxChar[100];
    printf("\n________________________________________________________________\n\n");
    printf("\n%s", texto);
    fflush(stdin);
    gets(auxChar);
    while(esSoloLetras(auxChar)==0)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\nSOLO DEBE INGRESAR LETRAS, REINTENTE:");
        gets(auxChar);

    }
    while(strlen(auxChar)>= largo)
    {
        printf("\n________________________________________________________________\n\n");
        printf("\n%s", texto);
        printf("\n%s", textoError);
        gets(auxChar);

    }
    strcpy(cadena, auxChar);


}

/**********************************************************************************************************/

/** \brief Calcula y muestra el total de los sueldos, su promedio y a los empleados que superan ese promedio.
 *
 * \param list[] Employee con el array de empleados a recorrer.
 * \param tam int con el tamaño del array de empleados a recorrer.
 * \param sector[] eSector con el array de sectores a recorrer.
 * \param tamSec int con el tamaño del array de sectores a recorrer.
 * \return void
 *
 */
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
            formatoTexto(list, tam);
            mostrarEmpleado(list[i], sector, tamSec);
        }

    }
}

/**********************************************************************************************************/

/** \brief ordena alfabeticamente a los empleados de cada sector y los muestra por pantalla.
 *
 * \param list[] Employee con el array de empleados a recorrer.
 * \param tam int con el tamaño del array de empleados a recorrer.
 * \param sector[] eSector con el array de sectores a recorrer.
 * \param tamSec int con el tamaño de sectores a recorrer.
 * \param aux Employee con el auxiliar para swapear los datos.
 * \return void
 *
 */
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

/**********************************************************************************************************/

/** \brief muestra un empleado solicitado por pantalla
 *
 * \param emp Employee con el empleado a mostrar
 * \param sec[] eSector con el array de sectores a recorrer.
 * \param tamSec int con el tamaño del array de sectores a recorrer.
 * \return void
 *
 */
void mostrarEmpleado(Employee emp, eSector sec[], int tamSec)
{

    int idSector=emp.sector;
    int indiceSector=buscarIndiceSector(sec, tamSec, idSector);


    printf("%2d     %10s        %10s          %.2f %8d    %10s\n\n", emp.id, emp.name, emp.lastName, emp.salary, emp.sector, sec[indiceSector].nameSector );
}

/**********************************************************************************************************/

/** \brief muestra por pantalla el id y la descripcion de un array de sectores.
 *
 * \param sector[] eSector con el array de sectores a recorrer.
 * \param tamSec int con el tamaño del array de sectores a recorrer.
 * \return void
 *
 */
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
/**********************************************************************************************************/

