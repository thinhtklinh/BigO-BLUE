// ex4: The Playboy Chimp
#include <bits/stdc++.h>
using namespace std;

int lastLower(vector<int>& arr, int l, int r, int val) {
    int pos = l;
    while (l < r) {
        int mid = l + ceil((r-l)*1.0/2); // cause loop if round down
        if (arr[mid] < val) {
            pos = mid;
            l = mid;
        }
        else r = mid-1;
    }
    if (arr[pos] >= val) return -1;
    else return pos;
}

int firstHigher(vector<int>& arr, int l, int r, int val) {
    int pos = r;
    while (l < r) {
        int mid = l + (r-l)/2;
        if (arr[mid] > val) {
            pos = mid;
            r = mid;
        }
        else l = mid+1;
    }
    if (arr[pos] <= val) return -1;
    else return pos;
}

int main() {
    int n, q, val;
    cin >> n;
    vector<int> tt(n);
    for (int i=0; i<n; i++) {
        cin >> tt[i];
    }
    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> val;
        int id1 = lastLower(tt, 0, n-1, val);
        if (id1 == -1) cout << "X ";
        else cout << tt[id1] << " ";

        int id2 = firstHigher(tt, 0, n-1, val);
        if (id2 == -1) cout <<"X\n";
        else cout << tt[id2] << '\n';
    }
}