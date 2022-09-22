#pragma once
#include "util.h"

typedef struct stm_ *stm;
typedef struct exp_ *exp;
typedef struct expList_ *expList;
typedef enum {plus, minus, times, divs} binop;

// statement
struct stm_ {
    enum {compoundStm, assignStm, printStm} kind;
    union {
        struct {stm stm1, stm2;} compound;
        struct {string id; exp exprs;} assign;
        struct {expList exps;} print;
    } u;
};

// statement constructors
stm CompoundStm(stm stm1, stm stm2);
stm AssignStm(string id, exp exprs);
stm PrintStm(expList exps);

// expression
struct exp_ {
    enum {idExp, numExp, opExp, eseqExp} kind;
    union {
        string id;
        int num;
        struct {exp left; binop oper; exp right;} op;
        struct {stm stmt; exp exprs;} eseq;
    } u;
};

// expression constructors
exp IdExp(string id);
exp NumExp(int num);
exp OpExp(exp left, binop oper, exp right);
exp EseqExp(stm stmt, exp exprs);

// expression list
struct expList_ {
    enum {pairExpList, lastExpList} kind;
    union {
        struct {exp head; expList tail;} pair;
        exp last;
    } u;
};

// expression list constructors
expList PairExpList(exp head, expList tail);
expList LastExpList(exp last);