#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc, n, x, val;
    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        set<int> bst;
        for (int i=0; i<n; i++) {
            cin >> val;
            bst.insert(val);
        }
        int sz = bst.size();
        if (sz == x) cout << "Good\n";
        else if (sz > x) cout << "Average\n";
        else cout << "Bad\n";
    }
}