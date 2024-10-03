17 #define FIFO_FILE "/tmp/fifo_twoway"
 18 void reverse_string(char *);
 19 int main() {
 20    int fd;
 21    char readbuf[80];
 22    char end[10];
 23    int to_end;
 24    int read_bytes;
 25 
 26    /* Create the FIFO if it does not exist */
 27    mkfifo(FIFO_FILE, S_IFIFO|0640);
 28    strcpy(end, "end");
 29    fd = open(FIFO_FILE, O_RDWR);
 30    while(1) {
 31       read_bytes = read(fd, readbuf, sizeof(readbuf));
 32       readbuf[read_bytes] = '\0';
 33       printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
 34       to_end = strcmp(readbuf, end);
 35 
 36       if (to_end == 0) {
 37          close(fd);
 38          break;
 39       }
 40       reverse_string(readbuf);
 41       printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));
 42       write(fd, readbuf, strlen(readbuf));
 43       /*
 44       sleep - This is to make sure other process reads this, otherwise this
 45       process would retrieve the message
 46       */
 47       sleep(2);
 48    }
 49    return 0;
 50 }



52 void reverse_string(char *str) {
 53    int last, limit, first;
 54    char temp;
 55    last = strlen(str) - 1;
 56    limit = last/2;
 57    first = 0;
 58 
 59    while (first < last) {
 60       temp = str[first];
 61       str[first] = str[last];
 62       str[last] = temp;
 63       first++;
 64       last--;
 65    }
 66    return;
 67 }
                                    