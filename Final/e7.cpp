#include <bits/stdc++.h>
using namespace std;
// ex7: Most Common Suffix
// type: Trie

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
        tmp->cntWord++; // there are cntWord that go through this Node
    }
}

int traversal(Node* root, int level, int& x) {
    int best = 0;
    for (int i=0; i<maxN; i++) {
        if (root->child[i] != nullptr) {
            best = max(best, traversal(root->child[i], level+1, x));
        }
    }
    if (level == x) best = max(best, root->cntWord);
    return best;
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
    int tc, n, q, x;
    string word;
    cin >> tc;
    while (tc--) {
        Node* root = new Node();
        cin >> n >> q;
        for (int i=0; i<n; i++) {
            cin >> word;
            reverse(word.begin(), word.end());
            addWord(root, word);
        }

        for (int i=0; i<q; i++) {
            cin >> x;
            cout << traversal(root, 0, x) << "\n";
        }

        // deleteTrie(root);
    }
}