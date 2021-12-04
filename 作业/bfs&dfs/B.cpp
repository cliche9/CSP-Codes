#include <iostream>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int res = 0;
    int opt = 0;
    int increment = 1;

    while (cin >> opt && opt != 0) {
        if (opt == 1)
            increment = 1;
        else if (opt == 2) {
            if (increment == 1)
                ++increment;
            else
                increment += 2;
        }
        res += increment;
    }
    cout << res;

    return 0;
}