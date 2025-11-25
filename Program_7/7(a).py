class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

def find(parent, i):
    if parent[i] != i:
        parent[i] = find(parent, parent[i])  # path compression
    return parent[i]

def union(parent, rank, x, y):
    xroot = find(parent, x)
    yroot = find(parent, y)

    if rank[xroot] < rank[yroot]:
        parent[xroot] = yroot
    elif rank[xroot] > rank[yroot]:
        parent[yroot] = xroot
    else:
        parent[yroot] = xroot
        rank[xroot] += 1

def kruskal(edges, vertices):
    # Initialize parent and rank as dictionaries
    parent = {v: v for v in vertices}
    rank   = {v: 0 for v in vertices}

    # Sort edges by ascending weight
    edges = sorted(edges, key=lambda e: e.weight)

    result = []

    for edge in edges:
        #print("Parent:", parent)

        x = find(parent, edge.src)
        y = find(parent, edge.dest)

        if x != y:
            result.append(edge)
            union(parent, rank, x, y)

        if len(result) == len(vertices) - 1:
            break

    #print("Final Parent:", parent)
    for e in result:
        print(f"{e.src} -- {e.dest} (weight = {e.weight})")

# Example static dataset
edges = [
    Edge('A', 'B', 4), Edge('A', 'C', 4), Edge('B', 'C', 2), Edge('C', 'D', 3),
    Edge('C', 'F', 2), Edge('C', 'E', 4), Edge('D', 'E', 3), Edge('F', 'E', 3)
]
vertices = ['A','B','C','D','E','F']

kruskal(edges, vertices)
