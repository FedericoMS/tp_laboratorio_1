#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funcionesGet.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    if(pFile != NULL)
    {
        pFile = fopen(path, "r");
        parser_EmployeeFromText(pFile, pArrayListEmployee);
    }
    else
    {
        printf("\nNo existe el archivo\n");
    }
    fclose(pFile);

    return 1;

}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    if(pFile != NULL)
    {
        pFile = fopen(path, "rb");
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        printf("\nNo existe el archivo\n");
    }
    fclose(pFile);

    return 1;;
}

int controller_newID(LinkedList* pArrayListEmployee, int* pContadorId)
{
    int newId;
    if(pContadorId != NULL)
    {
        newId = *pContadorId + 1;
    }
    return newId;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* pContadorId)
{

    Employee* anEmployee;
    anEmployee = employee_new();

    int auxId = controller_newID(pArrayListEmployee, pContadorId);
    char auxSueldo[50];
    char auxHorasTrabajadas[50];
    char auxNombre[50] ;
    int retorno = -1;

    int newSueldo;
    int newHorasTrabajadas;

    if(pArrayListEmployee != NULL)
    {
        getStringLetras("Ingrese el nombre del empleado nuevo\n","Error, nombre no valido\n", auxNombre);
        getStringNumeros("Ingrese el sueldo del empleado\n","Error, sueldo no valido\n", auxSueldo);
        getStringNumeros("Ingrese las horas trabajadas del empleado\n","Error, horas no validas\n", auxHorasTrabajadas);
    }

    newSueldo = atoi(auxSueldo);
    newHorasTrabajadas = atoi(auxHorasTrabajadas);
    stringToUpper(auxNombre);

    if(anEmployee != NULL)
    {
        employee_setId(anEmployee, auxId);
        employee_setNombre(anEmployee, auxNombre);
        employee_setHorasTrabajadas(anEmployee, newHorasTrabajadas);
        employee_setSueldo(anEmployee, newSueldo);
        ll_add(pArrayListEmployee, anEmployee);
        retorno = 0;
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* anEmployee;
    int i;
    int retorno = -1;
    char idChar[50];
    char opcionChar[50];
    char auxNombre[128];
    char sueldoChar[50];
    char horasTrabajadasChar[50];
    char opcionModificacion;
    int size;
    int idCharAux;
    int idObtenido;
    int opcionCharAux;
    int sueldoCharAux;
    int horasTrabajadasCharAux;

    if(pArrayListEmployee != NULL)
    {
        getStringNumeros("Ingrese el id del empleado que desea modificar \n", "Error, el id ingresado no es valido\n", idChar);
        idCharAux = atoi(idChar);
        size = ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            anEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(anEmployee, &idObtenido);
            if(idCharAux == idObtenido)
            {
                {
                    printf("Opciones:\n");
                    printf("\n 1. Modificar nombre del empleado.");
                    printf("\n 2. Modificar sueldo del empleado.");
                    printf("\n 3. Modificar horas trabajadas del empleado.");
                    printf("\n 4. Volver al menu.");
                    getStringNumeros("\nIngrese la opcion deseada: ", "\nError, el id ingresado no es valido\n", opcionChar);
                    opcionCharAux=atoi(opcionChar);

                    switch(opcionCharAux)
                    {
                    case 1:
                        getStringLetras("Ingrese el nombre nuevo del empleado\n","Error, nombre no valido\n", auxNombre);
                        stringToUpper(auxNombre);
                        printf("Esta seguro de que quiere cambiar el nombre del empleado por %s? Ingrese 's' para confirmar\n", auxNombre);
                        fflush(stdin);
                        scanf("%c", &opcionModificacion);
                        if(opcionModificacion == 's')
                        {
                            employee_setNombre(anEmployee, auxNombre);
                            retorno = 0;
                            break;
                        case 2:
                            getStringNumeros("Ingrese el nuevo sueldo del empleado\n","Error, sueldo no valido\n", sueldoChar);
                            sueldoCharAux= atoi(sueldoChar);
                            printf("Esta seguro de que quiere cambiar el sueldo del empleado por %d? Ingrese 's' para confirmar\n", sueldoCharAux);
                            fflush(stdin);
                            scanf("%c", &opcionModificacion);
                            if(opcionModificacion == 's')
                            {
                                employee_setSueldo(anEmployee, sueldoCharAux);
                                retorno = 0;
                                break;
                            }

                        case 3:
                            getStringNumeros("Ingrese las horas trabajadas del empleado\n","Error, horas trabajadas no validas\n", horasTrabajadasChar);
                            horasTrabajadasCharAux= atoi(horasTrabajadasChar);
                            printf("Esta seguro de que quiere modificar las horas trabajadas del empleado por %d? Ingrese 's' para confirmar\n", horasTrabajadasCharAux);
                            fflush(stdin);
                            scanf("%c", &opcionModificacion);
                            if(opcionModificacion == 's')
                            {
                                employee_setHorasTrabajadas(anEmployee, horasTrabajadasCharAux);
                                retorno = 0;
                                break;
                            }

                        case 4:
                            printf("\nSaliendo\n");
                            break;

                        default:
                            printf("Error. Opcion invalida.\n");
                        }
                    }
                }
            }
        }
    }

    return retorno;
}
int controller_removeEmployee(LinkedList* pArrayListEmployee, int* pContadorId)
{
    int i;
    int size;
    Employee* anEmployee;
    char idAux[30];
    int idAuxConv;
    int idBuscado;
    char opcion = getLetter("Desea eliminar un empleado? Ingrese 's' para confirmar\n", "Error, la opcion ingresada es invalida\n");
    char respuesta;
    if(opcion == 's')
    {
        do
        {
            getStringNumeros("Seleccione el id del empleado que quiere eliminar\n", "Error, el id ingresado no es valido\n", idAux);
            idAuxConv = atoi(idAux);

            if(idAuxConv <= *pContadorId)
            {
                size = ll_len(pArrayListEmployee);
                for(i=0; i<size; i++)
                {
                    anEmployee = ll_get(pArrayListEmployee, i);
                    employee_getId(anEmployee, &idBuscado);
                    if(idBuscado == idAuxConv)
                    {
                        respuesta = getLetter("Esta seguro de que desea eliminar dicho empleado? Ingrese 's' para confirmar\n", "Error, la opcion ingresada es invalida\n");
                        if(respuesta == 's')
                        {
                            printf("Se ha eliminado el empleado\n");
                            ll_remove(pArrayListEmployee, i);
                            break;
                        }
                        else
                        {
                            printf("No se elimino ningun empleado\n");
                            break;
                        }

                    }
                }
            }
        }
        while(opcion != 's' || idAuxConv > *pContadorId);
    }
    else
    {
        printf("Volviendo al menu principal\n");
    }


    return 1;
}






int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int idAux;
    int sueldoAux;
    int horasTrabajadasAux;
    char nombreAux[50];
    int retorno = -1;
    int sizeList = NULL;
    Employee* anEmployee;

    if(pArrayListEmployee != NULL)
    {
        printf("\n ID--------- Nombre --------- HorasTrabajadas ------- Sueldo \n");
        retorno = 0;
        sizeList = ll_len(pArrayListEmployee);
        for(i=0; i< sizeList; i++)
        {
            anEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(anEmployee, &idAux);
            employee_getNombre(anEmployee, nombreAux);
            employee_getSueldo(anEmployee, &sueldoAux);
            employee_getHorasTrabajadas(anEmployee, &horasTrabajadasAux);
            printf("%4d %14s %18d %20d \n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);

        }
    }
    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        employee_sortEmployee(pArrayListEmployee);
        retorno = 1;
    }
return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* anEmployee;
    int i;
    int* idAux;
    char* nombreAux;
    int* sueldoAux;
    int* horasTrabajadasAux;
    int size;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        idAux = malloc(sizeof(int));
        nombreAux = malloc(sizeof(char)*128);
        sueldoAux = malloc(sizeof(int));
        horasTrabajadasAux = malloc(sizeof(int));

        pFile = fopen(path, "w");
        fprintf(pFile, "ID,Nombre,HorasTrabajadas,Sueldo\n");
        size = ll_len(pArrayListEmployee);
        for(i=0; i < size; i++)
        {
            anEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(anEmployee, idAux);
            employee_getNombre(anEmployee, nombreAux);
            employee_getSueldo(anEmployee, sueldoAux);
            employee_getHorasTrabajadas(anEmployee, horasTrabajadasAux);
            fprintf(pFile, "%d,%s,%d,%d\n", *idAux, nombreAux, *sueldoAux, *horasTrabajadasAux);
        }

        free(nombreAux);
        free(idAux);
        free(sueldoAux);
        free(horasTrabajadasAux);
        fclose(pFile);
        printf("Se guardaron los datos correctamente\n");
    }
    else
    {
        printf("No se guardó el archivo\n");
    }
    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* anEmployee;
    int i;
    int size;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        size = ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            anEmployee = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(anEmployee, sizeof(Employee), 1, pFile);
        }
        fclose(pFile);
        printf("Se guardo el archivo correctamente\n");
    }
    else
    {
        printf("No se pudo guardar el archivo\n");
    }
    return 1;
}


