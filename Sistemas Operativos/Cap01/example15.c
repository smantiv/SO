/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 15-08-2024
Tema: Matrices
********************************************************/
#include <stdio.h>
#include <stdlib.h>

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int imprimirMatriz(int *matriz, int n){

  for(int i = 0; i<n*size; i++){
    if(i%n==0)
      printf("\n");
    printf("%d",*(matriz+i));
  }
  printf("\n-----------\n");
}

int main(int argc, char *argv[]){
  if(argc<2){
    printf("\nArgumentos validos: $ejecutable sizOfMtriz\n");
    exit(0);
  }
  int n = (atoi)argv[1];
  int size = n * n;
  int mA[size];
  int mB[size];
  int mC[size];

  /Inicializacion/

  for (int i=0; i<size;i++){
    mA[i]=1;
    mB[i]=2;
    mC[i]=0;
  }

  for(in i=0; i<size; i++){
    if(i%size==0)
      printf("\n");
    printf("%d", mA[i]);
  }
  for(int i=0;i<size; i++){
      if(i%size==0)
        printf("\n");
      printf("%d", mB[i]);
    }
  for(int i=0; i<size;i++){
        if(i%size==0)
          printf("\n");
        printf("%d", mC[i]);
      }
   imprimirMatriz(mA,n);
   imprimirMatriz(mB,n);
   imprimirMatriz(mC,n);
  /VERSION CLASICA DE MULTIPLICACION DE MATRICES:mA*mB=mC/
  for(int i=0; i<n;i++){ //filas
    for(int j=0; j<n; j++){ //columnas
      int suma = 0;
      int *pA = mA[i];
      int *pB = mB[i+j];

      for(int h=0; h<n; h++){ //filas * columnas
        suma += pA*pB;
      } 
      mC = suma;
    }
  }

  printf("\n Fin del programa!");

  return 0;

}