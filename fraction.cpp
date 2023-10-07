#include<bits/stdc++.h>
using namespace std;

template<class T>
T gcd(T a, T b) {
    if (a == 0) return b;
    return gcd(b % a, a); }
template<class T>
T lcm(T a, T b) {
    return (a*b)/ gcd(a, b); }

template<class T>
struct frac {
    T n,d;
    bool operator < (const frac& o) const {
        T lc = lcm(d,o.d);
        T A0 = n * (lc/d);
        T A1 = o.n * (lc/o.d);
        if (A0 < A1) return true;
        return false;
    }
    bool operator == (const frac& o) const {
        T gc = gcd(o.d,d);
        T di0 = d/gc;
        T di1 = o.d/gc;
        if (n % di0 || o.n % di1) return false;
        return n / di0 == o.n / di1;
    }
};
template<class T>
ostream& operator<<(ostream& o, const frac<T>& f) {
    o << "(" << f.n << " / " << f.d << ")"; return o; }


// test ------------------
#include"utils.hpp"

int main() {
    vector<frac<long long>> vk{
        {4,4},
        {3,3},
        {1,4},
        {1,3},
        {7,8},
        {6,7},
        {5,6},
        {4,5},
        {3,4},
        {2,3},
        {1,2},
        {9,11},
        {9,13},
        {112,11},
        {113,12}
    };
    //for (auto& f0: vk)
    //for (auto& f1: vk) {
    //    if (f0 == f1) cout << f0 << " = " << f1 << endl;
    //}
    stable_sort(vk.begin(),vk.end());
    cout << vk << endl;
}


