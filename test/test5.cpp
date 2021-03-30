#include <iostream>
using namespace std;

int main() {
    int a[5];
    memset(a, -1, sizeof(a));

    for (int i = 0; i < 5; i++)
        cout << a[i] << endl;

    return 0;
}