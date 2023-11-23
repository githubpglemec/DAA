#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long mod_pow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base %= modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent >>= 1;
    }

    return result;
}

int miller_rabin(long long n, int k) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;

    long long d = n - 1;
    while (d % 2 == 0) d /= 2;

    for (int i = 0; i < k; ++i) {
        long long a = 2 + rand() % (n - 4), x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1) continue;

        int witness = 1;
        while (d != n - 1) {
            x = (x * x) % n;
            d *= 2;

            if (x == 1) return 0;
            if (x == n - 1) witness = 0;
        }

        if (witness) return 0;
    }

    return 1;
}

int main() {
    long long num;
    int k;

    printf("Enter a number to test for primality: ");
    scanf("%lld", &num);

    printf("Enter the number of iterations (k) for Rabin-Miller test: ");
    scanf("%d", &k);

    printf("%lld is %s prime.\n", num, miller_rabin(num, k) ? "probably" : "not");

    // Adding name
    printf("Name: Hari Prasad Gyawali\n");

    return 0;
}
