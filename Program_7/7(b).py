def prim(graph,source):
    V = len(graph)
    selected = [False] * V
    key = [99999] * V
    parent = [-1] * V

    key[source] = 0

    for i in range(V - 1):
        min_val = 99999
        u = -1

        # Pick min key vertex not yet selected
        for v in range(V):
            if not selected[v] and key[v] < min_val:
                min_val = key[v]
                u = v

        selected[u] = True

        for v in range(V):
            if graph[u][v] != 0 and not selected[v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
                parent[v] = u

    for i in range(1, V):
        print(f"{parent[i]} -- {i} (weight = {graph[i][parent[i]]})")

graph = [
    [0, 4, 4, 0, 0, 0],
    [4, 0, 2, 0, 0, 0],
    [4, 2, 0, 3, 4, 2],
    [0, 0, 3, 0, 3, 0],
    [0, 0, 4, 3, 0, 3],
    [0, 0, 2, 0, 3, 0]
]
source = 0
prim(graph,source)
