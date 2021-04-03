#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> res_min;
vector<int> res_max;
int nums[1000000];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    deque<int> min, max;
    int n = 0, k = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        while (!min.empty() && nums[min.back()] > nums[i])
            min.pop_back();
        while (!max.empty() && nums[max.back()] < nums[i])
            max.pop_back();
        min.push_back(i);
        max.push_back(i);
        if (i + 1 >= k) {
            if (min.front() < i + 1 - k)
                min.pop_front();
            if (max.front() < i + 1 - k)
                max.pop_front();
            res_min.emplace_back(min.front());
            res_max.emplace_back(max.front());
        }
    }

    for (auto idx : res_min)
        cout << nums[idx] << ' ';
    cout << endl;
    for (auto idx : res_max)
        cout << nums[idx] << ' ';
    cout << endl;

    return 0;
}