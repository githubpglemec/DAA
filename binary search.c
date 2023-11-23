#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    // User input for array size and elements (Assuming a sorted array)
    int n;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements for the sorted array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // User input for target element
    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    // Perform Binary Search
    int index = binarySearch(arr, n, target);

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
