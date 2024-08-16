// ex6: minimum loss -> O(n^2)
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e16;

int main() {
    unsigned int n;
    cin >> n;
    vector<pair<long long, long long>> arr(n); // val, id
    for (unsigned int i=0; i<n; i++) {
        arr[i].second = i;
        cin >> arr[i].first;
    }

    sort(arr.begin(), arr.end(), [](const std::pair<long long, long long> &a, const std::pair<long long, long long> &b) {
    return a.first > b.first;
});


    long long minDif = INF;
    for (unsigned int i=0; i<n; i++) {
        for (unsigned int j=i+1; j<n; j++) {
            if (arr[j].second > arr[i].second) {
                long long dif = arr[i].first - arr[j].first;
                if (minDif > dif) minDif = dif;
                break;
            }
        }
    }
    cout << minDif;
    
}