#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// ex4: Freckles
// type: minimun spanning tree

#define maxV 100
const int INF = 1e9;

struct Tuple {
    int v;
    double w;

    Tuple(int vertex, double weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
vector<double> dist(maxV, INF);
// vector<int> path(maxV, -1);
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
                // path[adja.v] = u;
                pq.push(Tuple(adja.v, adja.w));
            }
        }
    }
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> V;
        vector<pair<double, double>> mole(V);
        for (int i=0; i<V; i++) {
            cin >> mole[i].first >> mole[i].second;
        }

        for (int u=0; u<V-1; u++) {
            for (int v=u+1; v<V; v++) {
                double dis = sqrt(pow(mole[u].first - mole[v].first, 2) + pow(mole[u].second - mole[v].second, 2));
                graph[u].push_back(Tuple(v, dis));
                graph[v].push_back(Tuple(u, dis));
            }
        }

        Prims(0);
        double total = 0;
        for (int i=0; i<V; i++) {
            if (dist[i] != INF) total += dist[i];
        }

        cout << setprecision(2) << fixed << total << "\n\n";
        
        for (int i=0; i<V; i++) {
            dist[i] = INF;
            visited[i] = 0;
            graph[i].clear();
        }
    }
    return 0;
} 