TARGET = prog
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall
SRCDIR = src

.PHONY: default all clean

# default: $(TARGET)
# all: default

STACK = $(CC) -c $(SRCDIR)/ds/stack/stack.c

# STACK algorithms

stack-menu:
	$(STACK)
	$(CC) stack.o $(SRCDIR)/ds/stack/stack-menu.c -o stack-menu

infix2postfix:
	$(STACK)
	$(CC) stack.o $(SRCDIR)/ds/stack/infix2postfix.c -o infix2postfix

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
	-rm -f stack-menu
	-rm -f sparse
	-rm -f infix2postfix