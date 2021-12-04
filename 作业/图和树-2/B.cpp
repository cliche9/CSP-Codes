#include <iostream>
#include <algorithm>
using namespace std;

bool intervalH[1000001] = {false};
bool intervalW[1000001] = {false};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    int res = 0;
    int left = 1e6;
    int right = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        left = min(left, ai);
        right = max(right, bi);
        for (int j = ai + 1; j <= bi; j++)
            intervalH[j] = true;
    }

    for (int i = 0; i < n; i++) {
        int ci, di;
        cin >> ci >> di;
        left = min(left, ci);
        right = max(right, di);
        for (int j = ci + 1; j <= di; j++)
            intervalW[j] = true;
    }

    for (int i = left; i <= right; i++) {
        intervalH[i] &= intervalW[i];
        if (intervalH[i])
            res++;
    }
    cout << res;
    return 0;
}