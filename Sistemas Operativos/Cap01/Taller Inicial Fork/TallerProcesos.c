/********************************************************
Autor: Sofia Mantilla
Materia: Sistemas Operativos
Fecha: 17-10-2024
Descripción: ParcialII - Este programa implementa la lectura de 
arreglos desde archivos y la suma de sus elementos utilizando 
comunicación entre procesos a través de pipes y fork().
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parcial01.h" //cabecera donde se declaran las funciones leer_arreglo y suma_arreglo

int main(int argc, char* argv[]) {
    //verificación de formato adecuado: ./ejecutable N1 archivo00 N2 archivo01
    if (argc != 5) {
        fprintf(stderr, "Error: Formato correcto: %s N1 archivo00 N2 archivo01\n", argv[0]);
        return EXIT_FAILURE;
    }

    //lectura de argumentos
    int N1 = atoi(argv[1]);
    const char* archivo00 = argv[2];
    int N2 = atoi(argv[3]);
    const char* archivo01 = argv[4];

    //llamada a la función leer_arreglo para leer los números desde los archivos
    int* arreglo1 = leer_arreglo(archivo00, N1);
    if (arreglo1 == NULL) {
        fprintf(stderr, "Error: No se pudo leer el archivo %s\n", archivo00);
        return EXIT_FAILURE;
    }

    int* arreglo2 = leer_arreglo(archivo01, N2);
    if (arreglo2 == NULL) {
        fprintf(stderr, "Error: No se pudo leer el archivo %s\n", archivo01);
        free(arreglo1);  //liberar memoria si ya se había reservado
        return EXIT_FAILURE;
    }

    //creación de pipes para la comunicación entre procesos
    int pipe1[2], pipe2[2], pipe3[2];
  
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        perror("Error al crear pipes");
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_FAILURE);
    }

    //creación del gran hijo para calcular la suma del primer arreglo
    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("Error al crear proceso hijo (gran hijo)");
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        //código del gran hijo
        close(pipe1[0]);  //cerrar el extremo de lectura del pipe1
        int sumaA = suma_arreglo(arreglo1, N1);
        printf("GranHijo: [%d] Sum_File1 = %d\n", getpid(), sumaA);
        write(pipe1[1], &sumaA, sizeof(sumaA));  //enviar la suma a través del pipe1
        close(pipe1[1]);
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_SUCCESS);
    }

    //creación del segundo hijo para calcular la suma del segundo arreglo
    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("Error al crear proceso hijo (segundo hijo)");
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        //código del segundo hijo
        close(pipe2[0]);  //cerrar el extremo de lectura del pipe2
        int sumaB = suma_arreglo(arreglo2, N2);
        printf("SegundoHijo: [%d] Sum_File2 = %d\n", getpid(), sumaB);
        write(pipe2[1], &sumaB, sizeof(sumaB));  //enviar la suma a través del pipe2
        close(pipe2[1]);
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_SUCCESS);
    }

    //creación del primer hijo para calcular la suma total
    pid_t pid3 = fork();
    if (pid3 == -1) {
        perror("Error al crear proceso hijo (primer hijo)");
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_FAILURE);
    }

    if (pid3 == 0) {
        //código del primer hijo
        close(pipe1[1]);  //cerrar el extremo de escritura del pipe1
        close(pipe2[1]);  //cerrar el extremo de escritura del pipe2
        close(pipe3[0]);  //cerrar el extremo de lectura del pipe3

        int sumaA, sumaB;
        read(pipe1[0], &sumaA, sizeof(sumaA));  //leer sumaA desde el pipe1
        read(pipe2[0], &sumaB, sizeof(sumaB));  //leer sumaB desde el pipe2

        int suma_total = sumaA + sumaB;
        printf("PrimerHijo: [%d] Suma total = %d\n", getpid(), suma_total);
        write(pipe3[1], &suma_total, sizeof(suma_total));  //enviar la suma total al pipe3

        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe3[1]);
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_SUCCESS);
    }

    //código del proceso padre
    close(pipe1[1]);  //cerrar los extremos de escritura de los pipes
    close(pipe2[1]);
    close(pipe3[1]);

    //leer la suma total desde el pipe3 y mostrarla
    int suma_total;
    read(pipe3[0], &suma_total, sizeof(suma_total));
    printf("Padre: [%d] Suma total = %d\n", getpid(), suma_total);

    //cerrar los extremos de lectura de los pipes
    close(pipe1[0]);
    close(pipe2[0]);
    close(pipe3[0]);

    //esperar a que los hijos terminen
    wait(NULL);
    wait(NULL);
    wait(NULL);

    //liberación de memoria
    free(arreglo1);
    free(arreglo2);

    return EXIT_SUCCESS;
}
