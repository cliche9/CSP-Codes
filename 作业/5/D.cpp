#include <iostream>
#include <stack>
using namespace std;

int heights[100002] = {0};

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> heights[i];
    
    long long int res = -__INT_MAX__ - 1;

    for (int i = 1; i <= n; i++) {
        stack<int> low;
        long long int left = 0, right = 0;
        low.push(i);
        for (int j = i - 1; j >= 0; j--) {
            while (!low.empty() && heights[j] < heights[low.top()])
                low.pop();
            if (low.empty()) {
                low.push(j);
                break;
            }
            low.push(j);
        }
        left = low.top() + 1;
        low.pop();
        low.push(i);
        for (int j = i + 1; j < n + 2; j++) {
            while (!low.empty() && heights[j] < heights[low.top()])
                low.pop();
            if (low.empty()) {
                low.push(j);
                break;
            }
            low.push(j);
        }
        right = low.top() - 1;
        low.pop();
        res = max(res, heights[i] * (right + 1 - left));
    }
    cout << res << endl;
    return 0;
}