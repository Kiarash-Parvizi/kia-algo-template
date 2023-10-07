#include<bits/stdc++.h>
using namespace std;

vector<bool> primes_bool(int n) {
    vector<bool> vk(n, true);
    vk[0] = false;
    vk[1] = false;
    for (int i = 2; i < n; i++) {
        if (!vk[i]) continue;
        for (int j = i+i; j < n; j+=i) {
            vk[j] = false;
        }
    }
    return vk;
}

vector<int> primes_list(int max_prime) {
    auto bb = primes_bool(max_prime+1);
    vector<int> res;
    for (int i = 2; i < bb.size(); i++) {
        if (bb[i]) {
            res.push_back(i);
        }
    }
    return res;
}

// test ------------------
#include"utils.hpp"
int main() {
    cout << primes_bool(21) << "\n";
    cout << primes_list(21) << "\n";
}


