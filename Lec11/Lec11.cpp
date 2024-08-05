#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 100
const int INF = 1e9;
vector<vector<int>> graph;
vector<vector<int>> dist;
vector<vector<int>> path;
int V;

void printPath(int s, int f) {
    if (s == f) {
        cout << f << " ";
        return;
    }
    if (path[s][f] == -1) {
        cout << "No path";
        return;
    }
    printPath(s, path[s][f]);
    cout << f << " ";
}

void printSol() {
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            if (i!=j) {
                cout << i << " -> " << j << ": ";
                printPath(i, j);
                cout << '\n';

                if (path[i][j] != -1) {
                    cout << "Dist: " << dist[i][j] << "\n";
                }
            }
        }
    }
}

bool FloyWarshall() {
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j) path[i][j] = i;
            else path[i][j] = -1;
        }
    }

    for (int k=0; k<V; k++) {
        for (int i=0; i<V; i++) {
            if (dist[i][k] == INF) continue;
            for (int j=0; j<V; j++) {
                if (dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    for (int i=0; i<V; i++) {
        if (dist[i][i] < 0) return false;
    }
    return true; // exist neg cycle
}

int main() {
    int tmp;
    cin >> V;
    graph = vector<vector<int>>(V, vector<int>(V));
    dist = vector<vector<int>>(V, vector<int>(V));
    path = vector<vector<int>>(V, vector<int>(V));

    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            cin >> tmp;
            if (tmp == 0 && i != j) graph[i][j] = INF; // not connected
            else graph[i][j] = tmp;
        }
    }

    if (FloyWarshall()) printSol();
    else cout << "Negative weight cycle exists";
    return 0;
}