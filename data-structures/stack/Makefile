LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: clean

# STACK algorithms

stack-menu: stack.o
	$(CC) -o $@ $^ $@.c -I.

infix2postfix: stack.o
	$(CC) -o $@ $^ $@.c -I.

postfix-eval: $(STACK)/stack.o
	$(CC) -o $@ $^ $@.c -I.

strrev: $(STACK)/stack.o
	$(CC) -o $@ $^ $@.c -I.

all: stack-menu infix2postfix postfix-eval strrev

clean:
	rm stack-menu
	rm infix2postfix
	rm postfix-eval
	rm strrev
