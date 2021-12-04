#include <iostream>
using namespace std;

const int inf = 610;
int img[inf][inf];
int sum[inf][inf];

int main() {
    int n, L, r, t;
    cin >> n >> L >> r >> t;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> img[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + img[i][j];

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pair<int, int> leftUp((i > r) ? i - r : 1, (j > r) ? j - r : 1);
            pair<int, int> rightBottom((i + r > n) ? n : i + r, (j + r > n) ? n : j + r);
            int count = (rightBottom.first - leftUp.first + 1) * (rightBottom.second - leftUp.second + 1);
            if ( sum[rightBottom.first][rightBottom.second] - sum[rightBottom.first][leftUp.second - 1] - sum[leftUp.first - 1][rightBottom.second] + sum[leftUp.first - 1][leftUp.second - 1] <= (t * count) )
                res++;
        }
    }

    cout << res;

    return 0;
}