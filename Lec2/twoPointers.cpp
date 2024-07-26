#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Slow and fast

// Ex1: O(n)
int fastNslow() {
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    int n = arr.size();

    int slow = 0;
    for (int fast = 1; fast < n; ++fast)
        if (arr[fast] != arr[slow]) {
            ++slow;
            arr[slow] = arr[fast];
        }
    cout << slow + 1 << endl;
    for (int i=0; i<slow+1;++i) cout<< arr[i] << " ";
    return 0;
}

// Ex2: O(n)
// const int maxn = 5e5 + 10, maxv = 1e6 + 10;
// int N, K, a[maxn], mark[maxv];

// void input() {
//     cin >> N >> K;
//     for (int i = 1; i <= N; ++i)
//         cin >> a[i];
// }

// void solution() {
//     int i = 1, j = 1, maxL = 0;
//     int cnt = 0, l = 0, r = 0;
//     while (i <= j && j <= N) {
//         while (j <= N && cnt <= K) {
//             if (mark[a[j]] == 0) cnt++;
//             mark[a[j]] = j;
//             if (cnt <= K) j++;
//         }

//         if (maxL < j - i) maxL = j - i, l = i, r = j - 1;

//         while (i<=j && cnt>K) {
//             if (i == mark[a[i]]) cnt--, mark[a[i]] = 0;
//             i++;
//         }
//     }
//     cout << l << " " << r;
// }

void fastNslow2() {
    int N = 8, maxV = 100;
    int arr[N+1], mark[maxV] = {0};
    int K = 3;
    
    for (int i=1; i<=N; i++) cin >> arr[i];

    int i=1, j=1, l = 0, r =0;
    int maxL = 0, cnt = 0;
    while (i <= j && j <= N) {
        while (j <= N) {
            if (mark[arr[j]] == 0) {
                cnt++;
            }
            mark[arr[j]] = j;
            if (cnt < K) j++;
            else break;
        }

        if (maxL < j - i + 1) {
            maxL = j - i + 1;
            l = i; r = j;
        }

        while (cnt == K && i <= j) {
            if (i == mark[arr[i]]) {
                cnt--;
                mark[arr[i]] = 0;
            }
            i++;
        }
    }
    cout << l << " " << r;
}

void leftNright() {
    int N, K;
    cin >> N >> K;
    const int maxN = 1e7 + 3, maxV = 1e9 + 3;
    int arr[maxN] = {0};
    for (int i=1; i<=N; i++) cin >> arr[i];

    int cnt = 0;
    int le = 1, ri=N;
    while (le < ri) {
        if (arr[le] + arr[ri] == K) {
            le++; ri--;
            cnt++;
        }
        else if (arr[le] + arr[ri] < K) le++;
        else ri--;
    }

    cout << cnt;
}

int leftNright2() {
    int N;
    cin >> N;

    vector<int> hei(N);
    for (int i=0; i<N; i++) {
        cin >> hei[i];
    }

    int le=0, ri=N-1, preHei;
    int maxA = (ri - le) * min(hei[le], hei[ri]);

    while (le < ri) {
        if (hei[le] <= hei[ri]) {
            preHei = hei[le];
            while (hei[le] <= preHei && le < ri) le++;
        }
        else {
            preHei = hei[ri];
            while (hei[ri] <= preHei && le < ri) ri--;
        }

        if (le == ri) {
            return maxA;
        }

        maxA = max(maxA, (ri-le) * min(hei[le], hei[ri]));
    }

    return maxA;
}

void slidingWindow() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int maxS = accumulate(arr.begin(), arr.begin()+K, 0);

    int curS = maxS;
    for (int i = K; i<N; i++) {
        curS += arr[i] - arr[i-K];
        maxS = max(maxS, curS);
    }

    cout << maxS;
}

void slidingWindow2() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n+1);
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    unordered_set<int> uset;
    int ptr = 1;
    int curS = 0;
    for (int i=1; i<=n; ++i) {
        curS += arr[i];
        if (curS < k) continue;
        else if (curS > k) {
            curS -= arr[ptr++];
        }

        if (curS == k) {
            uset.insert(i-ptr+1);
            int j = ptr;
            while (arr[j] == 0) {
                uset.insert(i-j);
                j++;
            }
        }
    }
    cout << uset.size();
}

int main() {
    // input();
    // solution();
    // fastNslow();
    // leftNright();
    // slidingWindow2();
    return 0;
}