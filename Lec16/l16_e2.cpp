// ex2: Graph Connectivity
#include <iostream>
using namespace std;

#define maxV 26
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
    int tc, V, a, b;
    string line;
    cin >> tc;
    cin.ignore();
    getline(cin, line);
    while (tc--) {
        getline(cin, line);
        V = line[0] - 'A' + 1;
        makeSet();
        while (getline(cin, line) && line != "") {
            a = line[0] - 'A';
            b = line[1] - 'A';
            unionSet(a, b);
        }

        int subG = 0;
        bool group[26] = {0};
        for (int i=0; i<V; i++) {
            int realPar = findSet(parent[i]);
            if (group[realPar] == 0) {
                subG++;
                group[realPar] = 1;
            }
        }

        cout << subG << "\n\n";
    }
}