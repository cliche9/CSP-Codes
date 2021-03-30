#include <iostream>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n = 0;
    int res = 0;
    cin >> n;
    
    int nums[n];

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n);
    for (int i = 1; i < n; i++) {
        if (nums[i] - nums[i - 1] == 1)
            res++;
    }

    cout << res;
    return 0;
}