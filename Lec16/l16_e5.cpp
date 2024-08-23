// ex5: Ice skating
#include <bits/stdc++.h>
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

bool isConnected(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first == b.first || a.second == b.second;
}

int main() {
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> snow(n);
    for (int i=0; i<n; i++) {
        cin >> snow[i].first >> snow[i].second;
    }
    
    makeSet();
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (isConnected(snow[i], snow[j])) unionSet(i, j);
        }
    }

    // count subset
    int subG = 0;
    bool group[100] = {0};
    for (int i=0; i<n; i++) {
        int realPar = findSet(parent[i]);
        if (group[realPar] == 0) {
            subG++;
            group[realPar] = 1;
        }
    }

    cout << subG-1;
}