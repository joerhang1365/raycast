CC=gcc
CFLAGS=-Wall -Werror -Wpedantic -I./include
LDFLAGS=-lm -lSDL2
PROJECT_NAME=raycast

SOURCE_FILES=$(wildcard src/*.c)

build: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROJECT_NAME) main.c $(SOURCE_FILES)

clean:
	rm -f $(PROJECT_NAME)
