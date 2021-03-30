#include <iostream>
using namespace std;

int w[10020] = {0};
bool geban[10020] = {false};
int minMax = INT_MAX;
int n, m;

void dfs(int left, int curPos) {
    if (curPos >= n)
        return;

    if (left == 1) {
        int curSum = 0;
        int preSum = 0;

        for (int i = 0; i < n; i++) {
            curSum += w[i];
            if (geban[i + 1] || i == n - 1) {
                preSum = max(preSum, curSum);
                curSum = 0;
            }
        }
        minMax = min(minMax, preSum);
        return;
    }

    geban[curPos] = true;
    dfs(left - 1, curPos + 1);
    geban[curPos] = false;
    dfs(left, curPos + 1);
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> w[i];

    dfs(m, 1);
    cout << minMax << endl;

    return 0;
}