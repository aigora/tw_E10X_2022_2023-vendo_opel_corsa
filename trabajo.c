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
    int mes[24];
    int year[24];
} dia;

typedef struct nom
{
    char nombre[50];
} nom;
typedef struct data
{
    double energia[17];
} data;

// funciones
void maximo(double vector[], int n, double *max);
void media(double vector[], int n, double *med);
void minimo(double vector[], int n, double *min);
void menu(void);
void ordena_mayor(double v[], int n);
void ordena_menor(double v[], int n);
//rama principal del programa
int main(int argc, const char * argv[])
{
    char menu_option;
    nom nombre_energia[17];
    FILE *pf;
    dia test= {{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
    {2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,
    2022,2022,2022,2022,2022,2022,2022,2022}};
    pf=fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
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
        int tamano=17;
        int i=0;
        int j=0;
        char x;
        int cuenta_lineas=0;
        while(fscanf(pf, "%c" , &x) != EOF)
        {
            if(x == '\n')
            {
                cuenta_lineas++;
            }
            if(cuenta_lineas==5)
            {
                break;
            }
        }
        printf("%i\n", cuenta_lineas);
        for (i=0; i<tamano; i++) {
            fscanf(pf, "%[^,]s", nombre_energia[i].nombre);
            printf("%s", nombre_energia[i].nombre);
            for (j=0; j<24; j++) {
                fscanf(pf, ",%lf", &datos[j].energia[i]);
                printf( ",%lf", datos[j].energia[i]);
            }
            fscanf(pf, "%c", &x);
            printf("%c", x);
        }
        for (i=0; i<24; i++) {
            maximo(datos[i].energia, tamano, &valor_maximo[i]);
            minimo(datos[i].energia, tamano, &valor_minimo[i]);
            media(datos[i].energia, tamano, &valor_media[i]);
        }
        // no entiendo muy bien que es lo que hace esta parte del codigo pero voy a hacer el menu
        printf("SELECCIONE LA ACCION QUE QUIERE LLEVAR A CABO\n");
        printf("\n");
        menu(); // funcion que escribe las opciones el menu en pantalla
        scanf("%c", &menu_option);
        char estadistico_option;
        int cambio1;
        int cambio2;
        int buscar_option;
        int buscar1;
        int buscar2;
        int ordenar_option;
        int ordenar;
        double vector_ordenar[24];
        switch(menu_option)
        {
            case '1':
                printf("ha selecionado el modo Estadistica\n");
                printf("Si quiere calcular los maximos pulse 1, si quiere calcular los minimos pulse 2, si quiere calcular la medias pulse 3\n");
                scanf(" %c", &estadistico_option);
                switch (estadistico_option) {
                    case '1':
                        for (i=0; i<24; i++) {
                            maximo(datos[i].energia, tamano, &valor_maximo[i]);
                            printf("En la fecha %i/%i el valor de energia maxima era %f.\n",
                            test.mes[i], test.year[i], valor_maximo[i]);
                        }
                        break;
                    case '2':
                        for (i=0; i<24; i++) {
                            minimo(datos[i].energia, tamano, &valor_minimo[i]);
                            printf("En la fecha %i/%i el valor de energia minima era %f.\n",
                            test.mes[i], test.year[i], valor_minimo[i]);
                        }
                        break;
                    case '3':
                        for (i=0; i<24; i++) {
                            media(datos[i].energia, tamano, &valor_media[i]);
                            printf("En la fecha %i/%i el valor de energia media era %f.\n",
                            test.mes[i], test.year[i], valor_media[i]);
                        }
                        break;
                    default:
                        printf("Esa no era una opcion.\n");
                        break;
                }
                break;
            case '2':
                printf("has seleccionado el modo para cargar datos\n");
                printf("Pulse 0 para Hidraulica, pulse 1 para Turbinacion bombeo, pulse 2 para Nuclear, pulse 3 para Carbon, pulse 4 para Motores diesel, pulse 5 para Turbina de gas, pulse 6 para Turbina de vapor, pulse 7 para Ciclo combinado, pulse 8 para Hidroeolica, pulse 9 para Eolica, pulse 10 para Solar fotovoltaica, pulse 11 para Solar termica, pulse 12 para Otras renovables, pulse 13 para Cogeneracion, pulse 14 para Residuos no renovables, pulse 16 para Residuos renovables, pulse 16 para Generacion total.\n");
                do {
                    scanf("%i", &cambio1);
                } while (cambio1>16);
                for (i=0; i<24; i++) {
                    printf("pulsa %i si quiere cambiar un dato de la fecha %i/%i, ", i,
                    test.mes[i], test.year[i]);
                }
                printf("\n");
                do {
                    scanf("%i", &cambio2);
                } while (cambio2>23);
                printf("Escriba el numero que quieras poner");
                scanf("%lf", &datos[cambio2].energia[cambio1]);
                break;
            case '3':
                printf("has seleccionado el modo para guardar resultados\n");
                
            // hacer cosas
                break;
            case '4':
                printf("has seleccionado el modo para buscar u ordenar valores\n");
                printf("Si quieres buscar valores pulse 1, si quieres ordenar valores pulse 2\n");
                scanf("%i", &buscar_option);
                switch (buscar_option) {
                    case 1:
                        printf("has elegido buscar valores\n");
                        printf("%i\n", cuenta_lineas);
                        printf("Pulse 0 para Hidraulica, pulse 1 para Turbinacion bombeo, pulse 2 para Nuclear, pulse 3 para Carbon, pulse 4 para Motores diesel, pulse 5 para Turbina de gas, pulse 6 para Turbina de vapor, pulse 7 para Ciclo combinado, pulse 8 para Hidroeolica, pulse 9 para Eolica, pulse 10 para Solar fotovoltaica, pulse 11 para Solar termica, pulse 12 para Otras renovables, pulse 13 para Cogeneracion, pulse 14 para Residuos no renovables, pulse 16 para Residuos renovables, pulse 16 para Generacion total.\n");
                        do {
                            scanf("%i", &buscar1);
                        } while (buscar1>16);
                        for (i=0; i<24; i++) {
                            printf("pulsa %i si quiere cambiar un dato de la fecha %i/%i, ", i,
                            test.mes[i], test.year[i]);
                        }
                        printf("\n");
                        do {
                            scanf("%i", &buscar2);
                        } while (buscar2>23);
                        printf("El valor que estas buscando es %lf\n", datos[buscar2].energia[buscar1]);
                        break;
                    case 2:
                        printf("has elegido ordenar valores\n");
                        printf("Si quieres ordenar de mayor a menor pulse 1, si quieres ordenar de menor a mayor pulse 2\n");
                        scanf("%i", &ordenar_option);
                        switch (ordenar_option) {
                            case 1:
                                printf("Pulse 0 para Hidraulica, pulse 1 para Turbinacion bombeo, pulse 2 para Nuclear, pulse 3 para Carbon, pulse 4 para Motores diesel, pulse 5 para Turbina de gas, pulse 6 para Turbina de vapor, pulse 7 para Ciclo combinado, pulse 8 para Hidroeolica, pulse 9 para Eolica, pulse 10 para Solar fotovoltaica, pulse 11 para Solar termica, pulse 12 para Otras renovables, pulse 13 para Cogeneracion, pulse 14 para Residuos no renovables, pulse 16 para Residuos renovables, pulse 16 para Generacion total.\n");
                                do {
                                    scanf("%i", &ordenar);
                                } while (ordenar>16);
                                for (i=0; i<24; i++) {
                                    vector_ordenar[i]=datos[i].energia[ordenar];
                                }
                                ordena_mayor(vector_ordenar, 24);
                                printf("De mayor a menor los datos de %s son:\n", nombre_energia[ordenar].nombre);
                                for (i=0; i<24; i++) {
                                    printf("%lf\n", vector_ordenar[i]);
                                }
                            case 2:
                                printf("Pulse 0 para Hidraulica, pulse 1 para Turbinacion bombeo, pulse 2 para Nuclear, pulse 3 para Carbon, pulse 4 para Motores diesel, pulse 5 para Turbina de gas, pulse 6 para Turbina de vapor, pulse 7 para Ciclo combinado, pulse 8 para Hidroeolica, pulse 9 para Eolica, pulse 10 para Solar fotovoltaica, pulse 11 para Solar termica, pulse 12 para Otras renovables, pulse 13 para Cogeneracion, pulse 14 para Residuos no renovables, pulse 16 para Residuos renovables, pulse 16 para Generacion total.\n");
                                do {
                                    scanf("%i", &ordenar);
                                } while (ordenar>16);
                                for (i=0; i<24; i++) {
                                    vector_ordenar[i]=datos[i].energia[ordenar];
                                }
                                ordena_menor(vector_ordenar, 24);
                                printf("De menor a mayor los datos de %s son:\n", nombre_energia[ordenar].nombre);
                                for (i=0; i<24; i++) {
                                    printf("%lf\n", vector_ordenar[i]);
                                }
                                break;
                            default:
                                printf("Eso no era una opcion\n");
                                break;
                        }
                        break;
                    default:
                        printf("Eso no era una de las opciones");
                        break;
                }
            // hacer cosas
                break;
            default:
                printf("esa opcion no estaba en el menu\n");
                break;
        }
        fclose(pf);

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
void ordena_mayor(double v[], int n)
{
    int i, j;
    float menor;
    for (i=0; i<n; i++)
    {
        for (j=0; j<i; j++)
        {
            if(v[j]<v[i])
            {
                menor=v[j];
                v[j]=v[i];
                v[i]=menor;
            }
        }
    }
}
void ordena_menor(double v[], int n)
{
    int i, j;
    float mayor;
    for (i=0; i<n; i++)
    {
        for (j=0; j<i; j++)
        {
            if(v[j]>v[i])
            {
                mayor=v[j];
                v[j]=v[i];
                v[i]=mayor;
            }
        }
    }
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
