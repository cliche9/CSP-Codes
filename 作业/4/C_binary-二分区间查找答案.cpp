#include <iostream>
using namespace std;

int n = 0;
int m = 0;
int w[100001] = {0};

bool check(int x) {
    int split_line = 0;
    int part_sum = 0;

    for (int i = 0; i < n; i++) {
        if (part_sum + w[i] <= x)
            part_sum += w[i];
        else {
            split_line++;
            part_sum = w[i];
            if (split_line > m - 1)
                return false;
        }
    }
    return true;
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    
    int left_bound = *max_element(w, w + n);
    int right_bound = 0;

    for (int i = 0; i < n; i++)
        right_bound += w[i];
    
    while (left_bound <= right_bound) {
        int mid = left_bound + (right_bound - left_bound) / 2;
        if (check(mid))
            right_bound = mid - 1;
        else
            left_bound = mid + 1;
    }
    // 最后left_bound = right_bound，所以输出谁都是对的
    cout << left_bound << endl;
    return 0;
}