/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Ejemplo en. clase de punteros
********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int rows, cols, i, j;
  int **matrix;
  
  rows = (int) atof(argv[1]);
  cols = (int) atof(argv[2]);
  
  //asignacion de memoria para la matriz
  matrix = (int **)malloc(rows*sizeof(int *));
  for (i=0; i<rows; i++){
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }
  
  //llenado matriz con valores iniciales
  for (i=0; i<rows; i++){
    for(j=0; j<cols; j++){
      matrix[i][j] = i*j;
    }
  }
  
  //impresion matriz
  for (i=0; i<rows; i++){
    for(j=0; j<cols; j++){
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }
  
  //liberacion o entrega de memoria
  for (i=0; i<rows; i++){
    free(matrix[i]);
  }
  free(matrix);
  
  return 0;
}