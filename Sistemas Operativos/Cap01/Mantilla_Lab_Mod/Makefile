GCC = gcc
FLAGS = -c

PROGRAMAS: labprincipal

labprincipal:
	$(GCC) $(FLAGS) librerialab.c
	$(GCC) $@.c librerialab.o -o $@
	$(RM) *.o

clear:
	4(RM) *.o labprincipal
	