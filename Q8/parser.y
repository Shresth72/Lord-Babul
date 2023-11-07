%token NUMBER

%left '+' '-'
%left '*' '/'
%%
S: E { printf("The result is %d\n", $1); }
    ;
    E: E '+' E { $$ = $1 + $3; }
    | E '-' E { $$ = $1 - $3; }
    | E '*' E { $$ = $1 * $3; }
    | E '/' E { $$ = $1 / $3; }
    | '-' E %prec '*' { $$ = -$2; }
    | F { $$ = $1; }
    ;
    F: '(' E ')' { $$ = $2; }
    | NUMBER { $$ = $1; }
    ;
%%
main(void)
{
    yyparse();
}
void yyerror(char *s) 
{
    fprintf(stderr, "error: %s\n", s);
}