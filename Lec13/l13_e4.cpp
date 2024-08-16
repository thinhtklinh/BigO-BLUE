// ex4: Monk and his Friends
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc, n, m;
    long long v;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        set<long long> s;
        for (int i=0; i<n; i++) {
            cin >> v;
            s.insert(v);
        }
        for (int i=0; i<m; i++) {
            cin >> v;
            if (s.find(v) == s.end()) {
                cout << "NO\n";
                s.insert(v);
            }
            else cout << "YES\n";
        }
    }
}