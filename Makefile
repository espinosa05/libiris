CC=gcc
CFLAGS=-Wall -O0 -ggdb
IRIS_FLAGS=-lGL -lglfw
SOFLAGS=-fPIC -shared

IRIS_SRCD=src/lib/iris/
IRIS_INCD=src/include/
TMP_DIR=tmp/

IRIS_SRC=					\
	$(IRIS_SRCD)iris.c			\
    	$(IRIS_SRCD)core/iris_getopt.c		\
	$(IRIS_SRCD)core/iris_window.c		\
	$(IRIS_SRCD)core/iris_utils.c		\
	$(IRIS_SRCD)core/window/iris_audio.c	\
	$(IRIS_SRCD)core/window/iris_gfx.c	\
	$(IRIS_SRCD)core/window/iris_input.c


all: install

clean: $(TMP_DIR)
	rm -rf $(TMP_DIR)

install: $(TMP_DIR)libiris.so
	cp -r $(IRIS_INCD)* /usr/include/
	cp $(TMP_DIR)libiris.so /usr/lib/

# build shared library
$(TMP_DIR)libiris.so: $(IRIS_SRC) $(TMP_DIR)
	$(CC) $(CFLAGS) $(SOFLAGS) $(IRIS_FLAGS) $(IRIS_SRC) -o $@

# build temporary output directory
$(TMP_DIR):
	mkdir $@

