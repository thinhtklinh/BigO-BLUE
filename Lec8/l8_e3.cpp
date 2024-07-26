// ex3: The Shortest Path
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 10000
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<Tuple> graph[maxV];
// vector<int> dist(maxV, INF);
vector<vector<int>> dist(maxV, vector<int>(maxV, INF));
// int path[maxV];

// for min heap
struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};

void dijsktra(int s) {
    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0));
    dist[s][s] = 0;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
        if (dist[s][head.v] != head.w) continue;
        for (int i=0; i<graph[head.v].size(); i++) {
            Tuple adja = graph[head.v][i];
            if (head.w + adja.w < dist[s][adja.v]) {
                dist[s][adja.v] = head.w + adja.w;
                pq.push(Tuple(adja.v, dist[s][adja.v]));
                // path[adja.v] = head.v;
            }
        }
    }   
}

void ex3() {
    int tc, v, p, b, c, s, f, r;
    string name, name2;
    map<string, int> cities;
    cin >> tc;
    while (tc--) {
        cin >> v;
        for (int i=0; i<v; i++) {
            cin >> name;
            cities[name] = i;
            cin >> p;
            while (p--) {
                cin >> b >> c;
                graph[i].push_back(Tuple(b-1, c));
            }
        }

        cin >> r;
        while(r--) {
            cin >> name >> name2;
            s = cities[name];
            f = cities[name2];
            if (dist[s][f] != INF) {
                cout << dist[s][f] << '\n';
            }
            else {
                dijsktra(s);
                cout << dist[s][f] << '\n';
            }
        }

        for (int i=0; i<v; i++) {
            graph[i].clear();
            for (int j=0; j<v; j++) {
                dist[i][j] = INF;
            }
        }
        cities.clear();
    }
}

int main() {
    ex3();
    return 0;
}