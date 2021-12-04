#include <iostream>
#include <queue>
using namespace std;

int neighbors[501][501] = {0};
int dist[501];
int cnt[501];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int F = 0;
    cin >> F;
    for (int f = 0; f < F; f++) {
        int n, m, w;
        int s, e;
        cin >> n >> m >> w;
        // 初始化neighbors, vis, dist, cnt
        for (int i = 1; i <= n; i++) {
            dist[i] = 1e5;
            cnt[i] = 0;
            for (int j = 1; j <= n; j++)
                neighbors[i][j] = 10001;
        }

        for (int i = 0; i < m; i++) {
            int ti = 0;
            cin >> s >> e >> ti;
            neighbors[s][e] = min(neighbors[s][e], ti);
            neighbors[e][s] = neighbors[s][e];
        }
        for (int i = 0; i < w; i++) {
            int tj = 0;
            cin >> s >> e >> tj;
            // 这里有没有两点间多条路呢？
            neighbors[s][e] = -tj;
        }

        bool tag = false;
        dist[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 1; i <= n; i++) {
                if (neighbors[now][i] != 10001 && dist[i] > dist[now] + neighbors[now][i]) {
                    dist[i] = dist[now] + neighbors[now][i];
                    q.push(i);
                    cnt[i] = cnt[now] + 1;
                }
                if (cnt[i] >= n) {
                    tag = true;
                    break;
                }
            }
        }
        if (tag || dist[s] < 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}