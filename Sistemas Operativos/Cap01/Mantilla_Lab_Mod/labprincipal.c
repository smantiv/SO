/*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 29-08-2024
Laborartorio Compilación Modular
        - Funcionamiento del código
        - Modularización del código
        - Creación de fichero de Automatización de Compilación
°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔*°❀⋆.ೃ࿔*:･°❀⋆.ೃ࿔**/

#define CAPACIDAD_INICIAL 4
#include <stdio.h>
#include <stdlib.h>
#include "librerialab.h"

/*funcion principal*/
int main(){
        int mariano;
        vectorDinamico editor;
        vectorInicio(&editor);

        addVector(&editor, "Hola ");
        addVector(&editor, "Profesional ");
        addVector(&editor, "en ");
        addVector(&editor, "formación ");
        addVector(&editor, "de ");
        addVector(&editor, "Ingenieria.");

        printf("\n");

        for (mariano = 0; mariano < totalVector(&editor); mariano++)
        printf("%s", (char *) getVector(&editor, mariano));
        
        printf("\n");

        /*se borra los 5 elementos del 1 a 5 */
        int a=5;
        while(a>1){
                borrarVector(&editor, a);
                a--;
        }
        printf("\n");

        setVector(&editor, 1, "Buenos");
        addVector(&editor, "dias");

        printf("\n");
        for (mariano = 0; mariano < totalVector(&editor); mariano++)
        printf("%s ", (char *) getVector(&editor, mariano));
        printf("\n");

        freeVector(&editor);
        return 0;
}