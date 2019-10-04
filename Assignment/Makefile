CC = gcc
EXEC = TicTacToe
CFLAGS = -Wall -Werror -pedantic -ansi -g
OBJ = run.o createTable.o userInterface.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

run.o : run.c createTable.h userInterface.h
	$(CC) $(CFLAGS) run.c -c

createTable.o : createTable.c createTable.h
	$(CC) -c createTable.c $(CFLAGS)

userInterface.o : userInterface.c userInterface.h
	$(CC) -c userInterface.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
