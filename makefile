all: graph

graph: graph.o queue.o nodes.o
	gcc -Wall -g -o graph graph.o queue.o nodes.o

nodes.o: nodes.c
	gcc -Wall -g -c nodes.c

graph.o: graph.c graph.h
	gcc -Wall -g -c graph.c

queue.o: queue.c queue.h
	gcc -Wall -g -c queue.c

clean:
	rm -f *.o graph