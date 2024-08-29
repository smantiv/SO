/*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 15-08-2024
Tema: Matrices
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔**/
#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(int *matriz, int n) {
    for (int i = 0; i < n * n; i++) {
        if (i % n == 0) {
            printf("\n");
        }
        printf("%d ", *(matriz + i)); 
    }
    printf("\n-----------\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("\nArgumentos validos: $ejecutable sizOfMtriz\n");
        exit(0);
    }

    int n = atoi(argv[1]);
    int size = n * n;
    int mA[size];
    int mB[size];
    int mC[size];

    // Inicializacion
    for (int i = 0; i < size; i++) {
        mA[i] = 1;
        mB[i] = 2;
        mC[i] = 0;
    }

    // Imprimir matrices originales
    printf("Matriz A:\n");
    imprimirMatriz(mA, n);
    printf("Matriz B:\n");
    imprimirMatriz(mB, n);
    printf("Matriz C (inicializada a cero):\n");
    imprimirMatriz(mC, n);

    // VERSION CLASICA DE MULTIPLICACION DE MATRICES: mA * mB = mC
    for (int i = 0; i < n; i++) { // filas de mA
        for (int j = 0; j < n; j++) { // columnas de mB
            int suma = 0;
            for (int k = 0; k < n; k++) { 
                suma += mA[i * n + k] * mB[k * n + j]; 
            }
            mC[i * n + j] = suma; 
        }
    }

    // Imprimir la matriz resultante
    printf("Matriz C (resultado de la multiplicación):\n");
    imprimirMatriz(mC, n);

    printf("\n Fin del programa!\n");

    return 0;
}
