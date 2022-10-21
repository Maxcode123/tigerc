%{
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "tokens.h"
#include "errormsg.h"

int charPos=1;

int yywrap(void)
{
 charPos=1;
 return 1;
}

void adjust(void)
{
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

id [a-zA-Z][a-zA-Z0-9]*
int [0-9]+

%%
{id} {adjust(); return ID;}
{int} {adjust(); yylval.ival=atoi(yytext); return INT;}

while {adjust(); return WHILE;}
for {adjust(); return FOR;}
to {adjust(); return TO;}
break {adjust(); return BREAK;}
let {adjust(); return LET;}
in {adjust(); return IN;}
function {adjust(); return FUNCTION;}
var {adjust(); return VAR;}
type {adjust(); return TYPE;}
array {adjust(); return ARRAY;}
if {adjust(); return IF;}
then {adjust(); return THEN;}
else {adjust(); return ELSE;}
do {adjust(); return DO;}
of {adjust(); return OF;}
nil {adjust(); return NIL;}

","	 {adjust(); return COMMA;}
":" {adjust(); return COLON;}
";" {adjust(); return SEMICOLON;}
"(" {adjust(); return LPAREN;}
")" {adjust(); return RPAREN;}
"[" {adjust(); return LBRACK;}
"]" {adjust(); return RBRACK;}
"{" {adjust(); return LBRACE;}
"}" {adjust(); return RBRACE;}
"." {adjust(); DOT;}
"+" {adjust(); return PLUS;}
"-" {adjust(); return MINUS;}
"*" {adjust(); return TIMES;}
"/" {adjust(); return DIVIDE;}
"=" {adjust(); return EQ;}
"<>" {adjust(); return NEQ;}
"<" {adjust(); return LT;}
"<=" {adjust(); return LE;}
">" {adjust(); return GT;}
">=" {adjust(); return GE;}
"&" {adjust(); return AND;}
"|" {adjust(); return OR;}
":=" {adjust(); return ASSIGN;}


" "	 {adjust(); continue;}
\n	 {adjust(); EM_newline(); continue;}
.	 {adjust(); EM_error(EM_tokPos,"illegal token");}

