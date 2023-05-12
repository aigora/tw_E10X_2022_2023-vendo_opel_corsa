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

<<<<<<< HEAD
=======

#define LONGUITUD_MAXIMA 1024

typedef struct 
{
    int mes;
    int year;
} dia;

typedef struct
{
    dia fecha;
    double energia[18];
} data;
double maximo(double vector[], double *max);
double media(double vector[], int n, double *med);

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
        int valor_maximo, valor_media;
        data datos[24];
        
        valor_maximo = maximo(datos[], &valor_maximo);
		valor_media = media(datos[], &valor_media);
        return 0;
    }
}
double maximo(double vector[], double *max)
{
	double numero_maximo;
	if(vector[i] > *max)
	{
		*max = vector[i];
	}
	numero_maximo = *max;
	return numero_maximo;
}

double media(double vector[], int n, double *med)
{
	int i;
	double result_suma = 0;
	double result_media;
	for(i = 0; i<n; i++)
	{
		result_suma = result_suma + vector[i];
	}
	result_media = result_suma / n;
	*med = result_media;
	return result_media;
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