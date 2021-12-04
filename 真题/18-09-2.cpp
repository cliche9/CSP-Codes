#include <iostream>
#include <vector>
using namespace std;

const int inf = 1e6 + 10;
int t[inf];
int sum[inf];

int main() {
    int n = 0;
    cin >> n;
    
    int ai, bi;
    for (int i = 0; i < n; i++) {
        cin >> ai >> bi;
        for (int j = ai + 1; j <= bi; j++)
            t[j] = 1;
    }

    for (int i = 1; i < inf; i++)
        sum[i] = sum[i - 1] + t[i];

    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> ai >> bi;
        res += (sum[bi] - sum[ai]);
    }

    cout << res;

    return 0;
}