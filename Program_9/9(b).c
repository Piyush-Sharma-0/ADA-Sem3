#include <stdio.h>
#include <limits.h>
struct Edge {
    int src, dest, weight;
};

int main() {

    int graph[6][6] = {
        {0, 4, 0, 0, 0, 2},
        {4, 0, 6, 0, 0, 3},
        {0, 6, 0, 3, 0, 0},
        {0, 0, 3, 0, 7, 0},
        {0, 0, 0, 7, 0, 1},
        {2, 3, 0, 0, 1, 0}
    };

    struct Edge edges[20];
    int E = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (graph[i][j] != 0) {
                edges[E].src = i;
                edges[E].dest = j;
                edges[E].weight = graph[i][j];
                E++;
            }
        }
    }

    int dist[6];

    for (int i = 0; i < 6; i++)
        dist[i] = 99999;

    int src = 0;
    dist[src] = 0;

    for (int i = 1; i <= 6 - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != 99999 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != 99999 && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle!\n");
            return 0;
        }
    }
printf("Bellman-Ford Result (source = %d):\n", src);
    for (int i = 0; i < 6; i++)
        printf("Distance to %d = %d\n", i, dist[i]);

    return 0;
}
