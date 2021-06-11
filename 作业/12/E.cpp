#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
const ll inf = 1e18 + 1;
ll weight[50];
ll value[50];
int n = 0;
ll v = 0;
vector<pair<ll, ll> > preSum;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    cin >> n >> v;

    for (int i = 0; i < n; i++) 
        cin >> weight[i] >> value[i];
    
    int m = n / 2;
    for (int i = 0; i < (1 << m); i++) {
        // 枚举每个组所有物品, 得到一系列空间-价值对
        ll sumWeight = 0, sumValue = 0;
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                sumWeight += weight[j];
                sumValue += value[j];
            }
        }
        preSum.emplace_back(sumWeight, sumValue);
    }

    sort(preSum.begin(), preSum.end());

    int cnt = 1;
    for (int i = 1; i < (1 << m); i++)
        // first -- weight, second -- value
        if (preSum[cnt - 1].second < preSum[i].second)
            preSum[cnt++] = preSum[i];
    

    ll res = 0;
    for (int i = 0; i < (1 << (n - m)); i++) {
        ll sumWeight = 0, sumValue = 0;
        for (int j = 0; j < (n - m); j++) {
            if ((i >> j) & 1) {
                sumWeight += weight[m + j];
                sumValue += value[m + j];
            }
        }
        if (sumWeight <= v) {
            auto iter = upper_bound(preSum.begin(), preSum.begin() + cnt, make_pair(v - sumWeight, inf));
            --iter;
            res = max(res, sumValue + iter->second);
        }
    }

    cout << res;

    return 0;
}