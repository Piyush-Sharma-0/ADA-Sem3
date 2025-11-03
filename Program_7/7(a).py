# Kruskal's Algorithm without using classes

# ---------- FIND FUNCTION (with path compression) ----------
def find(parent, i):
    if parent[i] != i:
        parent[i] = find(parent, parent[i])
    return parent[i]

# ---------- UNION FUNCTION (by rank) ----------
def union(parent, rank, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)

    if rank[rootX] < rank[rootY]:
        parent[rootX] = rootY
    elif rank[rootX] > rank[rootY]:
        parent[rootY] = rootX
    else:
        parent[rootY] = rootX
        rank[rootX] += 1

# ---------- KRUSKAL'S ALGORITHM ----------
def kruskalMST(V, edges):
    # Step 1: Sort edges by weight
    edges.sort(key=lambda edge: edge[2])  # edge = (src, dest, weight)

    parent = []
    rank = []
    result = []  # MST edges

    # Step 2: Create subsets (initially each vertex is its own parent)
    for node in range(V):
        parent.append(node)
        rank.append(0)

    e = 0  # number of edges in MST
    i = 0  # index for sorted edges

    # Step 3: Pick smallest edges one by one
    while e < V - 1 and i < len(edges):
        src, dest, weight = edges[i]
        i += 1

        x = find(parent, src)
        y = find(parent, dest)

        # If including this edge doesn't cause a cycle, include it
        if x != y:
            result.append((src, dest, weight))
            union(parent, rank, x, y)
            e += 1

    # Print the result
    print("Edges in the Minimum Spanning Tree:")
    total_weight = 0
    for src, dest, weight in result:
        print(f"{src} -- {dest} == {weight}")
        total_weight += weight
    print(f"Total weight of MST: {total_weight}")

# ---------- MAIN ----------
if __name__ == "__main__":
    V = int(input("Enter number of vertices: "))
    E = int(input("Enter number of edges: "))

    edges = []
    print("Enter edges (src dest weight):")
    for _ in range(E):
        src, dest, weight = map(int, input().split())
        edges.append((src, dest, weight))

    kruskalMST(V, edges)
