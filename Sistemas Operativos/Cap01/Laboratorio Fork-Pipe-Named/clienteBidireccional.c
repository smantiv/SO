 #define FIFO_FILE "/tmp/fifo_twoway"
 18 int main() {
 19    int fd;
 20    int end_process;
 21    int stringlen;
 22    int read_bytes;
 23    char readbuf[80];
 24    char end_str[5];
 25    printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
 26    fd = open(FIFO_FILE, O_CREAT|O_RDWR);
 27    strcpy(end_str, "end");
 28 
 29    while (1) {
 30       printf("Enter string: ");
 31       fgets(readbuf, sizeof(readbuf), stdin);
 32       stringlen = strlen(readbuf);
 33       readbuf[stringlen - 1] = '\0';
 34       end_process = strcmp(readbuf, end_str);
 35 
 36       //printf("end_process is %d\n", end_process);
 37       if (end_process != 0) {
 38          write(fd, readbuf, strlen(readbuf));
 39          printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
 40          read_bytes = read(fd, readbuf, sizeof(readbuf));
 41          readbuf[read_bytes] = '\0';
 42          printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
 43       } else {
 44          write(fd, readbuf, strlen(readbuf));
 45          printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
 46          close(fd);
 47          break;
 48       }
 49    }
 50    return 0;
 51 }
~                                          