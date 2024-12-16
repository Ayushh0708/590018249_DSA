#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

void insert(PriorityQueue *pq, int value) {
    if (pq->size == MAX) {
        printf("Queue is full!\n");
        return;
    }
    int i = pq->size++;
    while (i > 0 && pq->data[(i - 1) / 2] < value) {
        pq->data[i] = pq->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->data[i] = value;
}

int extractMax(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    int max = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    heapify(pq->data, pq->size, 0);
    return max;
}

int main() {
    PriorityQueue pq = {{0}, 0};
    insert(&pq, 10);
    insert(&pq, 20);
    insert(&pq, 5);
    printf("Max priority element: %d\n", extractMax(&pq));
    return 0;
}
