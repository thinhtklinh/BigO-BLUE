// Ex5: Diccionario Portunol
#include <bits/stdc++.h>
using namespace std;

#define maxN 26 // max number of nodes that a node can link to

struct Node {
    struct Node* child[maxN];

    Node() {
        for (int i=0; i<maxN; i++) child[i] = nullptr;
    }
};

struct Trie {
    Node* root;
    long long size;

    Trie() {
        root = new Node();
        size = 0;
    }

    ~Trie() {
        deleteTrie(this->root);
        this->root = nullptr;
    }

    void addWord(const string& s) {
        int ch;
        Node* tmp = root; // alias
        for (int i=0; i<s.length(); i++) {
            ch = s[i] - 'a'; // assume s contains lowercase
            if (tmp->child[ch] == nullptr) {
                tmp->child[ch] = new Node();
                size++;
            }
            tmp = tmp->child[ch];
        }
    }

    void calcRec(vector<long long>& vec, Node *tmp) {
        for (int i=0; i<maxN; i++) {
            if (tmp->child[i] != nullptr) {
                if (tmp != this->root) vec[i]++;
                calcRec(vec, tmp->child[i]);
            }
        }
    }

    void calc(vector<long long>& vec) {
        calcRec(vec, this->root);
    }


    void deleteTrie(Node* rot) {
        if (rot == nullptr) return;

        for (int i = 0; i < maxN; ++i) {
            if (rot->child[i] != nullptr) {
                deleteTrie(rot->child[i]);
            }
        }

        delete rot;
    }

};

int main() {
    int p, s;
    string w;
    while (cin >> p >> s && p) {
        Trie prefix, sufix;
        
        for (int i=0; i<p; i++) {
            cin >> w;
            prefix.addWord(w);
        }

        for (int i=0; i<s; i++) {
            cin >> w;
            reverse(w.begin(), w.end()); // reverse the word
            sufix.addWord(w);
        }

        long long ans = prefix.size * sufix.size;
        vector<long long> f(maxN);
        vector<long long> g(maxN);

        prefix.calc(f);
        sufix.calc(g);      
        
        for (int i=0; i<maxN; i++) {
            ans -= f[i] * g[i];
        }

        cout << ans << "\n";
    }
    return 0;
}