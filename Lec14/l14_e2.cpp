// Ex2: DNA Prefix -> O(n*len(s) + w)
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
        ch = s[i] - 'A'; // assume s contains lowercase
        if (tmp->child[ch] == nullptr) tmp->child[ch] = new Node();
        tmp = tmp->child[ch];
        tmp->cntWord++; // there are cntWord that go through this Node
    }
}

int traversal(Node* root, int level = 0) {
    int best = 0;
    for (int i=0; i<maxN; i++) {
        if (root->child[i] != nullptr) {
            best = max(best, traversal(root->child[i], level+1));
        }
    }
    return max(best, root->cntWord*level);
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
    int tc, n;
    string s;
    Node* root;
    cin >> tc;
    for (int t=1; t<=tc; t++) {
        cin >> n;
        root = new Node();

        for (int i=0; i<n; i++) {
            cin >> s;
            addWord(root, s);
        }

        cout << "Case " << t << ": " << traversal(root) << "\n";
        deleteTrie(root);
        root = nullptr;
    }
    return 0;
}