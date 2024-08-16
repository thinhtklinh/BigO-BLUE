#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> aq(n);
    double sumE = 0;
    int e;
    for (int i=0; i<n; i++) {
        cin >> e;
        aq[i] = e;
        sumE += e;
    }
    double l = 0, r = 1000, m, sumT;
    while (r - l > 1e-7) {
        m = (l+r)/2;
        sumT = 0;
        for (int i=0; i<n; i++) {
            if (aq[i] > m) sumT += aq[i] - m;
        }
        if (m*n < sumE - sumT*k/100) l = m;
        else r = m;
    }
    cout << setprecision(9) << fixed << m;

}