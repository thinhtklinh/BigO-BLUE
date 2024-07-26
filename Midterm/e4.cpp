#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 1001
int R, C;
bool maze[maxV][maxV];
pair<int, int> path[maxV][maxV];

void BFS(pair<int, int> s, pair<int, int> f) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    maze[s.first][s.second] = 0;
    q.push(s);
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        int ai, aj;
        for (int i = 0; i < 4; i++) {
            ai = v.first + dx[i];
            aj = v.second + dy[i];
            if (ai < 0 || ai >= R || aj < 0 || aj >= C); // invalid location
            else if (maze[ai][aj] == 0) { // adjacency + not visited
                maze[ai][aj] = 1; // visited
                q.push(make_pair(ai, aj));
                path[ai][aj] = make_pair(v.first, v.second);
                // if (ai == f.first && aj == f.second) return;
            }
        }
    }
}

void printTime(pair<int, int> s, pair<int, int> f) {
    int time = 0;
    if (f == s) {
        cout << 0 << '\n';
        return;
    }

    while (true) {
        f = path[f.first][f.second];
        time++;
        if (f == s) {
            break;
        }
    }
    cout << time << '\n';
}

int main() {
    cin >> R >> C;
    pair<int, int> s, f;
    while (R) {
        int b;
        cin >> b;
        while(b--) {
            int r, bomN, c;
            cin >> r >> bomN;
            while (bomN--) {
                cin >> c;
                maze[r][c] = 1; // has bom
            }
        }

        cin >> s.first >> s.second;
        cin >> f.first >> f.second;
        BFS(s, f);
        printTime(s, f);

        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j)  {
                path[i][j] = make_pair(-1, -1);
                maze[i][j] = 0;
            }
        }
        cin >> R >> C;
    }

    return 0;
}