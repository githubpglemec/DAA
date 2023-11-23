#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main() {
    // Example usage:
    int num1 = 48;
    int num2 = 18;

    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));

    // Add your name
    printf("\nHari Prasad Gyawali\n");

    return 0;
}
