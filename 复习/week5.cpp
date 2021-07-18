#include <iostream>
#define ll long long
using namespace std;

// 快速幂
ll quickPow(ll a, ll b, ll mod) {
    ll res = 1;
    for (a %= mod; b; a = a * a % mod, b >>= 1) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}

// 前缀和
// 
