#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char idAux[50], nombreAux[50], horasTrabajadasAux[50], sueldoAux[50];
    Employee* anEmployee;
    pFile = fopen("data.csv", "r");
    int band = 1;
    if(pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }

    do
    {
        if(band)
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            band = 0;
        }
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
        printf("Lei: %s--%s--%s--%s\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
        anEmployee = employee_newParametros(idAux, nombreAux, horasTrabajadasAux, sueldoAux);

        if(anEmployee != NULL)
        {
            ll_add(pArrayListEmployee, anEmployee);
            retorno = 1;

        }
    }while(!feof(pFile));

    fclose(pFile);
    return retorno;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* anEmployee;
    int retorno = -1;
    int flag;
    if(pFile != NULL)
    {
        do
        {

            anEmployee = employee_new();
            flag = fread(anEmployee, sizeof(Employee), 1, pFile);
            if(flag != NULL)
            {
                ll_add(pArrayListEmployee, anEmployee);
            }
        }while(!feof(pFile));

        retorno = 0;
    }
    return retorno;
}
