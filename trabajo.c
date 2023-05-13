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
#include <stdlib.h>
#include <string.h>


#define LONGUITUD_MAXIMA 1024

// donde se guardan los datos 
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

// funciones 
void maximo(double vector[], int n, double *max);
void media(double vector[], int n, double *med);
void minimo(double vector[], int n, double *min);
void menu(void);

//rama principal del programa 
int main()
{
    int menu_option;
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
        double valor_maximo[24], valor_media[24], valor_minimo[24];
        data datos[24];
        int tamaño=18;
        int i;
        for (i=0; i<tamaño; i++) {
            maximo(datos[i].energia, tamaño, &valor_maximo[i]);
            minimo(datos[i].energia, tamaño, &valor_minimo[i]);
            media(datos[i].energia, tamaño, &valor_media[i]);
        }
        // no entiendo muy bien que es lo que hace esta parte del codigo pero voy a hacer el menu 
        printf("SELECCIONE LA ACCION QUE QUIERE LLEVAR A CABO\n");
        printf("\n");
        menu(); // funcion que escribe las opciones el menu en pantalla 
        switch(menu_option)
        {
            case '1':
            printf("ha selecionado el modo Estadística\n");
            // hacer cosas
            break;
            case '2':
            printf("has seleccionado el modo para cargar datos\n");
            // hacer cosas
            break;
            case '3':
            printf("has seleccionado el modo para guardar resultados\n");
            // hacer cosas
            break;
            case '4':
            printf("has seleccionado el modo para buscar u ordenar valores\n");
            // hacer cosas 
            break;
            default:
            printf("eres mongolo\n"); // esa opcion no estaba en el menu 
            break;
        }
        

        return 0;
    }
}

//programa en las funciones 

void menu(void)
{
    printf("1 - Calculos Estadisticos\n");
    printf("2 - Carga de Nuevos Datos\n");
    printf("3 - Guardar Resultados\n"); // prosiblemente en sitios de memoria nuevos 
    printf("4 - Busqueda/ordenar valores\n");
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
void minimo(double vector[], int n, double *min)
{
    *min=vector[0];
    int i;
    for (i=0; i<n; i++) {
        if(vector[i] < *min)
        {
            *min = vector[i];
        }
    }
}

void media(double vector[], int n, double *med)
{
    int i;
    double result_suma=0;
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
