#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int prices[110];

    int t = 0;
    cin >> t;

    for (int m = 0; m < t; m++) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        for (int i = 0; i < n; i++)
            cin >> prices[i];
        sort(prices, prices + n);
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] > r)
                break;
            if (prices[i] < l)
                continue;
            if (k < prices[i])
                break;
            res++;
            k -= prices[i];
        }

        cout << res << endl;
    }

    return 0;
}