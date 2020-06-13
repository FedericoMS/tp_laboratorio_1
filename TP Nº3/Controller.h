/** \brief It loads the data from a selected .csv archive so it can be used in a linkedlist
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief It loads the data from a selected binary archive so it can be used in a linkedlist
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief It adds a new employee in a linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \param contadorId int*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* contadorId);
/** \brief It allows the user to modify a selected field from an employee contained in a linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief It removes an employee from the linkedlist where it is contained
 *
 * \param pArrayListEmployee LinkedList*
 * \param pContadorId int*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee, int* pContadorId);
/** \brief It saves a list of employees in a linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief It allows the user to sort a linkedlist of employees by name and ID
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief It saves the data from the linkedlist as a .csv archive
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief It saves the data from the linkedlist as a .bin archive
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief It generates a new id for a new employee
 *
 * \param pArrayListEmployee LinkedList*
 * \param contadorId int*
 * \return int
 *
 */
int controller_newID(LinkedList* pArrayListEmployee, int* contadorId);

