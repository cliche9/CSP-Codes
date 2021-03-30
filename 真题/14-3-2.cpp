#include <iostream>
#include <list>
using namespace std;

struct position {
    pair<int, int> leftUp;
    pair<int, int> rightBottom;
    
    position(int a, int b, int c, int d): leftUp(a, b), rightBottom(c, d) {}
    position(const position& pos) {
        leftUp.first = pos.leftUp.first;
        leftUp.second = pos.leftUp.second;
        rightBottom.first = pos.rightBottom.first;
        rightBottom.second = pos.rightBottom.second;
    }
};

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    list<pair<position, int> > windows;
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        position temp(a, b, c, d);
        windows.emplace_front(temp, i);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        auto pos = windows.begin();
        for (; pos != windows.end(); ++pos) {
            if (x >= pos->first.leftUp.first && x <= pos->first.rightBottom.first && y >= pos->first.leftUp.second && y <= pos->first.rightBottom.second) {
                cout << pos->second << endl;
                position temp(pos->first);
                int num = pos->second;
                windows.erase(pos);
                windows.emplace_front(temp, num);
                break;
            }
        }
        if (pos == windows.end())
            cout << "IGNORED" << endl;
    }

    return 0;
}