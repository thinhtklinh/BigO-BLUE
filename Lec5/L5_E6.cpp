// Ex6: Slick
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxV 250
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

void ex5() {
    cin >> R >> C;
    while (R) {
        string row;
        int cnt = 0;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin >> maze[i][j];
                if (maze[i][j]) cnt++;
            }
        }

        vector<int> ans(R*C+1);
        int vet = 0;
        for (int i=0; i<R && cnt; i++) {
            for (int j=0; j<C && cnt; j++) {
                if (maze[i][j] == 1) {
                    maze[i][j] = 2;
                    int val = BFS(make_pair(i, j)) + 1;
                    vet++;
                    ans[val] += 1;
                    cnt -= val;
                    // if (cnt == 0) break;
                }
            }
        }

        cout << vet << '\n';
        for (int i=0; i<ans.size(); i++) {
            if (ans[i] != 0) cout << i << ' ' << ans[i] << '\n';
        }

        cin >> R >> C;
    }
}

int main() {
    ex5();
}