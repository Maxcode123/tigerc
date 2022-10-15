#include "interp.h"

table interp(stm prog)
{
    table h = NULL;
    h = interpStm(prog, h);
    return h;
}

table Table(string id, int value, table next)
{
    table t = checked_malloc(sizeof(*t));
    t->id = id;
    t->value = value;
    t->next = next;
    return t;
}

int get(string id, table h)
{
    table n = h;
    while (n != NULL)
    {
        if (strcmp(n->id, id) == 0) return n->value;
        n = n->next;
    }
}

static void _print(table h)
{
    table n = h;
    while (n != NULL)
    {
        printf("%s: %d\n", n->id, n->value);
        n = n->next;
    }
}

table interpStm(stm s, table h)
{
    if (s->kind == compoundStm) return _interp_compoundstm(s, h);
    else if (s->kind == printStm) return _interp_printstm(s, h);
    else return _interp_assignstm(s, h);
}

static table _interp_compoundstm(stm c_stm, table h)
{
    return interpStm(c_stm->u.compound.stm2, interpStm(c_stm->u.compound.stm1, h));
}

static table _interp_printstm(stm p_stm, table h)
{
    return _interp_explist(p_stm->u.print.exps, h)->h;
}

static table _interp_assignstm(stm a_stm, table h)
{
    intAndTable it = interpExp(a_stm->u.assign.exprs, h);
    return Table(a_stm->u.assign.id, it->i, it->h);        
}

intAndTable IntAndTable(int i, table h)
{
    intAndTable it = checked_malloc(sizeof(*it));
    it->i = i;
    it->h = h;
    return it;
}

intAndTable interpExp(exp e, table h)
{
    if (e->kind == idExp) return IntAndTable(get(e->u.id, h), h);
    else if (e->kind == numExp) return IntAndTable(e->u.num, h);
    else if (e->kind == opExp) return _interp_opExp(e, h);
    else return interpExp(e->u.eseq.exprs, interpStm(e->u.eseq.stmt, h));
}

static intAndTable _interp_explist(expList expl, table h)
{
    if (expl->kind == lastExpList) return interpExp(expl->u.last, h);
    else 
    {
        intAndTable it = interpExp(expl->u.pair.head, h);
        return _interp_explist(expl->u.pair.tail, it->h);
    }
}

static intAndTable _interp_opExp(exp e, table h)
{
    intAndTable left = interpExp(e->u.op.left, h);
    intAndTable right = interpExp(e->u.op.right, left->h); 
    if (e->u.op.oper == plus) return IntAndTable(left->i + right->i, right->h);
    else if (e->u.op.oper == minus) return IntAndTable(left->i - right->i, right->h);
    else if (e->u.op.oper == times) return IntAndTable(left->i * right->i, right->h);
    else return IntAndTable(left->i / right->i, right->h); // check for div by zero!!
}