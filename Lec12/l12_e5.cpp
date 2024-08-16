// Ex5: Monkey and the Oiled Bamboo
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc, n, h;
    cin >> tc;
    for (int i=1; i<=tc;i++) {
        cin >> n;
        vector<int> step(n);
        step[0] = 0;
        for (int j=1; j<=n; j++) {
            cin >> h;
            step[j-1] = h-step[j-1];
            if (j != n) step[j] = h;
        }

        int k = 0;
        for (int j=0; j<n; j++) {
            if (step[j] > k) k = step[j];
            else if (step[j] == k) k++;
        }

        cout << "Case " << i << ": " << k << "\n";
    }
}