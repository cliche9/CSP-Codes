#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

const int inf = 1e9 + 10;
const int mod = 1e9 + 7;
const int K = 11;
int n, k;
int C[K][K];

struct matrix {
    ll x[K + 2][K + 2];
    matrix() {
        memset(x, 0, sizeof(x));
        x[0][0] = 1;
        for (int i = 1; i < k + 2; i++)
            x[0][i] = C[k][i - 1];
        for (int i = 1; i < k + 2; i++) {
            for (int j = 0; j < i; j++)
                x[i][j] = 0;
            for (int j = i; j < k + 2; j++)
                x[i][j] = C[k - i + 1][j - i];
        }    
    }
    matrix(const matrix &m) { memcpy(x, m.x, sizeof(x)); }
    matrix operator*(const matrix& m) {
        matrix res;
        for (int i = 0; i < k + 2; i++) {
            for (int j = 0; j < k + 2; j++) {
                res.x[i][j] = 0;
                for (int f = 0; f < k + 2; f++) {
                    res.x[i][j] += x[i][f] * m.x[f][j] % mod;
                    res.x[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix quickPow(matrix m, int t) {
    matrix res;
    memset(res.x, 0, sizeof(res.x));
    for (int i = 0; i < k + 2; i++)
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
    int t = 0;
    cin >> t;
    C[0][0] = 1;
    for (int i = 1; i < K; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        matrix t;
        t = quickPow(t, n - 1);
        ll res = 0;
        for (int j = 0; j < k + 2; j++)
            res += t.x[0][j] % mod;
        cout << res % mod << endl;
    }

    return 0;
}