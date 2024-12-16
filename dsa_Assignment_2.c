#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int sum = 0;
    float average;

    // Step 1: Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Step 2: Allocate memory dynamically using malloc()
    arr = (int *)malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program with an error code
    }

    // Step 3: Input n elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Step 4: Calculate sum and average
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    average = (float)sum / n;

    // Display sum and average
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", average);

    // Step 5: Release the memory using free()
    free(arr);

    return 0;
}