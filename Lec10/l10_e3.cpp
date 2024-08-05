// Ex3: XYZZY
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const int INF = 1e9;
vector<int> dist(maxV, -INF);
vector<bool> visited(maxV, 0);
vector<int> energy(maxV);
int V;

struct Edge {
    int s;
    int t;
    Edge(int source, int target) : s(source), t(target) {};
};

vector<Edge> graph;

bool hasPath(int s, int f) {
    fill(visited.begin(), visited.end(), 0);
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (Edge& edge : graph) {
            if (edge.s == u) {
                int v = edge.t;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    if (v == f) return true;
                }
            }
        }
    }
    return false;
}

bool BellmanFord(int s, int f) {
    fill(dist.begin(), dist.end(), -INF);
    dist[s] = 100;
    for (int i=0; i<V-1; i++) {
        for (Edge& edge : graph) {
            int u = edge.s;
            int v = edge.t;
            if (dist[u] > 0) {
                dist[v] = max(dist[v], dist[u] + energy[v]);
            }
        }
    }

    if (dist[f] > 0) return true;
    
    for (Edge& edge : graph) {
        int u = edge.s;
        int v = edge.t;
        if (dist[u] > 0 && dist[u] + energy[v] > dist[v] && hasPath(u, f)) {
            return true;
        }
    }

    return false;
}


int main() {
    int d, v;
    while (cin >> V && V != -1) {
        for (int u=0; u<V; u++) {
            cin >> energy[u] >> d;
            while (d--) {
                cin >> v;
                graph.push_back(Edge(u, v-1));
            }
        }

        bool can = BellmanFord(0, V-1);
        cout << (can ? "winnable\n" : "hopeless\n");

        graph.clear();
    }
    return 0;
}