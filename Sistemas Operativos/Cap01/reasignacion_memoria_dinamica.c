/*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 08-08-2024
Tema: Asignación de memoria dinamica
      Asignación del tamaño en Bytes de almacenamiento
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Función para imprimir el tamaño reasignado */
void info_almacenamiento(const int *siguiente, const int *anterior, int valores) {
    if (siguiente) {
        printf("%s ubicación = %p, Tamaño Reservado: %d valores (%zu bytes)\n",
               (siguiente != anterior ? "Nueva" : "Anterior"), (void *)siguiente, valores, 
               valores * sizeof(int)); 
    }
}

int main(int argc, char **argv) {
    const int patron[] = {1, 2, 3, 4, 5, 6, 7, 8};
    const int patron_size = sizeof patron / sizeof(int);
    int *siguiente = NULL, *anterior = NULL;

    if ((siguiente = (int *)malloc(patron_size * sizeof *siguiente))) { // Asigna el vector
        memcpy(siguiente, patron, sizeof patron); // llena el vector
        info_almacenamiento(siguiente, anterior, patron_size);
    } else {
        return EXIT_FAILURE;
    }

    // Reasigna los valores del vector en el siguiente ciclo
    const int realloc_size[] = {10, 20, 30, 40, 50, 60, 70, 80};
    for (int i = 0; i < sizeof realloc_size / sizeof(int); i++) { // Corregido: i!= -> i<
        if ((siguiente = (int *)realloc(anterior = siguiente, realloc_size[i] * sizeof(int)))) { // Corregido: aiguiente -> siguiente
            info_almacenamiento(siguiente, anterior, realloc_size[i]);
            assert(!memcmp(siguiente, anterior, sizeof patron)); // Verifica que los datos originales se mantengan
        } else {
            fprintf(stderr, "Error al reasignar memoria.\n");
            free(anterior); // Liberar la memoria anterior en caso de error
            return EXIT_FAILURE;
        }
    }

    printf("Se libera memoria reservada\n");
    free(siguiente); // Liberar la memoria al final

    return 0;
}
