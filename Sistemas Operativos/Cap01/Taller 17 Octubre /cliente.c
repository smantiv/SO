/********************************************************
Autor: Sofia Mantilla
Materia: Sistemas Operativos
Fecha: 17-10-2024
Descripción: El cliente envía mensajes al servidor a través 
de un archivo FIFO y muestra las respuestas invertidas,
terminando cuando envía "end".
********************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_FILE "/tmp/fifo_twoway"  //Ruta del archivo FIFO

int main() {
    int fd;                //Descriptor del archivo FIFO
    char readbuf[80];      //Buffer para el mensaje
    char end_str[5] = "end";  //Palabra "end" para terminar el proceso
    
    //Abrir el archivo FIFO para leer y escribir
    fd = open(FIFO_FILE, O_CREAT | O_RDWR);
    
    //Bucle para enviar mensajes
    while (1) {
        printf("Escribe un mensaje (o 'end' para terminar): ");
        fgets(readbuf, sizeof(readbuf), stdin);  // Leer el mensaje del usuario
        readbuf[strlen(readbuf) - 1] = '\0';  // Eliminar el salto de línea
        
        //Enviar el mensaje al servidor
        write(fd, readbuf, strlen(readbuf));
        
        //Si el mensaje es "end", cerrar el programa
        if (strcmp(readbuf, end_str) == 0) {
            close(fd);  // Cerrar el FIFO
            break;  // Salir del bucle
        }
        
        //Leer la respuesta del servidor
        int read_bytes = read(fd, readbuf, sizeof(readbuf));
        readbuf[read_bytes] = '\0';  // Terminar la cadena con '\0'
        
        //Mostrar la respuesta invertida
        printf("Respuesta del servidor: \"%s\"\n", readbuf);
    }
    
    return 0;
}
