#include <bits/stdc++.h>
using namespace std;
// ex2: Fibsieve Fantabulous
// type: unknown

pair<int, int> find(int s) {
    long long step = 2;
    long long layer = 1;
    long long cell = 1;
    while (cell < s) {
        cell += step;
        step += 2;
        layer++;
    }
    pair<int, int> ans;
    if (cell - s < layer) {
        if (layer % 2 == 0) {
            ans.second = layer;
            ans.first = layer - (cell - s);
        }
        else {
            ans.first = layer;
            ans.second = layer - (cell - s);
        }
    }
    else {
        layer--;
        cell = cell - (step-2);
        if (layer % 2 == 0) {
            ans.second = layer - (s - cell);
            ans.first = layer;
        }
        else {
            ans.first = layer - (s - cell);
            ans.second = layer;
        }
    }

    return ans;
}

int main() {
    long long tc, s;
    cin >> tc;
    for (int t=1; t<=tc; t++) {
        cin >> s;
        pair<int, int> out = find(s);
        cout << "Case " << t << ": " << out.first << " " << out.second << "\n";
    }
}