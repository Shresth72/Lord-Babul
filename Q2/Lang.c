#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent variables
typedef struct {
    char name[32];
    int value;
} Variable;

// Define an array to store variables
Variable variables[100];
int variableCount = 0;

// Function to look up a variable by name
Variable* findVariable(const char* name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return &variables[i];
        }
    }
    return NULL;
}


void evaluateExpression(const char* expression) {
    char varName[32];
    int value;
    if (sscanf(expression, "let %31s = %d", varName, &value) == 2) {
        // Define a new variable
        Variable* var = findVariable(varName);
        if (var == NULL) {
            strcpy(variables[variableCount].name, varName);
            variables[variableCount].value = value;
            variableCount++;
        } else {
            var->value = value;
        }
    } else if (sscanf(expression, "print %31s", varName) == 1) {
        // Print the value of a variable
        Variable* var = findVariable(varName);
        if (var != NULL) {
            printf("%s = %d\n", varName, var->value);
        } else {
            printf("Variable not found: %s\n", varName);
        }
    } else if (sscanf(expression, "%31s = %31s + %d", varName, varName, &value) == 3) {
        // Add a variable to itself
        Variable* var = findVariable(varName);
        Variable* var2 = findVariable(varName);
        if (var != NULL && var2 != NULL) {
            var->value = var2->value + value;
        } else {
            printf("Invalid variables in the addition operation.\n");
        }
    } else if (sscanf(expression, "%31s = %31s - %d", varName, varName, &value) == 3) {
        // Subtract a variable from itself
        Variable* var = findVariable(varName);
        Variable* var2 = findVariable(varName);
        if (var != NULL && var2 != NULL) {
            var->value = var2->value - value;
        } else {
            printf("Invalid variables in the subtraction operation.\n");
        }
    } else {
        printf("Invalid expression: %s\n", expression);
    }
}

int main() {
    char input[100];

    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        input[strcspn(input, "\n")] = '\0';  // Remove the newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        evaluateExpression(input);
    }

    return 0;
}
