#pragma once
#include "util.h"
#include "types.h"


// Pointer to node of variable table.
typedef struct table_ *table;

// Node of variable table implemented as linked list.
struct table_ {
    string id;
    int value;
    table next;
};

// Interpreter function.
table interp(stm prog);

// table constructor.
table Table(string id, int value, table next);

// Returns the value associated with id in the variable table pointed by h.
int get(string id, table h);

// Prints the values in the variable table pointed by h.
static void _print(table h);

// Interprets statement s and returns the updated variable table.
table interpStm(stm s, table h);

// Interprets compound statement c_stm and returns the updated variable table.
static table _interp_compoundstm(stm c_stm, table h);

// Interprets the print statement p_stm and returns the updated variable table.
static table _interp_printstm(stm p_stm, table h);

// Interprets the assignment statement a_stm and returns the update variable table.
static table _interp_assignstm(stm a_stm, table h);

typedef struct intAndTable_ *intAndTable;

// Result of expression interpretation.
struct intAndTable_ {
    int i;
    table h;
 };

// intAndTable constructor.
intAndTable IntAndTable(int i, table h);

// Interprets expression e.
intAndTable interpExp(exp e, table h);

// Interprets expression list expl.
static intAndTable _interp_explist(expList expl, table h);

// Interprets binary operation expression e.
static intAndTable _interp_opExp(exp e, table h);

