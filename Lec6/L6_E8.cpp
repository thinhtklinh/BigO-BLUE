#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define maxV 50000
int V, E;
vector<pair<int, int>> graph[maxV]; // end, len
long long dist[maxV];
long long maxD;
int leaf;

void DFS(int src) {
    fill(dist, dist+maxV, -1);
    stack<int> s;
    dist[src] = 0;
    s.push(src);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        for (int i=0; i<graph[v].size(); i++) {
            int adja = graph[v][i].first;
            int len = graph[v][i].second;

            if (dist[adja] == -1) {
                dist[adja] = dist[v] + len;
                s.push(adja);

                if (dist[adja] > maxD) {
                    maxD = dist[adja];
                    leaf = adja;
                }
            }
        }
    }

}

void ex8() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> V;
        E = V - 1;
        for (int i=0; i<V; i++) {
            graph[i].clear();
        }

        int u, v, l;
        for (int i=0; i<E; i++) {
            cin >> u >> v >> l;
            graph[u-1].push_back(make_pair(v-1, l));
            graph[v-1].push_back(make_pair(u-1, l));
        }

        maxD = 0;
        DFS(0);
        DFS(leaf);
        cout << maxD;
        if (tc) cout << '\n';
    }
}

int main() {
    ex8();
    return 0;
}

