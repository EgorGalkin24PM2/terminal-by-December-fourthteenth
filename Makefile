CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.o museum.o
	$(CC) -o main main.o museum.o

main.o: main.c museum.h
	$(CC) $(CFLAGS) -c main.c

exhibit.o: museum.c museum.h
	$(CC) $(CFLAGS) -c museum.c

clean:
	rm -f *.o main
