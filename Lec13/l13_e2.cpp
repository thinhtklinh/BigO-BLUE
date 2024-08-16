#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5;

int main() {
    int n;
    cin >> n;
    vector<vector<string>> teams(n, vector<string>(3));
    map<string, int> id;

    for (int i=0; i<n; i++) {
        cin >> teams[i][0] >> teams[i][1] >> teams[i][2];
        vector<string>& names = teams[i];
        int flag = INF;
        for (int j=0; j<3; j++) {
            if (names[j] == "Isenbaev") id["Isenbaev"] = 0;
            else if (id.find(names[j]) != id.end()) {
                flag = min(id[names[j]], flag);
            }
            else id[names[j]] = INF; // created with -1 (no link)
        }
        if (flag != INF) { // might need update
            for (int j=0; j<3; j++) {
                id[names[j]] = min(id[names[j]], flag+1);
            }
        }
    }

    for (int l=0; l<n-2; l++) {
        for (int i=0; i<n; i++) {
            vector<string>& names = teams[i];
            int flag = INF;
            for (int j=0; j<3; j++) {
                flag = min(id[names[j]], flag); // all names are created in map
            }
            if (flag != INF) { // might need update
                for (int j=0; j<3; j++) {
                    id[names[j]] = min(id[names[j]], flag+1);
                }
            }
        }
    }

    map<string, int>::iterator it;
    for (it = id.begin(); it != id.end(); it++) {
        cout << it->first << " ";
        if (it->second == INF) cout << "undefined\n";
        else cout << it->second<<'\n';
    }

    return 0;
}