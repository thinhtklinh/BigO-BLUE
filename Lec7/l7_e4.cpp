#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Topic {
    int id;
    long long diff;
    long long zs;

    Topic(int i, long long d, long long z) : id(i), diff(d), zs(z) {};

    bool operator<(const Topic &other) const {
        return (diff == other.diff && id < other.id) || (diff < other.diff);
    }
};

void ex4() {
    priority_queue<Topic> pq; // max heap
    int n;
    long long id, z, p, l, c, s;
    long long newZ;
    cin >> n;
    while (n--) {
        cin >> id >> z >> p >> l >> c >> s;
        newZ = 50*p + 5*l + 10*c + 20*s;
        pq.push(Topic(id, newZ - z, newZ));
    }
    int i=5;
    while(i--) {
        Topic tmp = pq.top();
        pq.pop();
        cout << tmp.id << ' ' << tmp.zs << '\n';
    }
}

int main() {
    ex4();
    return 0;
}
