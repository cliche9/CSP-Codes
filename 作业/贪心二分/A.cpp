#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int tracksLevel[30001] = {0};
map<pair<int, int>, int> intervals;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, m;
    int res = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        for (int j = l; j <= r; j++)
            tracksLevel[j]++;
        intervals[make_pair(l, r)] = k;
    }

    while (!intervals.empty()) {
        // 获取最大元素所在位置
        int max_index = max_element(tracksLevel + 1, tracksLevel + n + 1) - tracksLevel;
        // 在max_index处放一个垃圾桶，对应的level设为0，不可再放
        res++;
        tracksLevel[max_index] = 0;
        // 更新intervals，看是否有区间已经满足条件
        auto iter = intervals.begin();
        while (iter != intervals.end()) {
            if (iter->first.first <= max_index && iter->first.second >= max_index) {
                // erase已完成的interval，返回下一个位置
                if (iter->second == 1) {
                    // 更新tracksLevel
                    for (int i = iter->first.first; i <= iter->first.second; i++)
                        if (tracksLevel[i] > 0)
                            tracksLevel[i]--;
                    iter = intervals.erase(iter);
                    continue;
                }
                else
                    iter->second--;
            }
            iter++;
        }
    }

    cout << res << endl;
    return 0;
}