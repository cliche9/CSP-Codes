#include <iostream>
using namespace std;

int a[610][610];
// sum[i][j]: 第i行前j个数据之和
int sum[610][610];

int main() {
    int n, L, r, t;
    cin >> n >> L >> r >> t;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) 
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + a[i][j - 1];

    int res = 0;
    for (int i = 0; i < n; i++) {
        int upBorder = (i < r) ? 0 : i - r;
        int lowBorder = (i + r < n) ? i + r : n - 1;
        for (int j = 0; j < n; j++) {
            int leftBorder = (j < r) ? 0 : j - r;
            int rightBorder = (j + r < n) ? j + r : n - 1;
            double avg = 0;
            for (int k = upBorder; k <= lowBorder; k++) 
                avg += sum[k][rightBorder + 1] - sum[k][leftBorder];
            avg /= (lowBorder - upBorder + 1) * (rightBorder - leftBorder + 1);
            if (avg <= t)
                ++res;
        }
    }

    cout << res;

    return 0;
}