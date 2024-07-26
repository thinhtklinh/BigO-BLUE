// Ex5: Promotion
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Bill {
    int id;
    int val;

    Bill(int i, int v) : id(i), val(v) {};
    
    bool operator<(const Bill& other) const {
        return val < other.val;
    }
};

struct option {
    bool operator() (const Bill& a, const Bill& b) {
        return a.val > b.val;
    }
};

priority_queue<Bill> maxHip;
priority_queue<Bill, vector<Bill>, option> minHip;
bool used[1000000];

void ex5() {
    int n, k, b;
    long long total = 0;
    int id = 0;
    cin >> n;
    while (n--) {
        cin >> k;
        while(k--) {
            cin >> b;
            maxHip.push(Bill(id, b));
            minHip.push(Bill(id, b));
            id++;
        }
        while (used[maxHip.top().id]) maxHip.pop();
        while (used[minHip.top().id]) minHip.pop();

        total += maxHip.top().val - minHip.top().val;
        used[maxHip.top().id] = 1;
        maxHip.pop();
        
        used[minHip.top().id] = 1;
        minHip.pop();
    }
    cout << total;
}

int main() {
    ex5();
    return 0;
}