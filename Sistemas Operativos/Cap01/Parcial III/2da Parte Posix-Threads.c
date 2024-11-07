/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 07-11-2024
Tema: Parcial III

Descripción:
Esta aplicación permite crear una función que imprime "Hilo ID iniciado".
La función tiene un bucle interno que empieza a contar justo después de
imprimir "Hilo ID iniciado". La cuenta es de 300 enteros, imprimiendo
solo el 0 y el último valor del bucle. Al finalizar la cuenta, la función 
imprime "Hilo ID finalizado". El principal de la aplicación crea 5 hilos 
y asegura que los hilos impriman en orden como han sido creados.
********************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_HILOS 5
#define CUENTA 300

//Función que será ejecutada por cada hilo
void *funcion_hilo(void *arg) {
    int id = *(int *)arg; // Obtener el ID del hilo desde los argumentos
    printf("Hilo %d se ha iniciado\n", id);

    //Bucle que cuenta hasta CUENTA (300)
    for (int i = 0; i <= CUENTA; i++) {
        if (i == 0 || i == CUENTA) {
            printf("Hilo %d: %d\n", id, i); // Imprimir solo el 0 y el último valor
        }
    }

    printf("Hilo %d finalizado\n", id);
    return NULL; //Retornar NULL al finalizar
}

int main() {
    pthread_t hilos[NUM_HILOS]; //Arreglo para almacenar los identificadores de los hilos
    int ids[NUM_HILOS]; //Arreglo para almacenar los IDs de los hilos

    //Crear hilos
    for (int i = 0; i < NUM_HILOS; i++) {
        ids[i] = i + 1; //Asigna un ID único a cada hilo
        if (pthread_create(&hilos[i], NULL, funcion_hilo, &ids[i]) != 0) { //Error al crear hilo
            perror("Error al crear hilo"); 
            return 1;
        }
    }

    //Asegurarse de que se ejecuten en orden
    for (int i = 0; i < NUM_HILOS; i++) {
        pthread_join(hilos[i], NULL); //Esperar a que cada hilo termine antes de continuar
    }

    printf("Todos los hilos han finalizado\n");
    return 0; 
}


