#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 1e6 + 10;
int nums[inf];
int cnt[inf];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    nums[0] = nums[n + 1] = 0;
    
    // unique return 去重后的尾地址
    n = unique(nums, nums + n + 2) - nums;

    for (int i = 1; i < n - 1; i++) {
        if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
            cnt[nums[i]]++;
        else if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1])
            cnt[nums[i]]--;
    }
    int res = 0, sum = 0;

    for (int i = 10000; i > 0; i--) {
        sum += cnt[i];
        res = max(res, sum);
    }

    cout << res;

    return 0;
}

