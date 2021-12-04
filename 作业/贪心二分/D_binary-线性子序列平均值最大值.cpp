#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    int m = 0;
    cin >> n >> m;
    int weight[n];
    double diff_sum[n + 1];

    for (int i = 0; i < n; i++)
        cin >> weight[i];
    
    double left_bound = *min_element(weight, weight + n);
    double right_bound = *max_element(weight, weight + n);
    diff_sum[0] = 0;

    while (right_bound - left_bound > 1e-5) {
        double mid = left_bound + (right_bound - left_bound) / 2;
        double minSum = 0;
        bool tag = false;
        for (int i = 1; i <= n; i++) {
            diff_sum[i] = diff_sum[i - 1] + weight[i - 1] - mid;
            if (i >= m) {
                minSum = min(minSum, diff_sum[i - m]);
                if (diff_sum[i] > minSum) {
                    tag = true;
                    break;
                }
            }
        }
        if (tag)
            left_bound = mid;
        else
            right_bound = mid;
    }
    
    cout << (int)(right_bound * 1000) << endl;
    return 0;
}

// 空间优化
int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    int m = 0;
    cin >> n >> m;
    int weight[n];

    for (int i = 0; i < n; i++)
        cin >> weight[i];
    
    double left_bound = *min_element(weight, weight + n);
    double right_bound = *max_element(weight, weight + n);

    while (right_bound - left_bound > 1e-5) {
        double diff_sum = 0;
        double pre_diff_sum = 0;
        double minSum = 0;
        double mid = left_bound + (right_bound - left_bound) / 2;
        bool tag = false;
        for (int i = 0; i < n; i++) {
            diff_sum += (weight[i] - mid);
            if (i >= m - 1) {
                // 够了m个数
                if (i >= m) {
                    // m + 1个数开始才可能需要减去前面的
                    pre_diff_sum += (weight[i - m] - mid);
                    minSum = min(minSum, pre_diff_sum);
                }
                if (diff_sum > minSum) {
                    tag = true;
                    break;
                }
            }
        }
        if (tag)
            left_bound = mid;
        else
            right_bound = mid;
    }
    
    cout << (int)(right_bound * 1000) << endl;
    return 0;
}
