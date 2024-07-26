#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define maxV 100
int V, E;
vector<int> graph[maxV];
bool visited[maxV];
int path[maxV];

void DFS(int src) {
    for (int i=0; i<V; i++) {
        visited[i] = false;
        path[i] = -1;
    }
    stack<int> s;
    visited[src] = true;
    s.push(src);

    while(!s.empty()) {
        int v = s.top();
        s.pop();
        for (int i=0; i<graph[v].size(); i++) {
            int adja = graph[v][i];
            if (!visited[adja]) {
                visited[adja] = true;
                s.push(adja);
                path[adja] = v;
            }
        }
    }
}

void DFSRec(int s) {
    visited[s] = 1;
    for (int i=0; i<graph[s].size(); i++) {
        int v = graph[s][i];
        if (!visited[v]) {
            path[v] = s;
            DFSRec(v);
        }
    }
}

int main() {
    int u, v;
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s = 0;
    int f = 5;
    DFS(s);
    DFSRec(s);
    // printPath(s, f);
    return 0;
}

