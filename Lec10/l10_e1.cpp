#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 1000
const int INF = 1e9;
vector<int> dist(maxV, INF);
// vector<int> path(maxV, -1);
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
                // path[v] = u;
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
    int tc, a, b, c;
    cin >> tc;
    while (tc--) {
        cin >> V >> E;
        for (int i=0; i<E; i++) {
            cin >> a >> b >> c;
            graph.push_back(Edge(a, b, c));
        }
        if (BellmanFord(0)) cout << "not possible\n";
        else cout << "possible\n";

        graph.clear();
        for (int i=0; i<V; i++) {
            dist[i] = INF;
        }
    }

    return 0;
}