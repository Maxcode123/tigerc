#include <criterion/criterion.h>

#include "../src/interp.h"

Test(interp_test, prog1)
{
    // a := 10 + 2
    stm prog = AssignStm(String("a"), OpExp(NumExp(10), plus, NumExp(2)));
    table h = interp(prog);
    cr_assert(get("a", h) == 12, "!");
}

Test(interp_test, prog2)
{
    // a := 5 ; b := a + 2 ; c := b - 6 
    stm prog = CompoundStm(
        AssignStm(String("a"), NumExp(5)),
        CompoundStm(
            AssignStm(String("b"), OpExp(IdExp(String("a")), plus, NumExp(2))),
            AssignStm(String("c"), OpExp(IdExp(String("b")), minus, NumExp(6)))
        )
    );
    table h = interp(prog);
    cr_assert(get("a", h) == 5);
    cr_assert(get("b", h) == 7);
    cr_assert(get("c", h) == 1);
}

Test(interp_test, prog3)
{
    // _var := ( a := 1, a := a + 1 ; a := a + 1, a * a)
    stm prog = AssignStm(
        String("a"),
        EseqExp(
            CompoundStm(
                AssignStm(String("a"), NumExp(1)),
                CompoundStm(
                    AssignStm(String("a"), OpExp(IdExp(String("a")), plus, NumExp(1))),
                    AssignStm(String("a"), OpExp(IdExp(String("a")), plus, NumExp(1)))
                    )
                ),
                OpExp(IdExp(String("a")), times, IdExp(String("a")))
            )
        );
    table h = interp(prog);
    cr_assert(get("a", h) == 9);
}