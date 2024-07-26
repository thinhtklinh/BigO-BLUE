// ex4: Traffic Network
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 10000
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {}
};

vector<vector<int>> dist(2, vector<int>(maxV, INF));
vector<vector<vector<Tuple>>> graph(2, vector<vector<Tuple>>(maxV, vector<Tuple>()));

// for min heap
struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};

// type 0: s to all
// type 1: all to s
void dijsktra(int s, bool type) {
    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0));
    dist[type][s] = 0;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
        if (dist[type][head.v] != head.w) continue;
        for (int i=0; i<graph[type][head.v].size(); i++) {
            Tuple adja = graph[type][head.v][i];
            if (head.w + adja.w < dist[type][adja.v]) {
                dist[type][adja.v] = head.w + adja.w;
                pq.push(Tuple(adja.v, dist[type][adja.v]));
            }
        }
    }   
}

void ex4() {
    int tc, v, e, k, s, t;
    int a, b, c;
    int ans;
    cin >> tc;
    while (tc--) {
        cin >> v >> e >> k >> s >> t;
        for (int i=0; i<e; i++) {
            cin >> a >> b >> c;
            graph[0][a-1].push_back(Tuple(b-1, c)); // graph
            graph[1][b-1].push_back(Tuple(a-1, c)); // rev graph;
        }

        dijsktra(s-1, 0); // s to all
        dijsktra(t-1, 1); // all to t

        ans = dist[0][t-1]; // before picking a 2-way path

        for (int i=0; i<k; i++) {
            cin >> a >> b >> c;
            ans = min(dist[0][a-1] + c + dist[1][b-1], ans);
            ans = min(dist[0][b-1] + c + dist[1][a-1], ans);
        }

        if (ans != INF) cout << ans;
        else cout << -1;

        for (int i=0; i<2; i++) {
            for (int j=0; j<v; j++) {
                graph[i][j].clear();
                dist[i][j] = INF;
            }
        }

        if (tc) cout << '\n';
    }
}

int main() {
    ex4();
    return 0;
}