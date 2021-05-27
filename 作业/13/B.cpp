#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    string s;
    unordered_map<char, int> m;
    cin >> s;
    for (auto c : s)
        ++m[c];
    cout << abs(m['('] - m[')']) + abs(m['['] - m[']']);
    return 0;
}