#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 1e6;
int sum[200];
// small[i][j]: 区间[i, j]合并的耗费最小值
int small[200][200];
int large[200][200];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    int stones[2 * n];
    memset(small, 63, sizeof(small));
    for (int i = 1; i <= n; i++) 
        cin >> stones[i];
    for (int i = 1; i < n; ++i)
        stones[i + n] = stones[i];
    
    for (int i = 1; i <= 2 * n - 1; ++i) {
        // 前缀和sum[i]: [1, i]区间合并耗费
        sum[i] = sum[i - 1] + stones[i];
        small[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= 2 * n - len; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                small[i][j] = min(small[i][j], small[i][k] + small[k + 1][j] + sum[j] - sum[i - 1]);
                large[i][j] = max(large[i][j], large[i][k] + large[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    
    int res1 = inf, res2 = 0;
    for (int i = 1; i <= n; ++i) {
        res1 = min(res1, small[i][i + n - 1]);
        res2 = max(res2, large[i][i + n - 1]);
    }
    cout << res1 << endl << res2 << endl;

    return 0;
}