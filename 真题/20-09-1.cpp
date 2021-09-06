#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

pair<double, int> dist[210];

int main() {
    int n, x, y, xi, yi;
    cin >> n >> x >> y;

    for (int i = 1; i <= n; i++) {
        cin >> xi >> yi;
        dist[i].first = sqrt(pow(xi - x, 2) + pow(yi - y, 2));
        dist[i].second = i;
    }
    sort(dist, dist + n);

    cout << dist[1].second << endl
         << dist[2].second << endl
         << dist[3].second;

    return 0;
}