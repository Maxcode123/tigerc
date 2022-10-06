#include <criterion/criterion.h>

#include "../src/maxargs.h"

Test(maxargs_test, prog1)
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

Test(maxargs_test, prog2)
{
    // print( 1, 2, 3, 10 + 20 )
    stm prog = PrintStm(
        PairExpList(
            NumExp(1),
            PairExpList(
                NumExp(2),
                PairExpList(
                    NumExp(3),
                    LastExpList(
                        OpExp(NumExp(10), plus, NumExp(20))
                    )
                )
            )
        )
    );
    cr_assert(maxargs(prog) == 4, "maxargs does not return expected result");
}

Test(maxargs_test, prog3)
{
    // x := 3 ; y := x + 5; print( ( print( x, y, x + y ), x * y ), x, y, x * y, x + y )
    stm prog = CompoundStm(
        AssignStm(String("x"), NumExp(3)),
        CompoundStm(
            AssignStm(String("y"), OpExp(IdExp(String("x")), plus, NumExp(5))),
            PrintStm(
                PairExpList(
                    EseqExp(
                        PrintStm(
                            PairExpList(
                                IdExp(String("x")),
                                PairExpList(
                                    IdExp(String("y")),
                                    LastExpList(
                                        OpExp(IdExp(String("x")), plus, IdExp("y"))
                                    )
                                )
                            )
                        ),
                        OpExp(IdExp(String("x")), times, IdExp(String("y")))
                    ),
                    PairExpList(
                        IdExp(String("x")),
                        PairExpList(
                            IdExp(String("y")),
                            PairExpList(
                                OpExp(IdExp(String("x")), times, IdExp(String("y"))),
                                LastExpList(
                                    OpExp(IdExp(String("x")), plus, IdExp(String("y")))
                                )
                            )
                        )
                        )
                )
            )
        )
    );
    cr_assert(maxargs(prog) == 5, "maxargs does not return expected result.");
}

Test(maxargs_test, prog4)
{
    // A := ( print( 5, 6, 9 ), 7 )
    stm prog = AssignStm(
        String("A"),
        EseqExp(
            PrintStm(
                PairExpList(
                    NumExp(5),
                    PairExpList(
                        NumExp(6),
                        LastExpList(
                            NumExp(9)
                        )
                    )
                )
            ),
            NumExp(7)
        )
    );
    cr_assert(maxargs(prog) == 3, "maxargs does not return expected result.");
}