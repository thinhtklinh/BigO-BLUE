#include <bits/stdc++.h>
using namespace std;

// ex1: MUH and Important Things
// type: unknown

void print(vector<pair<int, int>> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i].second << ' ';
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> input;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input.push_back(make_pair(x, i + 1));
    }
    sort(input.begin(), input.end());
    vector<pair<int, int>> swaps; // number of swapable pair >= 2 -> >= 3 selections
    for (int i = 1; i < n && swaps.size() < 2; i++) {
        if (input[i - 1].first == input[i].first) {
            swaps.push_back(make_pair(i - 1, i)); // pair of idx can be swapped
        }
    }
    if (swaps.size() < 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    print(input);
    swap(input[swaps[0].first], input[swaps[0].second]);
    print(input);
    swap(input[swaps[1].first], input[swaps[1].second]);
    print(input);
}