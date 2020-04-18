CC=gcc
CFLAGS=-std=c11 -g -static
SRC_FILES=$(wildcard tcc_*.c)
OBJ_FILES=$(SRC_FILES:.c=.o)

tcc: $(OBJ_FILES)
	$(CC) -o tcc $(OBJ_FILES) $(LDFLAGS)

$(OBJ_FILES): tcc.h

test: tcc
	./test.sh


clean:
	rm -f tcc *.o *~ tmp*

.PHONY: test clean
