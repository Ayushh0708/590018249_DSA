//Implementation of Queue using Linked List

#include <stdio.h>
#include <stdlib.h>


typedef struct Node 
{
    int data;
    struct Node* next;
} Node;


typedef struct Queue 
{
    Node* front;
    Node* rear;
} Queue;


void initialize(Queue* q) 
{
    q->front = NULL;
    q->rear = NULL;
    printf("Queue initialized.\n");
}


void isEmpty(Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty.\n");
    } else 
    {
        printf("Queue is not empty.\n");
    }
}


void enqueue(Queue* q, int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (newNode == NULL) 
    {
        printf("Memory Error! Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) 
    {
        
        q->front = newNode;
        q->rear = newNode;
    } 
    else 
    {
        
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d to queue.\n", value);
}


void dequeue(Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue underflow! Cannot dequeue.\n");
        return;
    }
    
    Node* temp = q->front;
    printf("Dequeued %d from queue.\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL) 
    {
        
        q->rear = NULL;
    }
    
    free(temp); 
}


void peek(Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue is empty, nothing to peek.\n");
    } 
    else 
    {
        printf("Front element is %d\n", q->front->data);
    }
}


int main() 
{
    Queue q;
    initialize(&q);

    // Testing queue operations
    isEmpty(&q); // Should confirm that the queue is empty
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    peek(&q); // Should display 10 as the front element
    dequeue(&q); // Should remove 10
    peek(&q); // Should now display 20
    isEmpty(&q); // Should confirm that the queue is not empty

    // Dequeue all elements
    dequeue(&q); // Remove 20
    dequeue(&q); // Remove 30
    dequeue(&q); // Should report underflow
    peek(&q); // Should confirm the queue is empty

    printf("Assignment 5 Question 2 is successfully executed.\n");
    printf("Vaishnavi Singh, 590011338");

    return 0;
}
