// ex4: War
#include <iostream>
using namespace std;
#define maxV 10000

int parent[maxV*2];
int ranks[maxV*2];

int findSet(int u) {
    if (parent[u] != u) parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSet(int u, int v) {
    int paru = findSet(u);
    int parv = findSet(v);
    if (paru == parv) return;
    if (ranks[paru] > ranks[parv]) parent[parv] = paru;
    else {
        parent[paru] = parv;
        if (ranks[paru] == ranks[parv]) ranks[parv]++;
    }
}

int main() {
    int n, c, x, y;
    cin >> n;

    for (int i=0; i<maxV*2; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }

    while (cin >> c >> x >> y && c) {
        if (c == 1) {
            if (findSet(x) == findSet(y+maxV)) cout << -1 << '\n';
            else {
                unionSet(x, y);
                unionSet(x + maxV, y + maxV);
            }
        }
        else if (c == 2) {
            if (findSet(x) == findSet(y)) cout << -1 << "\n";
            else {
                unionSet(x, y + maxV);
                unionSet(y, x + maxV);
            }
        }
        else if (c == 3) cout << (findSet(x) == findSet(y)) << "\n";
        else cout << (findSet(x) == findSet(y + maxV)) << "\n";
    }
}