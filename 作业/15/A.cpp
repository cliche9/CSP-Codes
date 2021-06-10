#include <iostream>
#include <cstring>
using namespace std;

const int inf = 1e9 + 10;
const int D = 2;
int n, p;

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
                    res.x[i][j] += x[i][k] * m.x[k][j] % p;
                    res.x[i][j] %= p;
                }
            }
        }
        return res;
    }
};

matrix quickPow(matrix m, int t) {
    matrix res;
    res.x[0][1] = res.x[1][0] = 0;
    res.x[0][0] = res.x[1][1] = 1;
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
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> p;
        if (n <= 2) {
            cout << 1 << endl;
            continue;
        }
        matrix t;
        t.x[0][0] = t.x[0][1] = t.x[1][0] = 1;
        t.x[1][1] = 0;
        t = quickPow(t, n - 2);
        cout << (t.x[0][0] + t.x[0][1]) % p << endl;
    }

    return 0;
}