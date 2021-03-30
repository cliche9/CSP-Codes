#include <iostream>
using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n = 0;
    cin >> n;
    int matrix[n][n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    int count = 2 * n - 1;
    int row = 0, col = 0;
    for (int i = 0; i < count; i++) {
        if (i % 2 == 0) {
            while (row >= 0 && col < n)
                cout << matrix[row--][col++] << ' ';
            if (col < n)
                row++;
            else {
                row += 2;
                col--;
            }
        }
        else {
            while (col >= 0 && row < n)
                cout << matrix[row++][col--] << ' ';
            if (row < n) 
                col++;
            else {
                col += 2;
                row--;
            }
        }
    }

    return 0;
}

/* 对m * n的数组进行Z形输出

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int count = m + n - 1;

        int row = 0, col = 0;
        for (int i = 0; i < count; ++i) {
            if (i % 2 == 0) {
                while (row >= 0 && col < n)
                    res.emplace_back(matrix[row--][col++]);
                if (col < n)
                    row++;
                else {
                    row += 2;
                    col--;
                }
            }
            else {
                while (row < m && col >= 0)
                    res.emplace_back(matrix[row++][col--]);
                if (row < m)
                    col++;
                else {
                    col += 2;
                    row--;
                }
            }
        }
        
        return res;
    }
};

*/