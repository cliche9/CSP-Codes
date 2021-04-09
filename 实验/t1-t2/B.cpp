#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main() {
    freopen("实验/t1-t2/a.in", "r", stdin);
    freopen("实验/t1-t2/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    list<int> nums(n);
    for (auto &i : nums)
        cin >> i;

    nums.sort();
    int res = 0;
    while (!nums.empty()) {
        res++;
        auto iter = nums.begin();
        int color = *iter;
        while (iter != nums.end()) {
            if (*iter % color == 0) {
                iter = nums.erase(iter);
            }
            else 
                iter++;
        }
    }
    cout << res << endl;
    return 0;
}