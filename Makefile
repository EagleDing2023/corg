CC = gcc # Assign the variable CC as gcc command
CFLAGS = -Wall -Wextra #Warning all and warning extra

#Since the default goal is to build corg, now make and make all do the same thing
all: corg

extensions.o: extensions.c extensions.h
	$(CC) $(CFLAGS) -c extensions.c

main.o: main.c extensions.h
	$(CC) $(CFLAGS) -c main.c

corg: main.o extensions.o
	$(CC) $(CFLAGS) -o corg main.o extensions.o




# Forcefully remove all programs
clean:
	rm -f corg main.o extensions.o
