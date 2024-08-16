// ex8: Solve It -> not solved
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int p, q, r, s, t, u;

double calc(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
}

int main() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (calc(0) < 0 || calc(1) > 0) cout << "No solution\n";
        else {
            double l=0, r=1, x;
            int loop = 100;
            while (loop--) {
                x = (l+r)/2;
                double f = calc(x);
                if (f > 0) l = x;
                else r = x;
            }
            cout << setprecision(4) << fixed << x << '\n';
        }
    }
}