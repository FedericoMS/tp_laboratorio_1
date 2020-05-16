<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "auxiliarFunctions.h"
#include "ArrayEmployees.h"
#define TamEmpresa 1000

int main()
{
    Employee EmployeeArray[TamEmpresa];
    initEmployees(EmployeeArray, TamEmpresa);
    char opcion;
    do{
    opcion = menu();
    switch(opcion)
    {
        case 'a':
            createAnEmployee(EmployeeArray, TamEmpresa);
            fflush(stdin);
            break;

        case 'b':
            modifyEmployee(EmployeeArray, TamEmpresa);
            fflush(stdin);
            break;
        case 'c':
            findAnEmployeeToDelete(EmployeeArray, TamEmpresa);
            fflush(stdin);
            break;
        case 'd':
            reportInformation(EmployeeArray, TamEmpresa);
            fflush(stdin);
            break;
        case 'e':
            printf("Preparando para cerrar\n");
            break;
       default:
            printf("Opcion incorrecta\n");
            fflush(stdin);
            break;

    }

    system("pause");
    system("cls");
}while(opcion != 'e');

}

=======
#include <stdio.h>
#include <stdlib.h>
#include "auxiliarFunctions.h"
#include "ArrayEmployees.h"
#define TamEmpresa 1000

int main()
{
    Employee EmployeeArray[TamEmpresa];
    initEmployees(EmployeeArray, TamEmpresa);
    char opcion;
    do{
    opcion = menu();
    switch(opcion)
    {
        case 'a':
            createAnEmployee(EmployeeArray, TamEmpresa);
            fflush(stdin);
            break;

        case 'b':
            modifyEmployee(EmployeeArray, TamEmpresa);
            fflush(stdin);
            break;
        case 'c':
            findAnEmployeeToDelete(EmployeeArray, TamEmpresa);
            fflush(stdin);
            break;
        case 'd':
            reportInformation(EmployeeArray, TamEmpresa);
            fflush(stdin);
            break;
        case 'e':
            printf("Preparando para cerrar\n");
            break;
       default:
            printf("Opcion incorrecta\n");
            fflush(stdin);
            break;

    }

    system("pause");
    system("cls");
}while(opcion != 'e');

}

>>>>>>> cc9297751b537734d6ecaae03a35cd299dd089fe
