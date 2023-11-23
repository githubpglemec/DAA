#include <stdio.h>
#include <limits.h>

void matrixChainOrder(int p[], int n, int m[][n], int s[][n]) {
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParens(int s[][6], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p) / sizeof(p[0]) - 1;

    int m[n + 1][n + 1];
    int s[n][n];

    matrixChainOrder(p, n, m, s);

    printf("Minimum number of multiplications: %d\n", m[1][n]);
    printf("Optimal parenthesization: ");
    printOptimalParens(s, 1, n);

    return 0;
}
