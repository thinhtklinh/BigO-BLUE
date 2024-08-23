// ex1: Friends
#include <iostream>
using namespace std;

#define maxV 30000
int parent[maxV];
int ranks[maxV];
int size[maxV];

void makeSet() {
    for (int i=0; i<maxV; i++) {
        parent[i] = i;
        ranks[i] = 0;
        size[i] = 1;
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

    if (ranks[paru] > ranks[parv]) {
        parent[parv] = paru;
        size[paru] += size[parv];
    }
    else if (ranks[paru] < ranks[parv]) {
        parent[paru] = parv;
        size[parv] += size[paru];
    }
    else {
        parent[paru] = parv;
        ranks[parv]++;
        size[parv] += size[paru];
    }
}

int main() {
    int tc, N, M, a, b;
    cin >> tc;
    while (tc--) {
        makeSet();
        cin >> N >> M;
        for (int i=0; i<M; i++) {
            cin >> a >> b;
            unionSet(a-1, b-1);
        }

        int maxS = 0;
        for (int i=0; i<N; i++) maxS = max(maxS, size[i]);
        cout << maxS << "\n";
    }
}