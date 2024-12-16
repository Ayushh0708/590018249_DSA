#include <stdio.h>

void linearSearch(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Target %d found at index %d\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Target %d not found in the array.\n", target);
    }
}

int main() {
    int size, target;

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target value
    printf("Enter the target value to search: ");
    scanf("%d", &target);

    // Perform Linear Search
    linearSearch(arr, size, target);

    return 0;
}
