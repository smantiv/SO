/********************************************************
Autor: Sofia Mantilla
Materia: Sistemas Operativos
Fecha: 10-10-2024
Descripción: Funciones para lectura de arreglos y suma de enteros.
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "parcial01.h" //header

//con esta función se lee el contenido de un archivo y se guarda en un arreglo dinamico
int* leer_arreglo(const char* nombre_archivo, int cantidad_elementos) {
    FILE* archivo = fopen(nombre_archivo, "r"); //abre archivo modo lectura
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    int* arreglo = (int*)malloc(cantidad_elementos * sizeof(int));
    if (arreglo == NULL) {
        perror("Error al asignar memoria");
        fclose(archivo);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < cantidad_elementos; i++) {
        if (fscanf(archivo, "%d", &arreglo[i]) != 1) {
            fprintf(stderr, "Error al leer el elemento %d del archivo\n", i);
            free(arreglo);
            fclose(archivo);
            exit(EXIT_FAILURE);
        }
    }

    fclose(archivo);
    return arreglo;
}

//función para calcular suma de enteros
int suma_arreglo(int* arreglo, int cantidad_elementos) {
    int suma = 0;
    for (int i = 0; i < cantidad_elementos; i++) {
        suma += arreglo[i];
    }
    return suma;
}
