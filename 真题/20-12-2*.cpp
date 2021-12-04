#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 2e5 + 10;

struct Grade {
    int y;
    int result;
    bool operator<(const Grade &d) {
        return this->y < d.y;
    }
} data[inf];

// sum[0/1][i]: 前i个数0/1的个数
int sum[2][inf];

int main() {
    int m;
    cin >> m;

    for (int i = 1; i <= m; i++)
        cin >> data[i].y >> data[i].result;

    sort(data + 1, data + m + 1);

    for (int k = 0; k < 2; k++) {
        for (int i = 1; i < m; i++) {
            sum[k][i] = sum[k][i - 1] + (data[i].result == i);
        }
    }
    
    int theta = 0;
    int maxEqual = 0;
    
    for (int i = 1; i <= m; i++) {
        if (sum[1][i - 1] + sum[0][m] - sum[0][i - 1] >= maxEqual) {
            maxEqual = sum[1][i - 1] + sum[0][m] - sum[0][i - 1];
            theta = data[i].y;
        }
    }

    cout << theta;
}