CC=gcc
CFLAGS=-Wall -Os -liris

all: window_creation
clean: window_creation
	rm $^

window_creation: window_creation.c
	$(CC) $(CFLAGS) $^ -o $@

