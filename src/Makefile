CC = gcc
CFLAGS = -g -Wall
EXECUTABLE=shl

all: shl child529

child529: child529.c
	$(CC) $(CFLAGS) child529.c -o child529

shl: linkedlist.o shellMimic.c
	$(CC) $(CFLAGS) linkedlist.o shellMimic.c -o $(EXECUTABLE)
linkedlist.o: linkedlist.h 
clean:
	rm -rf *.o *.out *.gch child529 $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes --track-origins=yes -s ./$(EXECUTABLE)
