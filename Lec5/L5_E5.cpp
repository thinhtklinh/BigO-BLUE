// Ex5: Kefa and Park

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxV 100001
int V, E, catM;
bool visited[maxV]; // visited Vs
bool hasCat[maxV];
int path[maxV];          // previous V of this V
vector<int> graph[maxV]; // adjacent Vs of this V

// BFS, find leaf index, print Path to root && cat node <= m
void BFS(int s) {
    for (int i = 1; i <= V; ++i) {
        visited[i] = 0;
        path[i] = -1;
    }

    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graph[v].size(); ++i) {
            int adja = graph[v][i];
            if (!visited[adja]) {
                visited[adja] = 1;
                q.push(adja);
                path[adja] = v;
            }
        }
    }
}

bool checkPath(int s, int f) {
    int cat = 0;
    bool pre = 0;

    if (path[f] == -1) {
        return 0;
    }

    while (true) {
        if (hasCat[f]) {
            if (pre) cat++;
            else cat = 1;
            pre = 1;
        } else pre = 0;
        if (cat > catM) return 0;
        f = path[f];
        if (f == s) {
            if (hasCat[f]) {
                if (pre) cat++;
                else cat = 1;
            }
            break;
        }
    }
    if (cat > catM) return 0;
    else return 1;
}

void readEdgeList() {
    int u, v;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void ex5() {
    cin >> V >> catM;
    E = V - 1;
    for (int i = 1; i <= V; i++) {
        cin >> hasCat[i];
    }
    readEdgeList();
    // finish location is the lead node: V/2
    BFS(1);

    int leaf = 0;
    for (int i = 1; i <= V; i++) {
        if (graph[i].size() == 1) {
            leaf += checkPath(1, i);
        }
    }
    cout << leaf;
}

int main() {
    ex5();
}