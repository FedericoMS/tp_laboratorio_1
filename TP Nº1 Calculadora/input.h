


/** \brief despliega el menu de la calculadora
 *
 * \return char, de la variable "opcion"
 *
 */
char menu();

/** \brief retorna un numero de tipo double
 *
 * \param mensaje[] char, despliega el mensaje deseado que se pase como parametro
 * \return double
 *
 */


double getDouble(char mensaje[]);


/** \brief retorna la suma de los parámetros "x" e "y"
 *
 * \param x float
 * \param y float
 * \return double
 *
 */
double addition(float x, float y);



/** \brief retorna la resta de los parámetros "x" e "y"
 *
 * \param x float
 * \param y float
 * \return double
 *
 */
double substraction(float x, float y);



/** \brief retorna la multiplicación de los parámetros "x" e "y"
 *
 * \param x float
 * \param y float
 * \return double
 *
 */
double multiplication (float x, float y);


/** \brief retorna la división entre x e y, mientras que y sea distinto de 0
 *
 * \param x float
 * \param y float
 * \return double
 *
 */
double division(float x, float y);


/** \brief retorna el factorial de un numero
 *
 * \param numero long long int
 * \return long long int
 *
 */
long long int factorial(long long int numero);

/** \brief valida y castea el double pasado por parámetro a long long int
 *
 * \param number double
 * \return long long int
 *
 */
long long int validateFact(double number);



/** \brief retorna los valores calculados previamente de las distintas operaciones
 *
 * \param x double
 * \param y double
 * \param suma double
 * \param resta double
 * \param division double
 * \param multiplicacion double
 * \param factorX long longint
 * \param factorY long longint
 * \return void
 *
 */
void reportOperations(double x, double y, double suma, double resta, double division, double multiplicacion, long long int factorX, long long int factorY);



