#include <iostream>
#include <queue>
#define Pair pair<int, int>
using namespace std;

const int inf = 1e9;

// first - index, second - weight
vector<pair<int, int> > neighbors_to[1000001];
vector<pair<int, int> > neighbors_back[1000001];
int dist[1000001];
bool vis[1000001];
priority_queue<Pair, vector<Pair>, greater<Pair> > minHeap;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int T = 0;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m, s, e, c;
        int res = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            dist[i] = inf;
            vis[i] = false;
            neighbors_to[i].clear();
            neighbors_back[i].clear();
        }
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> c;
            neighbors_to[s].emplace_back(make_pair(e, c));
            neighbors_back[e].emplace_back(make_pair(s, c));
        }
        // 去过程
        dist[1] = 0;
        minHeap.push(make_pair(0, 1));
        while (!minHeap.empty()) {
            int x = minHeap.top().second;
            minHeap.pop();
            if (vis[x])
                continue;
            vis[x] = true;
            for (auto &v : neighbors_to[x]) {
                if (dist[v.first] > dist[x] + v.second) {
                    dist[v.first] = dist[x] + v.second;
                    minHeap.push(make_pair(dist[v.first], v.first));
                }
            }
        }
        // 去一趟的最短路之和
        for (int i = 1; i <= n; i++) {
            res += dist[i];
            dist[i] = inf;
            vis[i] = false;
        }
        // 回来过程
        dist[1] = 0;
        minHeap.push(make_pair(0, 1));
        while (!minHeap.empty()) {
            int x = minHeap.top().second;
            minHeap.pop();
            if (vis[x])
                continue;
            vis[x] = true;
            for (auto &v : neighbors_back[x]) {
                if (dist[v.first] > dist[x] + v.second) {
                    dist[v.first] = dist[x] + v.second;
                    minHeap.push(make_pair(dist[v.first], v.first));
                }
            }
        }
        for (int i = 1; i <= n; i++)
            res += dist[i];

        cout << res << endl;
    }

    return 0;
}