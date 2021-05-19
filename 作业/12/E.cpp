#include <iostream>
#include <set>
#define ll long long
using namespace std;

ll weight[41];
ll value[41];
set<pair<ll, ll> > sets;
ll preSum[41];
ll res;
int n = 0;
int v = 0;

void backtrack(int level, ll w, ll v, int end) {
    if (w < 0)
        return;
    
    if (level == end) {
        if (w < weight[level])
            sets.insert(make_pair(v - w, v));
        else
            sets.insert(make_pair(v - w + weight[level], v + value[level]));
        return;
    }
    backtrack(level + 1, w - weight[level], v + value[level], end);
    backtrack(level + 1, w, v, end);
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    cin >> n >> v;

    for (int i = 1; i <= n; i++) 
        cin >> weight[i] >> value[i];
    
    backtrack(0, v / 2, 0, n / 2);
    backtrack(n / 2 + 1, v / 2, 0, n);

    return 0;
}