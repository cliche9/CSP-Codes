#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e6 + 10;
int n, a[N];
stack<int> s;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    s.push(a[1]);
    for (int i = 2; i <= n ; i++) {
        while (s.size() && a[i] <= s.top()) {
            s.pop();
        }
        s.push(a[i]);
    }
    cout << s.size() << "\n";

    return 0;
}