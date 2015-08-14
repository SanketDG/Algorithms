TARGET = prog
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall
SRCDIR = ./src

.PHONY: default all clean

# default: $(TARGET)
# all: default

stack:
	$(CC) -c $(SRCDIR)/ds/stack/stack.c
	$(CC) stack.o $(SRCDIR)/ds/stack/stack-main.c -o stack

sparse-matrix:
	$(CC) -c $(SRCDIR)/algo/sparse-matrix/sparse-matrix.c
	$(CC) sparse-matrix.o $(SRCDIR)/algo/sparse-matrix/sparse-main.c -o sparse

# OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
# HEADERS = $(wildcard *.h)

# %.o: %.c $(HEADERS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# .PRECIOUS: $(TARGET) $(OBJECTS)

# $(TARGET): $(OBJECTS)
# 	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f stack
	-rm -f sparse