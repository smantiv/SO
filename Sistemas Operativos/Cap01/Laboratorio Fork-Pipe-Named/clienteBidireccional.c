/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 03-10-2024
Tema: Laboratorio Fork-Pipe-Named, cliente bidireccional
********************************************************/

#define FIFO_FILE "/tmp/fifo_twoway"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>  // Para open, O_CREAT, O_RDWR
#include <unistd.h> // Para close, read, write
#include <sys/types.h> // Para tipos de datos del sistema
#include <sys/stat.h>  // Para constantes de permisos como S_IFIFO

 int main() {
    int fd;
    int end_process;
    int stringlen;
    int read_bytes;
    char readbuf[80];
    char end_str[5];
    printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
    fd = open(FIFO_FILE, O_CREAT|O_RDWR);
    strcpy(end_str, "end");
 
    while (1) {
       printf("Enter string: ");
       fgets(readbuf, sizeof(readbuf), stdin);
       stringlen = strlen(readbuf);
       readbuf[stringlen - 1] = '\0';
       end_process = strcmp(readbuf, end_str);
 
       //printf("end_process is %d\n", end_process);
       if (end_process != 0) {
          write(fd, readbuf, strlen(readbuf));
          printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
          read_bytes = read(fd, readbuf, sizeof(readbuf));
          readbuf[read_bytes] = '\0';
          printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
       } else {
          write(fd, readbuf, strlen(readbuf));
          printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
          close(fd);
          break;
       }
    }
    return 0;
 }
     
