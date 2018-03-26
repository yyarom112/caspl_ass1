all: calc

calc:  PostFixStack.o
	gcc -g -Wall -o calc PostFixStack.o arithmetic activities.o:

PostFixStack.o: PostFixStack.c
	gcc -g -Wall -c -o PostFixStack.o PostFixStack.c
	
arithmetic activities.o: arithmetic activities.s
	nasm -g -f elf64 -w+all -o arithmetic activities.o arithmetic activities.s


clean:
	rm -f *.o
