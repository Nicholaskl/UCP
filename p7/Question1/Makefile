CC = gcc
EXEC = question1
CFLAGS = -Wall -Werror -pedantic -ansi -g
OBJ = question1.o mainMenu.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

question1.o : question1.c mainMenu.h
	$(CC) $(CFLAGS) question1.c -c

mainMenu.o : mainMenu.c mainMenu.h
	$(CC) -c mainMenu.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
