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

#define MAX_ROWS 1000
#define MAX_COLS 100


// Definicon de la estructura para almacenar los datos
typedef struct {
char fecha[20];
float hidraulica;
float solar;
// Agregar aqui los campos para- otras formas de generacion
} DatosGeneracion;

// Funcion para cargar los datos desde un archivo CSV
int cargarDatos(DatosGeneracion datos[MAX_ROWS], char *archivo) {
    FILE *fp;
    char buffer[1000];
    char *token;
    int row = 0;

    fp = fopen(archivo, "r");
    if (fp == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

    fgets(buffer, sizeof(buffer), fp); // Leer la primera linea (Titulo)
    fgets(buffer, sizeof(buffer), fp); // Leer la segunda linea (Sistema Electrico)
    fgets(buffer, sizeof(buffer), fp); // Leer la tercera linea (Magnitudes)
    fgets(buffer, sizeof(buffer), fp); // Leer la cuarta linea (Fecha)
    
    // Leer los datos de generacion
    while (fgets(buffer, sizeof(buffer), fp)) {
        token = strtok(buffer, ",");
        strcpy(datos[row].fecha, token);

        token = strtok(NULL, ",");
        datos[row].hidraulica = atof(token);

        token = strtok(NULL, ",");
        datos[row].solar = atof(token);

        // Agregar aqui el codigo para leer otras formas de generacion

        row++;
    }

    fclose(fp);
    return row; // Devolver el numero de filas leidas
}

// Funcion para realizar calculos estadisticos
void calcularEstadisticas(DatosGeneracion datos[MAX_ROWS], int numFilas) {
    float sumaHidraulica = 0.0;
    float sumaSolar = 0.0;
    float maxHidraulica = datos[0].hidraulica;
    float minHidraulica = datos[0].hidraulica;
    float maxSolar = datos[0].solar;
    float minSolar = datos[0].solar;

    for (int i = 0; i < numFilas; i++) {
        sumaHidraulica += datos[i].hidraulica;
        sumaSolar += datos[i].solar;

        if (datos[i].hidraulica > maxHidraulica) {
            maxHidraulica = datos[i].hidraulica;
        }

        if (datos[i].hidraulica < minHidraulica) {
            minHidraulica = datos[i].hidraulica;
        }

        if (datos[i].solar > maxSolar) {
            maxSolar = datos[i].solar;
        }

        if (datos[i].solar < minSolar) {
            minSolar = datos[i].solar;
        }
    }

    float promedioHidraulica = sumaHidraulica / numFilas;
    float promedioSolar = sumaSolar / numFilas;

    printf("Estadisticas de generacion hidraulica:\n");
    printf("Promedio: %.2f\n", promedioHidraulica);
    printf("Maximo: %.2f\n", maxHidraulica);
    printf("Minimo: %.2f\n", minHidraulica);

    printf("Estadisticas de generacion solar:\n");
    printf("Promedio: %.2f\n", promedioSolar);
    printf("Maximo: %.2f\n", maxSolar);
    printf("Minimo: %.2f\n", minSolar);
}

int main() {
    DatosGeneracion datos[MAX_ROWS];
    int numFilas;

    char archivo[] = "generacion_por_tecnologias_21_22_puntos_simplificado.csv";
    numFilas = cargarDatos(datos, archivo);

    if (numFilas == 0) {
        return 1;
    }

    calcularEstadisticas(datos, numFilas);

    return 0;
}



