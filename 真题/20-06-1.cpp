#include <iostream>
using namespace std;

struct {
    int x;
    int y;
    char type;
} points[1010];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y >> points[i].type;

    int t0, t1, t2;
    bool tagA, tagB;
    for (int i = 0; i < m; i++) {
        cin >> t0 >> t1 >> t2;
        if (points[0].type == 'A') {
            tagA = (t0 + points[0].x * t1 + points[0].y * t2 > 0);
            tagB = !tagA;
        } else {
            tagB = (t0 + points[0].x * t1 + points[0].y * t2 > 0);
            tagA = !tagB;
        }

        bool divided = true;
        for (int i = 1; i < n; i++) {
            if (points[i].type == 'A') {
                if ((t0 + points[i].x * t1 + points[i].y * t2 > 0) != tagA) {
                    cout << "No\n";
                    divided = false;
                    break;
                }
            } else {
                if ((t0 + points[i].x * t1 + points[i].y * t2 > 0) != tagB) {
                    cout << "No\n";
                    divided = false;
                    break;
                }
            }
        }
        if (divided)
            cout << "Yes\n";
    }
    return 0;
}