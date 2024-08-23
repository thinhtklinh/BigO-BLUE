// ex6: Cthulhu -> ElogV
#include <iostream>
using namespace std;

#define maxV 100
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

// requires: V == E && connected graph

int main() {
    int V, E, x, y;
    cin >> V >> E;
    makeSet();
    for (int i=0; i<E; i++) {
        cin >> x >> y;
        unionSet(x-1, y-1);
    }

    if (V != E) cout << "NO\n";
    else {
        int subG = 0;
        for (int i=0; i<V; i++) if (findSet(i) == i) subG++;
        if (subG == 1) cout << "FHTAGN!";
        else cout << "NO";
    }
}