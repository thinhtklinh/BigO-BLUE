// ex3: Forests
#include <bits/stdc++.h>
using namespace std;

#define maxV 99
int parent[maxV];
int ranks[maxV];
int P, T;

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

bool sameSet(const bool *a, const bool *b) {
    for (int i=0; i<T; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    int tc, a, b;
    string line;
    cin >> tc;
    cin.ignore();
    getline(cin, line);
    while (tc--) {
        getline(cin, line);
        stringstream ss(line);
        ss >> P >> T;

        bool IHearJ[99][99] = {0};
        while (getline(cin, line) && line != "") {
            stringstream ss(line);
            ss >> a >> b;
            IHearJ[a-1][b-1] = 1;
        }
        
        makeSet();
        for (int i=0; i<P-1; i++) {
            for (int j=i+1; j<P; j++) {
                if (findSet(i) != findSet(j) && sameSet(IHearJ[i], IHearJ[j])) {
                    unionSet(i, j);
                }
            }
        }

        int subG = 0;
        bool group[99] = {0};
        for (int i=0; i<P; i++) {
            int realPar = findSet(parent[i]);
            if (group[realPar] == 0) {
                subG++;
                group[realPar] = 1;
            }
        }

        cout << subG << "\n\n";
    }
}