/*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Ejercicio funciones mátematicas
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔**/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Función para calcular la suma de dos números
int suma() {
    int a, b;
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    int resultado = a + b;
    printf("La suma del numero %d y el numero %d es %d \n", a, b, resultado);
    return resultado; // Opcionalmente, puedes devolver el resultado de la suma
}

// Función para calcular el área de un círculo
float areaCirculo() {
    float radio;
    printf("Ingrese el valor del radio: ");
    scanf("%f", &radio);
    float area = PI * radio * radio;
    printf("El área de un círculo con radio %.2f es %.2f\n", radio, area);
    return area; // Opcionalmente, puedes devolver el área calculada
}

// Función para calcular el volumen de una esfera (no de una circunferencia)
double volumenEsfera() {
    float radio;
    printf("Ingrese el valor del radio: ");
    scanf("%f", &radio);
    double volumen = (4.0 / 3.0) * PI * pow(radio, 3); 
    printf("El volumen de una esfera con radio %.2f es %.2f \n", radio, volumen);
    return volumen; // Opcionalmente, puedes devolver el volumen calculado
}

// Función para calcular el volumen de un cono
double volumenCono() {
    float radio, altura;
    printf("Ingrese el valor del radio: ");
    scanf("%f", &radio);
    printf("Ingrese el valor de la altura: ");
    scanf("%f", &altura);
    double volumen = (1.0 / 3.0) * PI * radio * radio * altura;
    printf("El volumen de un cono con radio %.2f y altura %.2f es %.2f \n", radio, altura, volumen);
    return volumen; // Opcionalmente, puedes devolver el volumen calculado
}

// Función para calcular la hipotenusa de un triángulo rectángulo
double hipotenusa() {
    float cateto1, cateto2;
    printf("Ingrese la medida del cateto 1: ");
    scanf("%f", &cateto1);
    printf("Ingrese la medida del cateto 2: ");
    scanf("%f", &cateto2);
    double hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);
    printf("El valor de la hipotenusa de un triángulo, cuyos catetos son %.2f y %.2f, es %.2f \n", cateto1, cateto2, hipotenusa);
    return hipotenusa; // Opcionalmente, puedes devolver la hipotenusa calculada
}

int main() {
    suma();
    areaCirculo();
    volumenEsfera(); 
    volumenCono();
    hipotenusa();
    return 0;
}
