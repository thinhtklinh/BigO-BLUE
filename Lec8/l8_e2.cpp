// ex2: Mice and Maze
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

vector<Tuple> graph[maxV];
vector<int> dist(maxV, INF);
// int path[maxV];

// for min heap
struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};

void dijsktra(int s) {
    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
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

void ex2() {
    int v, f, t, e;
    cin >> v >> f >> t >> e;
    int a, b, c;
    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        graph[b-1].push_back(Tuple(a-1, c));
    }
    dijsktra(f-1);
    int ans = 0;
    for (int i=0; i<v; i++) {
        if (dist[i] <= t) ans++;
    }
    cout << ans;
}

int main() {
    ex2();
    return 0;
}