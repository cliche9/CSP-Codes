#include <iostream>
#include <numeric>
using namespace std;

const int maxn = 1e6 + 1;
const int mod = 998244353;
int dp[maxn];
int sums[maxn];
bool illegal[maxn] = {false};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    int n, m, k, t, times;
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        cin >> t;
        illegal[t] = true;
    }
    
    sums[0] = dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (illegal[i]) {
            dp[i] = 0;
            sums[i] = sums[i - 1];
            continue;
        }
        if (i <= k)
            dp[i] = sums[i - 1];
        else {
            dp[i] = sums[i - 1] - sums[i - k - 1];
            if (dp[i] < 0)
                dp[i] += mod;
        }
        sums[i] = (sums[i - 1] + dp[i]) % mod;
    }

    cout << dp[n];

    return 0;
}