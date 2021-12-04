#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[12][1 << 12];
int s[1 << 22][2];
int n = 0;
int h, w;

void dfs(int col, int pre_s, int now_s) {
    if (col > w)
        return;
    if (col == w) {
        s[n][0] = pre_s;
        s[n++][1] = now_s;
        return;
    }
    // 不放
    dfs(col + 1, (pre_s << 1) | 1, now_s << 1);
    // 竖放
    dfs(col + 1, (pre_s << 1), (now_s << 1) | 1);
    // 横放
    dfs(col + 2, (pre_s << 2) | 3, (now_s << 2) | 3);
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    cin >> h >> w;
    dfs(0, 0, 0);
    // 第0行全为1, 出现1次
    dp[0][(1 << w) - 1] = 1;
    for (int i = 0; i < h; i++)
        // 枚举每一行
        for (int j = 0; j < n; j++)
            // 枚举每行n种兼容方式
            dp[i + 1][s[j][1]] += dp[i][s[j][0]];

    cout << dp[h][(1 << w) - 1];
    return 0;
}