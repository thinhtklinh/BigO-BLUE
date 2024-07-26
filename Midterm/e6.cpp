#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 1;
    for (int i=0; i<str.length(); i++) {
        if (str[i] < 91) cnt++;
    }
    cout << cnt;

    return 0;
}