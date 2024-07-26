#include <bits/stdc++.h>
using namespace std;

const int maxV = 1e5 + 5, maxN = 1e5 + 5;
int arr[maxN];
int mark[maxV];

// Ex1: Array
int array() {
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];

    int i = 1, j = 1, l = 0, r = 0;
    int cnt = 0, minL = 1e5 + 5;

    while (i <= j && j <= N) {
        while (j <= N) {
            if (mark[arr[j]] == 0) {
                cnt++;
            }
            mark[arr[j]] = j;
            if (cnt < K)
                j++;
            else
                break;
        }

        if (j <= N && minL > j - i + 1) {
            minL = j - i + 1;
            l = i;
            r = j;
        }

        while (cnt == K && i <= j) {
            if (i == mark[arr[i]]) {
                cnt--;
                mark[arr[i]] = 0;
            } else {
                if (minL > j - i - 2) {
                    minL = j - i - 2;
                    l = i + 1;
                    r = j;
                }
            }
            i++;
        }
    }

    if (minL == 1e5 + 5)
        cout << "-1 -1";
    else
        cout << l << " " << r;
    return 0;
}

// Ex2: George and Round
void GeorgeNRound() {
    int n, m;
    cin >> n >> m;
    vector<int> rq(n);
    vector<int> probs(m);
    for (int i = 0; i < n; ++i)
        cin >> rq[i];
    for (int i = 0; i < m; ++i)
        cin >> probs[i];

    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (rq[i] <= probs[j]) {
            ++i, ++j, ++cnt;
        } else {
            ++j;
        }
    }
    if (cnt == n)
        cout << 0;
    else { // cnt < n
        cout << n - cnt - (m - j);
    }
}

// Ex3: Books
void Books() {
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int i = 0, j = 0;
    int tim = 0, maxL = 0;
    while (i <= j && j < n) {
        while (j < n) {
            tim += arr[j];
            if (tim <= t)
                ++j;
            else
                break;
        }

        if (maxL < j - i) {
            maxL = j - i;
        }

        while (i <= j && tim >= t) {
            tim -= arr[i];
            ++i;
        }
        ++j;
    }
    cout << maxL;
}

// Ex4: Dress'em in Vests!
void DressInVest() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> wants(n);
    vector<int> gots(m);
    vector<int> pairs;

    for (int i = 0; i < n; i++)
        cin >> wants[i];
    for (int i = 0; i < m; i++)
        cin >> gots[i];

    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (wants[i] - x <= gots[j] && gots[j] <= wants[i] + y) {
            pairs.push_back(i + 1);
            pairs.push_back(j + 1);
            ++cnt;
            ++i;
            ++j;
        } else if (wants[i] - x > gots[j])
            ++j;
        else if (wants[i] + y < gots[j])
            ++i;
    }

    cout << cnt << '\n';
    for (int i = 0; i < pairs.size(); i += 2) {
        cout << pairs[i] << ' ' << pairs[i + 1] << '\n';
    }
}

// Ex5: Seraja and Dima
void SerejaNDima() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1;
    int Se = 0, Di = 0;
    bool turnD = 0;
    while (l <= r) {
        if (arr[l] > arr[r]) {
            if (turnD)
                Di += arr[l];
            else
                Se += arr[l];
            ++l;
        } else {
            if (turnD)
                Di += arr[r];
            else
                Se += arr[r];
            --r;
        }

        turnD = 1 - turnD;
    }
    cout << Se << " " << Di;
}

// Ex6: Approximating a Constant Range -> tim doan con dai nhat ko chua qua 2 gia tri phan biet
// min max max2
// max min min2

void Approximating() {
    int n;
    cin >> n;
    vector<int> datas(n);
    for (int i = 0; i < n; ++i)
        cin >> datas[i];

    int i = 0, j = 1;
    int maxL = 1, mi = 0, Mi = 0;

    while (i <= j && j<n) {
        while (j < n) {
            if (datas[j] == datas[mi]) {
                if (mi == Mi) Mi = j;
                mi = j;
                ++j;
            }
            else if (datas[j] == datas[Mi]) {
                Mi = j;
                ++j;
            }
            else if (datas[j] < datas[mi]) {
                if (datas[mi] == datas[Mi]) {
                    mi = j;
                    ++j;
                }
                else {
                    break;
                }
            }
            else { // datas[j] > datas[Mi]
                if (datas[mi] == datas[Mi]) {
                    Mi = j;
                    ++j;
                }
                else {
                    break;
                }
            }
        }

        if (maxL < j - i) maxL = j - i;

        while (i <= j && j < n) {
            if (i == mi) {
                mi = Mi;
                Mi = j;
                ++i;
                break;
            }
            else if (i == Mi) {
                Mi = mi;
                mi = j;
                ++i;
                break;
            }
            else ++i;
        }
        ++j;
    }

    cout << maxL;
}

// Ex7: Wrath
void Wrath() {
    int n;
    cin >> n;
    vector<int> claws(n);
    for (int i=0; i<n; i++) cin >> claws[i];

    int alive = 1, head = n - 1 - claws[n-1];
    for (int i=n-2; i>-1; --i) {
        if (i < head) alive++;
        if (i - claws[i] < head && claws[i]) head = i - claws[i];
    }
    cout << alive;
}

// Ex8: Alice Bob and Chocolate
void AliceNBob() {
    int n;
    cin >> n;
    vector<int> socolas(n);
    for (int i=0; i<n; ++i) cin >> socolas[i];

    int aliceT = 0, bobT = 0;
    int l=0, r=n-1;
    while (l <= r) {
        if (aliceT < bobT) {
            bobT -= aliceT;
            aliceT = socolas[l];
            ++l;
        }
        else if (aliceT > bobT) {
            aliceT -= bobT;
            bobT = socolas[r];
            --r;
        }
        else if (l == r) {
            aliceT = socolas[l];
            ++l;
        }
        else {
            aliceT = socolas[l];
            bobT = socolas[r];
            ++l; --r;
        }
    }
    cout << l << " " << n - l;
}

int main() {
    // array();
    // GeorgeNRound();
    // Books();
    // DressInVest();
    // SerejaNDima();
    // Approximating();
    // Wrath();
    AliceNBob();
    return 0;
}