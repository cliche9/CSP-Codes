#include <iostream>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    int r, y, g;
    cin >> r >> y >> g;

    int n = 0;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int k, t;
        cin >> k >> t;
        switch (k) {
            case 0:
                res += t;
                break;
            case 1:
                res += t;
                break;
            case 2:
                res += (t + r);
                break;
            case 3:
                break;
        }
    }
    cout << res;

    return 0;
}