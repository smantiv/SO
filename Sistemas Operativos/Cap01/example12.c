/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 08-08-2024
Tema: Asignación de memoria dinamica
      Asignación del tamaño en Bytes de almacenamiento
********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int *varptr1 = malloc(4*sizeof(int));
  int *varptr2 = malloc(sizeof(int(4));
  int *varptr3 = malloc(4*sizeof*varptr3);
  
  if(*varptr1){
    for(int i=0; i<4; i++)
      varptr1(i)=i*i;
    for(int i=0; i<4; i++)
      printf("varptr1[%d]\t == %d\n", varptr1[i]);
  }
  
  printf("Se libera memoria reservada\n");
  free(varptr1);
  free(varptr2);
  free(varptr3);
  
  return 0;
  
  }