import queue
maxV = 100
INF = int(1e9)

class Node:
    def __init__(self, id, dist):
        self.w = dist
        self.v = id
    
    def __lt__(self, other):
        return self.w <= other.w
    
def dijkstra(s):
    pq = queue.PriorityQueue()
    pq.put(Node(s, 0))
    dist[s] = 0
    while not pq.empty():
        head = pq.get()
        if head.w != dist[head.v]:
            continue
        for adja in graph[head.v]:
            if head.w + adja.w < dist[adja.v]:
                dist[adja.v] = head.w + adja.w
                pq.put(Node(adja.v, dist[adja.v]))
                path[adja.v] = head.v

if __name__ == '__main__':    
    n = int(input())
    s, t = 0, 5
    graph = [[] for _ in range(n+3)]
    dist = [INF for _ in range(n+3)]
    path = [-1 for _ in range(n+3)]
    for i in range(n):
        ds = list(map(int, input().split()))
        for j in range(n):
            if ds[j]:
                graph[i].append(Node(j, ds[j]))
    dijkstra(s)
    ans = dist[t]
    print(ans)
    