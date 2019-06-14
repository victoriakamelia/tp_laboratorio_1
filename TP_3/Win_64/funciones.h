#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int funciones_getIntFromString(char *message, char *messageError, int reintentos, int minimum, int maximum, int *resultInteger);
int funciones_getName(char *message, char *messageError, int reintentos, char *nombre);
int funciones_getStringInput(char *message,int limite, char *outputString);
int funciones_isAphaNumeric(char *str);
int funciones_isHorasTrabajadas(int horas);
int funciones_isID(int id);
int funciones_isName(char *name);
int funciones_isNumericFloat(char *str);
int funciones_isNumericInteger(char *str);
int funciones_isOnlyLetters(char *str);
int funciones_isSueldo(int sueldo);
int funciones_ordenarArrayEnterosBubble(int *array, int cantidadElementos, int flagOrden);
int funciones_sort_ordenarArrayChars(char array[][50],int cantidadElementos, int flagOrden);
int funciones_swapArrayChars(char *primerArray,char *segundoArray);
int funciones_ValidHorasTrabajadasStr(char *str, int* auxHora);
int funciones_ValidIdStr(char *str, int* id);
int funciones_ValidSueldoStr(char *str, int* sueldo);
int swapInt(int* primerEntero,int* segundoEntero);



#endif // FUNCIONES_H_INCLUDED
