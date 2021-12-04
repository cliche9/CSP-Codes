#include <iostream>
using namespace std;

int weight[5010];
int value[5010];
int dp[5010][5010];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];
    
    for (int w = 1; w <= v; w++) {
        for (int i = 1; i <= n; i++) {
            if (w < weight[i])
                dp[w][i] = dp[w][i - 1];
            else
                dp[w][i] = max(dp[w][i - 1], dp[w - weight[i]][i - 1] + value[i]);
        }
    }

    cout << dp[v][n];

    return 0;
}