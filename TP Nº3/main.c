#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include <string.h>
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    LinkedList* miListaEmpleados = ll_newLinkedList();
    int contadorId = 0;
    int* pContadorId = &contadorId;
    int primeraVez = 0;
    char option;
    do
    {
        option = mainMenu();
        switch(option)
        {
        case 1:
            system("cls");
            if(primeraVez == 0)
            {
                controller_loadFromText("data.csv", miListaEmpleados);
                contadorId = ll_len(miListaEmpleados);
                primeraVez = 1;
            }
            else
            {
                ll_clear(miListaEmpleados);
                ll_deleteLinkedList(miListaEmpleados);
                miListaEmpleados = ll_newLinkedList();
                controller_loadFromText("data.csv", miListaEmpleados);
                contadorId = ll_len(miListaEmpleados);
            }
            break;
        case 2:
            system("cls");
            if(primeraVez == 0)
            {
                controller_loadFromBinary("data.bin", miListaEmpleados);
                contadorId = ll_len(miListaEmpleados);
                primeraVez = 1;
                printf("Se cargaron los empleados\n");
            }
            else
            {
                ll_clear(miListaEmpleados);
                ll_deleteLinkedList(miListaEmpleados);
                miListaEmpleados = ll_newLinkedList();
                controller_loadFromBinary("data.bin", miListaEmpleados);
                contadorId = ll_len(miListaEmpleados);
                printf("Se cargaron los empleados\n");
            }
            break;
        case 3:
            system("cls");
            controller_addEmployee(miListaEmpleados, pContadorId);
            break;
        case 4:
            system("cls");
            controller_editEmployee(miListaEmpleados);
            break;
        case 5:
            system("cls");
            controller_removeEmployee(miListaEmpleados, pContadorId);
            break;
        case 6:
            system("cls");
            controller_ListEmployee(miListaEmpleados);
            break;
        case 7:
            system("cls");
            employee_sortEmployee(miListaEmpleados);
            break;
        case 8:
            system("cls");
            controller_saveAsText("data.csv",miListaEmpleados);
            break;
        case 9:
            system("cls");
            controller_saveAsBinary("data.bin", miListaEmpleados);
            break;
        case 10:
            system("cls");
            printf("Saliendo\n");
            break;
        default:
            printf("Opcion incorrecta, por favor ingrese una opcion valida\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(option < 10);
}



























