// ex4: War
#include <bits/stdc++.h>
using namespace std;

#define maxV 10000
int parent[maxV];
int ranks[maxV];
vector<int> enermy(maxV, -1);
int V;

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

    if (ranks[paru] > ranks[parv]) {
        parent[parv] = paru;
        if (enermy[paru] == -1) enermy[paru] = enermy[parv];
        else if (enermy[parv] != -1) { // u and v have different enermy set, so their enermies must be friends now
            unionSet(enermy[paru], enermy[parv]);
        }
    }
    else {
        parent[paru] = parv;
        if (ranks[paru] == ranks[parv]) ranks[parv]++;
        if (enermy[parv] == -1) enermy[parv] = enermy[paru];
        else if (enermy[paru] != -1) { // u and v have different enermy set, so their enermies must be friends now
            unionSet(enermy[paru], enermy[parv]);
        }
    }
}

int main() {
    int c, x, y;
    cin >> V;
    makeSet();
    while (cin >> c >> x >> y && c != 0) {
        int parx = findSet(x);
        int pary = findSet(y);
        if (c == 1) { // set friends
            if (enermy[parx] != -1 && findSet(enermy[parx]) == pary) cout << -1 <<"\n"; 
            else unionSet(parx, pary);
        }
        else if (c == 2) { // set enermies
            if (parx == pary) cout << -1 << "\n";
            else {
                if (enermy[parx] != -1) unionSet(pary, enermy[parx]);
                else enermy[parx] = pary;
                
                if (enermy[pary] != -1) unionSet(parx, enermy[pary]);
                else enermy[pary] = parx;
            }
        }
        else if (c == 3) cout << (parx == pary ? 1 : 0 ) << "\n";
        else {
            if (enermy[parx] != -1 && findSet(enermy[parx]) == pary) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}

