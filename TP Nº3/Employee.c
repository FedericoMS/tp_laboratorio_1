#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <stdio.h>

Employee* employee_new()
{
    Employee* anEmployee;
    return anEmployee = (Employee*)malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* anEmployee;
    anEmployee = employee_new();

    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    auxId = atoi(idStr);
    strcpy(auxNombre, nombreStr);
    auxHoras = atoi(horasTrabajadasStr);
    auxSueldo = atoi(sueldoStr);

    if(anEmployee != NULL)
    {
        employee_setNombre(anEmployee, nombreStr);
        employee_setId(anEmployee, auxId);
        employee_setHorasTrabajadas(anEmployee, auxHoras);
        employee_setSueldo(anEmployee, auxSueldo);
    }

    return anEmployee;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!= NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;

}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        this->id =  id;
        retorno = 0;
    }
    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        this->horasTrabajadas =  horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;

}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    int retorno = -1;
    char auxNombre1 [128];
    char auxNombre2 [128];
    employee_getNombre(e1, auxNombre1);
    employee_getNombre(e2, auxNombre2);
    if(e1 != NULL && e2 != NULL)
    {
        if(strcmpi(auxNombre1, auxNombre2) > 0)
        {
        retorno = 1;
        }
    }

    return retorno;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int retorno = 0;
    int auxId1;
    int auxId2;
    employee_getId(e1, &auxId1);
    employee_getId(e2, &auxId2);
    if(e1 != NULL && e2 != NULL)
    {
        if(auxId1> auxId2)
        {
            retorno = 1;
        }
        else
        {
            if(auxId1 < auxId2)
            {
                retorno = -1;
            }

        }
    }

    return retorno;
}

int employee_sortEmployee(Employee* pArrayListEmployee)
{
    int respuesta;
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        printf("Elija una opcion\n");
        printf(" 1. Ordernar la lista de empleados por ID.\n");
        printf(" 2. Ordenar la lista de empleados por nombre.\n");
        printf(" 3. Volver al menu.\n");
        printf("\nOpcion: ");
        scanf("%d", &respuesta);

        switch(respuesta)
        {
        case 1:
            printf("Lista ordenada por id\n");
            ll_sort(pArrayListEmployee, employee_CompareById, 1);
            break;

        case 2:
            printf("Lista ordenada por nombre\n");
            ll_sort(pArrayListEmployee, employee_CompareByName, 1);
            break;

        case 3:
            printf("Saliendo\n\n");
            break;

        default:
            printf("Error. Opcion invalida\n");
        }

        retorno= 0;
    }
    return retorno;
}

