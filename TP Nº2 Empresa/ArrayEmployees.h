#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1
#include <string.h>
struct
{
int id;
char name[21];
char lastName[21];
float salary;
int sector;
int status;
}typedef Employee;



int findEmptyPlace(Employee arrayEmployees[],int length);
/** \brief it searches an empty place in the array
 *
 * \param arrayEmployees[] Employee
 * \param length int
 * \return int
 *
 */

void findAnEmployeeToDelete(Employee arrayEmployees[], int length);
/** \brief It seeks an employee to delete
 *
 * \param arrayEmployees[] Employee
 * \param length int
 * \return void
 *
 */


void modifyEmployee(Employee arrayEmployees[], int length);
/** \brief it allows the user to modify a previously selected employee from the array
 *
 * \param arrayEmployees[] Employee
 * \param length int
 * \return void
 *
 */



Employee modifyItem(Employee anEmployee);
/** \brief It displays a menu to allow the user modify an employee
 *
 * \param anEmployee Employee
 * \return Employee
 *
 */

void reportInformation(Employee arrayEmployees[], int length);
/** \brief it reports information such as the average wage and a list ordered alphabetically
 *
 * \param arrayEmployees[] Employee
 * \param length int
 * \return void
 *
 */

float promedio(int acumuladorValores, int cantidadValores);
/** \brief it returns the average
 *
 * \param acumuladorValores int
 * \param cantidadValores int
 * \return float
 *
 */


int salariesAboveTheAverage(Employee arrayEmployees[], int length);

/** \brief it returns the quantity of employees with salaries over the average
 *
 * \param arrayEmployees[] Employee
 * \param length int
 * \return int
 *
 */

float averageSalaryAmongEmployees(Employee arrayEmployees[], int length);
/** \brief it returns the average among employees
 *
 * \param arrayEmployees[] Employee
 * \param length int
 * \return float
 *
 */


int initEmployees(Employee arrayEmployees[], int length);
/** \brief To indicate that all positions in the array are empty, this function puts ,,,,,
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/


int addEmployee(Employee arrayEmployees[], int length, int id, char name[],char lastName[],float salary,int sector);
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space]
*/



void createAnEmployee (Employee arrayEmployees[],int length);
/** \brief create an employee by asking for its information
 *
 * \param  Employee arrayEmployees []
 * \param int length
 * \return void
 */


int findEmployeeById(Employee arrayEmployees [], int length,int id);
/** \brief it seeks an employee by its id
 *
 * \param [] Employee arrayEmployees
 * \param length int
 * \param id int
 * \return int
 *
 */




void reportAverageSalary(float promedio);
/** \brief  it shows the average salary of the company
 *
 * \param promedio float
 * \return void
 *
 */


int removeEmployee(Employee arrayEmployees [], int length, int id);
/** \brief It deletes an employee by changing its status to LIBRE
 *
 * \param [] Employee arrayEmployees
 * \param length int
 * \param id int
 * \return int
 *
 */



int sortEmployees(Employee arrayEmployees [], int length, int order);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param [] Employee arrayEmployees
* \param length int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/


int printEmployees(Employee arrayEmployees[], int length);
/** \brief print the content of employees array
*
* \param [] Employee arrayEmployees
* \param length int
* \return int
*
*/


void printAnEmployee(Employee anEmployee);
/** \brief print an employee
 *
 * \param anEmployee Employee
 * \return void
 *
 */


char menu();
/** \brief it displays a menu
 *
 * \return char
 *
 */


int generateNewID (Employee arrayEmployees [], int length);
/** \brief generates an id for a new employee
 *
 * \param  Employee arrayEmployees []
 * \param int length
 * \return void
 */

 int verifyExistenceOfEmployees(Employee arrayEmployees [], int length);

