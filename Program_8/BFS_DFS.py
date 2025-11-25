adj_list={1:[2,3], 2:[1,4,5], 3:[1,6,7], 4:[2,8], 5:[2,9], 6:[3,10], 7:[3], 8:[4], 9:[5], 10:[6]}
adj_matrix=[[0]*11 for _ in range(11)]
edges=[(1,2),(1,3),(2,4),(2,5),(3,6),(3,7),(4,8),(5,9),(6,10)]
for u,v in edges:
    adj_matrix[u][v]=adj_matrix[v][u]=1

start=int(input("Enter starting vertex (1-10): "))

def bfs(s):
    print("BFS",s,":",end=" ")
    vis=[0]*11
    q=[s]
    vis[s]=1
    front=0
    while front<len(q):
        v=q[front]
        front+=1
        print(v,end=" ")
        for nxt in adj_list[v]:
            if not vis[nxt]:
                vis[nxt]=1
                q.append(nxt)

def dfs(v,vis):
    vis[v]=1
    print(v,end=" ")
    for nxt in adj_list[v]:
        if not vis[nxt]:
            dfs(nxt,vis)

bfs(start)
print()
print("DFS",start,":",end=" ")
dfs(start,[0]*11)
