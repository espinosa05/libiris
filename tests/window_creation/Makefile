CC=gcc
CFLAGS=-Wall -lglfw -Os -liris

all: window_creation
clean: window_creation
	rm $^

window_creation: window_creation.c
	$(CC) $(CFLAGS) $^ -o $@

