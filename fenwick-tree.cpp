#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<class T>
struct FT {
    std::vector<T> data;
    FT(int size) : data(size+1) {}
    void insert(int idx, T value) {
        if (idx==0) { data[0]+=value; return; }
        while(idx < data.size()) {
            data[idx] += value;
            idx += idx & -idx;
        }
    }
    T get(int from, int to) {
        return sumto(to) - sumto(from-1);
    }
    T sumto(int idx) {
        if (idx < 0) return 0;
        T res = data[0];
        while(idx != 0) {
            res += data[idx];
            idx = idx & (idx - 1);
        }
        return res;
    }
};

int main() {
    FT<ll> f(1e4);
    for (int i = 0; i < 20; i++) {
        f.insert(i, i+1);
        for (int j = 0; j <= i; j++) {
            cout << f.get(0, j) << endl;
        }
        cout << "-----------\n";
    }
}

