// Ex4: 106 Miles To Chicago -> solved using modified dijkstra
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 102
const int INF = -1;

struct Tuple {
    int v;
    double w;

    Tuple(int vertex, double weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
vector<double> dist(maxV, INF);
vector<bool> visited(maxV, 0);

struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w < b.w;
    }
};

void dijsktra(int s, int f) {
    priority_queue<Tuple, vector<Tuple>, option> pq; // max heap
    pq.push(Tuple(s, 1));
    dist[s] = 1;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
        if (head.v == f) return;
        visited[head.v] = 1;
        if (dist[head.v] != head.w) continue;
        for (int i=0; i<graph[head.v].size(); i++) {
            Tuple adja = graph[head.v][i];
            if (!visited[adja.v] && head.w*adja.w > dist[adja.v]) {
                dist[adja.v] = head.w*adja.w;
                pq.push(Tuple(adja.v, dist[adja.v]));
            }
        }
    }   
}

int V, E;

int main() {
    int a, b;
    double p;
    while (cin >> V && V != 0) {
        cin >> E;
        for (int i=0; i<E; i++) {
            cin >> a >> b >> p;
            graph[a-1].push_back(Tuple(b-1, p/100));
            graph[b-1].push_back(Tuple(a-1, p/100));
        }

        dijsktra(0, V-1);
        cout << setprecision(6) << fixed << dist[V-1]*100 << " percent\n";

        for(int i=0; i<V; i++) {
            graph[i].clear();
            dist[i] = INF;
            visited[i] = 0;
        }
    }
    return 0;
}