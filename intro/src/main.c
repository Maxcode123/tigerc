#include "funcs.h"

int main()
{
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
    // stm prog = PrintStm(PairExpList(NumExp(5), PairExpList(NumExp(10), LastExpList(NumExp(15)))));
    printf("maxargs = %d\n", maxargs(prog));
}
