// ex7: Simulate Network
#include <bits/stdc++.h>
using namespace std;

#define maxV 100000
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

int main() {
    int C, c, a, b, l;
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        cin >> a >> b >> l;
        graph[a-1].push_back(Tuple(b-1, l));
        graph[b-1].push_back(Tuple(a-1, l));
    }

    cin >> C;
    priority_queue<int, vector<int>, greater<int>> minHip;
    for (int i=0; i<C; i++) {
        cin >> c;
        minHip.push(c);
    }

    Prims(0); // assume connected graph

    sort(dist.begin(), dist.begin()+V, greater<int>()); // sort for edges in MST
    long long tw = 0;
    for (int i=0; i<V; i++) {
        if (dist[i] > minHip.top()) {
            tw += minHip.top(); // replace by this caple
            minHip.pop();
        }
        else tw += dist[i];
    }

    cout << tw;
    return 0;
}