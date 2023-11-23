#include <stdio.h>

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    // User input for array size and elements
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // User input for target element
    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    // Perform sequential search
    int index = sequentialSearch(arr, n, target);

    // Print the result
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    // Add your name
    printf("\nHari Prasad Gyawali\n");

    return 0;
}
