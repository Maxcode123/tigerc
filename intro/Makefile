CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
TEST=test
ARGS=


test-maxargs: $(TEST)/bin/maxargs
	$<

$(TEST)/bin/maxargs: $(TEST)/maxargs_test.c $(OBJ)/funcs.o $(OBJ)/types.o $(OBJ)/util.o
	$(CC) $^ -o $@ -lcriterion

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(ARGS) -c $< -o $@

clean:
	rm -rf obj/* test/bin/*