LIBS = -lm
CC = gcc
CFLAGS = -g -Wall
SRCDIR = src

.PHONY: default all clean

# default: $(TARGET)
# all: default

# STACK algorithms

STACK = $(SRCDIR)/ds/stack

stack-menu: $(STACK)/stack.o
	$(CC) -o $@ $^ $(STACK)/$@.c -I$(STACK)

infix2postfix: $(STACK)/stack.o
	$(CC) -o $@ $^ $(STACK)/$@.c -I$(STACK)

postfix-eval: $(STACK)/stack.o
	$(CC) -o $@ $^ $(STACK)/$@.c -I$(STACK)

strrev: $(STACK)/stack.o
	$(CC) -o $@ $^ $(STACK)/$@.c -I$(STACK)

# Queue Algorithms

QUEUE = $(SRCDIR)/ds/queue

queue-menu: $(QUEUE)/queue.h
	$(CC) -o $@ $^ $(QUEUE)/$@.c -I$(QUEUE)

# Sparse Matrix Representation

SPARSE = $(SRCDIR)/algo/sparse-matrix

sparse-matrix: $(SPARSE)/sparse-matrix.o
	$(CC) -o $@ $^ $(SPARSE)/sparse-main.c -I$(SPARSE)

# Tower of Hanoi

toh:
	$(CC) $(SRCDIR)/algo/tower_of_hanoi/tower_of_hanoi.c -o $@

clean:
	-find . -name "*.o" -type f -delete
	-rm -f *.o
	-rm -f stack-menu
	-rm -f sparse
	-rm -f infix2postfix
	-rm -f postfix-eval
	-rm -f queue-menu
	-rm -f strrev
	-rm -f toh
