%{
#include <stdio.h>

int yylex();
void yyerror(const char *s);

int result; // Global variable to store the result

%}

%token NUMBER
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN
%left PLUS MINUS
%left MULTIPLY DIVIDE

%%

program:
    | program statement '\n'      { printf("Result: %d\n", $2); }
    ;

statement:
    expr                        { result = $1; }
    | ID ASSIGN expr             { /* Handle assignment here if needed */ }
    ;

expr:
    NUMBER                      { $$ = $1; }
    | expr PLUS expr            { $$ = $1 + $3; printf("Three-Address Code: T1 = %d + %d\n", $1, $3); }
    | expr MINUS expr           { $$ = $1 - $3; printf("Three-Address Code: T1 = %d - %d\n", $1, $3); }
    | expr MULTIPLY expr        { $$ = $1 * $3; printf("Three-Address Code: T1 = %d * %d\n", $1, $3); }
    | expr DIVIDE expr          {
        if ($3 != 0) {
            $$ = $1 / $3;
            printf("Three-Address Code: T1 = %d / %d\n", $1, $3);
        } else {
            yyerror("Division by zero");
        }
    }
    ;

%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
