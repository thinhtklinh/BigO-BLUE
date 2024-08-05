#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define maxV 200
int V, E;
vector<string> dict;
vector<int> dist(maxV);
vector<int> graph[maxV];

bool hasEdge(string s1, string s2) {
    if (s1.length() != s2.length()) return 0;
    bool dif = 0;
    for (int i=0; i<s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (dif) return 0;
            else dif = 1;
        }
    }
    if (dif) return 1;
    else return 0;
}

int findWordIdx(string w) {
    for (int i=0; i<dict.size(); i++) {
        if (dict[i] == w) return i;
    }
    return -1;
}

void BFS(int s, int f) {
    fill(dist.begin(), dist.end(), -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int &adja : graph[v]) {
            if (dist[adja] == -1) {
                dist[adja] = dist[v] + 1;
                q.push(adja);
            }

            if (adja == f) return;
        }
    }
}

int main() {
    int tc;
    string word, line, word2;
    cin >> tc;
    while (tc--) {
        while (cin >> word && word != "*") {
            dict.push_back(word);
        }

        V = dict.size();
        for (int i=0; i<V-1; i++) {
            for (int j=i+1; j<V; j++) {
                if (hasEdge(dict[i], dict[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        cin.ignore();
        while (getline(cin, line) && line != "") {
            stringstream ss(line);
            ss >> word >> word2;
            int s = findWordIdx(word);
            int f = findWordIdx(word2);
            BFS(s, f); // moi lan duyet tu 1 diem khac -> reset dist[]
            cout << word << " " << word2 << " " << dist[f] << '\n';
        }

        if (tc) cout << '\n';
        
        for (int i=0; i<V; i++) {
            graph[i].clear();
        }
        dict.clear();
    }

    return 0;
}