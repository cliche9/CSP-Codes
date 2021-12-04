#include <iostream>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    int cur = 0;
    int res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cur++;
        else {
            if (cur == 0)
                continue;
            res = max(res, cur);
            cur = 0;
        }
    }

    cout << res << endl;
    return 0;
}