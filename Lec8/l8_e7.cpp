// ex7: Chocolate Journey
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100003
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


void ex7() {
    int v, e, k, x, s, t;
    int a, b, c;
    cin >> v >> e >> k >> x;
    vector<int> choco(k);
    for (int i=0; i<k; i++) {
        cin >> choco[i];
    }
    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(Tuple(b, c));
        graph[b].push_back(Tuple(a, c));
    }
    cin >> s >> t;
    dijsktra(s, 0);
    dijsktra(t, 1);

    int ans = INF;
    for (int i=0; i<k; i++) {
        if (dist[0][choco[i]] != INF && dist[1][choco[i]] < x) {
            ans = min(dist[0][choco[i]] + dist[1][choco[i]], ans);
        }
    }

    if (ans != INF) cout << ans;
    else cout << -1;
}

int main() {
    ex7();
    return 0;
}