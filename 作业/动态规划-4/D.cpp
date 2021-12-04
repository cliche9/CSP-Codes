#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int inf = 5010;
const int mod = 1e9 + 7;
// dp[i][j]: 按i次电梯到达第j层的方案数
int dp[2][inf];
// sum[i][j] = sigma(dp[i][k]) (1 <= k <= j)
int sum[2][inf];
// 求floor((y + b) / 2): y + (b - y - 1) / 2
// 求ceil((y + b) / 2): y - (y - b - 1) / 2


int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    /*
    dp[0][a] = 1;
    for (int i = 1; i <= k; i++) {
        for (int y = 1; y <= n; y++) {
            if (y == b)
                continue;
            for (int x = 1; x <= n; x++) {
                if (x == b || x == y)
                    continue;
                if (abs(x - y) < abs(x - b)) {
                    dp[i][y] += dp[i - 1][x];
                    dp[i][y] %= mod;
                }
            }
        }
    }
 
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + dp[k][i]) % mod;
    */
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    dp[0][a] = 1;
    for (int i = a; i <= n; i++)
        sum[0][i] = 1;
    
    int now = 0, pre = 0;;
    for (int i = 1; i <= k; i++) {
        pre = now;
        now = i % 2;
        for (int y = 1; y <= n; y++) {
            if (y == b)
                continue;
            if (y < b)
                // 前缀和包含dp[pre][y], 需要减去
                dp[now][y] = ((sum[pre][y + (b - y - 1) / 2] - sum[pre][0] - dp[pre][y]) % mod + mod) % mod;
            else
                dp[now][y] = ((sum[pre][n] - sum[pre][y - (y - b - 1) / 2 - 1] - dp[pre][y]) % mod + mod) % mod;
            // 更新前缀和
            sum[now][y] = (sum[now][y - 1] + dp[now][y]) % mod;
        }
    }

    int res = 0;
    int t = k % 2;
    for (int i = 1; i <= n; i++)
        res = (res + dp[t][i]) % mod;

    cout << res;

    return 0;
}