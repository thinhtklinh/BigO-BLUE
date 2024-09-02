#include <bits/stdc++.h>
using namespace std;
// ex6: Learning Languages
// type: disjoint set union

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

vector<int> lang(101, -1);

int main() {
    int n, m, k, l;
    cin >> n >> m;
    makeSet();
    bool flag = 0; // has at least 1 person know lang
    for (int i=0; i<n; i++) {
        cin >> k;
        while (k--) {
            flag = 1;
            cin >> l;
            if (lang[l] == -1) {
                lang[l] = i;
            }
            else {
                unionSet(i, lang[l]); // connect as they speak same lang
            }
        }
    }

    int gr = 0;
    for (int i=0; i<n; i++) {
        if (findSet(i) == i) gr++;
    }

    if (!flag) cout << gr; 
    else cout << gr-1;
}