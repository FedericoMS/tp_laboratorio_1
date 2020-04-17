#include <stdio.h>
#include <stdlib.h>
#include "input.h"



char menu()
{
    char opcion;
    printf("\n Ingrese una opcion");
    printf("\n a. Ingresar 1er operando (A=x)");
    printf("\n b. Ingresar 2do operando (B=y)");
    printf("\n c. Calcular todas las operaciones");
    printf("\n d. Informar resultados");
    printf("\n e. Salir");
    scanf("%c", &opcion);
    return opcion;
}




long long int factorial(long long int numero)
{
    long long int factor = 1;
    int i;
    for (i = 1; i <= numero; i++)
    {
        factor = factor * i;
    }
    return factor;
}

long long int validateFact(double number)
{
    long long int factNumber;
    if (number > 0 && number == (long long int)number)
    {
        number = (long long int)number;
        factNumber = factorial(number);
    }
    else
    {
        factNumber = 0;
    }
    return factNumber;
}


double addition(float x, float y)
{
    double resultado = x + y;
    if(resultado == (int)resultado)
    {
        resultado = (int)resultado;
    }
    return resultado;

}

double substraction(float x, float y)
{
    double resultado = x - y;
    if(resultado == (int)resultado)
    {
        resultado = (int)resultado;
    }
    return resultado;

}

double multiplication (float x, float y)
{
    double resultado = x * y;
    if(resultado == (int)resultado)
    {
        resultado = (int)resultado;
    }
    return resultado;

}

double division(float x, float y)
{
    double resultado;
    if(x == 0 || y == 0)
    {
         resultado = 0;
    }
    else
    {
        resultado =  x / y;
    }
    return resultado;

}


void reportOperations (double x, double y, double suma, double resta, double division, double multiplicacion, long long int factorX, long long int factorY)
{

     printf("\nEl resultado de %.2f+%.2f es: %.2f",x, y, suma);
     printf("\nEl resultado de %.2f-%.2f es: %.2f",x, y, resta);
     if(y == 0)
     {
        printf("\nNo se puede dividir por 0");
     }
     else
     {
      printf("\nEl resultado de %.2f/%.2f es: %.2f",x, y, division);
     }
     printf("\nEl resultado de %.2f*%.2f: %.2f",x, y, multiplicacion);
    if (factorX == 0 && factorY == 0)
    {
        printf("\nNo se puede calcular el factorial de ninguno de los valores ingresados.\n");
    }
    else
    {
        if (factorX == 0)
        {
            printf("\nEl factorial de %d es: %lld", (int)y, factorY);
        }
        else
        {
            if (factorY == 0)
            {
                printf("\nEl factorial de %d es: %lld", (int)x, factorX);
            }
            else
            {
                printf("\nEl factorial de %d es %lld y el factorial de %d es %lld", (int)x, factorX, (int)y, factorY);
            }
        }
    }

}


double getDouble(char mensaje[])
{
    double dato;
    printf("%s", mensaje);
    scanf("%lf", &dato);

    return dato;
}


