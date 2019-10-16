CC = gcc
EXEC = TicTacToe
CFLAGS = -Wall -ansi -pedantic -Werror -std=c89 -g
OBJ = run.o createTable.o userInterface.o gameFunc.o logFunc.o LinkedList.o

ifdef SECRET
CFLAGS += -D SECRET
SECRET : clean $(EXEC)
endif

ifdef EDITOR
CFLAGS += -D EDITOR
EDITOR : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

run.o : run.c createTable.h userInterface.h
	$(CC) $(CFLAGS) run.c -c

createTable.o : createTable.c createTable.h
	$(CC) -c createTable.c $(CFLAGS)

userInterface.o : userInterface.c userInterface.h gameFunc.h LinkedList.h logFunc.h
	$(CC) -c userInterface.c $(CFLAGS)

gameFunc.o : gameFunc.c LinkedList.h logFunc.h  gameFunc.h
	$(CC) -c gameFunc.c $(CFLAGS)

logFunc.o : logFunc.c logFunc.h LinkedList.h
	$(CC) -c logFunc.c $(CFLAGS)

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) -c LinkedList.c $(CFLAGS)



clean:
	rm -f $(EXEC) $(OBJ)
