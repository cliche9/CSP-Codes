#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;
    int w;
} edges[200002];

int unions[100001];

bool cmp(const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
}

void init(int n) {
    for (int i = 0; i <= n; i++)
        unions[i] = i;
} 

int find(int x) {
    return unions[x] == x ? x : unions[x] = find(unions[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    unions[x] = y;
    return true;
}

long long kruskal(int e, int v) {
    long long ans = 0;
    sort(edges, edges + e, cmp);
    int cnt = 0;
    for (int i = 0; i < e; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            ans += edges[i].w;
            if (cnt++ == v - 1)
                break;
        }
    }

    return ans;
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    
    int n = 0, m = 0, p = 0;
    cin >> n >> m >> p;
    init(n);
    for (int i = 0; i < n; i++) {
        edges[i].u = 0;
        edges[i].v = i + 1;
        edges[i].w = p;
    }
    m += n;
    for (int i = n; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i].u = a;
        edges[i].v = b;
        edges[i].w = c;
    }

    cout << kruskal(m, n) << endl;

    return 0;
}