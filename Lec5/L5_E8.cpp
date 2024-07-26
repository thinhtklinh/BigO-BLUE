// Ex8: Sheep
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define maxV 250 
int R, C;
string maze[maxV];
// # rao
// . path
// k cuu
// v soi

bool inSide(int x, int y) {
    return x == 0 || x == R-1 || y == 0 || y == C-1;
}

pair<int, int> BFS(pair<int, int> s) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    bool section = 1;
    int sheep = 0;
    int wolf = 0;

    queue<pair<int, int>> q;
    q.push(s);
    if (maze[s.first][s.second] == 'k') sheep++;
    else if (maze[s.first][s.second] == 'v') wolf++;
    maze[s.first][s.second] = '#'; // visited
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        if (section && inSide(v.first, v.second)) section = 0;
        int ai, aj;
        for (int i = 0; i<4; i++) {
            ai = v.first + dx[i];
            aj = v.second + dy[i];
            if (ai < 0 || ai >= R || aj < 0 || aj >= C);
            else if (maze[ai][aj] == '#');
            else {
                if (maze[ai][aj] == 'k') sheep++;
                else if (maze[ai][aj] == 'v') wolf++;
                maze[ai][aj] = '#';
                q.push(make_pair(ai, aj));
            }
        }
    }

    pair<int, int> alive; // sheep, wolf
    if (section) {
        if (sheep > wolf) {
            alive.first = sheep;
            alive.second = 0;
        }
        else {
            alive.first = 0;
            alive.second = wolf;
        }
    }
    else {
        alive.first = sheep;
        alive.second = wolf;
    }
    return alive;
}

void ex8() {
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        cin >> maze[i];
    }

    int aliveS = 0;
    int aliveW = 0;
    pair<int, int> ans;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (maze[i][j] != '#') {
                ans = BFS(make_pair(i, j));
                aliveS += ans.first;
                aliveW += ans.second;
            }
        }
    }

    cout << aliveS << ' ' << aliveW; 
}

int main() {
    ex8();
    return 0;
}