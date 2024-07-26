// Ex6: Restaurant Rating
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void ex6() {
    int n, t, v;
    cin >> n;
    priority_queue<int> mah; // others
    priority_queue<int, vector<int>, greater<int>> mih; // top reviews
    while (n--) {
        cin >> t;
        if (t == 1) {
            cin >> v;
            if (!mih.empty() && v > mih.top()) {
                mah.push(mih.top());
                mih.pop();
                mih.push(v);
            }
            else {
                mah.push(v);
            }

            if (mih.size() < (mah.size() + mih.size())/3) {
                mih.push(mah.top());
                mah.pop();
            }
        }
        else {
            if (mih.empty()) {
                cout << "No reviews yet\n";
            }
            else cout << mih.top() << '\n';
        }
    }
}

int main() {
    ex6();
    return 0;
}