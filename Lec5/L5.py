from queue import Queue
maxV = 100
V = E = None
visited = [False]*maxV
path = [-1]*maxV
graph = [[] for _ in range(maxV)]

def BFS(s):
    for i in range(V):
        visited[i] = False
        path[i] = -1
    q = Queue()
    visited[s] = True
    q.put(s)
    while not q.empty():
        v = q.get()
        for adja in graph[v]:
            if not visited[adja]:
                visited[adja] = True
                q.put(adja)
                path[adja] = v


def printPath(s, f):
    ans = []
    if f == s:
        print(s)
        return
    if path[f] == -1:
        print("No path")
        return
    while True:
        ans.append(f)
        f = path[f]
        if f == s:
            ans.append(f)
            break
    
    for i in range(len(ans)-1, -1, -1):
        print(ans[i], end=' ')

def printPathRec(s, f):
    if s == f:
        print(f, end=' ')
    else:
        if path[f] == -1:
            print("No path")
        else:
            printPathRec(s, path[f])
            print(f, end=' ')
    
if __name__ == '__main__':
    V, E = map(int, input().split())
    for i in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    s = 0
    f = 5
    BFS(s)
    printPath(s, f)