/********************************************************
Autor: Sofia Mantilla
Materia: Sistemas Operativos
Fecha: 17-10-2024
Descripción: El servidor recibe los mensajes del cliente, 
los invierte y los reenvía, finalizando cuando recibe "end".
********************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_FILE "/tmp/fifo_twoway"  //Ruta del archivo FIFO

//Función que invierte una cadena de texto
void reverse_string(char *str) {
    int inicio = 0;
    int fin = strlen(str) - 1;
    char temp;
    
    //Intercambia los caracteres del inicio y el final
    while (inicio < fin) {
        temp = str[inicio];
        str[inicio] = str[fin];
        str[fin] = temp;
        inicio++;
        fin--;
    }
}

int main() {
    int fd;                //Descriptor del archivo FIFO
    char readbuf[80];      //Buffer para el mensaje
    char end[5] = "end";   //Palabra "end" para terminar el proceso
    
    //Crear el archivo FIFO si no existe
    mkfifo(FIFO_FILE, 0640);
    
    //Abrir el FIFO para leer y escribir
    fd = open(FIFO_FILE, O_RDWR);
    
    //Bucle para procesar mensajes
    while (1) {
        // Leer mensaje del cliente
        int read_bytes = read(fd, readbuf, sizeof(readbuf));
        readbuf[read_bytes] = '\0';  // Terminar la cadena con '\0'
        
        //Mostrar el mensaje recibido
        printf("Mensaje recibido: \"%s\"\n", readbuf);
        
        //Si el mensaje es "end", cerrar el programa
        if (strcmp(readbuf, end) == 0) {
            close(fd);  // Cerrar el FIFO
            break;  // Salir del bucle
        }
        
        //Invertir el mensaje
        reverse_string(readbuf);
        
        //Enviar el mensaje invertido de vuelta al cliente
        write(fd, readbuf, strlen(readbuf));
    }
    
    return 0;
}
