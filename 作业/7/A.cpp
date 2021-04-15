#include <iostream>
using namespace std;

int nums[1001] = {0};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    cout << (nums[1] + nums[2]) / 2 << ' ';

    for (int i = 2; i <= n - 1; i++)
        cout << (nums[i - 1] + nums[i] + nums[i + 1]) / 3 << ' ';

    cout << (nums[n - 1] + nums[n]) / 2;

    return 0;
}