all: run_file

run_file:  stack.o
	gcc -g -Wall -o run_file stack.o

stack.o: stack.c
	gcc -g -Wall -c -o stack.o stack.c


clean:
	rm -f *.o
