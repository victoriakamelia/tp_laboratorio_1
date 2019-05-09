
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

typedef struct
{
    int idSector;
    char nameSector[30];

}eSector;


char validarSeguir();

int addEmployee(Employee list[], int tam, eSector sector[], int tamSec);
int bajaEmpleado(Employee emp[],int tam, int id);
int buscarId(Employee emp[], int tam, int id);
int buscarIndiceSector(eSector list[], int tam,int id);
int buscarLibre(Employee list[],int tam);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int hayEmpleados(Employee list[], int tam);
int generarId();
int initEmployees(Employee list[],int tam);
int menu();
int menuDos();
int mostrarEmpleados(Employee list[], int tam, eSector sector[], int tamSec);
int validarFloat(char str[]);

void formatoTexto(Employee list[], int tam);
void getFloat(Employee list[],int indice, char texto[]);
void getInt(Employee list[], int indice,char message[],char eMessage[], int lowLimit, int hiLimit);
void getText(char texto[], char textoError[], char cadena[], int largo);
void listarDos(Employee list[], int tam, eSector sector[], int tamSec);
void listarUno(Employee list[], int tam, eSector sector[], int tamSec, Employee aux);
void mostrarEmpleado(Employee emp, eSector sec[], int tamSec);
void mostrarSectores(eSector sector[], int tamSec);

