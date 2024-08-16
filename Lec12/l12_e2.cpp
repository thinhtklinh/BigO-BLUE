// ex2: Pizzamania
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc, n, p, l, r;
    cin >> tc;
    while (tc--) {
        cin >> n >> p;
        vector<int> money(n);
        for (int i=0; i<n; i++) cin >> money[i];
        sort(money.begin(), money.end());
        l = 0, r = n-1;
        int pair = 0;
        while (l < r) {
            if (money[l] + money[r] == p) {
                pair++;
                l++;
                r--;
            }
            else if (money[l] + money[r] < p) l++;
            else r--;
        }
        cout << pair << "\n";
    }
}