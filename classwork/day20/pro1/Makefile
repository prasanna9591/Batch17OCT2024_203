CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/main.c src/defect.c
OBJ = main.o defect.o
BIN = bin

all: $(BIN)/prg

$(BIN)/prg: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(BIN)/prg $(OBJ)

