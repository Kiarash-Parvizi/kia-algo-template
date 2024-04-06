#include<bits/stdc++.h>
using namespace std;

struct bitvector {
    vector<int64_t> data;
    int64_t initvalue, one = 1;
    bitvector(int64_t size, bool initval): initvalue(initval?-1:0), data((size+63)/64, initval? -1 : 0) {}
    //
    void set(int64_t pos, bool val) {
        int64_t I = pos / 64, rem = pos%64;
        while (I >= data.size()) {
            data.push_back(initvalue);
        }
        if ((bool)(data[I] & (one<<rem)) ^ val) {
            data[I] ^= (one<<rem);
        }
    }
    void flip(int64_t pos) {
        int64_t I = pos / 64, rem = pos%64;
        while (I >= data.size()) {
            data.push_back(initvalue);
        }
        data[I] ^= (one<<rem);
    }
    bool get(int64_t pos) {
        int64_t I = pos / 64, rem = pos%64;
        if (I >= data.size()) {
            throw "bitvector: out of bound\n";
        }
        return data[I] & (one<<rem);
    }
};

// test ------------------
#include"utils.hpp"
int main() {
    int64_t n = 64;
    bitvector bv(n, 0);
    cout << "----\n";
    bv.set(0, true);
    bv.set(32, true);
    bv.set(31, false);
    bv.flip(31);
    bv.flip(1);
    bv.flip(60);
    bv.set(63, 1);
    bv.set(62, 1);
    bv.flip(2); bv.flip(2);
    bv.flip(3); bv.flip(3); bv.flip(3);
    for (int64_t i = 0; i < n; i++) {
        cout << bv.get(i);
    }
    cout << endl;
}


