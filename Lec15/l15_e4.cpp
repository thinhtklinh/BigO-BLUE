// ex4: Road Construction
#include <bits/stdc++.h>
using namespace std;

#define maxV 1000
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
vector<int> dist(maxV, INF);
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
    int tc, a, b, c;
    string ct1, ct2;
    cin >> tc;
    for (int t=1; t<=tc; t++) {
        cin >> E;
        // vector<string> city(V);
        map<string, int> city;
        int v = 0;
        map<string, int>::iterator it;
        for (int i=0; i<E; i++) {
            cin >> ct1 >> ct2 >> c;
            it = city.find(ct1);
            if (it == city.end()) {
                a = v;
                city[ct1] = v++;
            }
            else a = it->second;

            it = city.find(ct2);
            if (it == city.end()) {
                b = v;
                city[ct2] = v++;
            }
            else b = it->second;
            
            graph[a].push_back(Tuple(b, c));
            graph[b].push_back(Tuple(a, c));
        }

        V = v;

        Prims(0);

        int tw = 0;
        int flag = 0;
        for (int i=0; i<V; i++) {
            if (dist[i] == INF) {
                flag = 1;
                break;
            }
            tw += dist[i];
        }

        cout << "Case " << t << ": " << (flag ? "Impossible" : to_string(tw)) << "\n";

        for (int i=0; i<V; i++) {
            dist[i] = INF;
            visited[i] = 0;
            graph[i].clear();
        }
    }
}