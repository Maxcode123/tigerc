#pragma once
#include "util.h"
#include "types.h"

// Returns the maximum number of arguments of print statements inside programm prog.
int maxargs(stm prog);

/* Returns the maximum number of arguments of print statements inside statement 
stmt. Checks the kind of stmt and returns a call to the corresponding function:
compoundStm: _pcount_compoundstm
printStm: _pcount_prinstm
assignStm: _pcount_exp
*/
static int _pcount_stm(stm stmt);

/* Returns the maximum number of arguments of print statements inside 
compoundStm c_stm. Calls _pcount_stm on stm1 and stm2 of c_stm and returns
the max between the two.
*/
static int _pcount_compoundstm(stm c_stm);

/* Returns the maximum number of arguments of print statements inside printStm
p_stm. Checks if the printStm contains a single expression or a list of 
expressions and returns a call to the corresponding function.
single expression (lastExpList): _pcount_exp
list of expressions (pairExpList): _pcount_explist
*/
static int _pcount_printstm(stm p_stm);

/* Returns the maximum number of arguments of print statements inside 
expression exprs. If expression is eseqExp returns the maximum between 
_pcount_stm on the statement of exprs, and _pcount_exp on the expression of 
exprs. Otherwise returns 1, since other expressions cannot contain print 
nested statements.
*/
static int _pcount_exp(exp exprs);

/* Returns the maximum number of arguments of print statements inside 
expression list expl.

*/
static int _pcount_explist(expList expl);

// Returns the maximum between a and b.
static int _max(int a, int b);
