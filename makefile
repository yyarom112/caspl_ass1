all: calc

calc:  stack.o
	gcc -g -Wall -o calc stack.o

stack.o: stack.c
	gcc -g -Wall -c -o stack.o stack.c


clean:
	rm -f *.o
