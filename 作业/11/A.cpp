#include <iostream>
#include <numeric>
using namespace std;

const int maxn = 1e6 + 1;
const int mod = 998244353;
int dp[maxn];
int number[maxn];
bool illegal[maxn] = {false};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        cin >> number[i];
        illegal[number[i]] = true;
    }
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (illegal[i]) {
            dp[i] = 0;
            continue;
        }
        for (int j = 1; j <= k && i - j >= 0; j++)
            dp[i] += dp[i - j];
        dp[i] %= mod;
    }   

    cout << dp[n];

    return 0;
}