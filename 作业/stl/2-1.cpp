#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("作业/a.in", "r", stdin);
    freopen("作业/a.out", "w", stdout);
    int n = 0;
    int res = 0;
    cin >> n;
    vector<int> nums(n);
    for (auto& i : nums) 
        cin >> i;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++) 
        if (nums[i] - nums[i - 1] == 1)
            res++;
    
    cout << res;

    return 0;
}