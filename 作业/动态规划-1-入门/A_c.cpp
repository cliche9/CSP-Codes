#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e6 + 10;
ll n, m, k, track = 0;
ll f[N], sf[N], dont[N];
const ll p = 998244353;

void fun(ll i) {
 if (track < m && dont[track] == i) {
  f[i] = 0;
  sf[i] = sf[i - 1];
  track++;
  return;
 }
 if (i <= k)
  f[i] = sf[i - 1];
 else {
  f[i] = sf[i - 1] - sf[i - k - 1] ;
  if (f[i] < 0)
   f[i] += p;
 }
 sf[i] = (sf[i - 1] + f[i]) % p;
}

int main() {
 cin >> n >> m >> k;

 sf[0] = 1;
 for (ll i = 0; i < m; i++)
  cin >> dont[i];
 for (ll i = 1; i <= n; i++)
  fun(i);

 printf("%lld", f[n]);
 return 0;
}