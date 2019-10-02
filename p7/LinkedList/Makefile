CC = gcc
EXEC = LinkedListTest
CFLAGS = -Wall -Werror -pedantic -ansi -g
OBJ = LinkedListTest.o LinkedList.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

LinkedListTest.o : LinkedListTest.c LinkedListTest.h LinkedList.h
	$(CC) $(CFLAGS) LinkedListTest.c -c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) -c LinkedList.c $(CFLAGS)


clean:
	rm -f $(EXEC) $(OBJ)
