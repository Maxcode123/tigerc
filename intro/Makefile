CC=gcc
SRC=src
SRCS=$(wildcard $(SRC)/*.c)
OBJ=obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
TEST=test
ARGS=

test: test-maxargs test-interp

test-maxargs: $(TEST)/bin/maxargs
	$<

test-interp: $(TEST)/bin/interp
	$<

$(TEST)/bin/interp: $(TEST)/interp_test.c $(OBJ)/interp.o $(OBJ)/types.o $(OBJ)/util.o
	$(CC) $^ -o $@ -lcriterion

$(TEST)/bin/maxargs: $(TEST)/maxargs_test.c $(OBJ)/maxargs.o $(OBJ)/types.o $(OBJ)/util.o
	$(CC) $^ -o $@ -lcriterion

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(ARGS) -c $< -o $@

clean:
	rm -rf obj/* test/bin/*