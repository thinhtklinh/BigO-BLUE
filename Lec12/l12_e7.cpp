// ex7: Hacking the random number generator
#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& arr, int l, int r, int val) {
    if (l <= r) {
        int mid = l + (r-l)/2;
        if (arr[mid] == val) return mid;
        else if (arr[mid] > val) return binarySearch(arr, l, mid-1, val);
        else return binarySearch(arr, mid+1, r, val);
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int pair = 0;
    for (int i=0; i<n-1; i++) {
        int id = binarySearch(arr, i+1, n-1, arr[i]+k);
        if (id != -1) {
            pair++;
        }
    }

    cout << pair << '\n';
}