#include <iostream>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int volumns[n];
    double res_avg = 0;
    double temp_avg = 0;
    int length = m;

    for (int i = 0; i < n; i++)
        cin >> volumns[i];

    for (int i = 0; i <= n - m; i++) {
        temp_avg = 0;
        for (int k = i; k < m + i; k++)
            temp_avg += volumns[k];
        temp_avg /= m;
        length = m;
        res_avg = max(res_avg, temp_avg);
        for (int j = m + i; j < n; j++) {
            temp_avg = (temp_avg * length + volumns[j]) / (length + 1);
            length++;
            res_avg = max(res_avg, temp_avg);
        }
    }
    
    cout << (int)(res_avg * 1000) << endl;

    return 0;
}
