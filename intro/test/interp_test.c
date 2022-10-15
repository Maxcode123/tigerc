#include <criterion/criterion.h>

#include "../src/interp.h"

Test(interp_test, prog1)
{
    // a := 10 + 2
    stm prog = AssignStm(String("a"), OpExp(NumExp(10), plus, NumExp(2)));
    table h = interp(prog);
    cr_assert(get("a", h) == 12, "!");
}