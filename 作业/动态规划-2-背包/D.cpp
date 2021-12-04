#include <iostream>
using namespace std;

int numberOfThings[110][110];
int weight[1010];
int value[1010];
int cnt[1010];
int dp[1010];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, v;
    cin >> n >> v;

    int numberOfGroup = 0;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> weight[i] >> value[i] >> k;
        cnt[k]++;
        numberOfThings[k][cnt[k]] = i;
        numberOfGroup = max(numberOfGroup, k);
    }
    for (int k = 1; k <= numberOfGroup; k++) {
        // weight[numberOfThings[k][i]] : 第k组第i个物品的重量
        // dp[k][w] : 考虑容量为w的背包, 对前k个组的最大值
        for (int w = v; w >= 1; w--) {
            for (int i = 1; i <= cnt[k]; i++) {
                if (w >= weight[numberOfThings[k][i]])
                    dp[w] = max(dp[w], dp[w - weight[numberOfThings[k][i]]] + value[numberOfThings[k][i]]);
            }
        }
    }

    cout << dp[v];

    return 0;
}