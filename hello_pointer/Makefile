# Makefile for hello_pointer package.
# Created on March 25, 2015 Wed.
# Author: Guanglin Du

# Defines variables
CC = gcc
BIN = hello_pointer.exe
 
 all: run
 
hello_pointer_main.o: hello_pointer_main.c
	$(CC) -c hello_pointer_main.c -o hello_pointer_main.o

hello_pointer.o: hello_pointer.c hello_pointer.h
	$(CC) -c hello_pointer.c -o hello_pointer.o
	
$(BIN): hello_pointer_main.o hello_pointer.o
	$(CC) -o $(BIN) hello_pointer_main.o hello_pointer.o

.Phony: clean run

run: $(BIN)
	./$(BIN)
	
clean:
	rm *.o $(BIN)
