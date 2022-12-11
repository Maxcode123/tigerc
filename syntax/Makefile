CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
ARGS=-g
TIG=test.tig

test-syntax: a.out
	./$< $(TIG)

test-lex: lextest
	./$< $(TIG)

a.out: $(OBJ)/parsetest.o $(OBJ)/y.tab.o $(OBJ)/lex.yy.o $(OBJ)/errormsg.o $(OBJ)/util.o
	$(CC) $(ARGS) $^

lextest: $(OBJ)/driver.o $(OBJ)/lex.yy.o $(OBJ)/errormsg.o $(OBJ)/util.o
	$(CC) $(ARGS) $^ -o $@

$(SRC)/y.tab.h: $(SRC)/y.tab.c

$(SRC)/y.tab.c: $(SRC)/tiger.grm
	bison -v --header=$(SRC)/y.tab.h -o $@ $<

$(SRC)/lex.yy.c: $(SRC)/tiger.lex
	lex -o $@ $< 

$(OBJ)/driver.o: $(SRC)/y.tab.h

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(ARGS) -c $< -o $@

clean:
	rm -rf obj/* a.out $(SRC)/lex.yy.c $(SRC)/y.output $(SRC)/y.tab.c $(SRC)/y.tab.h