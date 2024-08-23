// ex5: ACM Contest and Blackout
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
vector<pair<int, int>> path(maxV); // path[v] = u, idx of graph[u]
vector<bool> visited(maxV, 0);
int V, E;

struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};


void Prims(int s, bool flag = 0) {
    fill(dist.begin(), dist.end(), INF);
    fill(visited.begin(), visited.end(), 0);

    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().v; // dont need the w info anymore
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;

        for (int i=0; i<graph[u].size(); i++) {
            Tuple adja = graph[u][i];
            if (!visited[adja.v] && adja.w < dist[adja.v]) {
                dist[adja.v] = adja.w;
                pq.push(Tuple(adja.v, adja.w));
                if (flag) path[adja.v] = make_pair(u, i);
            }
        }
    }
}

int main() {
    int tc, a, b, c;
    cin >> tc;
    while (tc--) {
        cin >> V >> E;
        for (int i=0; i<E; i++) {
            cin >> a >> b >> c;
            graph[a-1].push_back(Tuple(b-1, c));
            graph[b-1].push_back(Tuple(a-1, c));
        }

        int min1 = 0;
        Prims(0, 1); // record path
        for (int i=0; i<V; i++) min1 += dist[i];

        int min2 = INF;
        for (int i=1; i<V; i++) {
            pair<int, int> disE = path[i]; // this edge belongs to the MST
            int savedW = graph[disE.first][disE.second].w;
            graph[disE.first][disE.second].w = INF; // virtually disable it from the graph
            Prims(0);
            int tmp_min2 = 0;
            for (int j=0; j<V; j++) {
                tmp_min2 += dist[j];
                if (dist[j] == INF) break; // can't reach this node -> invalid MST
            }
            min2 = min(min2, tmp_min2);
            graph[disE.first][disE.second].w = savedW; // restore the edge
        }

        cout << min1 << " " << min2 << '\n';

        for (int i=0; i<V; i++) graph[i].clear();
    }
}