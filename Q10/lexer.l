%{
#include <stdio.h>
%}

%option noyywrap

DIGIT [0-9]

%%
{DIGIT}+    { yylval = atoi(yytext); return NUMBER; }
[-+*/\(\)]  { return *yytext; }
[ \t\n]     ;  // Skip whitespace and newlines

.           { printf("Invalid character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

