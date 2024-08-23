#include <iostream>
using namespace std;

#define maxV 20
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
    int Q, u, v, q;
    cin >> Q;
    makeSet();
    for (int i=0; i<Q; i++) {
        cin >> u >> v >> q;
        if (q == 1) unionSet(u, v);
        else if (q == 2) {
            int paru = findSet(u);
            int parv = findSet(v);
            if (paru == parv) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}