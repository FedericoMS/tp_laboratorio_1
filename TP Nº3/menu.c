#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int mainMenu()
{
    int option;
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n\n");
    printf("3. Alta de empleado\n\n");
    printf("4. Modificar datos de empleado\n\n");
    printf("5. Baja de empleado\n\n");
    printf("6. Listar empleados\n\n");
    printf("7. Ordenar empleados\n\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n");
    printf("10. Salir\n\n");
    option = getInt("Ingrese la opcion deseada: ", "No ha ingresado una opcion valida, intente de nuevo: ", 1, 10);
    return option;
}
