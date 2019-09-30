CC = gcc
EXEC = question1
CFLAGS = -Wall -Werror -pedantic -ansi -g
OBJ = question1.o menu.o read.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

question1.o : question1.c menu.h
	$(CC) $(CFLAGS) question1.c -c

menu.o : menu.c menu.h read.h
	$(CC) -c menu.c $(CFLAGS)

read.o : read.h menu.h
	$(CC) -c read.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
