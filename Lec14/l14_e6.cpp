// Ex6: No Prefix Set
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

bool isEmpty(Node*& node) {
    for (int i=0; i<maxN; i++) {
        if (node->child[i] != nullptr) return false;
    }
    return true;
}

void addWordNCheck(Node* root, const string& s, bool& flag) {
    int ch;
    Node*& tmp = root; // alias
    for (int i=0; i<s.length(); i++) {
        ch = s[i] - 'a'; // assume s contains lowercase
        if (tmp->child[ch] == nullptr) tmp->child[ch] = new Node();
        tmp = tmp->child[ch];
        if (tmp->cntWord) flag = 1; // bad set detected
    }
    if (!isEmpty(tmp)) flag = 1; // still has other words contains this word
    tmp->cntWord++; // mark end of s
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
    string s, detected;
    bool flag = 0;
    Node* root = new Node();
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s;
        if (!flag) {
            addWordNCheck(root, s, flag);
            if (flag) detected = s;
        }
    }
    cout << (flag ? "BAD SET" : "GOOD SET") << "\n";
    cout << detected;
    deleteTrie(root);
    root = nullptr;
    
    return 0;
}