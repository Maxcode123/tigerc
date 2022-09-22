#pragma once
#include "util.h"
#include "types.h"

/* definition of straight line program:
a := 5 + 3 ; b := ( print (a, a - 1 ) , 10 * a ); print( b )
*/
stm prog = CompoundStm(
    AssignStm(
        String("a"),
        OpExp(NumExp(5), plus, NumExp(3))),
    CompoundStm(
        AssignStm(
            String("b"),
            EseqExp(
                PrintStm(
                    PairExpList(
                        IdExp(String("a")),
                        LastExpList(
                            OpExp(IdExp(String("a")), minus, NumExp(1))
                            )
                        )
                        ),
                OpExp(NumExp(10), times, IdExp(String("a")))
            )
        ),
        PrintStm(
            LastExpList(
                IdExp(String("b"))
            )
        )
        )
);