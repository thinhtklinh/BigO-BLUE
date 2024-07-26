#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    long long b1, m, n;
    long long total = 0;
    cin >> b1 >> m >> n;
    for (long long i=1; i<=n; i++) {
        total += b1*i;
    }
    int ans = total - m;
    if (ans < 0) cout << 0;
    else cout << ans;
}