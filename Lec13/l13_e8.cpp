// ex8: Tanya and Postcard
#include <bits/stdc++.h>
using namespace std;

int borrow[123] = {0};

int main() {
    string s, t;
    cin >> s >> t;
    map<char, int> alphaT;
    map<char, int>::iterator it;

    int yay = 0, whoops = 0;

    for (int i=0; i<t.length(); i++) {
        if (alphaT.find(t[i]) == alphaT.end()) alphaT[t[i]] = 1;
        else alphaT[t[i]] += 1;
    }

    for (int i=0; i<s.length(); i++) {
        it = alphaT.find(s[i]);
        if (it != alphaT.end() && (it->second || borrow[s[i]-65])) {
            if (it->second) it->second--;
            else {
                borrow[s[i]-65]--;
                whoops--;
            }
            yay++;
        }
        else if (s[i] < 97) {
            char c = s[i]+32;
            it = alphaT.find(c);
            if (it != alphaT.end() && it->second) {
                it->second--;
                borrow[c-65]++;
                whoops++;
            }
        }
        else {
            char c = s[i]-32;
            it = alphaT.find(c);
            if (it != alphaT.end() && it->second) {
                it->second--;
                borrow[c-65]++;
                whoops++;
            }
        }
    }
    cout << yay << " " << whoops;
}

// s: AbCdaa
// t: aaBdbC
// 5 0