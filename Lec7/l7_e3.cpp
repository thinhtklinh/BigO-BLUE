#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void ex3() {
    int n, v;
    long long ans;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n) {
        ans = 0;
        while(n--) {
            cin >> v;
            pq.push(v);
        }

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a+b);
        }

        cout << ans << '\n';
        pq.pop();
        cin >> n;
    }
}

int main() {
    ex3();
    return 0;
}