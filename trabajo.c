#include <stdio.h>
#include<stdlib.h>
#include<string.h>


#define LONGUITUD_MAXIMA 1024

int lectura(int arcg, char **argv);
// un menu que permita al usuario elegir la tarea a realizar
// vectores de estructuras
// ficheros para leer y escribir
// prohibido el uso de variables fuera de main
// estructurar codigo con funciones
// uso de cabeceras de c
// obligatorio uso de github
// documentacion en una wiki de github
// diagrama de flujo que explique el proyecto

int lectura(int arcg,  char **argv)
{
    FILE *fp;
    char linea[LONGUITUD_MAXIMA];
    char *palabra;

    fp = fopen("generacion_por_tecnologias_21_22.csv","r");
    if(fp == NULL)
    {
        printf("error al abrir el archivo\n");
        return -1;
    }
    while(fgets(linea, LONGUITUD_MAXIMA, fp) != NULL)
    {
        palabra = strtok(linea,",");
        while(palabra != NULL)
        {
            printf("%s\n", palabra); //esto habria que guardarlo en una estructura en vez de escribirlo
            palabra = strtok(NULL,",");
        }
    }
    fclose(fp);
    return 0;
}
