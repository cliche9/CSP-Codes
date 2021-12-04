#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int num = 1001;
bool vis[num] = {false};
int sum[num] = {0};
int cnt[num] = {0};
int total = 0;
int head[num] = {0};
int n = 0;

struct Edge {
    int u;
    int v;
    int w;
    int next;
} edges[4 * num];

void init(int n) {
    total = 0;
    for (int i = 0; i <= n; i++)
        head[i] = -1;
}

void addEdge(int u, int v, int w) {
    edges[total].u = u;
    edges[total].v = v;
    edges[total].w = w;
    edges[total].next = head[u];
    head[u] = total++;
}

bool spfa(int s) {
    fill(sum, sum + num, 2e6 + 1);
    queue<int> q;
    sum[s] = 0;
    vis[s] = true;
    q.push(s);

    while (!q.empty()) {
        int xj = q.front();
        q.pop();
        vis[xj] = false;

        for (int i = head[xj]; i != -1; i = edges[i].next) {
            int xi = edges[i].v;
            if (sum[xi] > sum[xj] + edges[i].w) {
                cnt[xi] = cnt[xj] + 1;
                if (cnt[xi] >= n) {
                    cout << "impossible";
                    return false;
                }
                sum[xi] = sum[xj] + edges[i].w;
                if (!vis[xi]) {
                    vis[xi] = true;
                    q.push(xi);
                }
            }
        }
    }

    return true;
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int m = 0;
    cin >> n >> m;
    init(n);

    // 每个坑最多一瓶酸奶
    for (int i = 1; i <= n; i++) {
        addEdge(i - 1, i, 1);
        addEdge(i, i - 1, 0);
    }

    for (int i = 0; i < m; i++) {
        int k, a, b, c;
        cin >> k >> a >> b >> c;
        switch(k) {
            case 1: {
                // sum[b] - sum[a - 1] <= c
                addEdge(a - 1, b, c);
                break;
            }
            case 2: {
                // sum[b] - sum[a - 1] >= c
                // sum[a - 1] - sum[b] <= -c
                addEdge(b, a - 1, -c);
                break;
            }
            case 3: {
                // sum[b] - sum[a - ] <= c - 1
                addEdge(a - 1, b, c - 1);
                break;
            }
            case 4: {
                // sum[a - 1] - sum[b] <= -1 - c
                addEdge(b, a - 1, -1 - c);
                break;
            }
            case 5: {
                // sum[b] - sum[a - 1] == c
                // sum[b] - sum[a - 1] <= c && sum[a - 1] - sum[b] <= -c
                addEdge(a - 1, b, c);
                addEdge(b, a - 1, -c);
                break;
            }
        }
    }

    if (spfa(0))
        cout << sum[n];
    
    return 0;
}