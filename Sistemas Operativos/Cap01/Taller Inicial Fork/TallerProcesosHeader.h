/********************************************************
Autor: Sofia Mantilla
Materia: Sistemas Operativos
Fecha: 10-10-2024
Descripción: Header para TallerProcesosFunciones.c.
             Contiene la declaración de las funciones 
             para leer arreglos y sumar enteros.
********************************************************/

#ifndef TALLER_PROCESOS_HEADER_H
#define TALLER_PROCESOS_HEADER_H

// Función para leer un arreglo de enteros desde un archivo
// nombre_archivo: nombre del archivo a leer
// cantidad_elementos: número de enteros a leer
// Retorna un puntero a un arreglo dinámico de enteros
int* leer_arreglo(const char* nombre_archivo, int cantidad_elementos);

// Función para calcular la suma de un arreglo de enteros
// arreglo: puntero al arreglo de enteros
// cantidad_elementos: número de elementos en el arreglo
// Retorna la suma de los enteros en el arreglo
int suma_arreglo(int* arreglo, int cantidad_elementos);

#endif
