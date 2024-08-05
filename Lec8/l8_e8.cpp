// ex8: Almost Shortest Path
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 500
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

// for min heap
struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};

void dijkstra(vector<Tuple>* graph, vector<int>& dist, int s) {
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
            }
        }
    }
}

int main() {
    vector<Tuple> initG[maxV];
    vector<int> distS(maxV, INF);
    vector<Tuple> revG[maxV];
    vector<int> distD(maxV, INF);
    vector<Tuple> mainG[maxV];
    vector<int> distM(maxV, INF);

    int V, E, s, d;
    int a, b, c;
    cin >> V >> E;
    while (V) {
        cin >> s >> d;
        for (int i=0; i<E; i++) {
            cin >> a >> b >> c;
            initG[a].push_back(Tuple(b, c));
            revG[b].push_back(Tuple(a, c));
        }

        // find shortest path
        dijkstra(initG, distS, s);
        dijkstra(revG, distD, d);

        int minD = distS[d]; // min path s to d
        // eliminate edges from shortest path
        for (int u=0; u<V; u++) {
            for (int j=0; j<initG[u].size(); j++) {
                int v = initG[u][j].v;
                int w = initG[u][j].w;
                if (distS[u] + w + distD[v] != minD) {
                    mainG[u].push_back(Tuple(v, w));
                }
            }
        }

        dijkstra(mainG, distM, s);
        if (distM[d] != INF) cout << distM[d] << '\n';
        else cout << -1 << '\n';

        for (int i=0; i<V; i++) {
            initG[i].clear();
            revG[i].clear();
            mainG[i].clear();
            distS[i] = distD[i] = distM[i] = INF;
        }

        cin >> V >> E;
    }
    return 0;
}