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
}date;
typedef struct
{
    date fecha;
    double energia[18];
}data;
double maximo(double vector[], double *max);
double media(double vector[], int n, double *med);
int lectura(int arcg, char **argv);
>>>>>>> 6f52af8fa3b2343e090fa677f7294113723d9bcb
// un menu que permita al usuario elegir la tarea a realizar
// vectores de estructuras
// ficheros para leer y escribir
// prohibido el uso de variables fuera de main
// estructurar codigo con funciones
// uso de cabeceras de c
// obligatorio uso de github
// documentacion en una wiki de github
// diagrama de flujo que explique el proyecto
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
        
        valor_maximo = maximo(int vector[], int *max);
        valor_media = media(int vector[], int *med);
        return 0;
    }
    
    


}

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

double maximo(double vector[], double *max)
{
	double numero_maximo;
	if(vector[i] > *max)
	{
		*max = vector[i];
	}
	*max = numero_maximo;
	return numero_maximo;
}

double media(double vector[], int n, double *med)
{
	int i;
	double result_suma = 0;
	double result_media;
	*max = vector[0];
	for(i = 0; i<n; i++)
	{
		result_suma = result_suma + vector[i];
	}
	result_media = result_suma / n;
	*media = result_media;
	return result_media;
}

