#include <iostream>
using namespace std;
const long long mod = 1e9 + 7;
long long nums_index[100][100002] = {0};
long long minIndexs[100];
bool primes[100] = {false};

void getIndex(int l, int r, int c, long long b) {
    // 获取质因子的指数
    for (int i = 2; i < 100 && c != 1; i++) {
        while (primes[i] && c % i == 0) {
            c /= i;
            // 差分将区间操作化为点操作
            nums_index[i][l] += b;
            nums_index[i][r + 1] -= b;
        }
    }
}

long long quickPow(long long c, long long b, long long part_sum) {
    long long ans = part_sum;
    while (b) {
		if (b & 1)
			ans = (ans * c) % mod;
		b >>= 1;
		c = (c * c) % mod;
	}
	return ans;
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    // 筛出100内的质数
    for (int i = 2; i < 100; i++)
        if (i & 1)
            primes[i] = true;
    primes[2] = true;

    for (int i = 3; i < 100; i += 2)
        if (primes[i])
            for (int j = 2 * i; j < 100; j += i)
                primes[j] = false;
    
    int n = 0, m = 0;
    long long res = 1;
    cin >> n >> m;
    for (int i = 0; i < 100; i++)
        minIndexs[i] = __LONG_LONG_MAX__;

    for (int i = 0; i < m; i++) {
        // 处理m个区间
        long long l, r, c, b;
        cin >> l >> r >> c >> b;
        getIndex(l, r, c, b);
    }

    for (int i = 2; i < 100; i++) {
        if (primes[i]) {
            long long index = 0;
            for (int j = 1; j <= n; j++) {
                // 求和求质数的最小指数
                index += nums_index[i][j];
                minIndexs[i] = min(minIndexs[i], index);
            } 
        }
    }

    for (int i = 2; i < 100; i++) {
        // 对所有质因子求快速幂
        if (primes[i] && minIndexs[i]) {
            res = quickPow(i, minIndexs[i], res);
        }
    }

    cout << res << endl;

    return 0;
}