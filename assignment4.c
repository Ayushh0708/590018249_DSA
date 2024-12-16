//Stack implementation using array

#include <stdio.h>

#define Max 5 //defining maximum value 5

typedef struct //Stack Structure
{
    int items [Max];
    int top;
}Stack;

void initialize (Stack *s) //initializing stack
{
    s->top = -1;
    printf("Stack initialized.\n");
}

void isfull (Stack *s) //checking if stack is full
{
    if (s->top == Max - 1)
    {
    printf ("Stack is full.\n");
    }
    else
    {
    printf ("Stack is not full.\n");
    }
}

void isempty (Stack *s) //checking if stack is empty
{
    if (s->top == -1)
    {
        printf ("Stack is empty.\n");
    }
    else
    {
        printf ("Stack is not empty.\n");
    }
}

void push (Stack *s, int value) //adding element if stack is underflow
{
    if (s->top == Max - 1)
    {
        printf ("Stack overflow! Cannot push %d\n", value);
    }
    else
    {
        s->items[++s->top]= value;
        printf ("push %d to stack. \n", value);
    }
}

void pop (Stack *s) // removing element if stack is overflow
{
    if (s->top == -1)
    {
    printf ("Stack underflow! Cannot pop.\n");
    }
    else
    {
    printf ("popped %d from stack. \n", s->items[s->top--]);
    }
}

void peek (Stack *s) //displaying the top element
{
    if (s->top == -1)
    {
        printf ("Stack is empty.\n");
    }
    else
    {
        printf ("Top element is %d\n", s->items[s->top]);
    }
}

void main() //testing stack operations
{
Stack s;
initialize (&s);

pop(&s);
push (&s, 10);        //underflow condition
push (&s, 20);
push (&s, 30);
push (&s, 40);
push (&s, 50);
push (&s, 60);       //overflow condition because stack max is 5
push (&s, 70);
push (&s, 80);
push (&s, 90);
push (&s, 100);
peek (&s);

isfull(&s);  //checking if stack is full

while (s.top!= -1)
{
    pop (&s);  // will pop all elements
}

isempty (&s);  //checking if stack is empty



printf ("Assignment 4 completed by %s\n", "Vaishnavi Singh 590011338");
}