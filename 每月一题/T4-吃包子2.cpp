#include <iostream>
#include <set>
using namespace std;

const int maxX = 1e6 + 10;
int a[maxX];
// 要使数t符合条件, 需要删除的区间为[ L[t], R[t] ]
int L[maxX], R[maxX];
// 要使数[1, i]符合条件, 需要删除区间为[ preL[i], preR[i] ]
int preL[maxX], preR[maxX];
// 要使数[i, x]符合条件, 需要删除区间为[ sufL[i], sufR[i] ]
int sufL[maxX], sufR[maxX];

int n, x;

void init() {
    for (int i = 0; i <= x + 1; i++)
        L[i] = preL[i] = sufL[i] = x + 1;

    set<int> s1;
    for (int i = 1; i <= n; i++) {
        int t = a[i];
        auto iter = s1.upper_bound(t);
        if (iter == s1.end()) {
            s1.insert(t);
            continue;
        }
        L[t] = min(L[t], *iter);
        R[t] = max(R[t], *s1.rbegin());
        s1.insert(t);
    }
    set<int, greater<int> > s2;
    for (int i = n; i >= 1; i--) {
        int t = a[i];
        auto iter = s2.upper_bound(t);
        if (iter == s2.end()) {
            s2.insert(t);
            continue;
        }
        L[t] = min(L[t], *s2.rbegin());
        R[t] = max(R[t], *iter);
        s2.insert(t);
    }

    for (int i = 1; i <= x; i++) {
        preL[i] = min(preL[i - 1], L[i]);
        preR[i] = max(preR[i - 1], R[i]);
    }
    for (int i = x; i >= 1; i--) {
        sufL[i] = min(sufL[i + 1], L[i]);
        sufR[i] = max(sufR[i + 1], R[i]);
    }
}

bool check(int i, int mid) {
    if (mid <= preR[i])
        return false;
    if (mid <= sufR[mid])
        return false;
    if (i >= sufL[mid])
        return false;
    return true;
}

int main() {
    freopen("每月一题/a.in", "r", stdin);
    freopen("每月一题/a.out", "w", stdout);
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    init();

    long long res = 0;
    for (int i = 0; i < x; i++) {
        // 删除(i, mid)
        if (i >= preL[i])
            break;
        int left = i + 1, right = x + 1;
        while (left < right - 1) {
            int mid = (left + right) >> 1;
            if (check(i, mid))
                right = mid;
            else 
                left = mid;
        }
        res += x + 1 - left;
    }

    cout << res;
    return 0;
}