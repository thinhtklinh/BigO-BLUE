// ex8: Two Sets -> O(nlogn)
#include <bits/stdc++.h>
using namespace std;

#define maxV 100002
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
    int n, a, b;
    cin >> n >> a >> b;
    int A = 100000, B = 100001;

    vector<int> p(n);
    map<int, int> pos;
    int maxP = -1;
    
    for (int i=0; i<n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
        maxP = max(maxP, p[i]);
    }

    if (maxP >= max(a, b)) cout << "NO\n";
    else {
        makeSet();
        for (int i=0; i<n; i++) {
            if (pos.find(a - p[i]) != pos.end()) unionSet(i, pos[a - p[i]]);
            else unionSet(i, B);

            if (pos.find(b - p[i]) != pos.end()) unionSet(i, pos[b - p[i]]);
            else unionSet(i, A);
        }

        if (findSet(A) == findSet(B)) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=0; i<n; i++) {
                if (findSet(i) == findSet(A)) cout << 0 << " ";
                else cout << 1 << " ";
            }
        }
    }
}
