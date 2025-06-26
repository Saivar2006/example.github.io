#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
long long factorial(int n);
void clearInput();

int main() {
    int choice;
    double num1, num2;
    long long int1;
    double result;

    do {
        printf("\n=== C Calculator ===\n");
        printf("1) Addition\n2) Subtraction\n3) Multiplication\n4) Division\n");
        printf("5) Modulus (int)\n6) Power\n7) Factorial (int)\n0) Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: // Addition
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result = %.2f\n", result);
                break;
            case 2: // Subtraction
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result = %.2f\n", result);
                break;
            case 3: // Multiplication
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result = %.2f\n", result);
                break;
            case 4: // Division
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    result = num1 / num2;
                    printf("Result = %.2f\n", result);
                }
                break;
            case 5: // Modulus
                printf("Enter two integers: ");
                scanf("%d %d", &int1, (int*)&num2);
                if ((int)num2 == 0) {
                    printf("Error: Modulus by zero\n");
                } else {
                    printf("Result = %d\n", (int)int1 % (int)num2);
                }
                break;
            case 6: // Power
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = pow(num1, num2);
                printf("Result = %.2f\n", result);
                break;
            case 7: // Factorial
                printf("Enter an integer: ");
                scanf("%d", &int1);
                if (int1 < 0) {
                    printf("Error: Factorial of negative\n");
                } else {
                    printf("Result = %lld\n", factorial(int1));
                }
                break;
            case 0:
                printf("Exiting. Bye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        clearInput();
    } while (choice != 0);

    return 0;
}

long long factorial(int n) {
    long long f = 1;
    for (int i = 2; i <= n; ++i) f *= i;
    return f;
}

// Consume leftover input
void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
