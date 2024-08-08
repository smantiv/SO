/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Ejercicio en clase
********************************************************/

#include <stdlib.h>
#include <stdio.h>

int main(){
  char *p;
  char *q = NULL;
  printf("Address of p = %s\n", p);
  printf("About to copy\"Goodbye\" to q\n");
  strcpy(q, "Goodbye");
  printf("String copied\n");
  printf("%s\n");
         
  return 0;
}