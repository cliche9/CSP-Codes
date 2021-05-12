#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 1;
int nums[maxn];
int top[maxn];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    int piles = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    for (int i = 0; i < n; i++) {
        int poker = nums[i];
        int left = 0, right = piles;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (top[mid] >= poker)
                right = mid;
            else
                left = mid + 1;
        }
        if (left == piles)
            piles++;
        top[left] = poker;
    }

    cout << piles;
    return 0;
}