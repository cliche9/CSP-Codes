#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 1e6;
// deep[1][x]: 以x为根的子树到叶节点的最长距离
// deep[0][x]: 以x为根的子树到叶节点的最长距离方案
int deep[2][inf];
int res = 0, num = 0;
vector<int> nodes[inf];

void dfs(int cur, int pre) {
    bool isLeaf = true;
    for (auto &to : nodes[cur]) {
        if (to != pre) {
            isLeaf = false;
            dfs(to, cur);
            if (res < deep[1][cur] + deep[1][to] + 1) {
                // 直径小于当前直径, 直径和方案数均需要更新
                res = deep[1][cur] + deep[1][to] + 1;
                num = deep[0][cur] * deep[0][to];
            } else if (res == deep[1][cur] + deep[1][to] + 1)
                num += deep[0][cur] * deep[0][to];

            if (deep[1][cur] < deep[1][to] + 1) {
                // 新的最长距离, deep[0][cur] = deep[0][to], 替换成新最长距离的方案数
                deep[1][cur] = deep[1][to] + 1;
                deep[0][cur] = deep[0][to];
            } else if (deep[1][cur] == deep[1][to] + 1) 
                deep[0][cur] += deep[0][to];
        }
    }
    if (isLeaf) {
        deep[1][cur] = 0;
        deep[0][cur] = 1;
    }
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    dfs(1, 0);
    cout << res << ' ' << num;

    return 0;
}