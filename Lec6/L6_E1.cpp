#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxV 1001
int V, E;
bool visited[maxV]; // visited Vs
int path[maxV]; // previous V of this V
vector<int> graph[maxV]; // adjacent Vs of this V

// DFS and BFS are oke cause this is a tree
// tính chất: đồ thị liên thông n đỉnh và n - 1 cạnh là cây

void BFS(int s) {
    for (int i=0; i<V; ++i) {
        visited[i] = 0;
        path[i] = -1;
    }

    queue<int> q;
    visited[s] = 1;
    q.push(s);
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i<graph[v].size(); ++i) {
            int adja = graph[v][i];
            if (!visited[adja]) {
                visited[adja] = 1;
                q.push(adja);
                path[adja] = v;
            }
        }
    }
}

int printPath(int s, int f) {
    int ans = 0;
    int i = 0;
    if (f == s) {
        cout << s;
        return 0;
    }

    if (path[f] == -1) {
        return -1;
    }

    while (true) {
        ans++;
        f = path[f];
        if (f == s) {
            break;
        }
    }

    return ans;
}

void printPathRec(int s, int f) {
    if (s == f) cout << f;
    else {
        if (path[f] == -1) cout << "No path\n";
        else {
            printPathRec(s, path[f]);
            cout << f << ' ';
        }
    }
}

void readEdgeList() {
    // read edge list into graph
    int u, v;
    for (int i=0; i<E; ++i) {
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
}

int main() {
    cin >> V;
    E = V - 1;
    readEdgeList();
    int Q;
    cin >> Q;
    vector<int> targets;
    int tmp;
    while (Q--) {
        cin >> tmp;
        targets.push_back(tmp-1);
    }

    int s = 0;
    BFS(s);
    int lenmin = 1003;
    int choice = -1;

    for (int i=0; i<targets.size(); i++) {
        int len = printPath(s, targets[i]);
        if (len < lenmin || (len == lenmin && targets[i] < choice)) {
            choice = targets[i];
            lenmin = len;
        }
    }
    cout << choice+1;
    return 0;
}