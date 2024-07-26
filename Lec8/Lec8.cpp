#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxV 100
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<vector<Tuple>> graph;
vector<int> dist(maxV, INF);
int path[maxV];

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
                path[adja.v] = head.v;
            }
        }
    }   
}

int main() {
    int n, s, t;
    cin >> n;
    s = 0, t = 4;
    int d;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> d;
            if (d) graph[i].push_back(Tuple(j, d));
        }
    }
    dijsktra(s);
    int ans = dist[t];
    return 0;
}