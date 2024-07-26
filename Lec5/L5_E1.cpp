#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxV 1001
int V, E;
bool visited[maxV];      // visited Vs
int path[maxV];          // previous V of this V
vector<int> graph[maxV]; // adjacent Vs of this V

void BFS(int s) {
    for (int i=0; i<V; ++i) {
        visited[i] = 0;
        path[i] = -1;
    }

    queue<int> q;
    visited[s] = 1;
    q.push(s);
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i<graph[v].size(); ++i) {
            int adja = graph[v][i];
            if (!visited[adja]) {
                visited[adja] = 1;
                q.push(adja);
                path[adja] = v;
            }
        }
    }
}

int pathLength(int s, int f) {
    int len = 0;
    if (f == s) {
        return 0;
    }

    if (path[f] == -1) {
        return -1;
    }

    while (true) {
        len++;
        f = path[f];
        if (f == s) {
            break;
        }
    }

    return len*6;
}

// Ex1: Breadth First Search: Shortest Reach
void ex1() {
    int q;
    cin >> q;
    while (q--) {
        cin >> V >> E;
        for (int i=0; i<V; i++) graph[i].clear();
        int u, v;
        for (int i = 0; i < E; ++i) {
            cin >> u >> v;
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
        }

        int s;
        cin >> s;
        BFS(s-1);
        for (int i=0; i<V; i++) {
            if (i != s-1) cout << pathLength(s-1, i) << ' ';
        }

        if (q) cout << endl;
    }
}

int main() {
    ex1();
    
    return 0;
}