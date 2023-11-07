<program> ::= <declaration-list>

<declaration-list> ::= <declaration-list> <declaration>
                   | <declaration>

<declaration> ::= <type-specifier> <id-list>

<type-specifier> ::= int | float | char | double | void

<id-list> ::= <id>
          | <id-list> , <id>

<id> ::= <identifier>

<identifier> ::= <letter> <id-suffix>

<id-suffix> ::= <letter>
            | <digit>
            | _

<letter> ::= a | b | ... | z | A | B | ... | Z | _

<digit> ::= 0 | 1 | ... | 9

