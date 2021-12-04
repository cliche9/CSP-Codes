#include <iostream>
#include <queue>
using namespace std;

const int MAXM = 2500 * 2 + 210;
const int MAXN = 510;

int g[MAXN][MAXN];
int cnt[MAXN];

int main() {
 int F;//测试用例的数量
 cin >> F;

 for (int ii = 0; ii < F; ii++) {
  int n, m, w;
  cin >> n >> m >> w;
  memset(g, 0, sizeof(g));
  memset(cnt, 0, sizeof(cnt));

  int s, e, t; //s与e之间需要花费t
  //双向道路
  for (int j = 2; j <= (m + 1); j++) {
   cin >> s >> e >> t;
   g[s][e] = t;
   g[e][s] = t;
  }
  //单向时空隧道
  for (int k = (m + 2); k <= (m + w + 1); k++) {
   cin >> s >> e >> t;
   g[s][e] = -t;
  }

  int shortestPath[n + 1] ;
  for (int i = 1; i <= n; i++)
   shortestPath[i] = 1e9;
  queue<int> q;
  q.push(s);//将其入队
  shortestPath[s] = 0; //自己到自己最短路径为0

  while (!q.empty()) {
   int x = q.front();
   q.pop();

   for (int i = 1; i <= n; i++) {
    if (g[x][i] != 0 && shortestPath[i] > shortestPath[x] + g[x][i]) {
     shortestPath[i] = shortestPath[x] + g[x][i];
     q.push(i);
     cnt[i] = cnt[x] + 1;
    }
    if (cnt[i] >= n) {
     break;
    }
   }
  }

  if (shortestPath[s] < 0)
   cout << "YES\n";
  else
   cout << "NO\n";
 }

 return 0;
}