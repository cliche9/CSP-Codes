#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 5000;
int nums1[maxn];
int nums2[maxn];
int dp[maxn][maxn] = {0};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
        cin >> nums1[i];
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n1][n2];

    return 0;    
}
