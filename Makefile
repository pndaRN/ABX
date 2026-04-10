CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc/engine -Isrc/content -Isrc/application
LDFLAGS = -lSDL2 -lSDL2_image -lm 

SRC = $(wildcard src/engine/*.c) $(wildcard src/content/*.c) $(wildcard src/application/*.c)
OUT = game

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
