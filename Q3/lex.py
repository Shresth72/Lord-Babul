import ply.lex as lex
import ply.yacc as yacc

# Define the token names for the lexer
tokens = (
    'NUMBER',
    'PLUS',
    'MINUS',
    'PRINT',
)

# Define regular expressions for the tokens
t_PLUS = r'\+'
t_MINUS = r'-'
t_PRINT = r'PRINT'

# Define a rule to handle numbers
def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t

# Define a rule to handle whitespace
t_ignore = ' \t'

# Error handling rule
def t_error(t):
    print(f"Illegal character '{t.value[0]}'")
    t.lexer.skip(1)

# Build the lexer
lexer = lex.lex()

# Define the grammar rules for the parser
def p_program(p):
    '''
    program : statements
    '''
    p[0] = p[1]

def p_statements(p):
    '''
    statements : statements statement
               | statement
    '''
    if len(p) == 2:
        p[0] = [p[1]]
    else:
        p[1].append(p[2])
        p[0] = p[1]

def p_statement(p):
    '''
    statement : expression
              | PRINT expression
    '''
    if len(p) == 2:
        p[0] = ('expression', p[1])
    else:
        p[0] = ('print', p[2])

def p_expression(p):
    '''
    expression : expression PLUS expression
               | expression MINUS expression
    '''
    if p[2] == '+':
        p[0] = ('add', p[1], p[3])
    elif p[2] == '-':
        p[0] = ('subtract', p[1], p[3])

def p_expression_number(p):
    'expression : NUMBER'
    p[0] = ('number', p[1])

def p_error(p):
    print("Syntax error")

# Build the parser
parser = yacc.yacc()

# Main loop
while True:
    try:
        input_text = input("Enter a program: ")
    except EOFError:
        break
    if not input_text:
        continue

    result = parser.parse(input_text)
    if result is not None:
        def execute(node):
            if node[0] == 'number':
                return node[1]
            elif node[0] == 'add':
                return execute(node[1]) + execute(node[2])
            elif node[0] == 'subtract':
                return execute(node[1]) - execute(node[2])

        for statement in result:
            if statement[0] == 'print':
                print("Result:", execute(statement[1]))
    else:
        print("Syntax error")
