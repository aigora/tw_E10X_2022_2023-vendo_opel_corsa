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

#define numero_de_lineas 17
#define cantidad_de_posiciones_de_memoria 5

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
    double resultados;
} resultados_guardados;

// funciones
void maximo(double vector[], int n, double *max);
void media(double vector[], int n, double *med);
void minimo(double vector[], int n, double *min);

//menus
void menu(void);
void menu_estadistica(void);
void menu_energias(void);

void ordena_mayor(double v[], int n);
void ordena_menor(double v[], int n);

//rama principal del programa
int main(int argc, const char * argv[])
{
    printf("Bienvenido/a al panel de control de la generacion mensual(en GWh) dividida por energias en todo el territoio nacional,");
	printf("desde aqui podra acceder a los distintos calculos estadisticos, ordenar los valores e incluso introducir nuevos.\n"); //que nivel
	printf("Le recordamos que todos los datos que vera aqui presentes corresponden a los años 2021-2022 y que son de acceso y uso publico");
	char menu_option;
	nombre nombre_energia[17];
    FILE *pf;
    dia test= {{1,2,3,4,5,6,7,8,9,10,11,12,1,2,3,4,5,6,7,8,9,10,11,12},
    {2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2021,2022,2022,2022,2022,
    2022,2022,2022,2022,2022,2022,2022,2022}};// Estos dos vectores son para determinar las fechas

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
        int cuenta_lineas=0, funcion_cuenta_lineas = 0;
        while(fscanf(pf, "%c" , &x) != EOF)
        {
            if(x == '\n')
            {
                cuenta_lineas++;
            }
            if(cuenta_lineas == 5) // para poder usar los datos del fichero
            {
            	break;
			}
        }
        for (i=0; i<cantidad_De_energias; i++)  // porque es un por cada energia
        {
            fscanf(pf, "%[^,]s", nombre_energia[i].nombre);
            for (j=0; j<24; j++) // 24 datos en cada energia
            {
                fscanf(pf, ",%lf", &datos[j].energia[i]);
            }
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

        //MEMORIA
        char si_no;
        int posicion_de_memoria_seleccionada;


        switch(menu_option)
        {
            case '1':
                printf("Ha selecionado el modo Estadistica\n");
                printf("\n");
                printf("Selecione lo que quiere hacer: \n");
                menu_estadistica(); // funcion que imprime las opciones de menu estadistica para que no este todo tan aglomerado aqui
                scanf(" %c", &estadistico_option);
                switch (estadistico_option) {
                    case '1':
                        for (i=0; i<24; i++)
                        {
                            maximo(datos[i].energia, cantidad_De_energias, &valor_maximo[i]); // Con esto se juntan las fechas con sus respectivos datos del fichero
                            printf("En la fecha %i/%i el valor de energia maxima era %f.\n",
                            test.mes[i], test.year[i], valor_maximo[i]);
                        }
                        break;
                    case '2':
                        for (i=0; i<24; i++)
                        {
                            minimo(datos[i].energia, cantidad_De_energias, &valor_minimo[i]);
                            printf("En la fecha %i/%i el valor de energia minima era %f.\n",
                            test.mes[i], test.year[i], valor_minimo[i]);
                        }
                        break;
                    case '3':
                        for (i=0; i<24; i++)
                        {
                            media(datos[i].energia, cantidad_De_energias, &valor_media[i]);
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
                printf("Has seleccionado el modo para cargar datos\n");
                printf("Selecione la energia: \n");
                menu_energias();
                
                do
                {
                    scanf("%i", &cambio1);
                } while (cambio1>16);

                for (i=0; i<24; i++)
                {
                    printf("Pulsa %i si quiere cambiar un dato de la fecha %i/%i\n ", i,
                    test.mes[i], test.year[i]);
                }

                printf("\n");

                do 
				{
                    scanf("%i", &cambio2);
                } while (cambio2>23);

                printf("Escriba el numero que quieras poner:\n");
                scanf("%lf", &datos[cambio2].energia[cambio1]);
                printf("Gracias por introducir un dato nuevo haciendo uso de nuestro panel de control.\n");
                break;
            case '3':
                printf("Has seleccionado el modo para buscar u ordenar valores\n");
                printf("Si quieres buscar valores pulse 1\nSi quieres ordenar valores pulse 2\n");
                scanf("%i", &buscar_option);
                switch (buscar_option)
                {
                    case 1:
                        printf("Has elegido buscar valores\n");
                        printf("Selecciona la energia: \n");
                        menu_energias(); // es el mismo que el menu para ordenar valores
                        do
                        {
                            scanf("%i", &buscar1);
                        } while (buscar1>16);
                        for (i=0; i<24; i++)
                        {
                            printf("Pulsa %i si quiere buscar un dato de la fecha %i/%i\n ", i,
                            test.mes[i], test.year[i]);
                        }
                        printf("\n");
                        do
                        {
                            scanf("%i", &buscar2);
                        } while (buscar2>23);

                        printf("El valor que estas buscando es %lf\n", datos[buscar2].energia[buscar1]);
                        printf("Gracias por hacer uso de nuestro sistema de busqueda de datos, hasta la proxima.\n");
                        printf("¿Quieres guardar el dato que acabas de buscar?\n");
                        scanf("%c", &si_no); //crear si_no 
                        if(si_no == 's')
                        {
                            printf("¿En que posicion de memoria quieres guardarlo?, recuerda que solo hay %i posiciones de memoria.\n", cantidad_de_posiciones_de_memoria); //crear variable 
                            scanf("%i", &posicion_de_memoria_seleccionada); 
                            memoria[posicion_de_memoria_seleccionada-1].resultados = datos[buscar2].energia[buscar1];
                            printf("¿De que tipo de energia era el dato?\n");
                            scanf("%s", memoria[posicion_de_memoria_seleccionada-1].energia);
                            printf("El dato ha sido guardado con exito.\n");
                        }
                        if(si_no == 'n')
                        {
                            printf("De acuerdo\n");
                        }
                        system("pause");
                        break;
                    case 2:
                        printf("Has elegido ordenar valores\n");
                        printf("Si quieres ordenar de mayor a menor pulse 1\nSi quieres ordenar de menor a mayor pulse 2\n");
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
                                printf("Gracias por hacer uso de nuestro sistema de ordenacion de datos energeticos.\n");
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
                                printf("Gracias por hacer uso de nuestro sistema de ordenacion de datos energeticos.\n");
                                break;

                            default:
                                printf("Eso no era una opcion, seleciona una opcion valida\n");
                                break;
                        }
                        break;
                    default:
                        printf("Eso no era una de las opciones, seleciona una opcion valida\n");
                        break;
                }
            // hacer cosas
                break;
            case '4':
             	printf("El numero de lineas que tiene el fichero son %i\n", numero_de_lineas);
                system("pause");
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
    printf("4 - Numero de lineas del fichero\n");
}

void menu_estadistica(void)
{
    printf("1 - Calcular maximos\n");
    printf("2 - Calcular minimos\n");
    printf("3 - Calcular medias\n");
}

void menu_energias(void)
{
    printf("0 - Hidraulica\n");
    printf("1 - Turbinacion/bombeo\n");
    printf("2 - Nuclear\n");
    printf("3 - Carbon\n");
    printf("4 - Motores diesel\n");
    printf("5 - Turbina de gas \n");
    printf("6 - Turbina de vapor\n");
    printf("7 - Ciclo combinado\n");
    printf("8 - Hidroeolica\n");
    printf("9 - Eolica\n");
    printf("10 - Solar Fotovoltaica\n");
    printf("11 - Solar Termica\n");
    printf("12 - Otras renovables\n");
    printf("13 - Cogeneracion\n");
    printf("14 - Residuos no renovables\n");
    printf("15 - Residuos renovables\n");
    printf("16 - Generacion total\n");
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
