LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: clean

# STACK algorithms

STACK = $(SRCDIR)/ds/stack

stack-menu: stack.o
	$(CC) -o $@ $^ $@.c -I.

infix2postfix: $(STACK)/stack.o
	$(CC) -o $@ $^ $@.c -I.

postfix-eval: $(STACK)/stack.o
	$(CC) -o $@ $^ $@.c -I.

strrev: $(STACK)/stack.o
	$(CC) -o $@ $^ $@.c -I.

clean:
	rm stack-menu
	rm infix2postfix
	rm postfix-eval
	rm strrev
