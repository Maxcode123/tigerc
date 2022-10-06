#pragma once
#include "util.h"
#include "types.h"

void interp(stm prog);

typedef struct table_ *table;

struct table_ {
    string id;
    int value;
    table next;
};

table Table(string id, int value, table next);

static int _get(string id, table h);
static void _print(table h);

// constructor
table interpStm(stm s, table h);

static table _interp_compoundstm(stm c_stm, table h);

static table _interp_printstm(stm p_stm, table h);

static table _interp_assignstm(stm a_stm, table h);

typedef struct intAndTable_ *intAndTable;

struct intAndTable_ {
    int i;
    table h;
 };

// constructor
intAndTable IntAndTable(int i, table h);

intAndTable interpExp(exp e, table h);

static intAndTable _interp_explist(expList expl, table h);

static intAndTable _interp_opExp(exp e, table h);

