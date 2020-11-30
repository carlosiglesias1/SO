CCFLAGS = -Wall -g -O0

all: clean lista.o listaprocs.o
	gcc $(CCFLAGS) -o shell shell.c lista.o listaprocs.o
lista.o:lista.c lista.h
	gcc $(CCFLAGS) -c lista.c 
listaprocs.o:listaprocs.c listaprocs.h
	gcc $(CCFLAGS) -c listaprocs.c 
clean:
	rm -f *.o shell
