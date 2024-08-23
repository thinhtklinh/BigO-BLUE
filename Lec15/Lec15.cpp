#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
vector<int> dist(maxV, INF);
vector<int> path(maxV, -1);
vector<bool> visited(maxV, 0);
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
                path[adja.v] = u;
                pq.push(Tuple(adja.v, adja.w));
            }
        }
    }
}

void printMST() {
    int ans = 0;
    for (int i=0; i<V; i++) {
        if (path[i] == -1) continue;
        ans += dist[i];
        cout << path[i] << " - " << i << ": " << dist[i] << "\n";
    }
    cout << "Weight of MST: " << ans << "\n";
}

int main() {
    int u, v, w;
    cin >> V >> E;
    fill(path.begin(), path.end(), -1);
    for (int i=0; i<E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(Tuple(v, w));
        graph[v].push_back(Tuple(u, w));
    }
    int s = 0;
    Prims(s);
    printMST();
    return 0;
} 