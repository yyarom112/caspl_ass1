all: calc

calc:  PostFixStack.o arithmetic_activities.o
	gcc -g -Wall -o calc PostFixStack.o arithmetic_activities.o

PostFixStack.o: PostFixStack.c
	gcc -g -Wall -c -o PostFixStack.o PostFixStack.c
	
arithmetic_activities.o: arithmetic_activities.s
	nasm -g -f elf64 -w+all -o arithmetic_activities.o arithmetic_activities.s


clean:
	rm -f *.o
