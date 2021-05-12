#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 1;
int nums[3][maxn];
long long sums[maxn][3] = {0};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;

    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++) 
            cin >> nums[i][j];

    for (int i = 2; i <= n; i++) {
        sums[i][0] = min({sums[i - 1][0] + abs(nums[0][i] - nums[0][i - 1]), sums[i - 1][1] + abs(nums[0][i] - nums[1][i - 1]), sums[i - 1][2] + abs(nums[0][i] - nums[2][i - 1])});
        sums[i][1] = min({sums[i - 1][0] + abs(nums[1][i] - nums[0][i - 1]), sums[i - 1][1] + abs(nums[1][i] - nums[1][i - 1]), sums[i - 1][2] + abs(nums[1][i] - nums[2][i - 1])});
        sums[i][2] = min({sums[i - 1][0] + abs(nums[2][i] - nums[0][i - 1]), sums[i - 1][1] + abs(nums[2][i] - nums[1][i - 1]), sums[i - 1][2] + abs(nums[2][i] - nums[2][i - 1])});
    }

    cout << min({sums[n][0], sums[n][1], sums[n][2]});

    return 0;
}