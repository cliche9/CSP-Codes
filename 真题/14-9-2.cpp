#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    bool isVisited[103][103];
    memset(isVisited, 0, sizeof(isVisited));
    int res = 0;
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2 - 1; ++j) {
            for (int k = y1; k <= y2 - 1; ++k) {
                if (!isVisited[j][k])
                    ++res;
                isVisited[j][k] = true;
            }
        }
    }
    cout << res;
    
    return 0;
}