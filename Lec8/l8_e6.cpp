// ex6: Commandos
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<vector<int>> dist(2, vector<int>(maxV, INF));
vector<Tuple> graph[maxV];

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
        for (int i=0; i<graph[head.v].size(); i++) {
            Tuple adja = graph[head.v][i];
            if (head.w + adja.w < dist[type][adja.v]) {
                dist[type][adja.v] = head.w + adja.w;
                pq.push(Tuple(adja.v, dist[type][adja.v]));
            }
        }
    }   
}

void ex6() {
    int tc, v, e, s, t;
    int a, b;
    cin >> tc;
    for (int cid=1; cid<=tc; cid++) {
        cin >> v >> e;
        for (int i=0; i<e; i++) {
            cin >> a >> b;
            graph[a].push_back(Tuple(b, 1));
            graph[b].push_back(Tuple(a, 1));
        }
        cin >> s >> t;

        dijsktra(s, 0);
        dijsktra(t, 1);

        int time = 0;
        for (int i=0; i<v; i++) {
            time = max(dist[0][i] + dist[1][i], time);
        }

        for (int i=0; i<v; i++) {
            graph[i].clear();
            for (int j=0; j<2; j++) {
                dist[j][i] = INF;
            }
        }

        cout << "Case " << cid << ": " << time << '\n';
    }
}

int main() {
    ex6();
    return 0;
}