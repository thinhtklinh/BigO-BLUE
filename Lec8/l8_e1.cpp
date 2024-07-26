// ex1: Travelling Cost
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 10000
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

void ex1() {
    int e, a, b, c;
    cin >> e; 
    for (int i=0; i<e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(Tuple(b, c));
        graph[b].push_back(Tuple(a, c));
    }
    int s, f, q;
    cin >> s;
    dijsktra(s);
    cin >> q;
    while (q--) {
        cin >> f;
        if (dist[f] != INF) cout << dist[f] << '\n';
        else cout << "NO PATH\n";
    }
}

int main() {
    ex1();
    return 0;
}