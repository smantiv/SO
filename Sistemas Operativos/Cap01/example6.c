/********************************************************
Autor: S. Mantilla
Materia: Sistemas Operativos
Fecha: 01-08-2024
Tema: Bonus 01
********************************************************/

int main() {
  char *a = NULL;
  char *b = NULL;
  a = function("Hi, its fun to learn");
  b = function("systems engineer");
  printf("From main: %s %s\n", a,b);
}

char *function(char *p){
  char q[strlen(p)+1];
  strcpy(q,p);
  printf("From q: the string is %s\n", q);
  return q;
}