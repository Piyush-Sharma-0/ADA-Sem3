#include <stdio.h>

// Function to find the vertex with minimum key value
int minKey(int key[], int mstSet[]) {
    int min = 99999, min_index;
    for (int v = 0; v < 6; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[6][6]) {
    int parent[6];
    int key[6];
    int mstSet[6];

    // Initialize
    for (int i = 0; i < 6; i++)
        key[i] = 99999, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    // Find MST for 6 vertices
    for (int count = 0; count < 6 - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < 6; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    for (int i = 1; i < 6; i++)
        printf("%d -- %d (weight = %d)\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[6][6] = {
        {0, 4, 4, 0, 0, 0},
        {4, 0, 2, 0, 0, 0},
        {4, 2, 0, 3, 4, 2},
        {0, 0, 3, 0, 3, 0},
        {0, 0, 4, 3, 0, 3},
        {0, 0, 2, 0, 3, 0}
    };

    primMST(graph);
    return 0;
}
