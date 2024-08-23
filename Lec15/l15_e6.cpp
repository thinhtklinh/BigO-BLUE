// ex6: Audiophobia
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
vector<Tuple> dfsG[maxV];
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

int DFS(int s, int f) {
    fill(visited.begin(), visited.end(), 0);
    fill(dist.begin(), dist.end(), -1); // does it need to be reset in every query? -> YES
    stack<int> stac;
    visited[s] = true;
    stac.push(s);

    while(!stac.empty()) {
        int v = stac.top();
        stac.pop();
        for (int i=0; i<dfsG[v].size(); i++) {
            Tuple adja = dfsG[v][i];
            if (!visited[adja.v]) {
                visited[adja.v] = true;
                dist[adja.v] = max(dist[v], adja.w);
                if (adja.v == f) return dist[f];
                stac.push(adja.v);
            }
        }
    }
    return -1;
}


int main() {
    int Q, a, b, c;
    int tc = 1;
    while (cin >> V >> E >> Q && V != 0) {
        for (int i=0; i<E; i++) {
            cin >> a >> b >> c;
            graph[a-1].push_back(Tuple(b-1, c));
            graph[b-1].push_back(Tuple(a-1, c));
        }
        
        for (int u=0; u<V; u++) {
            if (path[u] == -1) Prims(u); // not sure connected graph
        }
        
        for (int u=0; u<V; u++) {
            if (path[u] != -1) {
                int v = path[u];
                int w = dist[u];
                dfsG[u].push_back(Tuple(v, w));
                dfsG[v].push_back(Tuple(u, w));
            }
        }

        cout << "Case #" << tc++ << "\n";
        fill(dist.begin(), dist.end(), -1);
        while (Q--) {
            cin >> a >> b;
            int ans = DFS(a-1, b-1);
            cout << (ans == -1 ? "no path" : to_string(ans)) << "\n";
        }
        cout << "\n";

        for (int i=0; i<V; i++) {
            dist[i] = INF;
            visited[i] = 0;
            path[i] = -1;
            graph[i].clear();
            dfsG[i].clear();
        }
    }
}