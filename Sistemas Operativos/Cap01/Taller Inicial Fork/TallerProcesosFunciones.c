/********************************************************
Autor: Sofia Mantilla
Materia: Sistemas Operativos
Fecha: 17-10-2024
Descripción: Implementación de funciones para la lectura 
             de arreglos y suma de enteros.
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "TallerProcesosHeader.h" //header con las declaraciones de las funciones

//función para leer un arreglo de enteros desde un archivo
int* leer_arreglo(const char* nombre_archivo, int cantidad_elementos) {
    FILE* archivo = fopen(nombre_archivo, "r"); //abre el archivo en modo lectura
    if (archivo == NULL) {
        perror("Error al abrir el archivo");  //manejo de error al abrir el archivo
        return NULL;  //retorna NULL si no se puede abrir el archivo
    }

    //asignación de memoria dinámica para el arreglo de enteros
    int* arreglo = (int*)malloc(cantidad_elementos * sizeof(int));
    if (arreglo == NULL) {
        perror("Error al asignar memoria");  //manejo de error en la asignación de memoria
        fclose(archivo);  //cierra el archivo si hay error en la asignación de memoria
        return NULL;
    }

    //lectura de los enteros desde el archivo y almacenamiento en el arreglo
    for (int i = 0; i < cantidad_elementos; i++) {
        if (fscanf(archivo, "%d", &arreglo[i]) != 1) {
            fprintf(stderr, "Error al leer el elemento %d del archivo\n", i);
            free(arreglo);  //liberar la memoria asignada si hay un error de lectura
            fclose(archivo);  //cierra el archivo
            return NULL;
        }
    }

    fclose(archivo);  //cierra el archivo después de la lectura exitosa
    return arreglo;   //retorna el arreglo de enteros leído
}

//función para calcular la suma de los enteros en un arreglo
int suma_arreglo(int* arreglo, int cantidad_elementos) {
    int suma = 0;
    for (int i = 0; i < cantidad_elementos; i++) {
        suma += arreglo[i];  //acumula los valores del arreglo en la variable suma
    }
    return suma;  //retorna la suma total de los elementos
}
