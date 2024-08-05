// ex6: Asterix and Obelix
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<int>> dist;
vector<vector<int>> maxC;
int V;

void FloyWarshall() {
    int loop = 2;
    while (loop--) {
        for (int k=0; k<V; k++) {
            for (int i=0; i<V; i++) {
                if (dist[i][k] == INF) continue;
                for (int j=0; j<V; j++) {
                    if (dist[k][j] == INF) continue;
                    int mf = max(maxC[i][k], maxC[k][j]);
                    if (dist[i][j] + maxC[i][j] > dist[i][k] + dist[k][j] + mf) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        maxC[i][j] = mf;
                    }
                }
            }
        }
    }
}

int main() {
    int E, Q, a, b, c;
    int tc=1;
    while (cin >> V && V != 0) {
        dist = vector<vector<int>>(V, vector<int>(V));
        maxC = vector<vector<int>>(V, vector<int>(V));
        vector<int> pCost(V);
        cin >> E >> Q;
        for (int i=0; i<V; i++) {
            cin >> pCost[i];
        }

        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                maxC[i][j] = max(pCost[i], pCost[j]);
                dist[i][j] = INF;
            }
        }

        for (int i=0; i<E; i++) {
            cin >> a >> b >> c;
            dist[a-1][b-1] = dist[b-1][a-1] = c;
        }

        FloyWarshall();

        cout << "Case #" << tc++ << "\n";
        for (int i=0; i<Q; i++) {
            cin >> a >> b;
            cout << (dist[a-1][b-1] == INF ? -1 : dist[a-1][b-1] + maxC[a-1][b-1]) << '\n';  
        }
        
        cout << "\n";
    }
}