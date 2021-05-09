#include <iostream>
#define ll long long
using namespace std;

const int inf = 1e6 + 1;
int n = 0;
ll sums[inf] = {0};
#define lowbit(x) (x & (-x))
ll ask(int x) {
    ll res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        res += sums[i];
    return res;
}

void update(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        sums[i] += v;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    int q = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int v = 0;
        cin >> v;
        update(i, v);
    }
    
    for (int i = 0; i < q; i++) {
        int opt = 0;
        cin >> opt;
        if (opt == 1) {
            int j, x;
            cin >> j >> x;
            update(j, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ask(r) - ask(l - 1) << endl;
        }
    }

    return 0;
}