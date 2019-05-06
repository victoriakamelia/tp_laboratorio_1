int calcularFactorial(int);
/** \Calcula el factorial de un valor numérico entero.
 *
 * \param Recibe un entero.
 * \return Retorna un entero con el resultado del factorial.
 *
 */



float dividir(int, int);
/** \brief Divide El primer valor númerico por el segundo valor numérico que recibe como parámetro.
 *
 * \param int Valor numérico dividendo.
 * \param int Valor numérico divisor.
 * \return float Retorna el resultado de la division.
 *
 */

int ingresarNumero();
/** \brief Solicita un número por consola y lo guarda como entero.
 *
 * \return Retorna el valor numérico entero solicitado por pantalla.
 *
 */


void menuPrincipal();
/** \brief Menú que se muestra por pantalla, hasta que el usuario desee.
 *
 * \param void.
 * \return void.
 *
 */


int multiplicar(int, int);
/** \brief Recibe dos valores numéricos enteros y los multiplica.
 *
 * \param Primer valor a multiplicar.
 * \param Segundo valor a multiplicar.
 * \return Retorna el resultado de la multiplicación.
 *
 */


void primerSubmenu(int, int);
/** \brief Muestra texto por consola y llama funciones.
 *
 * \param Primer valor numérico utilizado por las funciones.
 * \param  Segundo valor númerico utilizado por las funciones.
 * \return Void.
 *
 */


int restar(int, int);
/** \brief Recibe dos valores numericos y los resta.
 *
 * \param Primer valor numérico.
 * \param Segundo valor numérico a sustraer del primero.
 * \return Retorna el resultado de la resta efectuada.
 *
 */

void segundoSubmenu(int, int);
/** \brief Muestra texto por pantalla, indicando el resultado de las operaciones efectuadas,
 *         previamente validadas. Llama a las funciones que realizarán las operaciones.
 * \param Primer valor numérico.
 * \param Primer valor numérico.
 * \return Void
 *
 */

int sumar(int, int);
/** \brief Suma dos valores numericos.
 *
 * \param Primer valor numérico.
 * \param Primer valor numérico.
 * \return Retorna el resultado de la suma de los dos valores ingresados.
 *
 */


char validarSeguir();
/** \brief Consulta por pantalla al usuario si desea continuar.
 *
 * \return Retorna un char, que puede ser usado para levantar/bajar una bandera.
 *
 */

