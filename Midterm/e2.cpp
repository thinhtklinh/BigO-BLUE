// Pangram
#include <iostream>
using namespace std;

bool alpha[26];

int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (str[i] < 91) {
            str[i] += 32;
        }

        if (!alpha[str[i]-97]) {
            alpha[str[i]-97] = 1; 
            cnt++;
        }
    }
    if (cnt == 26) cout << "YES";
    else cout << "NO";
}