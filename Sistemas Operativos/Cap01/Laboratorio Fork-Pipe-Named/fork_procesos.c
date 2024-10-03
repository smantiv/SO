  8 #include <stdio.h>
  9 #include <stdlib.h>
 10 #include <unistd.h>
 11 #include <sys/types.h>
 12 
 13 
 14 void creacion_fork(int linea){
 15     pid_t proceso; 
 16     proceso = fork();
 17     if(proceso<0){
 18         printf("Error creación proceso\n");
 19         exit(1);
 20     }else if (proceso==0)
 21         printf("%d: Proceso =HIJO=: %d\n",linea, getpid());
 22     else
 23         printf("%d: Proceso =PADRE= %d\n",linea, getpid());
 24 }
 25 
 26 int main(int argc, char *argv[]){
 27     int p = (int) atoi(argv[1]);
 28     for(int i=0; i<p; i++)
 29         creacion_fork(i);
 30 
 31 
 32     printf("\n---\n\n");
 33     return 0;
 34 }