// Ex7: I Can Guess the Data Structure
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ex7() {
    int n, t, v;
    stack<int> stac;
    queue<int> cute;
    priority_queue<int> pq;
    while (cin >> n) {
        bool fs, fc, fp;
        fs = fc = fp = 1;
        for (int i=0; i<n; i++) {
            cin >> t >> v;
            if (t == 1) {
                if (fs) stac.push(v);
                if (fc) cute.push(v);
                if (fp) pq.push(v);
            }
            else {
                if (fs) {
                    if (stac.top() != v) fs = 0;
                    else stac.pop();
                }
                if (fc) {
                    if (cute.front() != v) fc = 0;
                    else cute.pop();
                }
                if (fp) {
                    if (pq.top() != v) fp = 0;
                    else pq.pop();
                }
            }
        }
        if (fs + fc + fp > 1) cout << "not sure\n";
        else if (fs + fc + fp == 0) cout << "impossible\n";
        else {
            if (fs) cout << "stack\n";
            else if (fc) cout << "queue\n";
            else cout << "priority queue\n";
        }

        while (!stac.empty()) stac.pop();
        while (!cute.empty()) cute.pop();
        while (!pq.empty()) pq.pop();
    }
}

int main() {
    ex7();
    return 0;
}