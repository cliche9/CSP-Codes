#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool tracks[30001] = {false};       // 标记某段是否已经放了桶
vector<pair<pair<int, int>, int> > intervals;       // 记录每一个区间

int main() {
    // 输入输出重定向，提交时需要删掉
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, m;
    long long res = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        // 存储l r k
        intervals.emplace_back(make_pair(l, r), k);
    }
    sort(intervals.begin(), intervals.end(), [](const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2) {
        // 按照r的大小，升序排列，然后依次处理数据（贪心）
        return p1.first.second < p2.first.second;
    });

    for (auto &intv : intervals) {
        // 遍历处理vector中存储的数据
        int hasLaidDown = 0;    // 当前区间，已经放置了几个垃圾桶
        for (int i = intv.first.first; i <= intv.first.second; i++)
            // 遍历当前区间
            if (tracks[i])  // 已经放置
                hasLaidDown++;
        int left_bucket = intv.second - hasLaidDown;        // 剩余该放的垃圾桶数目
        if (left_bucket > 0)        // 大于0，则此区间需要放桶
            res += left_bucket;
        for (int i = intv.first.second; i >= intv.first.first && left_bucket > 0; i--) {
            // 从后向前遍历，（贪心），将剩余的桶放在当前区间最后面
            if (!tracks[i]) {
                tracks[i] = true;           // track标记当前位置i放置了桶
                left_bucket--;
            }
        }
    }

    cout << res << endl;
    return 0;
}