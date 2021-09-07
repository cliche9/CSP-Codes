#include <iostream>
using namespace std;

bool contain7(int num) {
    while (num > 0) {
        if (num % 10 == 7)
            return true;
        num /= 10;
    }

    return false;
}

int main() {
    int n = 0;
    cin >> n;

    int num = 0;
    int skipNumber[4] = {0};
    int curNumber = 3;

    while (n > 0) {
        ++num;
        curNumber = (curNumber + 1) % 4;
        if (num % 7 == 0 || contain7(num))
            ++skipNumber[curNumber];
        else 
            --n;
    }

    for (int i = 0; i < 4; i++)
        cout << skipNumber[i] << endl;

    return 0;
}