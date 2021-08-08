

SRC_DIR=source
INCLUDE_DIR=include
TESTS_DIR=tests

CC=gcc
FLAGS=-std=c11 -g -Wall -Wextra -I $(INCLUDE_DIR)

INCLUDES=$(wildcard $(INCLUDE_DIR)/*.h) ../liberror/errors-handling.h
SOURCES=$(wildcard $(SRC_DIR)/*.c) $(TESTS_DIR)/tests.c
OBJECTS=$(SOURCES:.c=.o)
TARGET=onegin


%.o: %.c
	$(CC) $(FLAGS) $< -c -o $@

main.o: main.c
	$(CC) $(FLAGS) $< -c -o $@

all: main.o $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) main.o -o $(TARGET)

tests: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o testing


.PHONY: clean

clean:
	-rm -f $(OBJECTS) main.o 
	-rm -f testing
	-rm -f onegin

