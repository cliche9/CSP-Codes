#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

const int inf = 1e8 + 10;
const int M = 110;
int n, m;

// dp[i][j]: 第i天穿衣服j的快乐值和
// dp[i][j] = max(dp[i - 1][k] + h[k][j]), 1 <= k <= M
// 将矩阵乘法改为求最大值
struct matrix {
    ll x[M][M];
    matrix() { memset(x, 0, sizeof(x)); }
    matrix(const matrix &mt) { memcpy(x, mt.x, sizeof(x)); }
    matrix operator*(const matrix& mt) {
        matrix res;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                res.x[i][j] = 0;
                for (int k = 1; k <= m; k++)
                    res.x[i][j] = max(res.x[i][j], x[i][k] + mt.x[k][j]);
            }
        }
        return res;
    }
};

matrix quickPow(matrix mt, int t) {
    matrix res;
    // 1元此时变为0
    memset(res.x, 0, sizeof(res.x));
    while (t) {
        if (t & 1)
            res = res * mt;
        mt = mt * mt;
        t >>= 1;
    }
    return res;
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    cin >> n >> m;
    matrix t;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cin >> t.x[i][j];

    t = quickPow(t, n - 1);
    
    ll res = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, t.x[i][j]);
    cout << res;

    return 0;
}