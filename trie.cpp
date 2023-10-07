#include<bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        map<char, Node*> nxs;
        int cnt = 0;
    };
    Node* root;
    Trie() {
        root = new Node;
    }
    void add(const string& s) {
        Node* nd = root;
        for (char c: s) {
            if (nd->nxs.find(c) == nd->nxs.end()) {
                nd->nxs[c] = new Node;
            }
            nd = nd->nxs[c];
        //nd->cnt++;
        }
        nd->cnt++;
    }
};

// test ------------------
#include"utils.hpp"
int main() {
    vector<string> words{"kia","david","usa","kiarash","kia-engines","usaf", "kia-"};
    Trie t;
    for (auto& v: words) {
        t.add(v);
    }
    vector<int> res;
    for (auto& s: words) {
        Trie::Node* nd = t.root;
        int v = 0;
        for (char c: s) {
            nd = nd->nxs[c];
            v += nd->cnt;
        }
        res.push_back(v);
    }
    cout << res << "\n";
}


