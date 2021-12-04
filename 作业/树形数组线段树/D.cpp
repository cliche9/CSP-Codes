#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int inf = 1e6 + 10;
pair<int, int> nums[inf];
int sums[inf] = {0};
int cnt[inf] = {0};

#define lowbit(x) (x & (-x))
int query(int x) {
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        res += sums[i];
    return res;
}

void update(int x) {
    // 边界为inf! 因为second可能大于n, n为区间个数
    for (int i = x; i < inf; i += lowbit(i))
        sums[i]++;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i].first >> nums[i].second;
        nums[i].second++;
    }
    // sort排序, 先看first再看second
    sort(nums + 1, nums + n + 1);
    
    for (int i = 1; i <= n; i++) {
        // 先查后加
        cnt[query(nums[i].second)]++;
        update(nums[i].second);
    }

    for (int i = 0; i < n; i++)
        cout << cnt[i] << '\n';

    return 0;
}