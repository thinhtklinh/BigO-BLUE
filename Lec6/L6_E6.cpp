#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define maxV 100
int R, C;
string maze[maxV];
bool visited[maxV][maxV];
string target = "ALLIZZWELL";
int c;
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

int DFS(pair<int, int> s) {
    if (maze[s.first][s.second] != target[c]) return 0;
    if (c == target.size()-1) return 1; // found all
    visited[s.first][s.second] = 1; // choose it
    c++;
    for (int i=0; i<8; i++) {
        int ai = s.first + dx[i];
        int aj = s.second + dy[i];
        if (ai < 0 || ai >= R || aj < 0 || aj >= C);
        else if (!visited[ai][aj]) {
            int signal = DFS(make_pair(ai, aj)); 
            if (signal == 1) return 1;
            else if (signal == -1) return -1;
        }
    }
    c--;
    visited[s.first][s.second] = 0;
    if (c == -1) return -1;
    return 0;
}

// Ex6: ALL IZZ WELL
void ex6() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> R >> C;
        for (int i=0; i<R; i++) {
            cin >> maze[i];
        }

        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) visited[i][j] = 0;
        }

        bool flag = 0;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (maze[i][j] == 'A') {
                    c = 0;
                    if (DFS(make_pair(i, j)) == 1) {
                        flag = 1;
                        break;
                    }
                }
            }
        }

        if (flag) cout << "YES";
        else cout << "NO";

        if (tc) {
            cout << '\n';
        }
    }
}

int main() {
    ex6();
    return 0;
}