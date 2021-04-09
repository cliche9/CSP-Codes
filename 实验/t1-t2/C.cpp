#include <iostream>
using namespace std;

string check(int n) {
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (i & 1)
                odd++;
            else
                even++;
        }
    }
    if (odd > even)
        return "Odd";
    else if (odd < even)
        return "Even";
    else
        return "Same";
}

int main() {
    freopen("实验/t1-t2/a.in", "r", stdin);
    freopen("实验/t1-t2/a.out", "w", stdout);
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        cout << check(n) << endl;
    }

    return 0;
}