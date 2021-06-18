#include <iostream>
using namespace std;

int a[510][510];
int h[260];

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            ++h[a[i][j]];
        }
    }

    for (int i = 0; i < l; i++) 
        cout << h[i] << ' ';

    return 0;
}