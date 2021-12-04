#include <iostream>
#include <deque>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0, k = 0;
    cin >> n >> k;
    int number = 0;
    deque<int> members;
    for (int i = 1; i <= n; ++i)
        members.emplace_back(i);
    
    while (members.size() > 1) {
        int cur = members.front();
        members.pop_front();
        ++number;
        if (number % 10 != k && number % k != 0)
            members.emplace_back(cur);
    }

    cout << members.front();

    return 0;
}