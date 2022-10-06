#include "maxargs.h"
#include "interp.h"

int main()
{
    stm prog = CompoundStm(
        AssignStm(String("a"), NumExp(5)),
        AssignStm(String("b"), NumExp(10))
    );
    interp(prog);
}
