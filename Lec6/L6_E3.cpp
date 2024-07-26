#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define maxV 50
int R, C;
int maze[maxV][maxV];

bool inSide(int x, int y) {
    return x == 0 || x == R-1 || y == 0 || y == C-1;
}

int BFS(pair<int, int> s, int lakeID) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    maze[s.first][s.second] = lakeID;
    
    q.push(s);
    int size = 1;
    int isOcean = 0;
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (int i=0; i<4; ++i) {
            int ai = v.first + dx[i];
            int aj = v.second + dy[i];
            if (ai < 0 || ai >= R || aj < 0 || aj >= C);
            else if (maze[ai][aj] == '.') {
                if (!isOcean && inSide(ai, aj)) isOcean = 1;
                maze[ai][aj] = lakeID;
                q.push(make_pair(ai, aj));
                size++;
            }
        }
    }
    if (!isOcean) return size;
    else return 0;
}

void fillWithLand(pair<int, int> s) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    int lakeID = maze[s.first][s.second];
    maze[s.first][s.second] = '*'; // sure is lakeID
    
    q.push(s);
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (int i=0; i<4; ++i) {
            int ai = v.first + dx[i];
            int aj = v.second + dy[i];
            if (ai < 0 || ai >= R || aj < 0 || aj >= C);
            else if (maze[ai][aj] == lakeID) {
                maze[ai][aj] = '*';
                q.push(make_pair(ai, aj));
            }
        }
    }
}

// Lakes in Berland
void ex3() {
    cin >> R >> C;
    int k;
    cin >> k;
    string row;
    for (int i=0; i<R; i++) {
        cin >> row;
        for (int j=0; j<C; j++) maze[i][j] = row[j]; 
    }

    int lakeID = 50;
    vector<pair<int, int>> lakeS;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (!inSide(i, j) && maze[i][j] == '.') {
                int res = BFS(make_pair(i, j), lakeID);
                if (res) lakeS.push_back(make_pair(res, lakeID));
                lakeID++;
            }
        }
    }

    sort(lakeS.begin(), lakeS.end(), 
    [](const pair<int, int>& a, const pair<int, int>& b) {return a.first < b.first;});

    lakeS.resize(lakeS.size()-k);

    if (!lakeS.empty()) {
        int ans = 0;
        for (int i=0; i<lakeS.size(); i++) {
            ans += lakeS[i].first;
        }
        sort(lakeS.begin(), lakeS.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;});
        
        cout << ans << '\n';
        int l = 0;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (maze[i][j] == lakeS[l].second && l < lakeS.size()) {
                    fillWithLand(make_pair(i, j));
                    l++;
                    cout << '*';
                }
                else if (maze[i][j] != '.' && maze[i][j] != '*') cout << '.';
                else cout << char(maze[i][j]);
            }
            if (i != R-1) cout << '\n';
        }
    }
    else {
        cout << 0 << '\n';
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (maze[i][j] != '.' && maze[i][j] != '*') cout << '.';
                else cout << char(maze[i][j]);
            }
            if (i != R-1) cout << '\n';
        }
    }
}

int main() {
    ex3();
    return 0;
}