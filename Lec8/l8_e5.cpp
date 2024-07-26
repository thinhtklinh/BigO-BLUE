// ex5: Sending Email
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 20000
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
vector<int> dist(maxV, INF);
// int path[maxV];

// for min heap
struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};

void dijsktra(int s, int t) {
    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
        if (head.v == t) return; // found shortest path for s-t
        if (dist[head.v] != head.w) continue;
        for (int i=0; i<graph[head.v].size(); i++) {
            Tuple adja = graph[head.v][i];
            if (head.w + adja.w < dist[adja.v]) {
                dist[adja.v] = head.w + adja.w;
                pq.push(Tuple(adja.v, dist[adja.v]));
                // path[adja.v] = head.v;
            }
        }
    }   
}

void ex5() {
    int tc, v, e, s, t;
    int a, b, c;
    cin >> tc;
    for (int i=1; i<=tc; i++) {
        cin >> v >> e >> s >> t;
        for (int j=0; j<e; j++) {
            cin >> a >> b >> c;
            graph[a].push_back(Tuple(b, c));
            graph[b].push_back(Tuple(a, c)); 
        }

        dijsktra(s, t);
        cout << "Case #" << i << ": ";
        if (dist[t] != INF) cout << dist[t] << '\n';
        else cout << "unreachable\n";

        for (int j=0; j<v; j++) {
            graph[j].clear();
            dist[j] = INF;
        }
    }
}

int main() {
    ex5();
    return 0;
}