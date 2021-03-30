#include <cstdio>
#include <vector>
using std::vector;

int my_comp(const void *p1, const void *p2) {
    // 从小到大
    return *(int*)p1 - *(int*)p2;
}

int f(int x) {
    int a[10];
    int length = 0;
    int g1 = 0;
    int g2 = 0;

    while (x) {
        a[length++] = x % 10;
        x /= 10;
    }

    qsort(a, length, sizeof(int), my_comp);
    for (int i = 0; i < length; i++) {
        g1 *= 10;
        g1 += a[length - 1 - i];
        g2 *= 10;
        g2 += a[i];
    }

    return g1 - g2;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int ans = 0;
    int K = 0;
    scanf("%d%d", &ans, &K);

    for (int i = 0; i < K; i++)
        ans = f(ans);

    printf("%d", ans);
    return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n = 0;
    int right = 0;
    int left = 100;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        right = max(right, x[i]);
        left = min(left, x[i]);
    }

    int minCost = __INT_MAX__;

    for (int i = left + 1; i < right; i++) {
        int curCost = 0;
        for (int j = 0; j < n; j++)
            curCost += (x[j] - i) * (x[j] - i);
        minCost = min(minCost, curCost);
    }
    
    printf("%d", minCost);

    return 0;
}