// ex8: Greg and Graph
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<int>> dist;
int V;

int main() {
    int c;
    cin >> V;
    dist = vector<vector<int>>(V, vector<int>(V));
    vector<int> delV(V);
    for (int u=0; u<V; u++) {
        for (int v=0; v<V; v++) {
            cin >> c;
            dist[u][v] = c;
        }
    }

    for (int i=0; i<V; i++) {
        cin >> delV[i];
    }

    int k;
    vector<int> ans(V);
    for (int t=V-1; t>-1; t--) {
        k = delV[t]-1; // add k
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

        int total = 0;
        for (int i=V-1; i>=t; i--) {
            for (int j=V-1; j>=t; j--) {
                int u = delV[i]-1;
                int v = delV[j]-1;
                total += dist[u][v]; 
            }
        }
        ans[t] = total;
    }
    for (int i=0; i<V-1; i++) cout << ans[i] << " ";
    cout << ans[V-1];
    return 0;
}