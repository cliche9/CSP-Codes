#include <iostream>
#include <set>
using namespace std;

const int inf = 1e3 + 10;

set<pair<int, int> > position;

int res[5] = {0};
int offset[2] = {-1, 1};

bool isLegal(const pair<int, int> &p) {
    if (position.count(make_pair(p.first, p.second + 1)) && 
        position.count(make_pair(p.first, p.second - 1)) && 
        position.count(make_pair(p.first + 1, p.second)) && 
        position.count(make_pair(p.first - 1, p.second))
    ) {
        return true;
    }
    return false;
}

int main() {
    int n, x, y;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        position.insert(make_pair(x, y));
    }

    for (auto &p : position) {
        if (isLegal(p)) {
            int count = 0;
            for (int i = 0; i < 2; i++) {
                if (position.count(make_pair(p.first + offset[i], p.second + offset[i])))
                    ++count;
                if (position.count(make_pair(p.first - offset[i], p.second + offset[i])))
                    ++count;
            }
            ++res[count];
        }
    }

    for (int t : res)
        cout << t << endl;

    return 0;
}