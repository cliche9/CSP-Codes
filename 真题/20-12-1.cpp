#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, s, w, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> w >> s;
        sum += (s * w);
    }

    cout << max(sum, 0);

    return 0;
}