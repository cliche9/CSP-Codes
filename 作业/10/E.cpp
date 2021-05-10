#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 2e5 + 1;
int tree[inf << 2];
int p = 0;
int a = 0;

void update(int root, int left, int right, int pos, int newVal) {
    if (left == right) {
        tree[root] = newVal;
        return;
    }
    int mid = (left + right) / 2;
    if (pos <= mid)
        update(root << 1, left, mid, pos, newVal);
    else
        update(root << 1 | 1, mid + 1, right, pos, newVal);
    tree[root] = max(tree[root << 1], tree[root << 1 | 1]);
}

int query(int root, int left, int right, int lower_bound, int upper_bound) {
    if (left == lower_bound && right == upper_bound)
        return tree[root];
    int mid = (left + right) / 2;
    if (upper_bound <= mid)
        return query(root << 1, left, mid, lower_bound, upper_bound);
    if (lower_bound > mid)
        return query(root << 1 | 1, mid + 1, right, lower_bound, upper_bound);
    // 分散在两个区间
    return max(query(root << 1, left, mid, lower_bound, mid), query(root << 1 | 1, mid + 1, right, mid + 1, upper_bound));
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int m;
    int n = 0;
    cin >> m >> p;
    for (int i = 0; i < m; i++) {
        char opt;
        cin >> opt;
        if (opt == 'Q') {
            int l = 0;
            cin >> l;
            a = query(1, 1, 2e5, n - l + 1, n);
            cout << a << '\n';
        } else {
            int t = 0;
            cin >> t;
            update(1, 1, 2e5, ++n, (t + a) % p);
        }
    }

    return 0;
}