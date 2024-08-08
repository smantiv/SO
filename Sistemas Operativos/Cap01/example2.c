/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Ejemplo en clase
********************************************************/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  int x;
  int suma = 0;
  do{
    scanf("%d", &x);
    suma += x;
  } while(x!=0);
  printf("La suma es: %d \n", suma);
  return 0;

}