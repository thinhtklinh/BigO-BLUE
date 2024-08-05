// ex2: Meeting Prof.Miguel
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 26
const int INF = 1e9;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

vector<int> distY(maxV);
vector<int> distM(maxV);
vector<Tuple> graphY[maxV];
vector<Tuple> graphM[maxV];
int V;

struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w > b.w;
    }
};

void dijsktra(int s, vector<int>& dist, vector<Tuple>* graph) {
    fill(dist.begin(), dist.end(), INF);

    priority_queue<Tuple, vector<Tuple>, option> pq;
    pq.push(Tuple(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
        if (dist[head.v] != head.w) continue;
        for (int i=0; i<graph[head.v].size(); i++) {
            Tuple adja = graph[head.v][i];
            if (head.w + adja.w < dist[adja.v]) {
                dist[adja.v] = head.w + adja.w;
                pq.push(Tuple(adja.v, dist[adja.v]));
            }
        }
    }   
}


int main() {
    char t, p, a, b, y, m;
    int c;
    while (cin >> V && V != 0) {
        for (int i=0; i<V; i++) {
            cin >> t >> p >> a >> b >> c;
            if (t == 'Y') {
                graphY[a-65].push_back(Tuple(b-65, c));
                if (p == 'B') graphY[b-65].push_back(Tuple(a-65, c));
            }
            else {
                graphM[a-65].push_back(Tuple(b-65, c));
                if (p == 'B') graphM[b-65].push_back(Tuple(a-65, c));
            }
        }
        cin >> y >> m;
        dijsktra(y-65, distY, graphY); // search path for Young
        dijsktra(m-65, distM, graphM); // search path for Middle

        stack<pair<int, char>> ans; // min dist, location
        for (int i=0; i<maxV; i++) {
            if (distY[i] != INF && distM[i] != INF) {
                int cost = distY[i] + distM[i];
                pair<int, char> tmp = make_pair(cost, i+65);
                if (ans.empty()) ans.push(tmp);
                else if (cost <= ans.top().first) {
                    while (!ans.empty() && ans.top().first > tmp.first) ans.pop();
                    ans.push(tmp);
                }
            }
        }

        if (ans.empty()) cout << "You will never meet.\n";
        else {
            string out = "";
            int minD = ans.top().first;
            while (!ans.empty()) {
                pair<int, char> tmp = ans.top();
                out = " " + string(1, tmp.second) + out;
                ans.pop();
            }
            cout << minD << out << '\n';
        }

        for (int i=0; i<maxV; i++) {
            graphM[i].clear();
            graphY[i].clear();
        }
    }
}