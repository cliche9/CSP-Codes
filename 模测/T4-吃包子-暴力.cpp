#include <iostream>
#include <map>
using namespace std;

// first - value, second - endIndex
map<int, pair<int, int> > baozi;
int n = 0;
int x = 0;
int res = 0;

bool check(int l, int r) {
    auto iter = baozi.begin();
    int curBeginIndex = 0, preEndIndex = 0;
    for (auto iter = baozi.begin(); iter != baozi.end(); ++iter) {
        if (iter->first >= l && iter->first <= r)
            continue;
        if (preEndIndex > iter->second.first)
            return false;
        preEndIndex = iter->second.second;
    }

    return true;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int si = 0;
        cin >> si;
        if (baozi[si].first == 0)
            baozi[si].first = i;
        baozi[si].second = i;
    }

    for (int i = 1; i <= x; i++) {
        for (int j = i; j <= x; j++) {
            if (check(i, j)) {
                res += (x - j + 1);
                break;
            }
        }
    }
    
    cout << res;

    return 0;
}