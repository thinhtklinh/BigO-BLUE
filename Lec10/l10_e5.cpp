// ex5: Single source shortest path, negative weights
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 1000
const int INF = 1e9;
vector<int> dist(maxV, INF);
vector<bool> hasLoop(maxV, 0);
// vector<int> path(maxV, -1);
int V, E;

struct Edge {
    int s;
    int t;
    int w;
    Edge(int source, int target, int weight) : s(source), t(target), w(weight) {};
};

vector<Edge> graph;

void BellmanFord(int s) {
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
    
    bool flag;
    for (int i=0; i<V-1; i++) {
        flag = 0;
        for (int j=0; j<E; j++) {
            u = graph[j].s;
            v = graph[j].t;
            w = graph[j].w;
            if (dist[u] != INF && (dist[u] + w < dist[v])) {
                // return false;
                dist[v] = dist[u] + w;
                hasLoop[v] = 1;
                flag = 1;
            }
        }
        if (!flag) break; // no more update
    }
    // return true;
}

int main() {
    int q, s, f, a, b, c;
    while (cin >> V >> E >> q >> s && V != 0) {
        for (int i=0; i<E; i++) {
            cin >> a >> b >> c;
            graph.push_back(Edge(a, b, c));
        }
        
        BellmanFord(s);

        for (int i=0; i<q; i++) {
            cin >> f;
            if (hasLoop[f]) cout << "-Infinity\n";
            else if (dist[f] != INF) cout << dist[f] << '\n';
            else cout << "Impossible\n";
        }

        graph.clear();
        for (int i=0; i<V; i++) {
            dist[i] = INF;
            hasLoop[i] = 0;
        }
        cout << '\n';
    }

    return 0;
}