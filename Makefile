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

stack-menu: $(SRCDIR)/ds/stack/stack-menu.c
	$(STACK)
	$(CC) stack.o $(SRCDIR)/ds/stack/stack-menu.c -o stack-menu

infix2postfix: $(SRCDIR)/ds/stack/infix2postfix.c
	$(STACK)
	$(CC) stack.o $(SRCDIR)/ds/stack/infix2postfix.c -o infix2postfix

postfix-eval: $(SRCDIR)/ds/stack/postfix-eval.c
	$(STACK)
	$(CC) stack.o $(SRCDIR)/ds/stack/postfix-eval.c -o postfix-eval

sparse-matrix: $(SRCDIR)/algo/sparse-matrix/sparse-main.c
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
	-rm -f postfix-eval