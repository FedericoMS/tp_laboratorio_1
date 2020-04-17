#include <stdio.h>
#include <stdlib.h>
#include "input.h"



/*Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/
int main()
{
    char opcion;
    double a;
    double b;
    double sumados;
    double restados;
    double multiplicados;
    double divididos;
    int primeraVez = 0;
    long long int factA = 0;
    long long int factB = 0;
    do{
    opcion = menu();
    switch(opcion)
    {
        case 'a':
            a = getDouble("Ingrese un numero");
            primeraVez = 1;
            fflush(stdin);
            break;

        case 'b':
            b = getDouble("Ingrese un numero");
            primeraVez = 1;
            fflush(stdin);
            break;
        case 'c':
            sumados = addition(a, b);
            restados = substraction(a, b);
            multiplicados = multiplication (a, b);
            divididos = division(a, b);
            factA = validateFact(a);
            factB = validateFact(b);
            printf("Las operaciones han sido calculadas.");
            fflush(stdin);
            break;
        case 'd':
            if(primeraVez == 0)
            {
                printf("No se ingreso ningun valor\n");
                break;
            }
            else
            {
            reportOperations((int)a, (int)b,  sumados, restados,  divididos,  multiplicados, factA, factB);
            fflush(stdin);
            }
            break;
        case 'e':
            break;
        default:
            printf("Opcion incorrecta\n");
            fflush(stdin);

    }

    system("pause");
    system("cls");



    }while(opcion != 'e');

}


