#include <iostream>
using namespace std;

bool matrix[8][8];
bool tag[8];        // tag[i]记录第i列是否可以放棋子
int res = 0, n = 0;

void backtrack(int left, int row) {
    if (left == 0) {
        res++;
        return;
    }
    if (left > n - row)
        return;
    
    for (int col = 0; col < n; ++col) {
        if (matrix[row][col] == 0 && tag[col]) {
            matrix[row][col] = false;
            tag[col] = false;
            backtrack(left - 1, row + 1);
            matrix[row][col] = true;
            tag[col] = true;
        }
    }
    backtrack(left, row + 1);
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int k = 0;
    while (cin >> n >> k && n != -1 && k != -1) {
        res = 0;
        for (int i = 0; i < n; ++i) {
            tag[i] = true;
            for (int j = 0; j < n; ++j) {
                char t;
                cin >> t;
                if (t == '.')
                    matrix[i][j] = false;
                else
                    matrix[i][j] = true;
            }
        }
        backtrack(k, 0);
        cout << res << endl;
    }
    return 0;
}