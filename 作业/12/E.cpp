#include <iostream>
#include <set>
#define ll long long
using namespace std;

ll weight[41];
ll value[41];
set<pair<ll, ll> > set1;
set<pair<ll, ll> > set2;
ll preSum[41];
ll res;
int n = 0;
int v = 0;

void backtrack(int start, ll w, ll v, int end, bool tag) {
    if (start == end) {
        if (tag) {
            set1.insert(make_pair(w, v));
            set1.insert(make_pair(w + weight[start], v + value[start]));
        }
        else {
            set2.insert(make_pair(w, v));
            set2.insert(make_pair(w + weight[start], v + value[start]));
        }
        return;
    }
    if (tag) {
        backtrack(start + 1, w + weight[start], v + value[start], end, tag);
        backtrack(start + 1, w, v, end, tag);
    }
    else {
        backtrack(start + 1, w + weight[start], v + value[start], end, tag);
        backtrack(start + 1, w, v, end, tag);
    }
}

void init() {
    backtrack(0, 0, 0, n / 2, false);
    backtrack(n / 2 + 1, 0, 0, n, true);

    auto iter = set1.begin();
    auto rm = iter;
    ++rm;
    while (rm != set1.end()) {
        while (iter->second >= rm->second)
            rm = set1.erase(rm);
        ++iter;
        ++rm;
    }
    iter = set2.begin();
    rm = iter;
    ++rm;
    while (rm != set2.end()) {
        while (iter->second >= rm->second)
            rm = set1.erase(rm);
        ++iter;
        ++rm;
    }

    
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    cin >> n >> v;

    for (int i = 1; i <= n; i++) 
        cin >> weight[i] >> value[i];
    
    init();

    return 0;
}