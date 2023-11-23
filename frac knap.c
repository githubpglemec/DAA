#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double ratio; // Value-to-weight ratio
};

// Comparison function for sorting items based on ratio
int compare(const void* a, const void* b) {
    return (((struct Item*)b)->ratio - ((struct Item*)a)->ratio);
}

// Function to solve Fractional Knapsack problem
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    // Calculate value-to-weight ratios for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items in non-increasing order of value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Greedy selection of items
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take a fraction of the item to fill the knapsack
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].ratio * remainingCapacity;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n;

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input the values and weights of items
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    // Input the capacity of the knapsack
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Calculate and print the maximum value
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}
