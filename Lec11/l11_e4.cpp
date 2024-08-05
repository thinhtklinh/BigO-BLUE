// ex4: Risk
#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define maxV 20
const int INF = 1e9;
vector<vector<int>> dist;
int V = 20;

void FloyWarshall() {
    for (int k=0; k<V; k++) {
        for (int i=0; i<V; i++) {
            if (dist[i][k] == INF) continue;
            for (int j=0; j<V; j++) {
                if (dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n, v;
    int tc = 1;
    while (true) {
        dist = vector<vector<int>>(V, vector<int>(V, INF));
        for (int u=0; u<V-1; u++) {
            if (!(cin >> n)) return 0; // eof
            dist[u][u] = 0;
            for (int i=0; i<n; i++) {
                cin >> v;
                dist[u][v-1] = 1;
                dist[v-1][u] = 1;
            }
        }

        FloyWarshall();
        int q, s, f;
        cin >> q;
        cout << "Test Set #" << tc << '\n';
        for (int i=0; i<q; i++) {
            cin >> s >> f;
            cout << setw(2) << s << " to " << setw(2) << f << ": " << dist[s-1][f-1] << '\n';
        }
        cout << '\n';
        tc++;
    }
    return 0;
}