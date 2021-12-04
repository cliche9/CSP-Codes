#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e6 + 1;
int dfsCount = 0;
int sccCount = 0;
int scc[N];
int dfn[N];
bool vis[N];
vector<int> G1[N], G2[N];
int n = 0;
// dfsCount : dfs序计数，sccCount : scc计数
// dfn[i] : dfs后序序列中第i个点，dfn存后序序列
// scc[i] : i号点所在scc编号

void dfs1(int x) {
    vis[x] = true;
    for (auto y : G1[x]) 
        if (!vis[y])
            dfs1(y);
    dfn[++dfsCount] = x;
}

void dfs2(int x) {
    scc[x] = sccCount;
    for (auto y : G2[x])
        if (!scc[y])
            dfs2(y);
}

void kosaraju() {
    dfsCount = sccCount = 0;
    memset(scc, 0, sizeof(scc));
    memset(vis, 0, sizeof(vis));
    // 第一遍dfs
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);
    
    // 第二遍dfs
    for (int i = n; i >= 1; i--)
        if (!scc[dfn[i]])
            ++sccCount, dfs2(dfn[i]);
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G1[a].push_back(b);
        G2[b].push_back(a);
    }
    kosaraju();
    // 计算完scc后，只需要考虑没有入度的scc个数即可，有入度的scc可以从其他scc抵达
    int inDegree[sccCount + 1];
    memset(inDegree, 0, sizeof(inDegree));
    for (int i = 1; i <= n; i++)
        for (auto y : G1[i])
            if (scc[i] != scc[y])
                inDegree[scc[y]]++;

    int res = 0;
    for (int i = 1; i <= sccCount; i++)
        if (!inDegree[i])
            res++;
    cout << res;
    return 0;
}