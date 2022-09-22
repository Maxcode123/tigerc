#include "types.h"

stm CompoundStm(stm stm1, stm stm2)
{
    stm c_stm = checked_malloc(sizeof(*c_stm));
    c_stm->kind = compoundStm;
    c_stm->u.compound.stm1 = stm1;
    c_stm->u.compound.stm2 = stm2;
    return c_stm;
}

stm AssignStm(string id, exp exprs)
{
    stm a_stm = checked_malloc(sizeof(*a_stm));
    a_stm->kind = assignStm;
    a_stm->u.assign.id = id;
    a_stm->u.assign.exprs = exprs;
    return a_stm;
}

stm PrintStm(expList exps)
{
    stm p_stm = checked_malloc(sizeof(*p_stm));
    p_stm->kind = printStm;
    p_stm->u.print.exps = exps;
    return p_stm;
}

exp IdExp(string id)
{
    exp i_exp = checked_malloc(sizeof(*i_exp));
    i_exp->kind = idExp;
    i_exp->u.id = id;
    return i_exp;
}

exp NumExp(int num)
{
    exp n_exp = checked_malloc(sizeof(*n_exp));
    n_exp->kind = numExp;
    n_exp->u.num = num;
    return n_exp;
}

exp OpExp(exp left, binop op, exp right)
{
    exp o_exp = checked_malloc(sizeof(*o_exp));
    o_exp->kind = opExp;
    o_exp->u.op.left = left;
    o_exp->u.op.oper = op;
    o_exp->u.op.right = right;
    return o_exp;
}

exp EseqExp(stm stmt, exp exprs)
{
    exp e_exp = checked_malloc(sizeof(*e_exp));
    e_exp->kind = eseqExp;
    e_exp->u.eseq.stmt = stmt;
    e_exp->u.eseq.exprs = exprs;
    return e_exp;
}

expList PairExpList(exp head, expList tail)
{
    expList p_list = checked_malloc(sizeof(*p_list));
    p_list->kind = pairExpList;
    p_list->u.pair.head = head;
    p_list->u.pair.tail = tail;
    return p_list;
}

expList LastExpList(exp last)
{
    expList l_list = checked_malloc(sizeof(*l_list));
    l_list->kind = lastExpList;
    l_list->u.last = last;
    return l_list;
}