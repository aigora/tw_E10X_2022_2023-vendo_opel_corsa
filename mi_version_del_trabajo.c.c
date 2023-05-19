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
#include <math.h>


#define LONGUITUD_MAXIMA 1024 // esto ahora mismo no vale para nada, valdra cuando consiga hacer una funcion capaz de leerlo

// donde se guardan los datos

typedef struct data
{
    char tipo_de_energia[LONGUITUD_MAXIMA];
    int fecha[2]; // lo voy a cambiar por MES/DIA
    float energia[24];
} data;

// funciones
void maximo(double vector[], int n, double *max);
void media(double vector[], int n, double *med);
void minimo(double vector[], int n, double *min);
void menu(void);

//rama principal del programa
int main()
{
    float datos;
    int i,k=0, contador_de_lineas = 0, menu_option, variable_De_control;
    char caracter, string[LONGUITUD_MAXIMA];
    data hidraulica, turbinacion_bombeo, nuclear, carbon, fuel_y_gas, motores_diesel, turbina_De_gas, turbina_De_vapor, ciclo_combinado, hidroeolica, eolica, solar_fotovoltaica, solar_termica, otras_renovables, cogeneracion, residuos_no_renovables, resicuos_renovables, generacion_total;



    FILE *pf;
    pf = fopen("generacion_por_tecnologias_21_22_puntos.csv", "r");
    if (pf == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else
    {
        printf("Fichero abierto correctamente.\n");
        // guardar los datos en una estructura utilizable
        while(fscanf(pf,"%c", &caracter) != EOF)
        {
            if(caracter == '\n')
            {
                contador_de_lineas++;
            }
            if(contador_de_lineas == 5)
            {
                // funcion de contado de la primera linea 
                fscanf(pf,"%[^,]s,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", hidraulica.tipo_de_energia, &hidraulica.energia[0],&hidraulica.energia[1], &hidraulica.energia[2],&hidraulica.energia[3],&hidraulica.energia[4],&hidraulica.energia[5],&hidraulica.energia[6],&hidraulica.energia[7],&hidraulica.energia[8],&hidraulica.energia[9],&hidraulica.energia[10],&hidraulica.energia[11],&hidraulica.energia[12],&hidraulica.energia[13],&hidraulica.energia[14],&hidraulica.energia[15],&hidraulica.energia[16],&hidraulica.energia[17],&hidraulica.energia[18],&hidraulica.energia[19],&hidraulica.energia[20],&hidraulica.energia[22],&hidraulica.energia[23]);
                printf("%f\n", hidraulica.tipo_de_energia);
                break;
            }
            if(contador_de_lineas == 6) // cambiar hidraulica por eolica o algo asi 
            {
                // funcion de contado de la segunda linea 
                fscanf(pf,"%[^,]s,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", hidraulica.tipo_de_energia, &hidraulica.energia[0],&hidraulica.energia[1], &hidraulica.energia[2],&hidraulica.energia[3],&hidraulica.energia[4],&hidraulica.energia[5],&hidraulica.energia[6],&hidraulica.energia[7],&hidraulica.energia[8],&hidraulica.energia[9],&hidraulica.energia[10],&hidraulica.energia[11],&hidraulica.energia[12],&hidraulica.energia[13],&hidraulica.energia[14],&hidraulica.energia[15],&hidraulica.energia[16],&hidraulica.energia[17],&hidraulica.energia[18],&hidraulica.energia[19],&hidraulica.energia[20],&hidraulica.energia[22],&hidraulica.energia[23]);
                printf("%f\n", hidraulica.tipo_de_energia);
                break;
            }
        }


        printf("SELECCIONE LA ACCION QUE QUIERE LLEVAR A CABO\n");
        printf("\n");
        menu(); // funcion que escribe las opciones el menu en pantalla
        scanf("%i", &menu_option);
        switch(menu_option)
        {
            case '1':
            printf("ha selecionado el modo Estadística\n");
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

        system("pause");
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
