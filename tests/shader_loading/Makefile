CC=gcc
CFLAGS=-Wall -Os -liris

all: shader_loading
clean: shader_loading
	rm $^

shader_loading: shader_loading.c
	$(CC) $(CFLAGS) $^ -o $@

