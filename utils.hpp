#include<iostream>
using namespace std;

template<class T>
ostream& operator<<(ostream& o, const vector<T>& vec) {
    o << "["; for (const auto& v: vec) { o << v << ' '; } o << "]\n"; return o; }
template<class T>
ostream& operator<<(ostream& o, const set<T>& st) {
    o << "{"; for (const auto& v: st) { o << v << ' '; } o << "}\n"; return o; }
template<class T1, class T2>
ostream& operator<<(ostream& o, const pair<T1,T2>& pa) {
    o << "(" << pa.first << ", " << pa.second << ")"; return o; }
template<class K, class V>
ostream& operator<<(ostream& o, const map<K,V>& mp) {
    o << "{"; for (const auto& v: mp) { o << v << ' '; } o << "}\n"; return o; }


