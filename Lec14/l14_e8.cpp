// Ex8: Old Berland Language
#include <bits/stdc++.h>
using namespace std;

#define maxN 2 // max number of nodes that a node can link to

struct Node {
    struct Node* child[maxN];
    int cntWord;

    Node() {
        for (int i=0; i<maxN; i++) child[i] = nullptr;
        cntWord = 0;
    }
};

bool geneWord(Node* root, int l, string& word, string ans = "") {
    if (l == 0) {
        root->cntWord++;
        word = ans;
        return true;
    }
    for (int i=0; i<maxN; i++) {
        if (root->child[i] == nullptr) { // able to add new unique word
            root->child[i] = new Node();
            bool flag = geneWord(root->child[i], l-1, word, ans + char(i + '0'));
            if (flag == true) return flag;
        }
        else if (root->child[i]->cntWord == 0) { // this way will not cause prefix
            bool flag = geneWord(root->child[i], l-1, word, ans + char(i + '0'));
            if (flag == true) return flag;
        }
    }
    return false; // no way to create more unique word in this i
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
    int n, l;
    string word;
    bool flag = 0;
    cin >> n;
    vector<pair<int, int>> lens(n); // len, id
    vector<string> dict(n);

    for (int i=0; i<n; i++) {
        cin >> lens[i].first;
        lens[i].second = i;
    }

    sort(lens.begin(), lens.end());

    for (int i=0; i<n; i++) {
        word = "";
        if (geneWord(root, lens[i].first, word)) dict[lens[i].second] = word;
        else {
            flag = 1;
            break;
        }
    }

    if (flag) cout << "NO";
    else {
        cout << "YES\n";
        // sort(dict.begin(), dict.end());
        for (int i=0; i<dict.size(); i++) cout << dict[i] << '\n';
    }
    deleteTrie(root);
    root = nullptr;
    return 0;
}