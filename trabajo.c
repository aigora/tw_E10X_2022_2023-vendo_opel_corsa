//int lectura(int arcg, char **argv);
// un menu que permita al usuario elegir la tarea a realizar
// vectores de estructuras
// ficheros para leer y escribir
// prohibido el uso de variables fuera de main
// estructurar codigo con funciones
// uso de cabeceras de c
// obligatorio uso de github
// documentacion en una wiki de github
// diagrama de flujo que explique el proyecto


#include <stdio.h>
#include<stdlib.h>
#include<string.h>


#define LONGUITUD_MAXIMA 1024

typedef struct
{
    int mes;
    int year;
} dia;

typedef struct
{
    double energia[18];
    dia fecha;
} data;
void maximo(double vector[], int n, double *max);
void media(double vector[], int n, double *med);

int main()
{
    FILE *pf;
    pf=fopen("generacion_por_tecnologias_21_22.csv", "r");
    if (pf == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else
    {
        printf("Fichero abierto correctamente.\n");
        double valor_maximo, valor_media;
        data datos[24];
        int tamaño=24;
        maximo(datos, tamaño, &valor_maximo);
		media(datos, tamaño, &valor_media);
        return 0;
    }
}
void maximo(double vector[], int n, double *max)
{
    *max=vector[0];
    int i;
    for (i=0; i<n; i++) {
        if(vector[i] > *max)
        {
            *max = vector[i];
        }
    }
}

void media(double vector[], int n, double *med)
{
	int i;
	double result_suma = 0;
	for(i = 0; i<n; i++)
	{
		result_suma = result_suma + vector[i];
	}
	*med = result_suma / n;
}

/*int lectura(int arcg,  char **argv)
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
}*/
