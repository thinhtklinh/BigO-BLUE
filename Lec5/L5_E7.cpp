// Ex7: Ice Cave
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxV 250
int R, C;
int maze[maxV][maxV];

bool BFS(pair<int, int> s, pair<int, int> f) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // 1: .
    // 0: x

    maze[s.first][s.second] = 0;
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

            if (ai == f.first && aj == f.second) {
                if (maze[ai][aj] == 1) {
                    for (int s = 0; s < 4; s++) {
                        int si = ai + dx[s];
                        int sj = aj + dy[s];
                        if ( !(si < 0 || si >= R || sj < 0 || sj >= C) && si && sj) return 1; // has a way to jump back
                    }
                    return 0;
                }
                else {
                    return 1;
                }
            }

            else if (maze[ai][aj] == 1) { // adjacency + not visited
                maze[ai][aj] = 0; // visited
                q.push(make_pair(ai, aj));
            }
        }
    }
    return 0;
}

void ex5() {
    cin >> R >> C;
    string row;
    for (int i=0; i<R; i++) {
        cin >> row;
        for (int j=0; j<C; j++) {
            if (row[j] == '.') maze[i][j] = 1;
            else maze[i][j] = 0;
        }
    }

    pair<int, int> start, end;
    cin >> start.first >> start.second;
    start.first--; start.second--;
    cin >> end.first >> end.second;
    end.first--; end.second--;
    if (BFS(start, end)) cout << "YES";
    else cout << "NO";
}

int main() {
    ex5();
    // pass all but idk why: ????????????
}