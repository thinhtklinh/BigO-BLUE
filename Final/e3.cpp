// ex3: Ubiquitous Religions
#include <bits/stdc++.h>
using namespace std;
// Disjoint set union

#define maxV 50000
int parent[maxV];
int ranks[maxV];

void makeSet() {
    for (int i=0; i<maxV; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findSet(int u) {
    if (parent[u] != u) parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSet(int u, int v) {
    int paru = findSet(u);
    int parv = findSet(v);
    if (paru == parv) return;

    if (ranks[paru] > ranks[parv]) parent[parv] = paru;
    else if (ranks[paru] < ranks[parv]) parent[paru] = parv;
    else {
        parent[paru] = parv;
        ranks[parv]++;
    }
}

int main() {
    int n, m, tc = 1, a, b;
    while (cin >> n >> m && n) {
        makeSet();
        for (int i=0; i<m; i++) {
            cin >> a >> b;
            unionSet(a-1, b-1);
        }
        int group = 0;
        for (int i=0; i<n; i++) {
            if (findSet(i) == i) group++;
        }
        cout << "Case " << tc++ << ": " << group << "\n";
    }
}