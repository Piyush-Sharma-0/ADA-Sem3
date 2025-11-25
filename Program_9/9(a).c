#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int minDistance_array(int dist[], int visited[]) {
    int min = 99999, min_index = -1;

    for (int i = 0; i < 6; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra_array(int graph[6][6], int src) {
    int dist[6], visited[6];

    for (int i = 0; i < 6; i++) {
        dist[i] = 99999;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < 6 - 1; count++) {
        int u = minDistance_array(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < 6; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}


struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    int pos[6];
    struct HeapNode* array[6];
};

struct HeapNode* newHeapNode(int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->vertex = v;
    node->dist = dist;
    return node;
}

struct MinHeap* createMinHeap() {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;
    for (int i = 0; i < 6; i++) heap->pos[i] = 0;
    return heap;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size &&
        heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size &&
        heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        heap->pos[heap->array[smallest]->vertex] = idx;
        heap->pos[heap->array[idx]->vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}
struct HeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0) return NULL;

    struct HeapNode* root = heap->array[0];

    struct HeapNode* last = heap->array[heap->size - 1];
    heap->array[0] = last;

    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[last->vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;

        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

int isInMinHeap(struct MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

void dijkstra_heap(int graph[6][6], int src) {
    int dist[6];

    struct MinHeap* heap = createMinHeap();

    for (int v = 0; v < 6; v++) {
        dist[v] = 99999;
        heap->array[v] = newHeapNode(v, dist[v]);
        heap->pos[v] = v;
    }

    dist[src] = 0;
    heap->array[src]->dist = 0;

    heap->size = 6;

    while (heap->size > 0) {
        struct HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        for (int v = 0; v < 6; v++) {
            if (graph[u][v] && 
                isInMinHeap(heap, v) &&
                dist[u] != 99999 &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                decreaseKey(heap, v, dist[v]);
            }
        }
    }
}

int main() {
    FILE* file = fopen("dijkstra_times.txt", "a");

    int graph[6][6] = {
        {0, 4, 0, 0, 0, 2},
        {4, 0, 6, 0, 0, 3},
        {0, 6, 0, 3, 0, 0},
        {0, 0, 3, 0, 7, 0},
        {0, 0, 0, 7, 0, 1},
        {2, 3, 0, 0, 1, 0}
    };

    clock_t start, end;
    start = clock();
    for(int i=0;i<1000000;i++)
        dijkstra_array(graph, 0);
    end = clock();
    double t_array = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(file, "Dijkstra_Array %f\n", t_array);

    start = clock();
    for(int i=0;i<1000000;i++)
        dijkstra_heap(graph, 0);
    end = clock();
    double t_heap = (double)(end - start) / CLOCKS_PER_SEC;
    fprintf(file, "Dijkstra_Heap %f\n", t_heap);

    fclose(file);

    printf("Execution completed. Times logged to dijkstra_times.txt\n");

    return 0;
}
