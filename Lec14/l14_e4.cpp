// ex4: Contact
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
        tmp->cntWord++;  // there are cntWord that go through this Node
    }
}

int findWord(Node* root, const string& s) {
    int ch;
    Node*& tmp = root; // alias
    for (int i=0; i<s.length(); i++) {
        ch = s[i] - 'a';
        if (tmp->child[ch] == nullptr) return 0;
        tmp = tmp->child[ch];
    }
    return tmp->cntWord;
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
    Node* root = new Node();
    int n;
    string op, s;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> op >> s;
        if (op == "add") addWord(root, s);
        else cout << findWord(root, s) << "\n";
    }
    deleteTrie(root);
    root = nullptr;
    return 0;
}