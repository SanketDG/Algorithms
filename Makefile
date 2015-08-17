LIBS = -lm
CC = gcc
CFLAGS = -g -Wall
SRCDIR = src

.PHONY: default all clean

# default: $(TARGET)
# all: default

# STACK algorithms

STACK = $(SRCDIR)/ds/stack

# $(STACK)/stack.o: $(STACK)/stack.c $(STACK)/stack.h
# 	$(CC) -c -o $@ $< -I$(STACK)

stack-menu: $(STACK)/stack.o
	$(CC) -o $@ $^ $(STACK)/$@.c -I$(STACK)

infix2postfix: $(STACK)/stack.o
	$(CC) -o $@ $^ $(STACK)/$@.c -I$(STACK)

postfix-eval: $(STACK)/stack.o
	$(CC) -o $@ $^ $(STACK)/$@.c -I$(STACK)

SPARSE = $(SRCDIR)/algo/sparse-matrix

sparse-matrix: $(SPARSE)/sparse-matrix.o
	$(CC) -o $@ $^ $(SPARSE)/sparse-main.c -I$(SPARSE)

# OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
# HEADERS = $(wildcard *.h)

# %.o: %.c $(HEADERS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# .PRECIOUS: $(TARGET) $(OBJECTS)

# $(TARGET): $(OBJECTS)
# 	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	find . -name "*.o" -type f -delete
	-rm -f *.o
	-rm -f stack-menu
	-rm -f sparse
	-rm -f infix2postfix
	-rm -f postfix-eval