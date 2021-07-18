#include <iostream>
#include <queue>
#define pa pair<int, int>
using namespace std;

const int inf = 1e6 + 10;
int n;
bool visit[inf];
int dist[inf];
vector<pa> graph[inf];
int neighbor[inf][inf];
int cnt[inf];

int dijkstra(int s, int t) {
    for (int i = 0; i <= n; i++)
        dist[i] = inf;
    priority_queue<pa, vector<pa>, greater<pa> > q;
    dist[s] = 0;
    visit[s] = true;
    q.push(make_pair(dist[s], s));
    while (!q.empty()) {
        int now = q.top().second;
        q.pop();
        if (visit[now])
            continue;
        visit[now] = true;
        for (auto &e : graph[now]) {
            if (dist[e.second] > dist[now] + e.first) {
                dist[e.second] = dist[now] + e.first;
                q.push(make_pair(dist[e.second], e.second));
            }
        }
    }
    return dist[t];
}

int spfa(int s, int t) {
    bool tag = false;
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        visit[now] = false;
        for (int i = 1; i <= n; i++) {
            if (neighbor[now][i] != inf && dist[i] > dist[now] + neighbor[now][i]) {
                dist[i] = dist[now] + neighbor[now][i];
                if (!visit[i]) {
                    visit[i] = true;
                    q.push(i);
                }
                cnt[i] = cnt[now] + 1;
            }
            if (cnt[i] >= n) {
                tag = true;
                break;
            }
        }
    }
    if (tag || dist[t] < 0)
        return -1;
    return dist[t];
}