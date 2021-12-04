#include <iostream>
using namespace std;

int table[500001][26] = {0};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        for (int j = 0; j < 26; j++)
            table[i][j] = table[i - 1][j];
        table[i][c - 'A']++;
    }
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        int count = 0;
        cin >> l >> r;
        for (int j = 0; j < 26; j++)
            if (table[r][j] - table[l - 1][j] > 0)
                count++;
        if (count == 26)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0;
}