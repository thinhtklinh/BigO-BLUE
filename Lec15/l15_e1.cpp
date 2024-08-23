#include <bits/stdc++.h>
using namespace std;

#define maxV 10000
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
vector<int> dist(maxV);
vector<bool> visited(maxV);
int V, E;

struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};


void Prims(int s) {
    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().v; // dont need the w info anymore
        pq.pop();

        if (visited[u]) continue;
        else visited[u] = true;

        for (int i=0; i<graph[u].size(); i++) {
            Tuple adja = graph[u][i];
            if (!visited[adja.v] && adja.w < dist[adja.v]) {
                dist[adja.v] = adja.w;
                pq.push(Tuple(adja.v, adja.w));
            }
        }

    }
}

int main() {
    int a, b, c;
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        cin >> a >> b >> c;
        graph[a-1].push_back(Tuple(b-1, c));
        graph[b-1].push_back(Tuple(a-1, c));
    }

    for (int i=0; i<maxV; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    Prims(0);

    long long tw = 0;
    for (int i=0; i<V; i++) {
        if (dist[i] != INF) tw = tw + dist[i];
    }
    cout << tw;
} 