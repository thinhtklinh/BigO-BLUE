#include <iostream>
#include <queue>
#include <vector>
using namespace std;


void ex1() {
    int n, a;
    long long f, s, t;
    cin >> n;
    priority_queue<int> pq;
    for (int i=0; i<n; i++) {
        cin >> a;
        pq.push(a);
        if (pq.size() < 3) cout << -1 << '\n';
        else {
            f = pq.top();
            pq.pop();
            s = pq.top();
            pq.pop();
            t = pq.top();
            pq.pop();
            cout << f*s*t << '\n';
            pq.push(f);
            pq.push(s);
            pq.push(t);
        } 
    }
}

int main() {
    ex1();
    return 0;
}