#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int num_vertices;
    Node** adj_lists;
} GraphList;

typedef struct {
    int items[10];
    int front;
    int rear;
} Queue;

typedef struct {
    int items[100];
    int top;
} Stack;


/* ----------------- QUEUE FUNCTIONS (FOR BFS) ----------------- */

void initialize_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty_queue(Queue *q) {
    return q->front == -1;
}

int is_full_queue(Queue *q) {
    return q->rear == 10 - 1;
}

int enqueue(Queue *q, int value) {
    if (is_full_queue(q)) return -1;
    if (is_empty_queue(q)) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
    return 0;
}

int dequeue(Queue *q) {
    if (is_empty_queue(q)) return INT_MIN;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}


/* ----------------- STACK FUNCTIONS (FOR DFS) ----------------- */

Stack* create_stack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int is_empty_stack(Stack* stack) {
    return stack->top == -1;
}

int is_full_stack(Stack* stack) {
    return stack->top == 100 - 1;
}

int push(Stack* stack, int item) {
    if (is_full_stack(stack)) return INT_MAX;
    stack->items[++stack->top] = item;
    return 0;
}

int pop(Stack* stack) {
    if (is_empty_stack(stack)) return INT_MIN;
    return stack->items[stack->top--];
}


/* ----------------- GRAPH FUNCTIONS ----------------- */

GraphList* create_graph_list(int vertices) {
    GraphList* graph = malloc(sizeof(GraphList));
    graph->num_vertices = vertices;
    graph->adj_lists = malloc(sizeof(Node*) * vertices);

    for (int i = 0; i < vertices; i++)
        graph->adj_lists[i] = NULL;

    return graph;
}

int add_edge_list(GraphList* graph, int src, int dest) {
    Node* new_node = malloc(sizeof(Node));
    new_node->vertex = dest;
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;

    new_node = malloc(sizeof(Node));
    new_node->vertex = src;
    new_node->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = new_node;

    return 0;
}


/* ----------------- BFS ----------------- */

void traverse_bfs(GraphList* graph, int start_vertex) {
    int visited[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; i++)
        visited[i] = 0;

    Queue queue;
    initialize_queue(&queue);

    visited[start_vertex] = 1;
    enqueue(&queue, start_vertex);

    printf("BFS: ");

    while (!is_empty_queue(&queue)) {
        int curr = dequeue(&queue);
        printf("%d ", curr);

        Node* temp = graph->adj_lists[curr];
        while (temp) {
            int adj = temp->vertex;
            if (!visited[adj]) {
                visited[adj] = 1;
                enqueue(&queue, adj);
            }
            temp = temp->next;
        }
    }

    printf("\n");
}


/* ----------------- DFS ----------------- */

void traverse_dfs(GraphList* graph, int start_vertex) {
    int visited[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; i++)
        visited[i] = 0;

    Stack* stack = create_stack();
    push(stack, start_vertex);

    printf("DFS: ");

    while (!is_empty_stack(stack)) {
        int curr = pop(stack);
        if (!visited[curr]) {
            visited[curr] = 1;
            printf("%d ", curr);
        }

        Node* temp = graph->adj_lists[curr];
        while (temp) {
            if (!visited[temp->vertex])
                push(stack, temp->vertex);
            temp = temp->next;
        }
    }

    printf("\n");
}


/* ----------------- MAIN ----------------- */

int main() {
    GraphList* graph = create_graph_list(5);

    add_edge_list(graph, 0, 1);
    add_edge_list(graph, 0, 2);
    add_edge_list(graph, 0, 3);
    add_edge_list(graph, 1, 2);
    add_edge_list(graph, 3, 4);

    int start;
    printf("Enter source vertex (0-4): ");
    scanf("%d", &start);

    traverse_bfs(graph, start);
    traverse_dfs(graph, start);

    return 0;
}
