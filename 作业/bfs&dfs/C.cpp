#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int neighbors[201][201];        // 邻接矩阵
bool vis[201];                  // 是否已到达

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    while (cin >> n && n != 0) {
        int a = 0, b = 0, ki = 0;
        int level = 0;          // 当前位于电梯第几层
        int res = 0;            
        cin >> a >> b;

        if (a <= 0 || a > n || b <= 0 || b > n) {
            cout << -1 << endl;
            continue;
        }

        memset(neighbors, 0, sizeof(neighbors));
        memset(vis, 0, sizeof(vis));
        
        for (int i = 0; i < n; i++) {
            cin >> ki;
            ++level;
            if (level - ki > 0) 
                neighbors[level][level - ki] = true;
            if (level + ki <= n)
                neighbors[level][level + ki] = true;
        }

        queue<int> q;
        q.push(a);
        vis[a] = true;
        while (!vis[b] && !q.empty()) {     // 到达b或者已遍历全图
            int size = q.size();            // 每次取出一层节点
            for (int i = 0; i < size; ++i) {    // 从当前一层节点进入下一层
                int cur = q.front();
                q.pop();
                for (int j = 1; j <= n; ++j) {
                    if (vis[j])             // 已到达的节点不再入队
                        continue;
                    if (neighbors[cur][j]) {    // 新到达的节点入队
                        q.push(j);
                        vis[j] = true;
                    }
                }
            }
            ++res;
        }
        if (vis[b])         // 到达了b
            cout << res << endl;
        else                // 未到达b
            cout << -1 << endl;
    }
    
    return 0;
}