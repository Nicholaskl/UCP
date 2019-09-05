CC = gcc
EXEC = download
CFLAGS = -Wall -pedantic -ansi
OBJ = download.o download_stats.o

ifdef ALL_STATS
CFLAGS += -D ALL_STATS
ALL_STATS : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

download.o : download.c download_stats.h
	$(CC) $(CFLAGS) download.c -c

download_stats.o : download_stats.c download_stats.h download.h 
	$(CC) -c download_stats.c $(CLFAGS)

clean:
	rm -f $(EXEC) $(OBJ)
