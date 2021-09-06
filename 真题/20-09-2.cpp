#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 1e3 + 10;

struct {
    int x[inf];
    int y[inf];
} position[30];

int main() {
    int n, k, t, x_l, y_d, x_r, y_u;
    cin >> n >> k >> t >> x_l >> y_d >> x_r >> y_u;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < t; j++)
            cin >> position[i].x[j] >> position[i].y[j];

    int res1 = 0, res2 = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        bool risky = false;
        for (int j = 0; j < t; j++) {
            if (position[i].x[j] >= x_l && position[i].x[j] <= x_r && position[i].y[j] >= y_d && position[i].y[j] <= y_u) {
                ++count;
                risky = true;
            } else {
                count = 0;
            }
            if (count >= k) {
                ++res2;
                break;
            }
        }
        res1 += risky;
    }

    cout << res1 << endl << res2;
    
    return 0;
}