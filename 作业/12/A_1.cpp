#include <iostream>
using namespace std;

int weight[5010];
int value[5010];
int dp[5010];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];
    
    for (int i = 1; i <= n; i++) {
        for (int w = v; w >= 1; w--) {
            if (w < weight[i])
                continue;
            else
                dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    cout << dp[v];

    return 0;
}