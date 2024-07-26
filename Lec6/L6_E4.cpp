#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define maxV 10001
int V, E;
vector<int> graph[maxV];
vector<int> revG[maxV];
int visited[maxV];

bool DFS(int s) {
    if (graph[s].empty()) {
        visited[s] = 2;
        return 0; // end of path
    }
    visited[s] = 1;
    for (int i=0; i<graph[s].size(); i++) {
        int v = graph[s][i];
        if (visited[v] == 0) {
            int ans = DFS(v);
            if (ans == 1) return 1;
        }
        else if (visited[v] == 1) return 1;
    }
    visited[s] = 2;
    return 0;
}

// Dudu Service Maker
void ex4() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> V >> E;
        for (int i=0; i<V; i++) {
            graph[i].clear();
            revG[i].clear();
            visited[i] = 0;
        }

        int u, v;
        for (int i=0; i<E; i++) {
            cin >> u >> v;
            graph[u-1].push_back(v-1);
            revG[v-1].push_back(u-1);
        }

        int flag = 1;
        for (int i=0; i<V; i++) {
            if (revG[i].size() == 0) {
                // valid start point
                if (DFS(i) == 1) {
                    flag = 1;
                    break;
                }
                else {
                    flag = 0;
                }
            }
        }
        for (int i=0; i<V; i++)
            if (visited[i] != 2) { // uncheck -> has loop
                flag = 1;
                break;
            }
        if (flag) cout << "YES";
        else cout << "NO";

        if (tc) cout << '\n';
    }
}

int main() {
    ex4();
    return 0;
}