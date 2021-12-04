#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 1e6 + 100;
struct building {
    int index;
    int visits;
    bool operator<(const building &b) const{
        return visits > b.visits;
    }
} buildings[inf];

int outSeq[inf];

int main() {
    ios::sync_with_stdio(false);

    int t = 0;
    cin >> t;

    for (int m = 0; m < t; m++) {
        int n = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> buildings[i].visits;
            buildings[i].index = i;
        }
        sort(buildings + 1, buildings + n + 1);

        long long res = 0;
        int pos = 1;
        for (int i = 1; i <= n; i++) {
            res += 2ll * pos * (long long)buildings[i].visits;
            outSeq[buildings[i].index] = (i & 1) ? pos : -(pos++);
        }

        cout << res << endl;
        for (int i = 0; i <= n; i++)
            cout << outSeq[i] << ' ';
        cout << endl;
    }

    return 0;
}