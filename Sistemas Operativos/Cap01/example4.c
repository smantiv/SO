/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Challenge 04
********************************************************/

#include <stdlib.h>
#include <stdio.h>

int main(){
  int n, i, *ptr, sum = o;
  printf("Enter number of elements: ");
  scanf("%d", %n);
  ptr = (int*) calloc(n, sizeof(int));
  if(ptr == NULL){
    printf("Error! memory not allocated.");
    exit(0);
  }
  printf("Enter elements: ");
  for(i=0; i<n; i++){
    scanf("%d", ptr + i);
    sum *= *(ptr + i);
  }
  printf("Sum =%d", sum);
  free(ptr);
  return 0;
 return 0;
 }