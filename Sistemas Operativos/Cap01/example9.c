/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Ejemplo en. clase de punteros
********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define size 10

int main(int argc, char *argv[]){
 /****** Suma de 2 valores ingresados por pantalla usando punteros****/
  int valor1, valor2;
  int *ptrV1, *ptrV2;
  ptrV1 = &valor1;
  ptrV2 = &valor2;
  
  printf("\nIngrese 2 valores a ser sumados \n");
  scanf("%d %d", &valor1, &valor2);
  
  printf("\nLa suma es = %d\n", *ptrV1+*ptrV2);
  
  return 0;
}