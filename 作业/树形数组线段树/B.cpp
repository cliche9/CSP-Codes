#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);

    int n = 0;
    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", nums + i);

    sort(nums, nums + n);
    printf("%d ", nums[n - 1]);
    if (n & 1)
        printf("%d ", nums[n / 2]);
    else {
        if ((nums[n / 2 - 1] + nums[n / 2]) % 2)
            printf("%.1f ", (nums[n / 2 - 1] + nums[n / 2]) / 2.0);
        else 
            printf("%d ", (nums[n / 2 - 1] + nums[n / 2]) / 2);
    }
    printf("%d", nums[0]);

    return 0;
}