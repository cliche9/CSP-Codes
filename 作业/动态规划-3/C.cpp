#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// dp[i][j]: 区间[i, j]的最长回文子序列长度
int dp[4000][4000];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else 
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    cout << dp[0][n - 1];

    return 0;
}