#include <iostream>
#include <deque>
using namespace std;

typedef long long ll;
ll n, res;
ll heights[100100];
deque<pair<ll, ll> > s; //first是高度，second是index
pair<ll, ll> top;

int main() {
 cin >> n;
 for (ll i = 0; i < n; i++)
  cin >> heights[i];

// for (ll i = 0; i < n ; i++) {
//  if (s.size() == 1 && s.back().first > heights[i]) {
//   pair<ll, ll> top = s.back();
//   s.pop_back();
//   res = max(max(res, top.first), 2 * heights[i]);
//  }
//  while (s.size() >= 2 && s.back().first > heights[i]) {
//   pair<ll, ll> top = s.back();
//   s.pop_back();
//   res = max(res, (i - s.back().second - 1) * top.first);
//  }
//  s.push_back(make_pair(heights[i], i));
// }

 s.push_back(make_pair(0, 0));
 for (ll i = 0; i < n ; i++) {
  while (s.size() && s.back().first > heights[i]) {
   pair<ll, ll> top = s.back();
   s.pop_back();
   res = max(res, (i - s.back().second - 1) * top.first);
  }
  s.push_back(make_pair(heights[i], i));
 }

 while (s.size()) {
  if (s.size() * s.front().first > res)
   res = s.size() * s.front().first;
  s.pop_front();
 }
 cout << res << '\n';

 return 0;
}