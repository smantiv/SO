/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Ejemplo en. clase de punteros
********************************************************/

int main(int argc, char *argv[]) {
    int rows, cols, i, j;
    int **matrix;

    if (argc != 3) {
        fprintf(stderr, "Uso: %s <filas> <columnas>\n", argv[0]);
        return 1; //Indicar un error en la ejecución
    }

    rows = atoi(argv[1]); //Usar atoi para convertir cadenas a enteros
    cols = atoi(argv[2]);

    //Asignación de memoria para la matriz
    matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Error al asignar memoria para las filas.\n");
        return 1; // Indicar un error en la ejecución
    }

    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Error al asignar memoria para la columna %d.\n", i);

            //Liberar la memoria asignada previamente antes de salir
            for (j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);

            return 1; //Indicar un error en la ejecución
        }
    }

    //Llenado de la matriz con valores iniciales
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = i * j;
        }
    }

    //Impresión de la matriz
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]); // Agregar tabulación para mejor legibilidad
        }
        printf("\n");
    }

    //Liberación de memoria
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
