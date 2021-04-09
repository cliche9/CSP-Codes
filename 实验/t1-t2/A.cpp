#include <iostream>
using namespace std;

int counts[1000][5] = {0};

int main() {
    freopen("实验/t1-t2/a.in", "r", stdin);
    freopen("实验/t1-t2/a.out", "w", stdout);
    int n = 0, m = 0;
    int res = 0;
    int point = 0;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            counts[j][s[j] - 'A']++;
    }
    for (int i = 0; i < m; i++) {
        cin >> point;
        res += max({counts[i][0], counts[i][1], counts[i][2], counts[i][3], counts[i][4]}) * point;
    }

    cout << res << endl;
    return 0;
}