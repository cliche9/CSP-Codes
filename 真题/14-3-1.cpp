#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n = 0;
    int res = 0;
    int t = 0;
    unordered_map<int, bool> mapping;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        mapping[t] = true;
        if (t > 0 && mapping.count(-t))
            res++;
        if (t < 0 && mapping.count(-t))
            res++;
    }

    cout << res;
    return 0;
}