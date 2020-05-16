#include "ArrayEmployees.h"
#include "auxiliarFunctions.h"
char menu()
{
    char opcion;
    printf("Ingrese una opcion");
    printf("\n a. Altas.");
    printf("\n b. Modificar");
    printf("\n c. Baja");
    printf("\n d. Informar");
    printf("\n e. Salir\n");
    opcion = getLetter("Ingrese una letra de la lista para seleccionar una opcion\n", "Error, opcion no valida\n");
    return opcion;
}

void modifyEmployee(Employee arrayEmployees[], int length)
{
    if(verifyExistenceOfEmployees(arrayEmployees, length))
    {
        char respuesta;
        int i;
        int idAux;
        system("cls");
        int existeEmpleado = 0;
        respuesta = getLetter("Desea modificar algun empleado? Ingrese s para cofirmar\n", "Error, opcion no valida\n");
        if(respuesta == 's')
        {
            printEmployees(arrayEmployees, length);
            idAux = getInt("Ingrese el ID del empleado para modificar\n", "Error, el valor ingresado no es valido\n", 100, 1200);
            for(i=0; i<length; i++)
            {
                if(idAux == arrayEmployees[i].id)
                {
                    arrayEmployees[i] = modifyItem(arrayEmployees[i]);
                    existeEmpleado = 1;
                }

                else
                {
                    if(i == length)
                    {
                        printf("El id ingresado es incorrecto o no existe\n");
                    }
                }

            }
        }
        if(existeEmpleado == 0)
        {
            printf("El id ingresado es incorrecto o no existe\n");
        }
    }
    else
    {
        printf("No hay empleados en la empresa\n");
    }


}

Employee modifyItem(Employee anEmployee)
{
    Employee modifiedEmployee = anEmployee;
    char opcion;
    printf("Que desea modificar?");
    printf("\n Ingrese una opcion: ");
    printf("\n a. Nombre.");
    printf("\n b. Apellido.");
    printf("\n c. Salario.");
    printf("\n d. Sector.");
    printf("\n e. Salir.\n");
    opcion = getLetter("Ingrese una letra de la lista para seleccionar una opcion\n", "Error, opcion no valida\n");
    switch(opcion)
    {
        case 'a':
            getString("Ingrese el nuevo nombre: \n", "Error, ingrese un nombre valido\n" , modifiedEmployee.name);
            printf("Desea confirmar el cambio del nombre de su empleado por %s ? Ingrese s para confirmar\n", modifiedEmployee.name);
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                anEmployee = modifiedEmployee;
                printf("Se cambio el nombre a: %s\n", anEmployee.name);
            }
            else
            {
                printf("No se cambio el nombre\n");
            }
            fflush(stdin);
            break;

        case 'b':
            getString("Ingrese el nuevo apellido: \n", "Error, ingrese un nombre valido\n" , modifiedEmployee.lastName);
            printf("Desea confirmar el cambio de apellido de su empleado por %s ? Ingrese s para confirmar\n", modifiedEmployee.lastName);
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                anEmployee = modifiedEmployee;
                printf("Se cambio el apellido a: %s\n", anEmployee.lastName);
            }
            else
            {
                printf("No se cambio el apellido\n");
            }
            fflush(stdin);
            break;
        case 'c':
            modifiedEmployee.salary = getFloat("Ingrese el nuevo salario para su empleado entre 1 y 1000000\n", "Error, ingrese un salario valido\n", 1, 1000000);
            printf("Desea confirmar el cambio de salario de su empleado por %.2f ? Ingrese s para confirmar\n", modifiedEmployee.salary);
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                anEmployee = modifiedEmployee;
                printf("Se cambio el salario a: %.2f\n", anEmployee.salary);
            }
            else
            {
                printf("No se cambio el salario\n");
            }
            fflush(stdin);
            break;
        case 'd':
            modifiedEmployee.sector = getInt("\nIngrese el nuevo sector para su empleado entre 1 y 20\n", "Error, ingrese un sector valido\n", 1, 20);
            printf("Desea confirmar el cambio de sector de su empleado por %d ? Ingrese s para confirmar\n", modifiedEmployee.sector);
            fflush(stdin);
            scanf("%c", &opcion);
            if(opcion == 's')
            {
                anEmployee = modifiedEmployee;
                printf("Se cambio el sector a: %d\n", anEmployee.sector);
            }
            else
            {
                printf("No se cambio el sector\n");
            }
             fflush(stdin);
             break;
        case 'e':
            break;
        default:
            printf("Opcion incorrecta\n");
            fflush(stdin);

    }
    return modifiedEmployee;

}


void createAnEmployee (Employee arrayEmployees[], int length)
{
  Employee anEmployee;

    system("cls");
    anEmployee.id = getNewID(arrayEmployees, length);
    getString("Ingrese el nombre: \n", "Error, ingrese un nombre valido\n" , anEmployee.name);
    getString("Ingrese el apellido: \n", "Error, ingrese un apellido valido\n" , anEmployee.lastName);
    anEmployee.salary = getFloat("Ingrese el  salario para su empleado entre 1 y 1000000\n", "Error, ingrese un salario valido\n", 1, 1000000);
    anEmployee.sector = getInt("Ingrese el sector para su empleado entre 1 y 20\n", "Error, ingrese un sector valido\n", 1, 20);
    addEmployee(arrayEmployees, length, anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);


}

int addEmployee(Employee arrayEmployees[], int length, int id, char name[],char lastName[],float salary,int sector)
{
    int indice;
    indice = findEmptyPlace(arrayEmployees, length);

    if(indice != -1)
    {
        arrayEmployees[indice].id = id;
        strcpy(arrayEmployees[indice].name, name);
        strcpy(arrayEmployees[indice].lastName, lastName);
        arrayEmployees[indice].salary = salary;
        arrayEmployees[indice].sector = sector;
        arrayEmployees[indice].status = OCUPADO;

    }
    else
    {
        printf("No hay lugar disponible\n");
    }
    return indice;
}


void getAverageAndSortedList(Employee arrayEmployees [], int length)
{
    if(verifyExistenceOfEmployees(arrayEmployees, length))
    {
        system("cls");
        char opcion;
        printf("\n a. Ordenar y listar los empleados alfabeticamente por apellido y sector");
        printf("\n b. Promedio de sueldos y la cantidad de empleados que superan el salario promedio.");
        printf("\n c. Salir\n");
        opcion = getLetter("Ingrese una letra de la lista para seleccionar una opcion\n", "Error, opcion no valida\n");
        switch(opcion)
        {
        case 'a':
            sortEmployees(arrayEmployees, length, 1);
            printEmployees(arrayEmployees, length);
            break;

        case 'b':
            printf("El promedio de sueldos entre empleados de la compania es %.2f\n", averageSalaryAmongEmployees(arrayEmployees, length));
            printf("La cantidad de empleados con salarios superior al promedio son: %d\n", salariesAboveTheAverage(arrayEmployees, length));
            break;
        case 'c':
            printf("Preparando para cerrar\n");
            break;
       default:
            break;
        }
    }
    else
    {
        printf("No existen empleados en la empresa\n");
    }

}


float averageSalaryAmongEmployees(Employee arrayEmployees [], int length)
{
    int i;
    int sumatoriaDeSalarios = 0;
    int cantidadDeEmpleados = 0;
    float promedioSueldos = 0;
    for(i=0; i<length; i++)
    {
        if(arrayEmployees[i].status == OCUPADO)
        {
            sumatoriaDeSalarios = sumatoriaDeSalarios + arrayEmployees[i].salary;
            cantidadDeEmpleados++;
        }
    }
    promedioSueldos  = promedio(sumatoriaDeSalarios, cantidadDeEmpleados);
    return promedioSueldos;
}

float promedio(int acumuladorValores, int cantidadValores)
{
    float resultado;
    resultado = (float)acumuladorValores / cantidadValores;
    return resultado;
}

int salariesAboveTheAverage(Employee arrayEmployees [], int length)
{
    int i;
    int empleadosConSalarioSuperior = 0;

    for(i=0; i<length; i++)
    {
        if(arrayEmployees[i].salary > averageSalaryAmongEmployees(arrayEmployees, length) && arrayEmployees[i].status == OCUPADO)
        {
            empleadosConSalarioSuperior++;
        }
    }

    return empleadosConSalarioSuperior;
}

int getNewID(Employee arrayEmployees [], int length)
{
    int i;
    int newId;

    for(i=0; i<length; i++)
    {
        if(arrayEmployees[i].status == LIBRE && i == 0)
        {
            newId = 100;
            break;
        }
        else
        {

            if(arrayEmployees[i].status == LIBRE && arrayEmployees[i].id != (100+i))
            {
             newId = arrayEmployees[i-1].id;
             newId++;
             break;
            }
        }
    }
    return newId;
}

int initEmployees(Employee arrayEmployees [], int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        arrayEmployees[i].status = 0;
    }

    return 0;
}

int findEmptyPlace(Employee arrayEmployees [],int length)
{
    int i;
    int indice = -1;
    for(i=0; i<length; i++)
    {
        if(arrayEmployees[i].status==LIBRE)
        {
            indice = i;
            break;
        }
   }
   return indice;
}

int getEmployeeById(Employee arrayEmployees [], int length, int id)
{
    int i;
    int posicionEnIndice = -1;
    for(i=0; i<length; i++)
    {
        if(arrayEmployees[i].id == id)
        {
            posicionEnIndice = i;
        }

    }
    return posicionEnIndice;
}

void validateId(int index)
{
    if(index == -1)
    {
        printf("El id ingresado no existe\n");
    }


}

void getEmployeeToDelete(Employee arrayEmployees [], int length)
{
    if(verifyExistenceOfEmployees(arrayEmployees, length))
    {
        system("cls");
        int idEmpleadoABorrar;
        char opcion;
        printEmployees(arrayEmployees, length);
        idEmpleadoABorrar = getInt("Ingrese el ID del empleado que desea eliminar\n", "Error, ingrese el id de nuevo\n", 99, 1100);
        printf("Esta seguro de que quiere borrar dicho empleado? Ingrese s para confirmar\n");
        fflush(stdin);
        scanf("%c", &opcion);
        if(opcion == 's')
        {
            deleteEmployee(arrayEmployees, length, idEmpleadoABorrar);
        }
        else
        {
            printf("\nNo se borro ningun empleado.");
        }
    }
    else
    {
        printf("No existen empleados en la empresa\n");
    }
}


int deleteEmployee(Employee arrayEmployees [], int length, int id)
{
    int i;
    int retorno = -1;
    for(i=0; i<length; i++)
    {
        if(arrayEmployees[i].id == id)
        {
            arrayEmployees[i].status = LIBRE;
            retorno = 0;
        }
    }
    return retorno;
}

int sortEmployees(Employee arrayEmployees [], int length, int order)
{
    int i;
    int j;
    int retorno = -1;
    Employee auxEmployee;
    for(i=0; i<length - 1; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(order == 1 && strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) > 0)
            {
                auxEmployee = arrayEmployees[i];
                arrayEmployees[i] = arrayEmployees[j];
                arrayEmployees[j] = auxEmployee;
                retorno = 0;
            }
            else
            {
                if((order == 1 && strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) == 0) && arrayEmployees[i].sector > arrayEmployees[j].sector)
                {
                    auxEmployee = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = auxEmployee;
                    retorno = 0;
                }
            if(order == 0 && strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) < 0)
            {
                auxEmployee = arrayEmployees[i];
                arrayEmployees[i] = arrayEmployees[j];
                arrayEmployees[j] = auxEmployee;
                retorno = 0;
            }
            else
            {
                if((order == 0 && strcmp(arrayEmployees[i].lastName, arrayEmployees[j].lastName) == 0) && arrayEmployees[i].sector > arrayEmployees[j].sector)
                {
                    auxEmployee = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = auxEmployee;
                    retorno = 0;
                }
            }
        }
    }
}

    return retorno;
}



int printEmployees(Employee arrayEmployees[], int length)
{
    int i;
    printf("%4s %18s %18s %18s %18s \n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
    for(i=0; i<length; i++)
    {
        if(arrayEmployees[i].status == OCUPADO)
        {

            printAnEmployee(arrayEmployees[i]);
        }

    }
    return 0;
}


void printAnEmployee(Employee anEmployee)
{
    printf("%4d %17s %17s %19.2f %17d \n",anEmployee.id,
                                         anEmployee.name,
                                         anEmployee.lastName,
                                         anEmployee.salary,
                                         anEmployee.sector
                                         );
}

int verifyExistenceOfEmployees(Employee arrayEmployees [], int length)
 {
     int i;
     int verificacion = 0;
     for(i=0; i<length; i++)
     {
         if(arrayEmployees[i].status == OCUPADO)
         {
             verificacion = 1;
             break;
         }
     }

     return verificacion;
 }
