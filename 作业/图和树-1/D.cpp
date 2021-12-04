#include <iostream>
using namespace std;

struct edge {
    int v;
    int next;
};

int head[100001] = {0};
edge Edges[200002];
bool vis[100001] = {false};
int distances[100001] = {0};
pair<int, int> farthest(0, 0);

void dfs(int u, int dis) {
    for (int i = head[u]; i != -1; i = Edges[i].next) {
        if (!vis[Edges[i].v]) {
            if (farthest.second < dis)
                farthest = make_pair(Edges[i].v, dis);
            distances[Edges[i].v] = max(distances[Edges[i].v], dis);
            vis[Edges[i].v] = true;
            dfs(Edges[i].v, dis + 1);
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
    for (int i = 1; i <= n; i++)
        head[i] = -1;

    int total = 0;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        Edges[total].v = b;
        Edges[total].next = head[a];
        head[a] = total++;
        Edges[total].v = a;
        Edges[total].next = head[b];
        head[b] = total++;
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