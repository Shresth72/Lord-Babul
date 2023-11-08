#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Simple Calculator\n");
    printf("Enter an expression (e.g., 2 + 3): ");

    while (1) {
        scanf("%d %c %d", &num1, &operator, &num2);

        if (operator == '+') {
            result = num1 + num2;
            printf("Result: %d\n", result);
            printf("Three-Address Code: T1 = %d + %d\n", num1, num2);
        } else if (operator == '-') {
            result = num1 - num2;
            printf("Result: %d\n", result);
            printf("Three-Address Code: T1 = %d - %d\n", num1, num2);
        } else if (operator == '*') {
            result = num1 * num2;
            printf("Result: %d\n", result);
            printf("Three-Address Code: T1 = %d * %d\n", num1, num2);
        } else if (operator == '/') {
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %d\n", result);
                printf("Three-Address Code: T1 = %d / %d\n", num1, num2);
            } else {
                printf("Error: Division by zero\n");
            }
        } else {
            printf("Invalid operator\n");
        }

        printf("Enter another expression or 'q' to quit: ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'q') {
            break;
        }
        printf("Enter an expression: ");
    }

    return 0;
}
