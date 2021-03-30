#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n = 0;
    cin >> n;
    int visitor[n + 1];
    memset(visitor, 0, sizeof(visitor));

    for (int i = 0; i < n; ++i) {
        int t = 0;
        cin >> t;
        cout << ++visitor[t] << ' ';
    }

    return 0;
}