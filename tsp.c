#include <stdio.h>

#define MAX 10

int n; // Number of cities
int cost[MAX][MAX]; // Cost matrix
int visited[MAX]; // Array to keep track of visited cities
int minCost = 999; // Variable to store the minimum cost of the tour

void input() {
    int i, j;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");

    for (i = 0; i < n; i++) {
        visited[i] = 0; // Initializing visited array to 0

        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
}

void tsp(int city, int count, int tourCost) {
    int nextCity, i;

    visited[city] = 1;
    printf("%d ", city + 1);

    if (count == n - 1) { // If all cities visited
        tourCost += cost[city][0]; // Add cost to return to starting city
        if (tourCost < minCost) {
            minCost = tourCost; // Update minimum cost
        }
        visited[city] = 0; // Reset visited array for backtracking
        return;
    }

    for (nextCity = 0; nextCity < n; nextCity++) {
        if (!visited[nextCity] && cost[city][nextCity] != 0) {
            tsp(nextCity, count + 1, tourCost + cost[city][nextCity]);
        }
    }

    visited[city] = 0; // Reset visited array for backtracking
}

int main() {
    input();
    printf("\nOptimal Tour: ");
    tsp(0, 0, 0);
    printf("\nMinimum Cost: %d\n", minCost);

    // Adding name
    printf("Name: Hari Prasad Gyawali\n");

    return 0;
}
