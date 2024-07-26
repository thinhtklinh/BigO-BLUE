#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool del[100];

int main() {
    int tc, n, m, p;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        queue<pair<int, int>> tasks;
        priority_queue<pair<int, int>> pq;
        for (int i=0; i<n; i++) {
            cin >> p;
            tasks.push(make_pair(p, i));
            pq.push(make_pair(p, i));
        }

        int time = 0;
        while (!tasks.empty()) {
            pair<int, int> t = tasks.front();
            tasks.pop();

            while (del[pq.top().second] == 1) {
                pq.pop();
            }
            
            if (t.first < pq.top().first) {
                tasks.push(t);
            }
            else {
                time++;
                del[t.second] = 1;
                if (t.second == m) break;
            }
        }

        cout << time << '\n';
        for (int i=0; i<n; i++) del[i] = 0;
    }
}