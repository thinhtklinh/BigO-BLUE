// ex7: Bank and Vulnerable Passwords
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

void addWord(Node* root, const string& s) {
    int ch;
    Node*& tmp = root; // alias
    for (int i=0; i<s.length(); i++) {
        ch = s[i] - 'a'; // assume s contains lowercase
        if (tmp->child[ch] == nullptr) tmp->child[ch] = new Node();
        tmp = tmp->child[ch];
    }
    tmp->cntWord++; // mark end of s
}

bool traversal(Node* root) {
    for (int i=0; i<maxN; i++) {
        if (root->child[i] != nullptr) {
            if (root->cntWord > 0) return 1; // at least two words have same prefix 
            bool flag = traversal(root->child[i]);
            if (flag) return 1;
        }
    }
    return 0;
}

void deleteTrie(Node* root) {
    if (root == nullptr) return;

    for (int i = 0; i < maxN; ++i) {
        if (root->child[i] != nullptr) {
            deleteTrie(root->child[i]);
        }
    }

    delete root;
}

int main() {
    int n;
    string s;
    cin >> n;
    Node* root = new Node();
    for (int i=0; i<n; i++) {
        cin >> s;
        addWord(root, s);
    }
    bool ans = traversal(root);
    cout << (ans ? "vulnerable" : "non vulnerable") << "\n";
    deleteTrie(root);
    root = nullptr;
}