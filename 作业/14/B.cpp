#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 1e5;
int k = 0;
// minSum[cur][i]: 以cur为根的子树选取i个节点的最小路径和
long long minSum[inf][101];
// first - to, second - weight
vector<pair<int, int> > nodes[inf];
// num[i]: 以i为根节点的子树包含重要节点的个数
int num[inf];

void dfs(int cur, int pre) {
    for (auto &e : nodes[cur]) {
        if (e.first != pre) {
            dfs(e.first, cur);
            // minSum[cur][i] = min(minSum[cur][i], 
            // minSum[e.to][j] + minSum[cur][i - j] + j * (k - j) * e.weight)
            // 重要的节点数
            num[cur] += num[e.first];
            for (int i = min(k, num[cur]); i >= 0; --i)
                for (int j = 0; j <= i && j <= min(k, num[e.first]); ++j)
                    minSum[cur][i] = min(minSum[cur][i], minSum[e.first][j] + minSum[cur][i - j] + j * (k - j) * e.second);
        }
    }
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, m, a, b, c;
    cin >> n >> m >> k;
    memset(minSum, 63, sizeof(minSum));
    for (int i = 1; i <= m; i++) {
        int t = 0;
        cin >> t;
        num[t] = 1;
        minSum[t][1] = 0;
    }
    minSum[n][0] = 0;
    for (int i = 1; i < n; i++) {
        minSum[i][0] = 0;
        cin >> a >> b >> c;
        nodes[a].emplace_back(b, c);
        nodes[b].emplace_back(a, c);
    }

    dfs(1, 0);
    cout << minSum[1][k];

    return 0;
}