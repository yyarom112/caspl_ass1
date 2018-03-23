all: calc

calc:  PostFixStack.o
	gcc -g -Wall -o calc PostFixStack.o

PostFixStack.o: PostFixStack.c
	gcc -g -Wall -c -o PostFixStack.o PostFixStack.c


clean:
	rm -f *.o
