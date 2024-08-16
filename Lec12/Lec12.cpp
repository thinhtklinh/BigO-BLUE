#include <iostream>
#include <vector>
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

int bsFirst(const vector<int>& arr, int l, int r, int val) {
    if (l <= r) {
        int mid = l + (r-l)/2;
        if (arr[mid] == val && (mid == l || arr[mid-1] != val)) return mid;
        else if (arr[mid] > val) return bsFirst(arr, l, mid-1, val);
        else return bsFirst(arr, mid+1, r, val);
    }
    return -1;
}

int bsLast(const vector<int>& arr, int l, int r, int val) {
    if (l <= r) {
        int mid = l + (r-l)/2;
        if (arr[mid] == val && (mid == r || arr[mid+1] != val)) return mid;
        else if (arr[mid] > val) return bsLast(arr, l, mid-1, val);
        else return bsLast(arr, mid+1, r, val);
    }
    return -1;
}

