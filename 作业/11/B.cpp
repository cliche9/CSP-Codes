#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 1;
int nums[maxn];
int cnt[maxn] = {0};
long long sums[maxn];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }

    sums[1] = cnt[1];
    for (int i = 2; i < maxn; i++)
        sums[i] = max(sums[i - 1], sums[i - 2] + cnt[i] * i);

    cout << sums[maxn - 1];

    return 0;
}