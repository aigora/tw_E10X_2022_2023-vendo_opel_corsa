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


#define LONGUITUD_MAXIMA 1024 // esto ahora mismo no vale para nada, valdra cuando consiga hacer una funcion capaz de leerlo

// donde se guardan los datos
typedef struct dia
{
    int mes;
    int year;
} dia;

typedef struct data
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
int main(int argc, const char * argv[])
{
    char menu_option;
    FILE *pf;
    pf=fopen("generacion_por_tecnologias_21_22_puntos.csv", "r");
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
        int i=0;
        char x;
        int cuenta_lineas=0;
        while (cuenta_lineas!=4) {
            if(fscanf(pf, "%c", &x)=='\n')
            {
                cuenta_lineas++;
            }
        }
        i=0;
        while (fscanf(pf, "%c", &x)!=EOF) {
            if(x=='a')
            {
                break;
            }
        }
        while (fscanf(pf, ",%i/%i,", &datos[i].fecha.mes, &datos[i].fecha.year)!=EOF) {
            i++;
            if(i==24)
            {
                break;
            }
        }
        i=0;
        for (i=0; i<24; i++) {
            printf("%i/%i", datos[i].fecha.mes, datos[i].fecha.year);
        }
        while (fscanf(pf, ",%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &datos[0].energia[i], &datos[1].energia[i], &datos[2].energia[i], &datos[3].energia[i], &datos[4].energia[i], &datos[5].energia[i], &datos[6].energia[i], &datos[7].energia[i], &datos[8].energia[i], &datos[9].energia[i], &datos[10].energia[i], &datos[11].energia[i], &datos[12].energia[i], &datos[13].energia[i], &datos[14].energia[i], &datos[15].energia[i], &datos[16].energia[i], &datos[17].energia[i], &datos[18].energia[i], &datos[19].energia[i], &datos[20].energia[i], &datos[21].energia[i], &datos[22].energia[i], &datos[23].energia[i])!=EOF) {
            i++;
        }
        for (i=0; i<24; i++) {
            maximo(datos[i].energia, tamaño, &valor_maximo[i]);
            minimo(datos[i].energia, tamaño, &valor_minimo[i]);
            media(datos[i].energia, tamaño, &valor_media[i]);
        }
        // no entiendo muy bien que es lo que hace esta parte del codigo pero voy a hacer el menu
        printf("SELECCIONE LA ACCION QUE QUIERE LLEVAR A CABO\n");
        printf("\n");
        menu(); // funcion que escribe las opciones el menu en pantalla
        char estadistico_option;
        scanf("%c", &menu_option);
        switch(menu_option)
        {
            case '1':
                printf("ha selecionado el modo Estadística\n");
                printf("Si quiere calcular los maximos pulse 1, si quiere calcular los minimos pulse 2, si quiere calcular la medias pulse 3\n");
                scanf(" %c", &estadistico_option);
                switch (estadistico_option) {
                    case '1':
                        for (i=0; i<24; i++) {
                            printf("En la fecha %i/%i el valor de energia maxima era %f.\n", datos[i].fecha.mes, datos[i].fecha.year, valor_maximo[i]);
                        }
                        break;
                    case '2':
                        for (i=0; i<24; i++) {
                            printf("En la fecha %i/%i el valor de energia minima era %f.\n", datos[i].fecha.mes, datos[i].fecha.year, valor_minimo[i]);
                        }
                        break;
                    case '3':
                        for (i=0; i<24; i++) {
                            printf("En la fecha %i/%i el valor de energia media era %f.\n", datos[i].fecha.mes, datos[i].fecha.year, valor_media[i]);
                        }
                        break;
                    default:
                        printf("Esa no era una opcion.\n");
                        break;
                }
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
                printf("esa opcion no estaba en el menu\n");
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
