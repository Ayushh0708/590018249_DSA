#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Doubly Linked List Node Structure
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

// Singly Linked List Functions
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtBeginning(struct Node** head) {
    if (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head != NULL) {
        struct Node* temp = *head;
        if (temp->next == NULL) {
            *head = NULL;
        } else {
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Doubly Linked List Functions
void dInsertAtBeginning(struct DNode** head, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void dInsertAtEnd(struct DNode** head, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct DNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void dDisplayList(struct DNode* head) {
    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Simple To-Do List Application Using Singly Linked List
void addTask(struct Node** head, int task) {
    insertAtEnd(head, task);
}

void removeTask(struct Node** head) {
    deleteAtBeginning(head);
}

void showTasks(struct Node* head) {
    displayList(head);
}

// Main Function to Demonstrate the Program
int main() {
    struct Node* sHead = NULL;   // Head of Singly Linked List
    struct DNode* dHead = NULL;  // Head of Doubly Linked List

    // Singly Linked List Example
    printf("Singly Linked List:\n");
    insertAtBeginning(&sHead, 10);
    insertAtEnd(&sHead, 20);
    insertAtEnd(&sHead, 30);
    displayList(sHead);

    deleteAtBeginning(&sHead);
    displayList(sHead);

    deleteAtEnd(&sHead);
    displayList(sHead);

    // Doubly Linked List Example
    printf("\nDoubly Linked List:\n");
    dInsertAtBeginning(&dHead, 40);
    dInsertAtEnd(&dHead, 50);
    dInsertAtEnd(&dHead, 60);
    dDisplayList(dHead);

    // To-Do List Application
    struct Node* toDoList = NULL;
    printf("\nTo-Do List Application:\n");
    addTask(&toDoList, 100);  // Add tasks
    addTask(&toDoList, 200);
    showTasks(toDoList);

    removeTask(&toDoList);  // Remove a task
    showTasks(toDoList);

    // Free allocated memory (not shown for simplicity in understanding)

    return 0;
}
