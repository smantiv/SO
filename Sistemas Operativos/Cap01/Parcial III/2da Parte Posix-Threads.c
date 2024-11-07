/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 07-11-2024
Tema: Parcial III

Descripción:
Esta aplicación que permite crear una función
que permite imprimir "Hilo ID iniciado". La función tendrá
un bucle interno el cual empezará a contar justo después
de imprimir "Hilo ID iniciado". La cuenta debe ser de 300
enteros. Se imprime a su vez, solo el 0 y el último valor
del bucle. Finalizado la cuenta  la función imprimirá
"Hilo ID finalizado". El principal de la aplicación crea
5 hilos y hacer que los hilos impriman en orden como han
sido creados.

********************************************************/


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_HILOS 5
#define CUENTA 300

void *funcion_hilo(void *arg) {
    int id = *(int *)arg;
    printf("Hilo %d iniciado\n", id);

    for (int i = 0; i <= CUENTA; i++) {
        if (i == 0 || i == CUENTA) {
            printf("Hilo %d: %d\n", id, i);
        }
    }

    printf("Hilo %d finalizado\n", id);
    return NULL;
}

int main() {
    pthread_t hilos[NUM_HILOS];
    int ids[NUM_HILOS];

    // Creación de hilos en orden
    for (int i = 0; i < NUM_HILOS; i++) {
        ids[i] = i + 1;
        if (pthread_create(&hilos[i], NULL, funcion_hilo, &ids[i]) != 0) {
            perror("Error al crear hilo");
            return 1;
        }
	pthread_join(hilos[i], NULL);  // Asegura que se ejecuten en orden
    }

    printf("Todos los hilos han finalizado\n");
    return 0;
