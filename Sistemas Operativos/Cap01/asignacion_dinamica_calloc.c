/*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 08-08-2024
Tema: Asignación de memoria dinamica
      Asignación del tamaño en Bytes de almacenamiento
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔**/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int *vP1 = calloc(4, sizeof(int));
    int *vP2 = calloc(1, sizeof(int[4])); // o simplemente: int *vP2 = calloc(4, sizeof(int));
    int *vP3 = calloc(4, sizeof *vP3);

    if (vP2) { // Verificar si la asignación de memoria fue exitosa
        for (int i = 0; i < 4; i++) {
            printf("vP2[%d]\t == %d\n", i, vP2[i]); 
        }
    } else {
        printf("Error al asignar memoria para vP2\n");
    }

    printf("Se libera memoria reservada\n");
    free(vP1);
    free(vP2);
    free(vP3);

    return 0;
}
