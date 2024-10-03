/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 03-10-2024
Tema: Piped Named o FIFO o Tuberia
Topico: Comunicación Unidireccional
        
        SERVIDOR
********************************************************/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FIFO_FILE "MYFIFO"

int main() {
    int fd;
    char readbuf[80];
    char end[10];
    int to_end;
    int read_bytes;
    
    /* Create the FIFO if it does not exist */
    mknod(FIFO_FILE, S_IFIFO | 0640, 0);
    strcpy(end, "end");
    while(1) {
        fd = open(FIFO_FILE, O_RDONLY);
        read_bytes = read(fd, readbuf, sizeof(readbuf));
        readbuf[read_bytes] = '\0';
        printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
        to_end = strcmp(readbuf, end);
        if (to_end == 0) {
            close(fd);
            break;
        }
    }
}
