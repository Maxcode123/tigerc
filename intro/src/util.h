#pragma once
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char *string;
string String(char *);

typedef char _bool;
#define TRUE 1
#define FALSE 0

void *checked_malloc(int);