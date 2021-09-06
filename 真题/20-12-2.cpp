#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 1e5 + 10;
// s[][i]: 前i个数0的个数, 1的个数
int s[2][inf];

struct Grade {
    int y;
    int result;
    bool operator<(const Grade& t) const {
        return y < t.y;
    }
} data[inf];

int main() {
    int m = 0;
    cin >> m;

    for (int i = 1; i <= m; i++)
        cin >> data[i].y >> data[i].result;
    sort(data + 1, data + m + 1);

    // 建立前缀和
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i][j - 1] + (data[j].result == i);
        }
    }

    int res = 0, maxCount = 0;
    for (int i = 1; i <= m; i++) {
        // 对于每个数, 看前半段0个数和后半段1个数
        int theta = data[i].y;
        int count = s[0][i - 1] + s[1][m] - s[1][i - 1];
        if (count >= maxCount) {
            maxCount = count;
            res = theta;
        }
        // 跳过相同值
        while (i + 1 <= m && theta == data[i + 1].y)
            ++i;
    }

    cout << res;

    return 0;
}