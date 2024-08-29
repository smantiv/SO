/*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Ejercicio funciones mátematicas
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔**/

#include <stdio.h>
#include <math.h>
#include "funciones.h"

#define PI 3.14159265358979323846

void suma(){
  /* Calcular suma */
  int a,b;
  printf("Ingrese el primer numero\n");
  scanf("%d",&a);
  printf("Ingrese el segundo numero\n");
  scanf("%d",&b);
  int suma = a + b;
  printf("La suma del numero %d y el numero %d es %d \n", a, b, suma);
}

void areaCirculo() {
  /* Calcular el área de un círculo ingresando el radio por teclado */
  float r;
  printf("Ingrese el valor del radio: ");
  scanf("%f", &r); 
  float area = PI * (r * r);  
  printf("El área de un círculo con radio %f es %f\n", r, area);
}

void vol(){
  /* Calcular el volumen de circunferencia ingresando el radio por teclado */
  float r2;
  printf("Ingrese el valor del radio\n");
  scanf("%f",&r2);
  double vol = 4/3.0 * PI * (r2*r2*r2);
  printf("El volumen de una circunferencia con radio %f es %f \n", r2,vol);
}

void volC(){
  /* Calcular el volumen de un cono ingresando variables necesarias por teclado */
  float r3;
  float h;
  printf("Ingrese el valor del radio\n");
  scanf("%f",&r3);
  printf("Ingrese el valor de la altura\n");
  scanf("%f",&h);
  double volC = 1/3.0 * PI * (r3*r3) * h;
  printf("El volumen de una circunferencia con radio %f y altura %f es %f \n", r3, h, volC);
}

void hipo(){
  /* Calcular una hipotenusa ingresando variables necesarias por teclado */
  float catO;
  float catC;
  printf("Ingrese la medida del cateto 1\n");
  scanf("%f",&catO);
  printf("Ingrese el valor del cateto 2\n");
  scanf("%f",&catC);
  double tan = sqrt((catO*catO)+(catC*catC));
  printf("El valor de la hipotenusa de un triángulo, cuyo cateto opuesto es %f y cateto contiguo es %f, es %f \n", catO, catC, tan);
}
