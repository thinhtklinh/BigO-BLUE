#include <iostream>
#include <vector>
// #include <stack>
using namespace std;

#define maxV 10000
int V, E;
vector<int> graph[maxV];
int visited[maxV];

int DFS(int s) {
    visited[s] = 1;
    for (int i=0; i<graph[s].size(); i++) {
        int v = graph[s][i];
        if (!visited[v]) {
            visited[s] += DFS(v);
        }
    }
    return visited[s];
}

// Ex5: The Last Shot
void ex5() {
    cin >> V >> E;
    int u, v;
    for (int i=0; i<E; i++) {
        cin >> u >> v;
        if (u != v) graph[u-1].push_back(v-1);
    }

    int maxD = 1, curD;
    for (int i=0; i<V; i++) {
        int curD = DFS(i);
        maxD = max(curD, maxD);
        for (int j=0; j<V; j++) {
            visited[j] = 0;
        }
    }
    cout << maxD;
}

int main() {
    ex5();
    return 0;
}