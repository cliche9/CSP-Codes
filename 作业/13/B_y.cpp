#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[200][200];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    string s;
    cin >> s;
    int len = s.length();
    memset(dp, 63, sizeof(dp));
    for (int i = 1; i <= len; ++i) {
        dp[i][i] = 1;
        for (int j = 1; j < i; ++j)
            dp[i][j] = 0;
    }
    for (int d = 2; d <= len; ++d) {
        for (int i = 1; i <= len + 1 - d; ++i) {
            int j = i + d - 1;
            if ((s[i - 1] == '(' && s[j - 1] == ')') || (s[i - 1] == '[' && s[j - 1] == ']'))
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            for (int k = i; k < j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
    cout << dp[1][len];

    return 0;
}