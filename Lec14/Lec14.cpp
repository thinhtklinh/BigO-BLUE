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

bool findWord(Node* root, const string& s) {
    int ch;
    Node*& tmp = root; // alias
    for (int i=0; i<s.length(); i++) {
        ch = s[i] - 'a';
        if (tmp->child[ch] == nullptr) return false;
        tmp = tmp->child[ch];
    }
    return tmp->cntWord > 0;
}

bool isWord(Node*& node) {
    return node->cntWord != 0;
}

bool isEmpty(Node*& node) {
    for (int i=0; i<maxN; i++) {
        if (node->child[i] != nullptr) return false;
    }
    return true;
}

bool removeWord(Node* root, const string& s, int level, const int& len) {
    if (root == nullptr) return false;
    if (level == len) {
        if (root->cntWord > 0) {
            root->cntWord--;
            return true;
        }
        else return false;
    }
    int ch = s[level] - 'a';
    int flag = removeWord(root->child[ch], s, level+1, len);
    if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch])) {
        delete root->child[ch];
        root->child[ch] = nullptr;
    }
    return flag;
}

void printWords(Node* root, string s = "") {
    if (isWord(root)) cout << s << endl;
    for (int i=0; i<maxN; i++) {
        if (root->child[i]) printWords(root->child[i], s + char(i + 'a'));
    }
}

bool traversal(Node* root) {
    for (int i=0; i<maxN; i++) {
        if (root->child[i] != nullptr) {
            if (root->cntWord > 0) return 0; // at least two words have same prefix 
            bool flag = traversal(root->child[i]);
            if (!flag) return 0;
        }
    }
    return 1;
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
    addWord(root, "the");
    addWord(root, "then");
    addWord(root, "bigo");
    cout << findWord(root, "there") << "\n";
    cout << findWord(root, "the") << "\n";
    cout << findWord(root, "then") << "\n";
    removeWord(root, "bigo", 0, 4);
    removeWord(root, "the", 0, 3);
    removeWord(root, "th", 0, 2);
    printWords(root);
    return 0;
}