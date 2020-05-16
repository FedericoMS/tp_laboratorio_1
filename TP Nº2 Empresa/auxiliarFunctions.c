#include "auxiliarFunctions.h"
#include <stdio.h>
#include <stdlib.h>
void getString(char message[], char errorMessage[], char string[])
{
    printf("%s", message);
    fflush(stdin);
    gets(string);
    int i;
    for(i=0; string[i]!= '\0'; i++)
    {
        while((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
        {
            printf("%s", errorMessage);
            fflush(stdin);
            gets(string);
            i=0;
        }
    }
}

float getFloat(char message[], char errorMessage[], int min, int max)

{
    float a;
    printf("%s", message);
    scanf("%f", &a);
    while(a < min || a > max)
    {
        printf("%s", errorMessage);
        scanf("%f", &a);
    }
    return a;
}

char getLetter(char message[], char errorMessage[])
{
    char letter;
    printf("%s", message);
    fflush(stdin);
    scanf("%c", &letter);
    while((letter < 'a' || letter > 'z') && (letter < 'A' || letter > 'Z'))
    {
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%c", &letter);
    }
    return letter;
}

int getInt(char message[], char errorMessage[], int min, int max)

{
    int a;
    printf("%s", message);
    scanf("%d", &a);
    while(a < min || a > max)
    {
        printf("%s", errorMessage);
        scanf("%d", &a);
    }
    return a;
}







