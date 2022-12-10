CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
ARGS=-g

test: a.out
	./$< test.tig

a.out: $(OBJ)/parsetest.o $(OBJ)/y.tab.o $(OBJ)/lex.yy.o $(OBJ)/errormsg.o $(OBJ)/util.o
	$(CC) $(ARGS) $^

$(SRC)/y.tab.c: $(SRC)/tiger.grm
	bison -v --header=$(SRC)/y.tab.h -o $@ $<

$(SRC)/lex.yy.c: $(SRC)/tiger.lex
	lex -o $@ $< 

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(ARGS) -c $< -o $@

clean:
	rm -rf obj/* a.out $(SRC)/lex.yy.c $(SRC)/y.output $(SRC)/y.tab.c $(SRC)/y.tab.h