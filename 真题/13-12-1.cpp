#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    unordered_map<int, int> mapping;
    int n = 0, t = 0;
    int maxCount = 0;
    int ans = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        mapping[t]++;
        if (mapping[t] > maxCount) {
            maxCount = mapping[t];
            ans = t;
        }
        if (mapping[t] == maxCount && t < ans)
            ans = t;
    }
    printf("%d", ans);

    return 0;
}
