#include <iostream>
using namespace std;

int a[610][610];
int sum[610][610];

int main() {
    int n, l, r, t;
    cin >> n >> l >> r >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + a[i][j - 1];
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int up = i >= r ? i - r : 0;
        int down = i <= n - 1 - r ? i + r : n - 1;
        for (int j = 0; j < n; j++) {
            double s = 0;
            int left = j >= r ? j - r: 0;
            int right = j <= n - 1 - r ? j + r : n - 1;
            for (int k = up; k <= down; k++)
                s += sum[k][right + 1] - sum[k][left];
            s /= ((down - up + 1) * (right - left + 1));
            if (s <= t)
                ++res;
        }
    }

    cout << res;

    return 0;
}