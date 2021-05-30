#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

// server[i] -- SERVER
// server[i][j] -- task[j]
// server[i][j]
struct wEdge {
    int to;
    ll weight;
    wEdge(int t = 0, ll w = 0): to(t), weight(w) {}
};

struct task {
    int number;
    int inDegree;
    bool isNotCalculate;
    int serverOrTime;
    vector<wEdge> edges;
    task(int n = 0): number(n) {}
};

vector<task> server[10010];
ll serverTime[10010];
int sequence[10010];
int n = 0;

ll ask(int q) {
    if (serverTime[q] != -1)
        return serverTime[q];
    ll res = 0;
    queue<int> seq;
    for (auto &t : server[q])
        if (t.inDegree == 0)
            seq.push(t.number);
    while (!seq.empty()) {
        int curTask = seq.front();
        seq.pop();
        if (server[q][curTask].isNotCalculate)
            res += ask(server[q][curTask].serverOrTime) + 1;
        else
            res += server[q][curTask].serverOrTime;
        for (auto &e : server[q][curTask].edges)
            if (--server[q][e.to].inDegree == 0)
                seq.push(e.to);
    }
    serverTime[q] = res;
    return res;
}

void init() {
    for (int i = 1; i <= n; i++)
        ask(i);
    
    for (int i = 1; i <= n; i++) {
        int size = server[i].size();
        server[i].emplace_back(size + 1);
        for (int j = 1; j <= size; j++) {
            if (server[i][j].edges.empty()) {
                server[i][j].edges.emplace_back(size + 1, (server[i][j].isNotCalculate ? 1 + serverTime[server[i][j].serverOrTime] : server[i][j].serverOrTime));
                break;
            }
            for (auto &e : server[i][j].edges)
                e.weight = (server[i][j].isNotCalculate ? 1 + serverTime[server[i][j].serverOrTime] : server[i][j].serverOrTime);
        }
    }
}

ll query(int q) {
    queue<int> seq;
    ll dis[server[q].size()];
    memset(dis, 0, sizeof(0));
    for (auto &t : server[q])
        if (t.inDegree == 0)
            seq.push(t.number);
    while (!seq.empty()) {
        int curTask = seq.front();
        seq.pop();
        for (auto &e : server[q][curTask].edges) {
            dis[e.to] = max(dis[e.to], dis[curTask] + e.weight);
            if (--server[q][e.to].inDegree == 0)
                seq.push(e.to);
        }
    }
    return dis[server[q].size()];
}

int main() {
    freopen("模测/a.in", "r", stdin);
    freopen("模测/a.out", "w", stdout);
    int m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        server[i].resize(k + 1);
        for (int j = 1; j <= k; j++) {
            server[i][j].number = j;
            int l;
            cin >> l;
            server[i][j].edges.resize(l + 1);
            for (int p = 0; p < l; p++) {
                int num = 0;
                cin >> num;
                server[i][j].edges[l].to = num;
                ++server[i][num].inDegree;
            }
            cin >> server[i][j].isNotCalculate >> server[i][j].serverOrTime;
        }
    }

    memset(serverTime, -1, sizeof(serverTime));
    init();

    int q;
    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << query(q) << endl;
    }

    return 0;
}