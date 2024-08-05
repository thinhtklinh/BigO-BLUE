// Ex2: Extended traffic
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 200
const int INF = 1e9;
vector<int> dist(maxV, INF);
vector<bool> hasLoop(maxV, 0);
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
                dist[v] = dist[u] + w;
                hasLoop[v] = 1;
                flag = 1;
            }
        }
        if (!flag) break; // no more update
    }
}

int main() {
    int tc, u, v, q, f;
    cin >> tc;
    vector<int> busy(maxV);
    for (int t=1; t<=tc; t++) {
        cin >> V;
        for (int i=0; i<V; i++) {
            cin >> busy[i];
        }
        cin >> E;
        for (int i=0; i<E; i++) {
            cin >> u >> v;
            graph.push_back(Edge(u-1, v-1, pow(busy[v-1]-busy[u-1], 3)));
        }

        BellmanFord(0); 

        cout << "Case " << t << ":\n";
        cin >> q;
        for (int i=0; i<q; i++) {
            cin >> f;
            f--;
            if (!hasLoop[f] && dist[f] != INF && dist[f] >= 3) cout << dist[f] << '\n';
            else cout << "?\n";
        }

        fill(dist.begin(), dist.end(), INF);
        graph.clear();
        fill(hasLoop.begin(), hasLoop.end(), 0);
    }

    return 0;
}