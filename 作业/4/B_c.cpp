#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

vector<int> a;
vector<int> b;

int main() {
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.push_back(x);
    }

    x = *min_element(a.begin(), a.end());
    int y = *min_element(b.begin(), b.end());
    int p = accumulate(a.begin(), a.end(), 0) - x;
    int q = accumulate(b.begin(), b.end(), 0) - y;
    int maxx = max(p, q);

    int res = x + y + maxx;
    cout << res << endl;

    return 0;
}