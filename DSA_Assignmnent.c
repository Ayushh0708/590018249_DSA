#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Array to track visited nodes

// BFS function
void BFS(int start, int vertices) {
    int queue[MAX], front = -1, rear = -1;
    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

// DFS function
void DFS(int current, int vertices) {
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[current][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

// Main function
int main() {
    int vertices, edges, choice, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // Remove this for directed graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("Choose traversal method (1 for BFS, 2 for DFS): ");
    scanf("%d", &choice);

    // Reset visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    if (choice == 1) {
        BFS(start, vertices);
    } else if (choice == 2) {
        printf("DFS Traversal: ");
        DFS(start, vertices);
        printf("\n");
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
