// ex2: Connect the Campus
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define maxV 750
const int INF = 1e9;

struct Tuple {
    int v;
    double w;

    Tuple(int vertex, double weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
vector<double> dist(maxV, INF);
// vector<int> path(maxV);
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
    int a, b;
    double c;
    while (cin >> V && V != 0) {
        vector<pair<double, double>> location(V);
        for (int i=0; i<V; i++) {
            cin >> location[i].first >> location[i].second;
        }

        cin >> E; // exist edges
        for (int i=0; i<E; i++) {
            cin >> a >> b;
            graph[a-1].push_back(Tuple(b-1, 0));
            graph[b-1].push_back(Tuple(a-1, 0));
        }

        for (int i=0; i<V-1; i++) {
            for (int j=i+1; j<V; j++) {
                pair<double, double> pos1 = location[i];
                pair<double, double> pos2 = location[j];
                c = sqrt(pow(pos1.first - pos2.first, 2) + pow(pos1.second - pos2.second, 2));
                graph[i].push_back(Tuple(j, c));
                graph[j].push_back(Tuple(i, c));
            }
        }

        Prims(0);

        double tw = 0;
        for (int i=0; i<V; i++) {
            if (dist[i] != INF) tw += dist[i];
        }

        cout << setprecision(2) << fixed << tw << "\n";

        for (int i=0; i<V; i++) {
            dist[i] = INF;
            visited[i] = 0;
            graph[i].clear();
        }
    }
}