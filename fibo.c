#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    // User input for the Fibonacci number
    int n;
    printf("Enter a non-negative integer for Fibonacci calculation: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Exit with an error code
    }

    // Calculate and print the Fibonacci number
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    // Add your name
    printf("\nHari Prasad Gyawali\n");

    return 0;
}
