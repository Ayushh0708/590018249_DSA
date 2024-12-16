//Implementation of Queue using Array

#include <stdio.h>
#include <Stdlib.h>

#define MAX 5

typedef struct
{
    int items [MAX];
    int front,rear;
}Queue;

void initialize (Queue *q)
{
    q->front = q->rear = -1;
}

void isEmpty(Queue* q)
{
    if (q->front == -1)
    {
    printf ("Queue is Empty.\n");
    }
    else
    {
    printf ("Queue is not empty.\n");
    }
}

void isFull(Queue* q)
{
    if ((q->rear +1)% MAX == q->front)
    {
        printf("Queue is full.\n");
    }
    else
    printf("Queue is not full.\n");
}

void enqueue (Queue* q, int value)
{
    if ((q->rear +1)% MAX == q->front)
    {
        printf("Queue is full! Cannot Enqueue %d\n", value);
    }

    else
    {
        if(q->front == -1)
        {
            q->front =0;
        }
        q->rear = (q->rear +1)% MAX;
        q->items [q->rear]= value;
        printf ("Enqueue %d to queue.\n", value);
    }
}

void dequeue (Queue* q)
{
    if (q-> front == -1)
    {
        printf("Queue is empty! Cannot dequeue.\n");
    }
    else
    {
        printf ("Dequeued %d from queue.\n",q->items[q->front]);
        if (q->front == q-> rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = (q->front +1)% MAX;
        }
    }
}

void peek(Queue* q)
{
    if(q->front == -1)
    {
        printf ("Queue is empty, nothing to peek.\n");
    }
    else
    {
        printf("Front element is %d\n", q->items[q->front]);
    }
}

int main()
{
    Queue q;
    initialize (&q);

    dequeue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    peek(&q);

    while (q.front!= -1)
    {
        dequeue(&q);
    }

    peek(&q);
    printf("Assignment 5 Question 1 is successfully executed.\n");
    printf("Vaishnavi Singh, 590011338");

    return 0;
}