#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

const int mod = 998244353;
const int inf = 1e9 + 10;
const int D = 3;

// a[i]: 前i个像素点有偶数个蓝色和绿色像素的方案数
// b[i]: 全为奇数
// c[i]: 有一个偶数
// a[i] = a[i - 1] + c[i - 1]
// b[i] = b[i - 1] + c[i - 1]
// c[i] = 2 * a[i - 1] + 2 * b[i - 1] + c[i - 1]
struct matrix {
    long long x[D][D];
    matrix() { memset(x, 0, sizeof(x)); }
    matrix(const matrix &m) { memcpy(x, m.x, sizeof(x)); }
    matrix operator*(const matrix& m) {
        matrix res;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < D; j++) {
                res.x[i][j] = 0;
                for (int k = 0; k < D; k++) {
                    res.x[i][j] += x[i][k] * m.x[k][j] % mod;
                    res.x[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix quickPow(matrix m, int t) {
    matrix res;
    for (int i = 0; i < D; i++)
        res.x[i][i] = 1;
    while (t) {
        if (t & 1)
            res = res * m;
        m = m * m;
        t >>= 1;
    }
    return res;
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int t = 0, n = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        matrix t;
        t.x[0][0] = t.x[0][2] = t.x[1][1] = t.x[1][2] = t.x[2][2] = 1;
        t.x[2][0] = t.x[2][1] = 2;
        t = quickPow(t, n);
        cout << t.x[0][0] % mod << endl;
    }

    return 0;
}