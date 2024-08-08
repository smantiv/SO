/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 08-08-2024
Tema: Asignación de memoria dinamica
********************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int var =480;
  int *varptr = &var;
  int **doubleptr = &varptr;
  
  printf("Valor de la variable \t\t = %d\n", var);
  printf("Valor del puntero \t\t = %d\n", *varptr);
  printf("Valor del puntero doble \t = %d\n", **doubleptr);
  
  printf("Dirección de la variable \t\t = %d\n", &var);
  
  printf("Dirección del puntero \t\t = %d\n", &varptr);
  printf("Valor en el puntero \t\t = %d\n", varptr);
  
  printf("Dirección de la variable \t\t = %d\n", *doubleptr);
  printf("Dirección de la variable \t\t = %d\n", doubleptr);
  
  return 0;
}