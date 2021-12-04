#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pa pair<int, int>
#define triple pair<int, pair<int, int> >
using namespace std;

const int inf = 1e7;
// first 可达点 ----- first 承重量，second 通行时间
vector<triple> neighbors[10001];
bool vis[10001];
int dist[10001];
int n, T;

bool reachable(int minC) {
    priority_queue<pa, vector<pa>, greater<pa> > q;

    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
        vis[i] = false;
    }
    // dijistra
    dist[1] = 0;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int now = q.top().second;
        q.pop();
        if (vis[now])
            continue;
        vis[now] = true;
        for (auto &tr : neighbors[now]) {
            if (tr.second.first > minC && dist[tr.first] > dist[now] + tr.second.second) {
                dist[tr.first] = dist[now] + tr.second.second;
                q.push(make_pair(dist[tr.first], tr.first));
            }
        }
    }
    if (dist[n] <= T)
        return true;
    return false;
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    int X = 0;
    cin >> X;
    for (int x = 0; x < X; x++) {
        int m = 0;
        int left = 1e7;
        int right = 1;
        cin >> n >> m >> T;

        // 初始化
        for (int i = 1; i <= n; i++) 
            neighbors[i].clear();
        // 输入
        for (int i = 0; i < m; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            left = min(left, c);
            right = max(right, c);
            neighbors[a].emplace_back(make_pair(b, make_pair(c, d)));
            neighbors[b].emplace_back(make_pair(a, make_pair(c, d)));
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (reachable(mid))
                left = mid + 1;
            else
                right = mid;
        }
        cout << left << endl;
    }

    return 0;
}