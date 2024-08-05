#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const int INF = 1e9;
vector<int> dist(maxV, INF);
vector<int> path(maxV, -1);
int V, E;

struct Edge {
    int s;
    int t;
    int w;
    Edge(int source, int target, int weight) : s(source), t(target), w(weight) {};
};

vector<Edge> graph;

bool BellmanFord(int s) {
    int u, v, w;
    dist[s] = 0;
    for (int i=0; i<V-1; i++) {
        for (int j=0; j<E; j++) {
            u = graph[j].s;
            v = graph[j].t;
            w = graph[j].w;
            if (dist[u] != INF && (dist[u] + w < dist[v])) {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }
    
    for (int j=0; j<E; j++) {
        u = graph[j].s;
        v = graph[j].t;
        w = graph[j].w;
        if (dist[u] != INF && (dist[u] + w < dist[v])) return false;
    }
    return true;
}

int main() {
    int s, t, a, b, c;
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        cin >> a >> b >> c;
        graph.push_back(Edge(a, b, c));
    }

    s = 0, t = 4;
    bool res = BellmanFord(s);
    if (res) {
        cout << dist[t] << endl;
    }
    else cout << "Graph contains negative weight cycle" << endl;

    return 0;
}