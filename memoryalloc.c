//Memory allocation using malloc() and free()

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr;
    int sum = 0;
    float avg;

    printf("Enter the number of elements:");
    scanf ("%d", &n);

    arr= (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory not allocated.\n");
    }

    printf("Enter %d elements: \n", n);
    for (int i=0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    avg= (float) sum/n;
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2f\n", avg);

    free (arr);
}