#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxValue = 1e6;
vector<int> students[maxValue + 1];
int inDegree[maxValue + 1] = {0};
vector<int> res;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        students[a].push_back(b);
        inDegree[b]++;
    }
    priority_queue<int, vector<int>, greater<int> > topoQueue;
    for (int i = 1; i <= n; i++) {
        if (!inDegree[i])
            topoQueue.push(i);
    }
    int level = 1;

    while (!topoQueue.empty()) {
        int u = topoQueue.top();
        topoQueue.pop();
        res.push_back(u);
        for (auto v : students[u])
            if (--inDegree[v] == 0)
                topoQueue.push(v);
    }

    for (auto e : res)
        cout << e << ' ';

    return 0;
}