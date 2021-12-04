#include <iostream>
using namespace std;

int main() {
    int input;
    int res = 0;
    int base = 0;
    while (cin >> input) {
        if (input == 0)
            break;
        switch (input) {
            case 1:
                res += 1;
                base = 0;
                break;
            case 2:
                base += 2;
                res += base;
                break;
        }
    }

    cout << res;

    return 0;
}