#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int minGap = 10000;
    int n = 0;

    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            minGap = min(minGap, abs(num[i] - num[j]));

    printf("%d", minGap);
    return 0;
}