#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> dict[11];

int main() {
    int tc;
    cin >> tc;
    string word, f, t;
    while (tc--) {
        while (true) {
            cin >> word;
            if (word == "*") break;
            dict[word.length()].push_back(word);
        }
        cin >> f >> t;
        for (int i=0; i<f.length(); i++) {
            
        }
    }
}