#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesGet.h"

int getInt(char mensaje[])
{
    int auxiliarInt;
    printf("%s", mensaje);
    scanf("%d", &auxiliarInt);
    return auxiliarInt;
}


char getLetter(char message[], char errorMessage[])
{
    char letter;
    printf("%s", message);
    fflush(stdin);
    scanf("%c", &letter);
    while((letter<'a' || letter>'z') && (letter<'A' || letter>'Z'))
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%c", &letter);
    }
    return letter;
}

void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0;i<largo;i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}



int esNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}


void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);

}



int getStringLetras(char mensaje[],char mensajeError[], char input[])
{

    char auxiliar[50];
    getString(mensaje, auxiliar);
    while(!esSoloLetras(auxiliar))
    {
        printf("%s", mensajeError);
        getString(mensaje, auxiliar);

    }
    strcpy(input, auxiliar);
    return 1;
}



int getStringNumeros(char mensaje[],char mensajeError[], char input[])
{
    char auxiliar[50];
    getString(mensaje, auxiliar);
    while(!esNumerico(auxiliar))
    {

        printf("%s", mensajeError);
        getString(mensaje, auxiliar);
    }
    strcpy(input, auxiliar);
    return 1;

}

