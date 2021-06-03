#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

const int inf = 1e7;
long long sum[inf];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, m, a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }

    long long res = -1e9;
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && sum[q.back()] > sum[i])
            q.pop_back();
        q.push_back(i);
        while (!q.empty() && i - m > q.front())
            q.pop_front();
        res = max(res, sum[i] - sum[q.front()]);
    }
    cout << res;

    return 0;
}