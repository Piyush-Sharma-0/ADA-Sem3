class GraphList:
    def __init__(self, vertices):
        self.num_vertices = vertices
        self.adj_lists = {i: [] for i in range(vertices)}

    def add_edge(self, src, dest):
        self.adj_lists[src].append(dest)
        self.adj_lists[dest].append(src)

def dfs_iterative(graph, start_vertex):
    visited = [0] * graph.num_vertices
    stack = []

    stack.append(start_vertex)

    while stack:
        curr_vertex = stack.pop()

        if not visited[curr_vertex]:
            visited[curr_vertex] = 1
            print(f"Visited {curr_vertex}")
        for adj_vertex in graph.adj_lists[curr_vertex]:
            if not visited[adj_vertex]:
                stack.append(adj_vertex)

    return 0

graph = GraphList(5)
graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(0, 3)
graph.add_edge(1, 2)
graph.add_edge(3, 4)

dfs_iterative(graph, 0)
