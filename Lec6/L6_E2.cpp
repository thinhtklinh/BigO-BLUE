#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define maxV 100000
int V, E;
vector<int> graph[maxV];
bool visited[maxV];
// int path[maxV];

int BFS(int s) {
    queue<int> q;
    visited[s] = 1;
    q.push(s);

    int cnted = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i<graph[v].size(); ++i) {
            int adja = graph[v][i];
            if (!visited[adja]) {
                visited[adja] = 1;
                q.push(adja);
                cnted++;
            }
        }
    }
    return cnted;
}

// Prayatna
void ex2() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> V >> E;
        for (int i=0; i<V; i++) {
            graph[i].clear();
        }

        for (int i=0; i<V; i++) {
            visited[i] = 0;
        } 

        int u, v;
        for (int i=0; i<E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int subG = 0;
        int cnted = 0;
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                cnted += BFS(i);
                subG++;
            }
            if (cnted == V) break;
        }
        // cout << "ans: " << subG;
        cout << subG;
        if (tc) cout << endl;
    }

}

int main() {
    ex2();
    return 0;
}