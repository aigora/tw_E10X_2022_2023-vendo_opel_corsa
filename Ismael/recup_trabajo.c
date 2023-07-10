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

#define MAX_DATOS 100

typedef struct {
    char nombreEnergia[50];
    float valor;
} Dato;

void cargarDatos(Dato datos[], int *numDatos, FILE *archivoEntrada) {
    char linea[100];
    fgets(linea, sizeof(linea), archivoEntrada); // Leer la primera linea y descartarla
    *numDatos = 0;
    while (fgets(linea, sizeof(linea), archivoEntrada) != NULL) {
        char *token = strtok(linea, ",");
        strcpy(datos[*numDatos].nombreEnergia, token);
        token = strtok(NULL, ",");
        datos[*numDatos].valor = atof(token);
        (*numDatos)++;
    }
}

void escribirResultados(Dato datos[], int numDatos, FILE *archivoSalida) {
    int i;
    for (i = 0; i < numDatos; i++) {
        fprintf(archivoSalida, "%s,%.2f\n", datos[i].nombreEnergia, datos[i].valor);
    }
}

void calcularMaximos(Dato datos[], int numDatos) {
    int i;
    float maxValor = datos[0].valor;
    for (i = 1; i < numDatos; i++) {
        if (datos[i].valor > maxValor) {
            maxValor = datos[i].valor;
        }
    }
    printf("El maximo valor es: %.2f\n", maxValor);
}

void calcularMinimos(Dato datos[], int numDatos) {
    int i;
    float minValor = datos[0].valor;
    for (i = 1; i < numDatos; i++) {
        if (datos[i].valor < minValor) {
            minValor = datos[i].valor;
        }
    }
    printf("El minimo valor es: %.2f\n", minValor);
}

void calcularMedias(Dato datos[], int numDatos) {
    int i;
    float suma = 0.0;
    for (i = 0; i < numDatos; i++) {
        suma += datos[i].valor;
    }
    float media = suma / numDatos;
    printf("La media de los valores es: %.2f\n", media);
}

void ordenarMayor(Dato datos[], int numDatos) {
    int i, j;
    for (i = 0; i < numDatos - 1; i++) {
        for (j = 0; j < numDatos - i - 1; j++) {
            if (datos[j].valor < datos[j+1].valor) {
                Dato temp = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = temp;
            }
        }
    }
}

void ordenarMenor(Dato datos[], int numDatos) {
    int i, j;
    for (i = 0; i < numDatos - 1; i++) {
        for (j = 0; j < numDatos - i - 1; j++) {
            if (datos[j].valor > datos[j+1].valor) {
                Dato temp = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = temp;
            }
        }
    }
}

int main() {
    Dato datos[MAX_DATOS];
    int numDatos = 0;
    FILE *archivoEntrada, *archivoSalida;

    archivoEntrada = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (archivoEntrada == NULL) {
        printf("No se pudo abrir el archivo de entrada.\n");
        return 1;
    }

    cargarDatos(datos, &numDatos, archivoEntrada);
    fclose(archivoEntrada);

    printf("Datos cargados correctamente.\n");

    calcularMaximos(datos, numDatos);
    calcularMinimos(datos, numDatos);
    calcularMedias(datos, numDatos);

    ordenarMayor(datos, numDatos);

    archivoSalida = fopen("resultados.txt", "w");
    if (archivoSalida == NULL) {
        printf("No se pudo abrir el archivo de salida.\n");
        return 1;
    }

    escribirResultados(datos, numDatos, archivoSalida);
    fclose(archivoSalida);

    printf("Resultados escritos correctamente en el archivo de salida.\n");

    return 0;
}
