all: programa

programa: main.o grafo.o
	gcc -o programa main.o grafo.o
 
main.o: main.c 
	gcc -c main.c -o main.o
 
grafo.o: grafo.c 
	gcc -c grafo.c -o grafo.o

clean:
	rm *.o