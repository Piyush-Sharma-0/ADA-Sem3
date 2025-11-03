import sys

# ---------- PRIM'S ALGORITHM ----------
def primMST(V, graph):
    # graph is an adjacency matrix or adjacency list of edge weights

    # Initialize all keys as infinite and MST set as False
    key = [sys.maxsize] * V
    parent = [-1] * V
    mstSet = [False] * V

    # Start from the first vertex (you can start from any)
    key[0] = 0

    for _ in range(V - 1):
        # Pick the vertex u not in MST with the smallest key
        min_key = sys.maxsize
        u = -1
        for v in range(V):
            if not mstSet[v] and key[v] < min_key:
                min_key = key[v]
                u = v

        # Add the picked vertex to MST set
        mstSet[u] = True

        # Update key and parent of the adjacent vertices
        for v in range(V):
            if graph[u][v] != 0 and not mstSet[v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
                parent[v] = u

    # Print the constructed MST
    print("Edges in the Minimum Spanning Tree:")
    total_weight = 0
    for i in range(1, V):
        print(f"{parent[i]} -- {i} == {graph[i][parent[i]]}")
        total_weight += graph[i][parent[i]]
    print(f"Total weight of MST: {total_weight}")


# ---------- MAIN ----------
if __name__ == "__main__":
    V = int(input("Enter number of vertices: "))

    print("Enter the adjacency matrix (0 for no edge):")
    graph = []
    for i in range(V):
        row = list(map(int, input().split()))
        graph.append(row)

    primMST(V, graph)
