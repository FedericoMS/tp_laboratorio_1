#include <stdio.h>
#include <string.h>
int getInt(char message[], char errorMessage[], int min, int max);
/** \brief It returns a validated int
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param min int
 * \param max int
 * \return int
 *
 */

float getFloat(char message[], char errorMessage[], int min, int max);
/** \brief it returns a validated float
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param min int
 * \param max int
 * \return float
 *
 */

char getLetter(char message[], char errorMessage[]);
/** \brief it returns a validated letter
 *
 * \param message[] char
 * \param errorMessage[] char
 * \return char
 *
 */

void getString(char message[], char errorMessage[], char string[]);
/** \brief it returns a validated string
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param str[] char
 * \return void
 *
 */

