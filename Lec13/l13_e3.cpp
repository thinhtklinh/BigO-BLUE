// ex3: megacity
#include <bits/stdc++.h>
using namespace std;

const int TARGET = 1e6;

int main() {
    int n, k, x, y;
    cin >> n >> k;
    vector<pair<double, int>> city(n);
    for (int i=0; i<n; i++) {
        cin >> x >> y >> city[i].second;
        city[i].first = sqrt(x*x + y*y);
    }
    sort(city.begin(), city.end());
    double r = 0;
    if (k >= TARGET) cout << r;
    for (int i=0; i<n; i++) {
        r = city[i].first;
        k += city[i].second;
        if (k >= TARGET) {
            cout << setprecision(7) << fixed << r;
            break;
        }
    }
    if (k < TARGET) cout << -1;
}