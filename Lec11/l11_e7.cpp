// ex7: Event Organizer
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 2001
const int INF = -1;
int V;

struct Tuple {
    int v;
    int w;

    Tuple(int vertex, int weight) : v(vertex), w(weight) {};
};

struct option {
    bool operator() (const Tuple& a, const Tuple& b) const {
        return a.w < b.w;
    }
};

vector<Tuple> graph[maxV];
vector<int> dist(maxV, INF);

void dijsktra(int s) {
    fill(dist.begin(), dist.end(), INF);
    priority_queue<Tuple, vector<Tuple>, option> pq; // max heap
    pq.push(Tuple(s, 0));
    dist[s] = 0;
    while (!pq.empty()) {
        Tuple head = pq.top();
        pq.pop();
        if (dist[head.v] != head.w) continue;
        for (int i=0; i<graph[head.v].size(); i++) {
            Tuple adja = graph[head.v][i];
            if (head.w + adja.w > dist[adja.v]) {
                dist[adja.v] = head.w + adja.w;
                pq.push(Tuple(adja.v, dist[adja.v]));
            }
        }
    }   
}

struct Event {
    int s, e, c;
    Event(int start, int end, int cost) : s(start), e(end), c(cost) {};
};

int main() {
    int tc;
    int s, e, c;
    cin >> tc;
    while (tc--) {
        cin >> V;
        vector<Event> events(V+1, Event(0, 0, 0));
        for (int i=1; i<=V; i++) {
            cin >> events[i].s >> events[i].e >> events[i].c;
            graph[0].push_back(Tuple(i, events[i].c));
        }
        for (int u=1; u<=V; u++) {
            for (int v=1; v<=V; v++) {
                if (events[v].s >= events[u].e) graph[u].push_back(Tuple(v, events[v].c));
            }
        }

        dijsktra(0);
        int maxC = -1;
        for (int u=1; u<=V; u++) {
            maxC = max(maxC, dist[u]);
        }
        cout << maxC << '\n';
        for (int i=0; i<=V; i++) {
            graph[i].clear();
        }
    }
}