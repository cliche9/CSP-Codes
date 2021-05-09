#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int inf = 1e6 + 2;
int n = 0;
pair<int, int> nums[inf];
int sums[inf] = {0};
int cnt[inf] = {0};

#define lowbit(x) (x & (-x))
int ask(int x) {
    int res = 0;
    for (int i = x; i >= 1; i -= lowbit(i))
        res += sums[i];
    return res;
}

void update(int x) {
    for (int i = x; i <= n; i += lowbit(i))
        sums[i]++;
}

int main() {
    ios::sync_with_stdio(false);
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i].first >> nums[i].second;
    
    sort(nums + 1, nums + n + 1);
    
    for (int i = 1; i <= n; i++) {
        cnt[ask(nums[i].second + 1)]++;
        update(nums[i].second + 1);
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", cnt[i]);

    return 0;
}