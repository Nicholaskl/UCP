CC = gcc
EXEC = question1
CFLAGS = -Wall -Werror -pedantic -ansi -g
OBJ = question1.o read.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

question1.o : question1.c read.h
	$(CC) $(CFLAGS) question1.c -c

read.o : read.c read.h
	$(CC) -c read.c $(CFLAGS)


clean:
	rm -f $(EXEC) $(OBJ)
