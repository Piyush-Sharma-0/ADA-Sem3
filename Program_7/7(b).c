#include <stdio.h>
#include <limits.h> // for INT_MAX

#define MAX 100 // maximum number of vertices

// ---------- FUNCTION TO FIND MINIMUM KEY ----------
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// ---------- FUNCTION TO PRINT THE MST ----------
void printMST(int parent[], int graph[MAX][MAX], int V) {
    int totalWeight = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i < V; i++) {
        printf("%d -- %d == %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

// ---------- PRIM'S ALGORITHM ----------
void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];  // Array to store constructed MST
    int key[MAX];     // Key values used to pick minimum weight edge
    int mstSet[MAX];  // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1; // Add the picked vertex to the MST set

        // Update key and parent index of adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph, V);
}

// ---------- MAIN FUNCTION ----------
int main() {
    int V;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);

    return 0;
}
