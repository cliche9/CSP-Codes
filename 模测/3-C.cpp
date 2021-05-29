#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

// server[i] -- SERVER
// server[i][j] -- task[j]
// server[i][j]
struct task {
    int number;
    int inDegree;
    bool isNotCalculate;
    int serverOrTime;
    vector<int> to;
};

vector<task> server[10010];
ll serverTime[10001];

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
        for (auto &t : server[q][curTask].to)
            if (--server[q][t].inDegree == 0)
                seq.push(t);
    }
    serverTime[q] = res;
    return res;
}

int main() {
    freopen("模测/a.in", "r", stdin);
    freopen("模测/a.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        server[i].resize(k + 1);
        for (int j = 1; j <= k; j++) {
            server[i][j].number = j;
            int l;
            cin >> l;
            server[i][j].to.resize(l);
            for (int p = 0; p < l; p++) 
                cin >> server[i][j].to[p];
            cin >> server[i][j].isNotCalculate >> server[i][j].serverOrTime;
        }
    }
    memset(serverTime, -1, sizeof(serverTime));
    int q;
    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << ask(q) << endl;
    }

    return 0;
}