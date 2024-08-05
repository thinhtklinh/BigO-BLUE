// ex3: Arbitrage
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const int INF = -1;
// vector<vector<int>> graph;
vector<vector<float>> dist;
vector<string> money;
int V;

bool FloyWarshall() {
    for (int k=0; k<V; k++) {
        for (int i=0; i<V; i++) {
            if (dist[i][k] == INF) continue;
            for (int j=0; j<V; j++) {
                if (dist[k][j] != INF && dist[i][j] < dist[i][k]*dist[k][j]) {
                    dist[i][j] = dist[i][k]*dist[k][j];
                }
            }
        }
    }

    for (int i=0; i<V; i++) {
        if (dist[i][i] > 1) return false;
    }
    return true; // exist neg cycle
}


int findIdx(string name) {
    for (int i=0; i<money.size(); i++) {
        if (money[i] == name) return i;
    }
    return -1;
}

int main() {
    int tc = 1;
    while (cin >> V && V != 0) {
        dist = vector<vector<float>>(V, vector<float>(V, INF));
        // for (int i=0; i<V; i++) dist[i][i] = 1;
        string line;
        for (int i=0; i<V; i++) {
            cin >> line;
            money.push_back(line);
        }
        int E;
        float c;
        string name1, name2;
        cin >> E;
        for (int i=0; i<E; i++) {
            cin >> name1 >> c >> name2;
            int u = findIdx(name1);
            int v = findIdx(name2);
            dist[u][v] = c;
        }

        cout << "Case " << tc << ": ";
        if (FloyWarshall()) cout << "No\n";
        else cout << "Yes\n"; // has cycle
        money.clear();
        tc++;
    }
    return 0;
}