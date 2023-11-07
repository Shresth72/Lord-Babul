#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_SYMBOL_LENGTH 50

// Symbol table structure
typedef struct {
    char name[MAX_SYMBOL_LENGTH];
    int address;
} SymbolTableEntry;

SymbolTableEntry symbolTable[100]; 
int symbolTableSize = 0;

// Helper function to add an entry to the symbol table
void addToSymbolTable(char* name, int address) {
    if (symbolTableSize < 100) {
        strcpy(symbolTable[symbolTableSize].name, name);
        symbolTable[symbolTableSize].address = address;
        symbolTableSize++;
    }
}

int main() {
    FILE* inputFile = fopen("input.asm", "r"); 
    FILE* outputFile = fopen("output.obj", "w"); 

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int address = 0;

    // First Pass
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Parse the line and update the symbol table
        char *label = strtok(line, " \t\n");
        if (label != NULL && label[strlen(label) - 1] == ':') {
            label[strlen(label) - 1] = '\0'; // Remove the colon
            addToSymbolTable(label, address);
        }

        address++; // Increment the address
    }

    // Reset the file to the beginning for the second pass
    fseek(inputFile, 0, SEEK_SET);
    address = 0;

    // Second Pass
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char* label = strtok(line, " \t\n");

        if (label == NULL || label[strlen(label) - 1] == ':') {
        } else {
            printf("Address %d: %s\n", address, line);
            fprintf(outputFile, "Address %d: %s\n", address, line);
            address++;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
