#pragma once
#include "util.h"
#include "types.h"

static int _pcount_stm(stm stmt);
static int _pcount_compoundstm(stm c_stm);
static int _pcount_subcompountstm(stm stmt);
static int _pcount_printstm(stm p_stm);
static int _pcount_exp(exp exprs);
static int _pcount_explist(expList expl);
static int _max(int a, int b);
