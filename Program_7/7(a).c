#include <stdio.h>

// Structure for an edge
struct Edge {
    int src, dest, weight;
};

// Structure for subset in union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find parent (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two sets by rank
void unionSet(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Sort edges based on weight using simple bubble sort
void sortEdges(struct Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskalMST(struct Edge edges[], int E) {
    struct Edge result[6]; // To store MST edges
    struct Subset subsets[6];

    // Initialize subsets
    for (int v = 0; v < 6; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    sortEdges(edges, E);

    int e = 0, i = 0; // e = result count, i = edge index

    while (e < 6 - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        if (x != y) {
            result[e++] = next;
            unionSet(subsets, x, y);
        }
    }
    for (i = 0; i < e; i++)
        printf("%d -- %d  (weight = %d)\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    struct Edge edges[] = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {2, 3, 3},
        {2, 5, 2}, {2, 4, 4}, {3, 4, 3}, {5, 4, 3}
    };

    int E = sizeof(edges) / sizeof(edges[0]);

    kruskalMST(edges, E);
    return 0;
}
