
CC = gcc
EXEC = TicTacToe
CFLAGS = -Wall -ansi -pedantic -Werror -std=c89 -g
OBJ = Run.o CreateTable.o UserInterface.o GameFunc.o LogFunc.o LinkedList.o WinCondition.o

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

Run.o : Run.c CreateTable.h UserInterface.h
	$(CC) $(CFLAGS) Run.c -c

CreateTable.o : CreateTable.c CreateTable.h
	$(CC) -c CreateTable.c $(CFLAGS)

UserInterface.o : UserInterface.c UserInterface.h GameFunc.h LinkedList.h LogFunc.h CreateTable.h
	$(CC) -c UserInterface.c $(CFLAGS)

GameFunc.o : GameFunc.c LinkedList.h LogFunc.h  GameFunc.h WinCondition.h
	$(CC) -c GameFunc.c $(CFLAGS)

LogFunc.o : LogFunc.c LogFunc.h LinkedList.h
	$(CC) -c LogFunc.c $(CFLAGS)

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) -c LinkedList.c $(CFLAGS)

WinCondition.o : WinCondition.c WinCondition.h
	$(CC) -c WinCondition.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
