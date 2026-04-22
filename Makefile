CC = gcc # Assign the variable CC as gcc command
CFLAGS = -Wall -Wextra #Warning all and warning extra

#Since the default goal is to build corg, now make and make all do the same thing
all: corg

corg: main.c
	$(CC) $(CFLAGS) -o corg main.c

# Forcefully remove all programs
clean:
	rm -f corg
