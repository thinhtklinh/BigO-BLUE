// ex1: Search Engine -> O(nlen(s) + qlen(s))
#include <bits/stdc++.h>
using namespace std;

#define maxN 26 // max number of nodes that a node can link to

struct Node {
    struct Node* child[maxN];
    int cntWord;

    Node() {
        for (int i=0; i<maxN; i++) child[i] = nullptr;
        cntWord = 0;
    }
};

void addWord(Node* root, const string& s, const int& prio) {
    int ch;
    Node*& tmp = root; // alias
    for (int i=0; i<s.length(); i++) {
        ch = s[i] - 'a'; // assume s contains lowercase
        if (tmp->child[ch] == nullptr) tmp->child[ch] = new Node();
        tmp = tmp->child[ch];
        tmp->cntWord = max(tmp->cntWord, prio);
    }
    // tmp->cntWord++; // mark end of s
}

int query(Node* root, const string& s) {
    int ch;
    Node*& tmp = root; // alias
    for (int i=0; i<s.length(); i++) {
        ch = s[i] - 'a';
        if (tmp->child[ch] == nullptr) return -1;
        tmp = tmp->child[ch];
    }
    return tmp->cntWord;
}

int main() {
    Node* root = new Node();
    int n, q, w;
    string s;
    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> s >> w;
        addWord(root, s, w);
    }
    for (int i=0; i<q; i++) {
        cin >> s;
        cout << query(root, s) << "\n";
    }
    return 0;
}