#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxV 100
int V, E;
bool visited[maxV]; // visited Vs
int path[maxV]; // previous V of this V
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

void printPath(int s, int f) {
    int ans[maxV];
    int i = 0;
    if (f == s) {
        cout << s;
        return;
    }

    if (path[f] == -1) {
        cout << "No path\n";
        return;
    }

    while (true) {
        ans[i++] = f;
        f = path[f];
        if (f == s) {
            ans[i++] = s;
            break;
        }
    }

    while (i--) {
        cout << ans[i] << ' ';
    }
}

void printPathRec(int s, int f) {
    if (s == f) cout << f;
    else {
        if (path[f] == -1) cout << "No path\n";
        else {
            printPathRec(s, path[f]);
            cout << f << ' ';
        }
    }
}

void readAdjacencyMatrix() {
    int mark;
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            cin >> mark;
            if (mark == 1) {
                graph[i].push_back(j);
            }
        }
    }
}

void readEdgeList() {
    // read edge list into graph
    int u, v;
    for (int i=0; i<E; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int main() {
    cin >> V >> E;
    readAdjacencyMatrix();
    readEdgeList();

    int s = 0;
    int f = 5;
    BFS(s);
    printPath(s, f);
    return 0;
}