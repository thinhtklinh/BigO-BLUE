// ex7: Lost And Survived
#include <bits/stdc++.h>
using namespace std;

#define maxV 100000
int parent[maxV];
int ranks[maxV];
int size[maxV];
int sizeCnt[maxV+1];

int minS = 1;
int maxS = 1;

void makeSet() {
    for (int i=0; i<maxV; i++) {
        parent[i] = i;
        ranks[i] = 0;
        size[i] = 1; // everyone is the leader of their own set
    }
}

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v) {
    int paru = findSet(u);
    int parv = findSet(v);
    if (paru == parv) return;

    sizeCnt[size[paru]]--;
    sizeCnt[size[parv]]--;

    if (ranks[paru] > ranks[parv]) {
        parent[parv] = paru;
        size[paru] += size[parv];
        sizeCnt[size[paru]]++;
        if (size[paru] > maxS) maxS = size[paru]; // update maxS
    }
    else {
        parent[paru] = parv;
        if (ranks[paru] == ranks[parv]) ranks[parv]++;
        size[parv] += size[paru];
        sizeCnt[size[parv]]++;
        if (size[parv] > maxS) maxS = size[parv]; // update maxS
    }
}

int main() {
    int V, Q, a, b;
    cin >> V >> Q;
    makeSet();

    sizeCnt[1] = V;
    for (int i=0; i<Q; i++) {
        cin >> a >> b;
        unionSet(a-1, b-1);
        if (sizeCnt[minS] == 0) { // update minS since no group has this size now
            for (int j=minS+1; j<=V; j++) {
                if (sizeCnt[j]) {
                    minS = j;
                    break;
                }
            }
        }
        cout << maxS - minS << "\n";
    }
}