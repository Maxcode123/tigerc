CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
TEST=test
ARGS=-g

lextest: $(OBJ)/driver.o $(OBJ)/lex.yy.o $(OBJ)/errormsg.o $(OBJ)/util.o
	$(CC) $(ARGS) $^ -o $@

$(SRC)/lex.yy.c: $(SRC)/tiger.lex
	lex -o $@ $< 

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(ARGS) -c $< -o $@

clean:
	rm -rf obj/*