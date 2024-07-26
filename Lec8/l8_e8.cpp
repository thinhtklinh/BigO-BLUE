// ex7: Almost Shortest Path
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 500
const int INF = 1e9;

struct Tuple {
    int v;
    int w;
    float f;

    Tuple(int vertex, int weight, bool flag) : v(vertex), w(weight), f(flag) {};
};

vector<Tuple> graph[maxV];
vector<int> dist(maxV, INF);

// for min heap
struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};

void dijsktra(int s, int t) {
    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
        if (head.v == t) return;
        if (dist[head.v] != head.w) continue;
        for (int i=0; i<graph[head.v].size(); i++) {
            Tuple adja = graph[head.v][i];
            if (head.w + adja.w < dist[adja.v]) {
                dist[adja.v] = head.w + adja.w;
                pq.push(Tuple(adja.v, dist[adja.v]));
            }
        }
    }   
}

void dijsktra2(int s, int t, int minP) {
    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
        if (head.v == t) return;
        if (dist[head.v] != head.w) continue;
        for (int i=0; i<graph[head.v].size(); i++) {
            Tuple adja = graph[head.v][i];
            int tmp = head.w + adja.w;
            if (tmp < dist[adja.v]) {
                if (adja.v == t && tmp == minP) continue;
                dist[adja.v] = tmp;
                pq.push(Tuple(adja.v, dist[adja.v]));
            }
        }
    }   
}

void ex8() {
    int v, e, s, d;
    int a, b, c;
    cin >> v >> e;
    while (v) {
        cin >> s >> d;
        for (int i=0; i<e; i++) {
            cin >> a >> b >> c;
            graph[a].push_back(Tuple(b, c));
        }

        dijsktra(s, d);
        int shortest = dist[d];
        for (int i=0; i<v; i++) dist[i] = INF;
        dijsktra2(s, d, shortest);

        if (dist[d] != INF) cout << dist[d] << '\n';
        else cout << -1 << '\n';

        cin >> v >> e;
    }
}

int main() {
    ex8();
    return 0;
}