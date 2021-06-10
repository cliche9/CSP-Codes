#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

// server[i] -- 
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
    ll serverOrTime;
    vector<wEdge> edges;
    task(int n = 0): number(n), inDegree(0), isNotCalculate(false), serverOrTime(0) {}
};

vector<task> server[10100];
ll serverTime[10100];
int n = 0;

ll query(int q) {
    if (serverTime[q] != -1)
        return serverTime[q];
    int size = server[q].size();
    ll timeTo[110];
    memset(timeTo, 0, sizeof(timeTo));
    queue<int> seq;
    for (int i = 1; i < size; i++)
        if (server[q][i].inDegree == 0)
            seq.push(i);
    
    while (!seq.empty()) {
        int curTask = seq.front();
        seq.pop();
        for (auto &e : server[q][curTask].edges) {
            if (server[q][curTask].isNotCalculate)
                timeTo[e.to] = max(timeTo[e.to], timeTo[curTask] + query(e.weight) + 1);
            else
                timeTo[e.to] = max(timeTo[e.to], timeTo[curTask] + e.weight);
            if (--server[q][e.to].inDegree == 0)
                seq.push(e.to);
        }
    }
    serverTime[q] = timeTo[size - 1];
    return serverTime[q];
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
            server[i][j].inDegree = l;
            for (int p = 0; p < l; p++) {
                int num = 0;
                cin >> num;
                server[i][num].edges.emplace_back(j, server[i][num].serverOrTime);
            }
            cin >> server[i][j].isNotCalculate >> server[i][j].serverOrTime;
        }
        server[i].emplace_back(k + 1);
        for (int j = 1; j <= k; j++) {
            if (server[i][j].edges.empty()) {
                server[i][j].edges.emplace_back(k + 1, server[i][j].serverOrTime);
                ++server[i][k + 1].inDegree;
            }
        }
    }

    memset(serverTime, -1, sizeof(serverTime));

    int q;
    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << query(q) << endl;
    }

    return 0;
}