

SRC_DIR=source
INCLUDE_DIR=include
TESTS_DIR=tests

CC=gcc
FLAGS=-std=c11 -g -Wall -Wextra -I $(INCLUDE_DIR)

TESTS=$(TESTS_DIR)/unit-tests.c
INCLUDES=$(wildcard $(INCLUDE_DIR)/*.h) $(TESTS_DIR)/unit-tests.h
SOURCES=$(wildcard $(SRC_DIR)/*.c)
OBJECTS=$(SOURCES:.c=.o)


%.o: %.c
	$(CC) $(FLAGS) $< -c -o $@

unit-tests.o: $(TESTS)
	$(CC) $(FLAGS) $< -c -o $@

main.o: main.c
	$(CC) $(FLAGS) $< -c -o $@

tests: unit-tests.o $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) unit-tests.o -o unit-tests

all: main.o $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) main.o -o solver

.PHONY: clean

clean:
	-rm -f $(OBJECTS) main.o unit-tests.o
	-rm -f unit-tests
	-rm -f solver

