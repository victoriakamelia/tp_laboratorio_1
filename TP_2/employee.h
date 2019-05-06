
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

typedef struct
{
    int idSector;
    char nameSector[30];

} eSector;


int menu();
int menuDos();
char validarSeguir();
int initEmployees(Employee list[],int tam);
int buscarLibre(Employee list[],int tam);
