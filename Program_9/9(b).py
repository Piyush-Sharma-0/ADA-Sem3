class Edge():
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight
    def printEdge(self):
        print(f"{self.src} -- {self.dest} == {self.weight}")

graph=[[0, 4, 0, 0, 0, 2],
       [4, 0, 6, 0, 0, 3],
       [0, 6, 0, 3, 0, 0],
       [0, 0, 3, 0, 7, 0],
       [0, 0, 0, 7, 0, 1],
       [2, 3, 0, 0, 1, 0]]

edges = []
E=0
for i in range(6):
    for j in range(6):
        if graph[i][j] != 0:
            edges.append(Edge(i, j, graph[i][j]))
            E+=1
dist=[9999]*6
src=0
dist[src]=0

for i in range(5):
    for j in range(E):
        u=edges[j].src
        v=edges[j].dest
        weight=edges[j].weight
        if dist[u] != 9999 and dist[u]+weight < dist[v]:
            dist[v]=dist[u]+weight

for i in range(E):
    u=edges[i].src
    v=edges[i].dest
    weight=edges[i].weight
    if dist[u] != 9999 and dist[u]+weight < dist[v]:
        print("Graph contains negative weight cycle")
        break

for i in range(6):
    print(f"Distance from source to vertex {i} is {dist[i]}")
    pass
for edge in edges:
    edge.printEdge()
print(dist)