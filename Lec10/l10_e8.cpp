// Ex8: Maelstrom
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const int INF = 1e9;
int V, E;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
vector<int> dist(maxV, INF);

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

int main() {
    cin >> V;
    string val;
    for (int i=0; i<V; i++) {
        for (int j=0; j<=i; j++) {
            if (i != j) {
                cin >> val;
                if (val != "x") {
                    graph[i].push_back(Tuple(j, stoi(val)));
                    graph[j].push_back(Tuple(i, stoi(val)));
                }
            }
        }
    }

    dijsktra(0);

    int time = 0;
    for (int i=0; i<V; i++) {
        time = max(time, dist[i]);
    }

    cout << time;

    return 0;
}