CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BINDIR=bin
BIN=$(BINDIR)/main
ARGS=-Wno-implicit-function-declaration

run:
	$(BIN)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(ARGS) -c $< -o $@

clean:
	rm -rf bin/* obj/*