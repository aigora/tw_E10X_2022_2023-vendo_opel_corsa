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

#define ranuras_De_memoria 5

// donde se guardan los datos
typedef struct dia
{
    int mes[24];
    int year[24];
} dia;

typedef struct nombre
{
    char nombre[50];
} nombre;

typedef struct data
{
    double energia[17];
} data;

typedef struct resultados_guardados
{
    nombre energia;
    int mes, year;
    double resultados;
} resultados_guardados;

// funciones
void maximo(double vector[], int n, double *max);
void media(double vector[], int n, double *med);
void minimo(double vector[], int n, double *min);

//menús
void menu(void);
void menu_estadistica(void);
void menu_energias(void);

void ordena_mayor(double v[], int n);
void ordena_menor(double v[], int n);

void slot_De_memoria(int slot_de_memoria, resultados_guardados memoria[slot_de_memoria-1]);


//rama principal del programa
int main(int argc, const char * argv[])
{
    char menu_option;
    nombre nombre_energia[17];
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
        resultados_guardados memoria[5];
        int cantidad_De_energias=17;
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
            if(cuenta_lineas==5) // esto salta las 5 primeras lineas
            {
                break;
            }
        }

        //printf("%i\n", cuenta_lineas); [TEST]
        for (i=0; i<cantidad_De_energias; i++)  // porque es un por cada energia
        {
            fscanf(pf, "%[^,]s", nombre_energia[i].nombre);
            //printf("%s", nombre_energia[i].nombre); [TEST]
            for (j=0; j<24; j++) // 24 datos en cada energia
            {
                fscanf(pf, ",%lf", &datos[j].energia[i]);
                //printf( ",%lf", datos[j].energia[i]); [TEST]
            }
            //fscanf(pf, "%c", &x); // esto imprime un salto de linea no es necesario si solo se quieren guardar los datos  [TEST]
            //printf("%c", x); [TEST]
        }

        for (i=0; i<24; i++)
        {
            maximo(datos[i].energia, cantidad_De_energias, &valor_maximo[i]);
            minimo(datos[i].energia, cantidad_De_energias, &valor_minimo[i]);
            media(datos[i].energia, cantidad_De_energias, &valor_media[i]);
        }
       
        printf("SELECCIONE LA ACCION QUE QUIERE LLEVAR A CABO\n");
        printf("\n");
        menu(); // funcion que escribe las opciones el menu en pantalla
        scanf("%c", &menu_option);
        char estadistico_option; // variables para intercambiar unos valores por otros
        int cambio1, cambio2;

        int buscar_option; // variables para buscar valores
        int buscar1, buscar2;

        int ordenar_option; // variables para ordenar valores
        int ordenar;
        double vector_ordenar[24];
        switch(menu_option)
        {
            case '1':
                printf("ha selecionado el modo Estadistica\n");
                 //printf("Si quiere calcular los maximos pulse 1, si quiere calcular los minimos pulse 2, si quiere calcular la medias pulse 3\n");
                printf("\n");
                printf("selecione lo que quiere hacer: \n");
                menu_estadistica(); // funcion que imprime las opciones de menu estadistica para que no este todo tan aglomerado aqui
                scanf(" %c", &estadistico_option);
                switch (estadistico_option) {
                    case '1':
                        for (i=0; i<24; i++)
                        {
                            maximo(datos[i].energia, cantidad_De_energias, &valor_maximo[i]);
                            printf("En la fecha %i/%i el valor de energia maxima era %f.\n",
                            test.mes[i], test.year[i], valor_maximo[i]);
                        }
                        system("pause"); //BORRAR DEFINITIVO
                        break;
                    case '2':
                        for (i=0; i<24; i++)
                        {
                            minimo(datos[i].energia, cantidad_De_energias, &valor_minimo[i]);
                            printf("En la fecha %i/%i el valor de energia minima era %f.\n",
                            test.mes[i], test.year[i], valor_minimo[i]);
                            system("pause"); //BORRAR DEFNITIVO
                        }
                        break;
                    case '3':
                        for (i=0; i<24; i++)
                        {
                            media(datos[i].energia, cantidad_De_energias, &valor_media[i]);
                            printf("En la fecha %i/%i el valor de energia media era %f.\n",
                            test.mes[i], test.year[i], valor_media[i]);
                        }
                        system("pause"); //BORRAR DEFINITIVO
                        break;
                    default:
                        printf("Esa no era una opcion.\n");
                        system("pause"); //BORRAR DEFINITIVO
                        break;
                }
                break;
            case '2':
                printf("has seleccionado el modo para cargar datos\n");
                printf("Selecione la energia: \n");
                menu_energias();
                
                do
                {
                    scanf("%i", &cambio1);
                } while (cambio1>16);

                for (i=0; i<24; i++)
                {
                    printf("pulsa %i si quiere cambiar un dato de la fecha %i/%i, ", i,
                    test.mes[i], test.year[i]);
                }

                printf("\n");

                do {
                    scanf("%i", &cambio2);
                } while (cambio2>23);

                printf("Escriba el numero que quieras poner");
                scanf("%lf", &datos[cambio2].energia[cambio1]);
                system("pause"); //BORRAR DEFINITIVO
                break;
            case '3':
                printf("has seleccionado el modo para buscar u ordenar valores\n");
                printf("Si quieres buscar valores pulse 1, si quieres ordenar valores pulse 2\n");
                scanf("%i", &buscar_option);
                switch (buscar_option)
                {
                    case 1:
                        printf("has elegido buscar valores\n");
                        printf("%i\n", cuenta_lineas);
                        printf("selecciona la energia: \n");
                        menu_energias(); // es el mismo que el menu para ordenar valores
                        do
                        {
                            scanf("%i", &buscar1);
                        } while (buscar1>16);
                        for (i=0; i<24; i++)
                        {
                            printf("pulsa %i si quiere cambiar un dato de la fecha %i/%i, ", i,
                            test.mes[i], test.year[i]);
                        }
                        printf("\n");
                        do
                        {
                            scanf("%i", &buscar2);
                        } while (buscar2>23);

                        printf("El valor que estas buscando es %lf\n", datos[buscar2].energia[buscar1]);
                        break;
                    case 2:
                        printf("has elegido ordenar valores\n");
                        printf("Si quieres ordenar de mayor a menor pulse 1, si quieres ordenar de menor a mayor pulse 2\n");
                        scanf("%i", &ordenar_option);
                        switch (ordenar_option)
                        {
                            case 1:
                                printf("Selecione la energia: \n");
                                menu_energias();
                                do
                                {
                                    scanf("%i", &ordenar);
                                } while (ordenar>16);
                                for (i=0; i<24; i++)
                                {
                                    vector_ordenar[i]=datos[i].energia[ordenar];
                                }
                                ordena_mayor(vector_ordenar, 24);
                                printf("De mayor a menor los datos de %s son:\n", nombre_energia[ordenar].nombre);
                                for (i=0; i<24; i++)
                                {
                                    printf("%lf\n", vector_ordenar[i]);
                                }
                                system("pause"); //BORRAR DEFINITIVO
                                break;

                            case 2:
                                printf("Selecione la energia: \n");
                                menu_energias();
                                do
                                {
                                    scanf("%i", &ordenar);
                                } while (ordenar>16);
                                for (i=0; i<24; i++)
                                {
                                    vector_ordenar[i]=datos[i].energia[ordenar];
                                }
                                ordena_menor(vector_ordenar, 24);
                                printf("De menor a mayor los datos de %s son:\n", nombre_energia[ordenar].nombre);
                                for (i=0; i<24; i++)
                                {
                                    printf("%lf\n", vector_ordenar[i]);
                                }
                                system("pause"); //BORRAR DEFINITIVO
                                break;

                            default:
                                printf("Eso no era una opcion, seleciona una opcion valida\n");
                                system("pause"); //BORRAR DEFINITIVO
                                break;
                        }
                        break;
                    default:
                        printf("Eso no era una de las opciones, seleciona una opcion valida\n");
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
    printf("3 - Busqueda/ordenar valores\n");
}

void menu_estadistica(void)
{
    printf("1 - calcular maximos\n");
    printf("2 - calcular minimos\n");
    printf("3 - calcular medias\n");
}

void menu_energias(void)
{
    printf("0 - hidraulica\n");
    printf("1 - turbinacion/bombeo\n");
    printf("2 - nuclear\n");
    printf("3 - carbon\n");
    printf("4 - motores diesel\n");
    printf("5 - turbina de gas \n");
    printf("6 - turbina de vapor\n");
    printf("7 - ciclo combinado\n");
    printf("8 - hidroeolica\n");
    printf("9 - eolica\n");
    printf("10 - Solar Fotovoltaica\n");
    printf("11 - Solar Termica\n");
    printf("12 - otras renovables\n");
    printf("13 - Cogeneracion\n");
    printf("14 - residuos no renovables\n");
    printf("15 - residuos renovables\n");
    printf("16 - generacion total\n");
}

void slot_De_memoria(int slot_de_memoria, resultados_guardados memoria[slot_de_memoria-1]) //porque los vectores empiezan en 0
{
    printf("ha seleccionado el modo de guardado de resultados\n");
    printf("selecciona la ranura de memoria en la que lo quieres guardar\n");
    printf("recuerda que solo tienes %i ranuras de memoria\n", ranuras_De_memoria);
    if(slot_de_memoria == 1)
    {
        printf("has seleccionado el slot de memoria numero 1");
        printf("seleccione el nombre que desea introducir:\t");
        scanf("%s", memoria[slot_de_memoria-1].energia.nombre);
        printf("\n");
        printf("seleccione el dato que desea guardar: \t");
        scanf("%lf", &memoria[slot_de_memoria-1].resultados);
        printf("\n");
        printf("seleccione la fecha en la que lo quiere guardar en formato MES/AÑO \t");
        scanf("%i/%i", &memoria[slot_de_memoria-1].mes, &memoria[slot_de_memoria-1].year);
        system("pause"); //borrar definitivo
    }
    else if(slot_de_memoria == 2)
    {
        printf("has seleccionado el slot de memoria numero 2");
        printf("seleccione el nombre que desea introducir:\t");
        scanf("%s", memoria[slot_de_memoria-1].energia.nombre);
        printf("\n");
        printf("seleccione el dato que desea guardar: \t");
        scanf("%lf", &memoria[slot_de_memoria-1].resultados);
        printf("\n");
        printf("seleccione la fecha en la que lo quiere guardar en formato MES/AÑO \t");
        scanf("%i/%i", &memoria[slot_de_memoria-1].mes, &memoria[slot_de_memoria-1].year);
        system("pause"); //borrar definitivo
    }
    else if(slot_de_memoria == 3)
    {
        printf("has seleccionado el slot de memoria numero 3");
        printf("seleccione el nombre que desea introducir:\t");
        scanf("%s", memoria[slot_de_memoria-1].energia.nombre);
        printf("\n");
        printf("seleccione el dato que desea guardar: \t");
        scanf("%lf", &memoria[slot_de_memoria-1].resultados);
        printf("\n");
        printf("seleccione la fecha en la que lo quiere guardar en formato MES/AÑO \t");
        scanf("%i/%i", &memoria[slot_de_memoria-1].mes, &memoria[slot_de_memoria-1].year);
        system("pause"); //borrar definitivo
    }
    else if(slot_de_memoria == 4)
    {
        printf("has seleccionado el slot de memoria numero 4");
        printf("seleccione el nombre que desea introducir:\t");
        scanf("%s", memoria[slot_de_memoria-1].energia.nombre);
        printf("\n");
        printf("seleccione el dato que desea guardar: \t");
        scanf("%lf", &memoria[slot_de_memoria-1].resultados);
        printf("\n");
        printf("seleccione la fecha en la que lo quiere guardar en formato MES/AÑO \t");
        scanf("%i/%i", &memoria[slot_de_memoria-1].mes, &memoria[slot_de_memoria-1].year);
        system("pause"); //borrar definitivo
    }
    else if(slot_de_memoria == 5)
    {
        printf("has seleccionado el slot de memoria numero 5");
        printf("seleccione el nombre que desea introducir:\t");
        scanf("%s", memoria[slot_de_memoria-1].energia.nombre);
        printf("\n");
        printf("seleccione el dato que desea guardar: \t");
        scanf("%lf", &memoria[slot_de_memoria-1].resultados);
        printf("\n");
        printf("seleccione la fecha en la que lo quiere guardar en formato MES/AÑO \t");
        scanf("%i/%i", &memoria[slot_de_memoria-1].mes, &memoria[slot_de_memoria-1].year);
        system("pause"); //borrar definitivo
    }
    else
    {
        printf("recuerda que solo tienes %i slots de memoria", ranuras_De_memoria);
        system("pause"); //borrar definitivo
    }
}


void maximo(double vector[], int n, double *max)
{
    *max=vector[0];
    int i;
    for (i=0; i<n; i++)
    {
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
    for (i=0; i<n; i++)
    {
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
