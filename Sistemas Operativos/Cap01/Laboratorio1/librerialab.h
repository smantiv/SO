/*
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 29-08-2024
Laborartorio Compilación Modular
        - Funcionamiento del código
        - Modularización del código
        - Creación de fichero de Automatización de Compilación
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
        INTERFAZ DE LIBRERIA DE FUNCIONES: MENÚ DE FUNCIONES
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
*/

#ifndef _LIBRERIALAB_H_
#define _LIBRERIALAB_H_

#define CAPACIDAD_INICIAL 4

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
        int capacidad;
        int totalElementos;
        void **elementos;
} vectorDinamico;

/*Inicializacion de los valores del Vector, casting y reserva de memoria*/
void vectorInicio(vectorDinamico *V);

/*Retorna total de elementos */
int totalVector(vectorDinamico *V);

/*Redimensiona el vector*/
static void resizeVector(vectorDinamico *V, int capacidad);

/*Agregar elementos al vector*/
void addVector(vectorDinamico *V, void *elemento);

/*Liberación de memoria Dinámica*/
void freeVector(vectorDinamico *V);

/*Obtencion de elemento según indice y redimension*/
void *getVector(vectorDinamico *V, int indice);

/*Ubicar elemento en un indice*/
void setVector(vectorDinamico *V, int indice, void *elemento);

/*Borrar elemento según indice y redimension*/
void borrarVector(vectorDinamico *V, int indice);

#endif


