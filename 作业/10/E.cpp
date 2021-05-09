#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 2e5 + 1;
int n = 0;
int a = 0;
int p = 0;
int d[inf << 2];
int s[inf];

void build(int x, int l, int r) {
    if (l >= r) {
        d[x] = s[l];
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    d[x] = max(d[x * 2], d[x * 2 + 1]);
}

int ask(int x, int l, int r, int p1, int p2) {
    if (l == p1 && r == p2)
        return d[x];
    int m = (l + r) / 2;
    if (p2 <= m)
        return ask(x * 2, l, m, p1, p2);
    if (p1 > m)
        return ask(x * 2 + 1, m + 1, r, p1, p2);
    int lch_val = ask(x * 2, l, m, p1, m);
    int rch_val = ask(x * 2 + 1, m + 1, r, m + 1, p2);
    return max(lch_val, rch_val);
}


int main() {
    ios::sync_with_stdio(false);
    int m;
    cin >> m >> p;

    for (int i = 0; i < m; i++) {
        char opt;
        cin >> opt;
        if (opt == 'Q') {
            int l = 0;
            cin >> l;
            a = ask(1, 1, n, n - l + 1, n);
            cout << a << endl;
        } else {
            int t = 0;
            cin >> t;
            s[++n] = (t + a) % p;
            build(1, 1, n);
        }
    }
    
    return 0;
}