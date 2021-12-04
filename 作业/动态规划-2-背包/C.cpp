#include <iostream>
using namespace std;

int number[10010];
// first - weight / second - value
pair<int, int> things[10010];
pair<int, long long> split_things[1000010];
long long dp[10010];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++)
        cin >> things[i].first >> things[i].second >> number[i];
    
    // 二进制拆分
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int t = number[i];
        for (int k = 1; k <= t; k <<= 1) {
            cnt++;
            split_things[cnt].first = k * things[i].first;
            split_things[cnt].second = k * things[i].second;
            t -= k;
        }
        if (t > 0) {
            cnt++;
            split_things[cnt].first = t * things[i].first;
            split_things[cnt].second = t * things[i].second;
        }
    }

    for (int i = 1; i <= cnt; i++) {
        for (int w = v; w >= 1; w--) {
            if (w < split_things[i].first)
                continue;
            else
                dp[w] = max(dp[w], dp[w - split_things[i].first] + split_things[i].second);
        }
    }

    cout << dp[v];

    return 0;
}