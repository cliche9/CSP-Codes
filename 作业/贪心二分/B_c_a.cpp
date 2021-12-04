#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int min_a = *min_element(a, a + n);
    int min_b = *min_element(b, b + n);
    int sum_a = 0;
    int sum_b = 0;
    for (int i = 0; i < n; i++) {
        sum_a += a[i];
        sum_b += b[i];
    }

    cout << min_a + min_b + max(sum_a - min_a, sum_b - min_b) << endl;
    return 0;
}