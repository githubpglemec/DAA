#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int random(int low, int high) {
    return low + rand() % (high - low + 1);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Randomly choose a pivot and swap with the last element
        int pivotIndex = random(low, high);
        swap(&arr[pivotIndex], &arr[high]);

        // Partition the array and get the index of the pivot
        pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Seed for random number generation
    srand(time(NULL));

    // User input for array size and elements
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Randomized Quick Sort
    randomizedQuickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Add your name
    printf("\nHari Prasad Gyawali\n");

    return 0;
}
