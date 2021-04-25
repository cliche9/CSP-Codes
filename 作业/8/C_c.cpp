#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e6 + 10;
queue<int> q;
int vis[N], dis[N], cnt[N];
int tot, point[N], w[N], v[N], nxt[N];

void add(int x, int y, int z) {
 tot++;
 nxt[tot] = point[x];
 point[x] = tot;
 v[tot] = y;
 w[tot] = z;
}

bool SPFA(int s) {
 fill(dis, dis + N, 1e9);

 dis[s] = 0;
 vis[s] = 1;
 q.push(s);

 while (!q.empty()) {
  int x = q.front();
  q.pop();
  vis[x] = 0;

  for (int i = point[x]; i ; i = nxt[i]) {
   int y = v[i];
   if (dis[y] > dis[x] + w[i]) {
    cnt[y] = cnt[x] + 1;
    if (cnt[y] >= n) {
     cout << "impossible";
     return false;
    }
    dis[y] = dis[x] + w[i];
    if (vis[y] != 1) {
     vis[y] = 1;
     q.push(y);
    }
   }
  }
 }
 return true;
}

int main() {
 cin >> n >> m;

 //每个坑最多一瓶酸奶
 for (int i = 1; i <= n; i++) {
  add(i - 1, i, 1);
  add(i, i - 1, 0);
 }
 //m个酸奶
 while (m--) {
  int a, b, k, c;
  cin >> k >> a >> b >> c;
  if (k == 1) {
   add(a - 1, b, c);
  } else if (k == 2) {
   add(b, a - 1, -c);
  } else if (k == 3) {
   add(a - 1, b, c - 1);
  } else if (k == 4) {
   add(b, a - 1, -1 - c);
  } else if (k == 5) {
   add(a - 1, b, c);
   add(b, a - 1, -c);
  }
 }
 if (SPFA(0))
  cout << *max_element(dis + 1, dis + n + 1) << endl;

 return 0;
}