all: sig.o
	gcc sig.o -o test
sig.o: sig.c
	gcc -c sig.c
run: all
	./test
