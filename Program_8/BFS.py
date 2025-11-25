class GraphList:
    def __init__(self, vertices):
        self.num_vertices = vertices
        self.adj_lists = {i: [] for i in range(vertices)}

    def add_edge(self, src, dest):
        self.adj_lists[src].append(dest)
        self.adj_lists[dest].append(src)

def bfs_iterative(graph, start_vertex):
    visited = [0] * graph.num_vertices
    queue = []

    visited[start_vertex] = 1
    queue.append(start_vertex)

    while queue:
        curr = queue.pop(0)
        print(f"Visited {curr}")

        for neighbor in graph.adj_lists[curr]:
            if not visited[neighbor]:
                visited[neighbor] = 1
                queue.append(neighbor)


graph = GraphList(5)

graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(0, 3)
graph.add_edge(1, 2)
graph.add_edge(3, 4)

bfs_iterative(graph, 0)
