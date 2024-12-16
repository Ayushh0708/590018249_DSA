#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node Structure
struct SNode {
    int data;
    struct SNode* next;
};

// Doubly Linked List Node Structure
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

// Functions for Singly Linked List

// Insert at the beginning
void insertAtBeginningS(struct SNode** head, int data) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEndS(struct SNode** head, int data) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct SNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specified position
void insertAtPositionS(struct SNode** head, int data, int position) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = data;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct SNode* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from the beginning
void deleteFromBeginningS(struct SNode** head) {
    if (*head == NULL) return;

    struct SNode* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete from the end
void deleteFromEndS(struct SNode** head) {
    if (*head == NULL) return;

    struct SNode* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete at a specified position
void deleteAtPositionS(struct SNode** head, int position) {
    if (*head == NULL) return;

    struct SNode* temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) return;

    struct SNode* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Display Singly Linked List
void displayListS(struct SNode* head) {
    struct SNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Functions for Doubly Linked List

// Insert at the beginning
void insertAtBeginningD(struct DNode** head, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}

// Insert at the end
void insertAtEndD(struct DNode** head, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct DNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specified position
void insertAtPositionD(struct DNode** head, int data, int position) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;

    if (position == 0) {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head != NULL) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct DNode* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from the beginning
void deleteFromBeginningD(struct DNode** head) {
    if (*head == NULL) return;

    struct DNode* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) (*head)->prev = NULL;
    free(temp);
}

// Delete from the end
void deleteFromEndD(struct DNode** head) {
    if (*head == NULL) return;

    struct DNode* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// Delete at a specified position
void deleteAtPositionD(struct DNode** head, int position) {
    if (*head == NULL) return;

    struct DNode* temp = *head;

    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) (*head)->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;

    free(temp);
}

// Display Doubly Linked List
void displayListD(struct DNode* head) {
    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test implementations
int main() {
    struct SNode* singlyList = NULL;
    struct DNode* doublyList = NULL;

    // Singly Linked List Operations
    insertAtBeginningS(&singlyList, 10);
    insertAtEndS(&singlyList, 20);
    insertAtPositionS(&singlyList, 15, 1);
    displayListS(singlyList);

    deleteFromBeginningS(&singlyList);
    deleteFromEndS(&singlyList);
    displayListS(singlyList);

    // Doubly Linked List Operations
    insertAtBeginningD(&doublyList, 10);
    insertAtEndD(&doublyList, 20);
    insertAtPositionD(&doublyList, 15, 1);
    displayListD(doublyList);

    deleteFromBeginningD(&doublyList);
    deleteFromEndD(&doublyList);
    displayListD(doublyList);

    return 0;
}
