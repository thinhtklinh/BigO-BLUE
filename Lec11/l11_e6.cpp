// ex6: Thunder Mountain
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const int INF = 1e9;
vector<vector<float>> dist;
int V;

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

float getDist(pair<float, float>& a, pair<float, float>& b) {
    return sqrt((pow(a.first-b.first, 2) + pow(a.second-b.second, 2)));
}

int main() {
    int tc, x, y;
    cin >> tc;
    for (int t=1; t<=tc; t++) {
        cin >> V;
        dist = vector<vector<float>>(V, vector<float>(V));
        vector<pair<float, float>> town;
        for (int i=0; i<V; i++) {
            cin >> x >> y;
            town.push_back(make_pair(x, y));
        }
        for (int u=0; u<V; u++) {
            for (int v=0; v<V; v++) {
                float d = getDist(town[u], town[v]);
                if (d <= 10) dist[u][v] = d;
                else dist[u][v] = INF;
            }
        }

        FloyWarshall();
        float maxD = -1;
        for (int u=0; u<V; u++) {
            for (int v=0; v<V; v++) {
                maxD = max(maxD, dist[u][v]);
            }
        }

        cout << "Case #" << t << ":\n";
        if (maxD == INF) cout << "Send Kurdy\n";
        else cout << setprecision(4) << fixed << maxD << "\n";
        if (t != tc) cout << "\n";
    }
}