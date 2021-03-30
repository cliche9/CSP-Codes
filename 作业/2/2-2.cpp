#include <iostream>
#include <map>
using namespace std;

int main() {
    freopen("作业/a.in", "r", stdin);
    freopen("作业/a.out", "w", stdout);
    map<int, int> mapping;
    int n = 0;
    int t = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        mapping[t]++;
        cout << mapping[t] << ' ';
    }

    return 0;
}