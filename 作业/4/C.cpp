#include <iostream>
using namespace std;

int w[10020];
int geban[10020];
int minn = 2147483647;
int n, m;

//k代表已经插入几个隔板了，i代表已经决定哪个位置了
void dfs(int k, int ii) {
    if (ii == n + 1)
        return;
    if (k == (m - 1)) {
        int sum = 0;
        int summ = -1;

        for (int i = 0; i < n; i++) {
            sum += w[i];
            if (i == n - 1 || geban[i + 1] == 1) {
                if (sum > summ)
                summ = sum;
                sum = 0;
            }
        }
        if (summ < minn)
            minn = summ;
        return;
    }
    geban[ii] = 1;
    dfs(k + 1, ii + 1);
    geban[ii] = 0;
    dfs(k, ii + 1);
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    cin >> n >> m;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        w[i] = x;
    }
    dfs(0, 1);
    cout << minn << endl;

    return 0;
}