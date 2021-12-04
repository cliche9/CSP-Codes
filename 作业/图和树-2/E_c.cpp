#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
typedef long long ll;
#define pa pair<ll,ll>
using namespace std;

const ll MAXM = 50010 * 2;
const ll MAXN = 10010;

ll N, M, T;
ll dis[MAXN], vis[MAXN];
ll tot, point[MAXN], w[MAXM], v[MAXM], nxt[MAXM], t[MAXM];

void add(ll x, ll y, ll z, ll o) {
 tot++;
 nxt[tot] = point[x];
 point[x] = tot;
 v[tot] = y;
 w[tot] = z;
 t[tot] = o;
}

bool check(ll mid) {
 priority_queue<pa, vector<pa>, greater<pa>> q;
 for (ll i = 1; i <= N; i++)
  dis[i] = 1e9, vis[i] = 0;
 dis[1] = 0;
 q.push(make_pair(0, 1));

 while (!q.empty()) {
  ll x = q.top().second;
  q.pop();
  if (vis[x])
   continue;
  vis[x] = 1;

  for (ll i = point[x]; i; i = nxt[i])
   if (w[i] > mid && dis[v[i]] > (dis[x] + t[i]) ) {
    dis[v[i]] = dis[x] + t[i];
    q.push(make_pair(dis[v[i]], v[i]));
   }

 }
 return (dis[N] <= T ? true : false);
}

void clear() {
 tot = 0;
 fill(dis, dis + MAXN, 0);
 fill(vis, vis + MAXN, 0);
 fill(point, point + MAXN, 0);
 fill(w, w + MAXM, 0);
 fill(v, v + MAXM, 0);
 fill(nxt, nxt + MAXM, 0);
 fill(t, t + MAXM, 0);
}

int main() {
 freopen("作业/data/a.in", "r", stdin);
 freopen("作业/data/a.out", "w", stdout);
 ll F;
 cin >> F;

 ll A, B, C, D; //最大承重量为C，通行时间为D
 for (ll i = 0; i < F; i++) {
  clear();
  ll maxc = -1e9, minc = 1e9;
  cin >> N >> M >> T;
  for (ll j = 0; j < M; j++) {
   cin >> A >> B >> C >> D;
   add(A, B, C, D);
   add(B, A, C, D);
   maxc = max(maxc, C);
   minc = min(minc, C);
  }

  ll l = minc, r = maxc;
  while (l < r) {
   ll mid = (l + r) / 2;
   if (check(mid))
    l = mid + 1;
   else
    r = mid;
  }
  cout << l << '\n';
 }

 return 0;
}