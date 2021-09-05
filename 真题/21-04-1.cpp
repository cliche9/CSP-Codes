#include <iostream>
using namespace std;

int h[256];

int main() {
    int n, m, l;
    int t = 0;

    cin >> n >> m >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t;
            ++h[t];
        }
    }

    for (int i = 0; i < l; i++) 
        cout << h[i] << ' ';

    return 0;
}