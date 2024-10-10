/********************************************************
Autor: Sofia Mantilla
Materia: Sistemas Operativos
Fecha: 10-10-2024
Descripción: ParcialII
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parcial01.h" //cabecera

int main(int argc, char* argv[]) {
    //con esto se verifica que se esté usando el formato adecuado requerido en el enunciado: ./ejecutable N1 archivo00 N2 archivo01
    if (argc != 5) {
        fprintf(stderr, "Formato correcto: %s N1 archivo00 N2 archivo01\n", argv[0]);
        return EXIT_FAILURE;
    }

    //Lectura de archivos y argumentos que se pasan por pantalla al ejecutar
    int N1 = atoi(argv[1]);
    const char* archivo00 = argv[2];
    int N2 = atoi(argv[3]);
    const char* archivo01 = argv[4];

    //se llama a la función leer_arreglo para que lea los números en el archivo, recordar que esta función está en el archivo parcial 01.c
    int* arreglo1 = leer_arreglo(archivo00, N1);
    int* arreglo2 = leer_arreglo(archivo01, N2);
  
    //creación de pipes
    int pipe1[2], pipe2[2], pipe3[2];
  
    //Se verifica que las pipes s ehayan creado correctamente
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        perror("Error al crear pipes");
        exit(EXIT_FAILURE);
    }

    //Creacion del gran hijo: Crea un nuevo proceso (fork()). Si pid1 es 0, significa que estamos en el proceso hijo.
    pid_t pid1 = fork();
    if (pid1 == 0) {
        close(pipe1[0]);
        int sumaA = suma_arreglo(arreglo1, N1);
        printf("GranHijo: [%d] Sum_File1 = %d\n", getpid(), sumaA);
        write(pipe1[1], &sumaA, sizeof(sumaA));
        close(pipe1[1]);
        //liberación de memoria
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_SUCCESS);
    }

    //creación segundo hijo
    pid_t pid2 = fork();
    if (pid2 == 0) {
        close(pipe2[0]);
        int sumaB = suma_arreglo(arreglo2, N2);
        printf("SegundoHijo: [%d] Sum_File2 = %d\n", getpid(), sumaB);
        write(pipe2[1], &sumaB, sizeof(sumaB));
        close(pipe2[1]);
        //liberación de memoria
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_SUCCESS);
    }

    //creación primer hijo
    pid_t pid3 = fork();
    if (pid3 == 0) {
        close(pipe1[1]);
        close(pipe2[1]);
        close(pipe3[0]);

        int sumaA, sumaB;
        read(pipe1[0], &sumaA, sizeof(sumaA));
        read(pipe2[0], &sumaB, sizeof(sumaB));

        int suma_total = sumaA + sumaB;
        printf("PrimerHijo: [%d] Suma total = %d\n", getpid(), suma_total);
        write(pipe3[1], &suma_total, sizeof(suma_total));
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe3[1]);
        //liberación de memoria
        free(arreglo1);
        free(arreglo2);
        exit(EXIT_SUCCESS);
    }

    //el proceso padre cierra los extremos de escritura de los pipes porque solo necesita leer
    close(pipe1[1]);
    close(pipe2[1]);
    close(pipe3[1]);

    //Lee la suma_total desde pipe3 y la imprime.
    int suma_total;
    read(pipe3[0], &suma_total, sizeof(suma_total));
    printf("Padre: [%d] Suma total = %d\n", getpid(), suma_total);

    close(pipe1[0]);
    close(pipe2[0]);
    close(pipe3[0]);

    //el proceso padre espere a que sus procesos hijos terminen antes de continuar.
    wait(NULL);
    wait(NULL);
    wait(NULL);

    //libera memoria
    free(arreglo1);
    free(arreglo2);

    return EXIT_SUCCESS;
}


  
 
