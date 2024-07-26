#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define maxV 50
int R, C;
string maze[maxV];
char alpha; // 65 to 90
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
char stepM;

int DFS(pair<int, int> s) {
    if (maze[s.first][s.second] != alpha) return 0;
    stepM = max(stepM, alpha);
    if (alpha == 'Z') return stepM; // found all
    alpha++;
    for (int i=0; i<8; i++) {
        int ai = s.first + dx[i];
        int aj = s.second + dy[i];
        if (ai < 0 || ai >= R || aj < 0 || aj >= C);
        else if (DFS(make_pair(ai, aj))) return stepM; 
    }
    alpha--;
    if (alpha == 'A') return stepM;
    else return 0;
}

// Ex7: ABC Path
void ex7() {
    int tc = 1;
    cin >> R >> C;
    while (true) {
        for (int i = 0; i<R; i++) {
            cin >> maze[i];
        }

        int maxL = 0, curL;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (maze[i][j] == 'A') {
                    alpha = 'A';
                    stepM = 'A';
                    curL = DFS(make_pair(i, j)) - 64;
                    maxL = max(maxL, curL);
                }
            }
        }

        cout << "Case " << tc << ": " << maxL;
        tc++;
        cin >> R >> C;
        if (R) cout << '\n';
        else break;
    }
}

int main() {
    ex7();
    return 0;
}