CC = gcc
EXEC = SortingCalc
CFLAGS = -Wall -pedantic -ansi
OBJ = numbers.o order.o user_input.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

numbers.o : numbers.c order.h user_input.h
	$(CC) $(CFLAGS) numbers.c -c

order.o : order.c numbers.h order.h 
	$(CC) -c order.c $(CFLAGS)

user_input.o : user_input.c user_input.h numbers.h
	$(CC) -c user_input.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
