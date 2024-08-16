// ex7: Hardwood Species
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    int tc;
    string line;
    cin >> tc;
    cin.ignore();
    getline(cin, line);
    while (tc--) {
        map<string, int> tree;
        int total = 0;
        while (getline(cin, line) && line != "") {
            if (tree.find(line) == tree.end()) tree[line] = 1;
            else tree[line] += 1;
            total += 1;
        }

        map<string, int>::iterator it;
        for (it=tree.begin(); it!=tree.end(); it++) {
            cout << it->first << " " << setprecision(4) << fixed << it->second*100.0 / total << "\n";
        }
        cout << "\n";
    }
}