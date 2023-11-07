#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Structure to represent a symbol
typedef struct Symbol {
    char name[50];
    int value;
    struct Symbol* next;
} Symbol;

// Create an array of symbol pointers
Symbol* symbolTable[TABLE_SIZE];

// Initialize the symbol table
void initializeSymbolTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        symbolTable[i] = NULL;
    }
}

// Hash function to calculate the index
int hash(char* name) {
    unsigned int hash = 0;
    while (*name) {
        hash = (hash * 31) + *name;
        name++;
    }
    return hash % TABLE_SIZE;
}

// Add a symbol to the symbol table
void insertSymbol(char* name, int value) {
    int index = hash(name);
    
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    newSymbol->value = value;
    newSymbol->next = NULL;
    
    // Check if the index is empty
    if (symbolTable[index] == NULL) {
        symbolTable[index] = newSymbol;
    } else {
        // Handle collision by chaining
        Symbol* current = symbolTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSymbol;
    }
}

Symbol* searchSymbol(char* name) {
    int index = hash(name);
    Symbol* current = symbolTable[index];
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;  // Symbol not found
}

int main() {
    initializeSymbolTable();
    
    // Insert some symbols
    insertSymbol("x", 10);
    insertSymbol("y", 20);
    insertSymbol("z", 42);
    
    char searchName[50];
    int k = 3;
    printf("Enter a symbol to search: ");
    scanf("%s", searchName);
    
    Symbol* result = searchSymbol(searchName);
    
    if (result != NULL) {
        printf("Symbol found: %s = %d\n", result->name, result->value);
    } else {
        printf("Symbol not found\n");
    }
    
    return 0;
}
