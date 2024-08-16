// ex3: Eko
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> tree(n);
    for (int i=0; i<n; i++) cin >> tree[i];
    sort(tree.begin(), tree.end(), greater<int>());
    tree.push_back(0); // cut all
    long long cut = 0;
    long long ans;
    for (int i=0; i<n; i++) {
        if (tree[i+1] == tree[i]) continue;
        int tmp = cut + (tree[i]-tree[i+1])*(i+1);
        if (tmp > m) {
            long long x = ceil((m - cut)*1.0/(i+1));
            ans = tree[i] - x;
            break;
        }
        else if (tmp < m) {
            cut = tmp;
        }
        else {
            ans = tree[i+1];
            break;
        }
    }
    cout << ans << "\n";
}