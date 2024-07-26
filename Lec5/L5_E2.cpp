#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxV 21
int R, C;
int maze[maxV][maxV];

int hasPath(pair<int, int> s, pair<int, int> f) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push(s);
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        int ai, aj;
        for (int i = 0; i < 4; i++) {
            ai = v.first + dx[i];
            aj = v.second + dy[i];
            if (ai < 0 || ai >= R || aj < 0 || aj >= C); // invalid location
            else if (ai == f.first && aj == f.second) return 1;
            else if (maze[ai][aj] == 1) { // adjacency + not visited
                maze[ai][aj] = 2;
                q.push(make_pair(ai, aj));
            }
        }
    }
    return 0;
}

// Ex2: Validate The Maze
void ex2() {
    int t;
    cin >> t;
    while (t--) {
        cin >> R >> C;
        string row;
        int cnt = 0;
        pair<int, int> start;
        pair<int, int> end;
        int gate = 0;
        for (int i = 0; i < R; i++) {
            cin >> row;
            for (int j = 0; j < C; j++) {
                if (row[j] == '.') {
                    if (i == 0 || j == 0 || i == R - 1 || j == C - 1) {
                        if (gate == 0) start = make_pair(i, j);
                        else end = make_pair(i, j);
                        gate++;
                    }
                    maze[i][j] = 1;
                } else
                    maze[i][j] = 0;
            }
        }
        if (gate != 2) {
            cout << "invalid";
        }
        else {
            if (hasPath(start, end)) cout << "valid";
            else cout << "invalid";
        }

        if (t) cout << endl;
    }
}

int main() {
    ex2();
    return 0;
}