#include <bits/stdc++.h>
using namespace std;

int tracks[30010];
vector<tuple<int, int, int>> luduan;
long long res;

int main() {
    int n, m;
    cin >> n >> m;

    int l, r, k;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        luduan.emplace_back(make_tuple(l, r, k));
    }
    sort(luduan.begin(), luduan.end(), [](const tuple<int, int, int> &p1, const tuple<int, int, int> &p2) {
        return get<1>(p1) < get<1>(p2);
    });

    while (luduan.size()) {
        tuple<int, int, int> a = luduan.front();
        int exists = 0;
        for (int i = get<0>(a); i <= get<1>(a); i++)
            if (tracks[i])
                exists++;

        int left = get<2>(a) - exists;
        for (int i = get<1>(a); i >= get<0>(a) && left > 0; i--) {
            if (!tracks[i]) {
                tracks[i] = 1;
                left--;
                res++;
            }
        }
        luduan.erase(luduan.begin());
    }

    cout << res << endl;
    return 0;
}