#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxV 100001
int dist[maxV];

int generateNode(int s, int f, vector<int> keys) {
    for (int i=0; i<maxV; i++) dist[i] = -1;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i<keys.size(); i++) {
            int adja = ((long long)v*keys[i]) % 100000;
            if (dist[adja] == -1) {
                q.push(adja);
                dist[adja] = dist[v] + 1;
            }
            if (adja == f) return dist[adja];
        }
    }
    return -1;
}

void ex3() {
    int mkey, lock, N;
    cin >> mkey >> lock;
    cin >> N;
    vector<int> keys(N);
    for (int i=0; i<N; i++) {
        cin >> keys[i];
    }
    cout << generateNode(mkey, lock, keys);
}

int main() {
    ex3();
    return 0;
}