#include <iostream>
using namespace std;

const int inf = 1e2 + 10;

struct ball {
    int x;
    int v;
} balls[inf];

int main() {
    int n, L, t;
    cin >> n >> L >> t;

    for (int i = 0; i < n; i++) {
        cin >> balls[i].x;
        balls[i].v = 1;
    }

    for (int i = 0; i < t; i++) {
        for (int b = 0; b < n; b++) {
            // 判断两侧边界
            if (balls[b].x == L || balls[b].x == 0)
                balls[b].v = -balls[b].v;
            // 判断碰撞
            for (int j = 0; j < n; j++) {
                if (j != b && balls[b].x == balls[j].x) {
                    balls[b].v = -balls[b].v;
                    balls[j].v = -balls[j].v;
                }
            }
            // 运动1s
            balls[b].x += balls[b].v;
        }
    }

    for (int i = 0; i < n; i++)
        cout << balls[i].x << ' ';

    return 0;
}