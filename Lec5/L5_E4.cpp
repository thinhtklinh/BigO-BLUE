#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxV 21
int R, C;
int maze[maxV][maxV];

int BFS(pair<int, int> s) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push(s);
    int cell = 0;
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        int ai, aj;
        for (int i = 0; i < 4; i++) {
            ai = v.first + dx[i];
            aj = v.second + dy[i];
            if (ai < 0 || ai >= R || aj < 0 || aj >= C); // invalid location
            else if (maze[ai][aj] == 1) { // adjacency + not visited
                maze[ai][aj] = 2; // visited
                q.push(make_pair(ai, aj));
                cell++;
            }
        }
    }
    return cell;
}

void ex4() {
    int tc;
    cin >> tc;
    for (int id = 1; id <= tc; id++) {
        cin >> C >> R;
        string row;
        pair<int, int> start;
        for (int i = 0; i < R; i++) {
            cin >> row;
            for (int j = 0; j < C; j++) {
                if (row[j] == '.') maze[i][j] = 1;
                else if (row[j] == '#') maze[i][j] = 0;
                else {
                    start.first = i;
                    start.second = j;
                    maze[i][j] = 2;
                }
            }
        }
        cout << "Case " << id << ": " << BFS(start) + 1;
        if (id != tc) cout << endl;
    }
}

int main() {
    ex4();
}