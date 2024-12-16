#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of array for binary tree

void insert(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Tree is full.\n");
        return;
    }
    arr[*size] = value;
    (*size)++;
}

void printTreeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
