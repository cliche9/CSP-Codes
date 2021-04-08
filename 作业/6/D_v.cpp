#include <iostream>
#include <vector>
using namespace std;

vector<int> neighbors[100001];
bool vis[100001] = {false};
int distances[100001] = {0};
pair<int, int> farthest(0, 0);

void dfs(int u, int dis) {
    for (auto v : neighbors[u]) {
        if (!vis[v]) {
            if (farthest.second < dis)
                farthest = make_pair(v, dis);
            distances[v] = max(distances[v], dis);
            vis[v] = true;
            dfs(v, dis + 1);
        }
    }
}

void init(int n) {
    for (int i = 1; i <= n; i++)
        vis[i] = false;
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    init(n);
    vis[1] = true;
    dfs(1, 1);
    init(n);
    vis[farthest.first] = true;
    dfs(farthest.first, 1);
    init(n);
    vis[farthest.first] = true;
    dfs(farthest.first, 1);

    for (int i = 1; i <= n; i++)
        cout << distances[i] << ' ';

    return 0;
}