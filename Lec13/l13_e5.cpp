// ex5: Penguins
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string type;
    cin >> n;
    cin.ignore();
    map<string, int> pens;
    while (n--) {
        getline(cin, type);
        if (pens.find(type) == pens.end()) pens[type] = 1;
        else pens[type] += 1;
    }

    pair<string, int> ans = make_pair("-1", -1);
    map<string, int>::iterator it;
    for (it = pens.begin(); it != pens.end(); it++) {
        if (it->second > ans.second) {
            ans.second = it->second;
            ans.first = it->first;
        }
    }

    cout << ans.first;
}