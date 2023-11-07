#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Simple Calculator\n");
    printf("Enter an expression (e.g., 5 + 3, 2 * 4, 9 ^ 2, log 10): ");

    if (scanf("%lf %c %lf", &num1, &operator, &num2) == 3) {
        switch (operator) {
            case '+':
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            case '*': 
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                }
                break;
            case '^':
                result = pow(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 'l': // Handle "log" operation
                if (num1 <= 0 || num2 <= 1) {
                    printf("Invalid arguments for logarithm.\n");
                } else {
                    result = log(num2) / log(num1);
                    printf("Result: %.2lf\n", result);
                }
                break;
            default:
                printf("Invalid operator. Supported operators: +, -, *, /, ^, log\n");
                break;
        }
    } else {
        printf("Invalid input. Please use the format: number operator number\n");
    }

    return 0;
}
