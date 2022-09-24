#include <criterion/criterion.h>

#include "../src/funcs.h"

Test(maxargs_test, test_progs)
{
    // a := ( print( 10 ), 10 + 2 )
    stm prog = AssignStm(
        String("a"),
        EseqExp(
            PrintStm(LastExpList(NumExp(10))),
            OpExp(NumExp(10), plus, NumExp(2))
        )
    );
    cr_assert(maxargs(prog) == 1, "maxargs does not return expected result.");
}