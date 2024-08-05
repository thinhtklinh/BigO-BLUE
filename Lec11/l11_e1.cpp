// ex1: Possible Friends
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 50
const int INF = 1e9;
vector<vector<int>> dist;
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

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string row;
        cin >> row;
        V = row.length();
        dist = vector<vector<int>>(V, vector<int>(V));
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (row[j] == 'Y') dist[i][j] = 1;
                else if (j == i) dist[i][j] = 0;
                else dist[i][j] = INF;
            }
            if (i < V-1) cin >> row;
        }

        FloyWarshall();
        pair<int, int> ans = make_pair(0, 0); // maxPF, id
        for (int i=0; i<V; i++) {
            int PF = 0;
            for (int j=0; j<V; j++) {
                if (dist[i][j] == 2) PF++; // j is PF of i
            }
            if (PF > ans.first) {
                ans.first = PF;
                ans.second = i;
            }
        }
        cout << ans.second << " " << ans.first << "\n";
    }
}