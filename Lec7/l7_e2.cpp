#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> hip;

void heapDown(int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < hip.size() && hip[l] < hip[smallest]) smallest = l;
    if (r < hip.size() && hip[r] < hip[smallest]) smallest = r;
    if (smallest != i) {
        swap(hip[i], hip[smallest]);
        heapDown(smallest);
    }
}

void heapUp(int i) {
    while (i > 0 && hip[(i-1)/2] > hip[i]) {
        swap(hip[i], hip[(i-1)/2]);
        i = (i-1)/2;
    }
}

void push(int val) {
    hip.push_back(val);
    heapUp(hip.size() - 1);
}

void ex2_TLE() {
    int q;
    int t, n;
    hip.clear();
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> t;
        if (t == 1) {
            cin >> n;
            push(n);
        }
        else if (t == 2) {
            cin >> n;
            for (int j=0; j<hip.size(); j++) {
                if (hip[j] == n) {
                    if (j == hip.size()-1 || hip.size() == 1) {
                        hip.pop_back();
                    }
                    else {
                        hip[j] = hip[hip.size()-1];
                        hip.pop_back();
                        heapDown(j);
                        heapUp(j);
                    }
                    break;
                }
            }
        }
        else {
            cout << hip[0] << '\n';
        }
    }
}

// void ex2_2() {
//     long long q;
//     long long t, n;
//     cin >> q;
//     vector<long long> h;
//     make_heap(h.begin(), h.end(), greater<long long>());
//     for (int i=0; i<q; i++) {
//         cin >> t;
//         if (t == 1) {
//             cin >> n;
//             h.push_back(n);
//             push_heap(h.begin(), h.end(), greater<long long>());
//         }
//         else if (t == 2) {
//             cin >> n;
//             vector<long long>::iterator it;
//             for (it = h.begin(); it!=h.end(); it++) {
//                 if (*it == n) {
//                     h.erase(it);
//                     break;
//                 }
//             }
//             make_heap(it, h.end(), greater<long long>());
//         }
//         else {
//             cout << h[0] << '\n';
//         }
//     }
// }

void ex2() {
    priority_queue<int, vector<int>, greater<int>> pq, pqDel;
    int q;
    int t, v;
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> v;
            pq.push(v);
        }
        else if (t == 2) {
            cin >> v;
            pqDel.push(v);
        }
        else {
            while (!pqDel.empty() && pq.top() == pqDel.top()) {
                pq.pop();
                pqDel.pop();
            }
            cout << pq.top() << '\n';
        }
    }
}

int main() {
    ex2();
}