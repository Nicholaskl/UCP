CC = gcc
EXEC = generate
CFLAGS = -Wall -Werror -pedantic -ansi -g
OBJ = generate.o randomarray.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

generate.o : generate.c randomarray.h
	$(CC) $(CFLAGS) generate.c -c

randomarray.o : randomarray.c randomarray.h
	$(CC) -c randomarray.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
