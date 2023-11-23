#include <stdio.h>

#define MAX 10

int n; // Number of elements
int set[MAX]; // Set of elements
int sum; // Target sum
int subset[MAX]; // Array to keep track of included elements in the subset

void input() {
    int i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);
}

void subsetSum(int index, int currentSum, int count) {
    int i;

    if (currentSum == sum) {
        printf("Subset found: { ");
        for (i = 0; i < count; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    if (index == n || currentSum > sum) {
        return;
    }

    subset[count] = set[index];
    subsetSum(index + 1, currentSum + set[index], count + 1);

    subsetSum(index + 1, currentSum, count);
}

int main() {
    input();
    printf("\nSubsets with the sum %d:\n", sum);
    subsetSum(0, 0, 0);

    // Adding name
    printf("Name: Hari Prasad Gyawali\n");

    return 0;
}
