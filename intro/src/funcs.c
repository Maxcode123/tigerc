#include "funcs.h"


int maxargs(stm prog)
{
    return _pcount_stm(prog);
}

static int _pcount_stm(stm stmt)
{
    if (stmt->kind == compoundStm) return _pcount_compoundstm(stmt);
    else if (stmt->kind == printStm) return _pcount_printstm(stmt);
    else return _pcount_exp(stmt->u.assign.exprs);
}

static int _pcount_compoundstm(stm c_stm)
{
    return _max(_pcount_stm(c_stm->u.compound.stm1), _pcount_stm(c_stm->u.compound.stm2));
}

static int _pcount_printstm(stm p_stm)
{
    if (p_stm->u.print.exps->kind == lastExpList) return _pcount_exp(p_stm->u.print.exps->u.last);
    else return _pcount_explist(p_stm->u.print.exps);
}

static int _pcount_exp(exp exprs)
{
    if (exprs->kind == eseqExp) return _max(_pcount_stm(exprs->u.eseq.stmt), _pcount_exp(exprs->u.eseq.exprs));
    return 1;
}

static int _pcount_explist(expList expl)
{
    expList n = expl;
    int c = 1;
    int _m = 0;
    while (n->kind == pairExpList) 
    {
        c++;
        if (n->u.pair.head->kind == eseqExp) _m = _max(_m, _pcount_exp(n->u.pair.head));            
        n = n->u.pair.tail;
    }
    return _max(_m, c);   
}

static int _max(int a, int b)
{
    if (a > b) return a;
    return b;
}
