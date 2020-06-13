#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief It creates the space to save an employee in dynamic memory
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief It creates the space to save an employee with its fields in dynamic memory
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief It removes an employee from the dynamic memory
 *
 * \param Employee*
 * \return void
 *
 */
void employee_delete(Employee*);

/** \brief It sets an id to an employee
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);
/** \brief It gets an id from an employee
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief It sets a name to an employee
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief It gets a name from an employee
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief It sets the worked hours to an employee
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief it gets the worked hours from an employee
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief it sets a new salary to an employee
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief it gets the salary from an employee
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief It compares the names from two selected employees
 *
 * \param e1 Employee*
 * \param e2 Employee*
 * \return int
 *
 */
int employee_CompareByName(Employee* e1, Employee* e2);

/** \brief It compares the id's from two selected employees
 *
 * \param e1 Employee*
 * \param e2 Employee*
 * \return int
 *
 */
int employee_CompareById(Employee* e1, Employee* e2);

/** \brief It sorts an employee's linkedlist
 *
 * \param pArrayListEmployee Employee*
 * \return int
 *
 */
int employee_sortEmployee(Employee* pArrayListEmployee);

#endif // employee_H_INCLUDED
