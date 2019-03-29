int calcularFactorial(int);
/** \Calcula el factorial de un valor num�rico entero.
 *
 * \param Recibe un entero.
 * \return Retorna un entero con el resultado del factorial.
 *
 */



float dividir(int, int);
/** \brief Divide El primer valor n�merico por el segundo valor num�rico que recibe como par�metro.
 *
 * \param int Valor num�rico dividendo.
 * \param int Valor num�rico divisor.
 * \return float Retorna el resultado de la division.
 *
 */

int ingresarNumero();
/** \brief Solicita un n�mero por consola y lo guarda como entero.
 *
 * \return Retorna el valor num�rico entero solicitado por pantalla.
 *
 */


void menuPrincipal();
/** \brief Men� que se muestra por pantalla, hasta que el usuario desee.
 *
 * \param void.
 * \return void.
 *
 */


int multiplicar(int, int);
/** \brief Recibe dos valores num�ricos enteros y los multiplica.
 *
 * \param Primer valor a multiplicar.
 * \param Segundo valor a multiplicar.
 * \return Retorna el resultado de la multiplicaci�n.
 *
 */


void primerSubmenu(int, int);
/** \brief Muestra texto por consola y llama funciones.
 *
 * \param Primer valor num�rico utilizado por las funciones.
 * \param  Segundo valor n�merico utilizado por las funciones.
 * \return Void.
 *
 */


int restar(int, int);
/** \brief Recibe dos valores numericos y los resta.
 *
 * \param Primer valor num�rico.
 * \param Segundo valor num�rico a sustraer del primero.
 * \return Retorna el resultado de la resta efectuada.
 *
 */

void segundoSubmenu(int, int);
/** \brief Muestra texto por pantalla, indicando el resultado de las operaciones efectuadas,
 *         previamente validadas. Llama a las funciones que realizar�n las operaciones.
 * \param Primer valor num�rico.
 * \param Primer valor num�rico.
 * \return Void
 *
 */

int sumar(int, int);
/** \brief Suma dos valores numericos.
 *
 * \param Primer valor num�rico.
 * \param Primer valor num�rico.
 * \return Retorna el resultado de la suma de los dos valores ingresados.
 *
 */


char validarSeguir();
/** \brief Consulta por pantalla al usuario si desea continuar.
 *
 * \return Retorna un char, que puede ser usado para levantar/bajar una bandera.
 *
 */

