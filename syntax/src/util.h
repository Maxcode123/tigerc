#include <assert.h>

typedef char *string;
typedef char Bool;

#define TRUE 1
#define FALSE 0

void *checked_malloc(int);
string String(char *);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {Bool head; U_boolList tail;};
U_boolList U_BoolList(Bool head, U_boolList tail);

