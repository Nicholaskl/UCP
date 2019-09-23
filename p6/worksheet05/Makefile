CC = gcc
EXEC = plotLog
CFLAGS = -Wall -Werror -pedantic -ansi -g
OBJ = display.o plot.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

display.o : display.c plot.h
	$(CC) $(CFLAGS) display.c -c

plot.o : plot.c plot.h
	$(CC) -c plot.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
