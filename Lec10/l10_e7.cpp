// Ex7: Alice in Amsterdam, I mean Wonderland
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const long long INF = 1e12;
vector<long long> dist(maxV, INF);
vector<bool> hasLoop(maxV, 0);
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
    for (int i=0; i<V; i++) {
        for (int j=0; j<E; j++) {
            u = graph[j].s;
            v = graph[j].t;
            w = graph[j].w;
            if (dist[u] != INF && (dist[u] + w < dist[v])) {
                dist[v] = dist[u] + w;
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
    vector<string> cities;
    string name;
    int c, q, s, f;
    int tc = 1;
    while (cin >> V && V != 0) {
        for (int i=0; i<V; i++) {
            cin >> name;
            cities.push_back(name);
            for (int j=0; j<V; j++) {
                cin >> c;
                if (c != 0) graph.push_back(Edge(i, j, c));
            }
        }
        E = graph.size();
        cin >> q;
        int preS = -1;
        cout << "Case #" << tc << ":\n";
        bool loop;
        for (int i=1; i<=q; i++) {
            cin >> s >> f;
            if (s != preS) { // reset for new BellmanFord
                loop = 0;
                for (int u=0; u<V; u++) {
                    dist[u] = INF;
                }
                if (!BellmanFord(s)) loop = 1;
                preS = s;
            }

            if (loop) cout << "NEGATIVE CYCLE\n";
            else if (dist[f] == INF) cout << cities[s] << "-" << cities[f] << " NOT REACHABLE\n";
            else cout << cities[s] << "-" << cities[f] << " " << dist[f] << '\n';
        }

        cities.clear();
        graph.clear();
        tc++;
    }

    return 0;
}