// ex1: Where is the Marble
#include <bits/stdc++.h>
using namespace std;

int bsFirst(const vector<int>& arr, int l, int r, int val) {
    if (l <= r) {
        int mid = l + (r-l)/2;
        if (arr[mid] == val && (mid == l || arr[mid-1] != val)) return mid;
        else if (arr[mid] < val) return bsFirst(arr, mid+1, r, val);
        else return bsFirst(arr, l, mid-1, val);
    }
    return -1;
}

int main() {
    int n, q, val, tc=1;
    while (cin >> n >> q && n != 0) {
        vector<int> arr(n);
        for (int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << "CASE# " << tc++ << ":\n";
        while (q--) {
            cin >> val;
            int id = bsFirst(arr, 0, n-1, val);
            if (id != -1) cout << val << " found at " << id+1 << '\n';
            else cout << val << " not found\n";
        }
    }
}