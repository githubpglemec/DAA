#include <stdio.h>

#define MAX 10

int n, W;
int wt[MAX], val[MAX];
int dp[MAX + 1][MAX + 1];

void input() {
    int i;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack() {
    int i, w;

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
}

void printResult() {
    printf("Maximum value in knapsack: %d\n", dp[n][W]);
}

int main() {
    input();
    knapsack();
    printResult();

    // Adding name
    printf("Name: Hari Prasad Gyawali\n");

    return 0;
}
