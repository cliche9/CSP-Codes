#include <iostream>
#include <stack>
using namespace std;

int heights[100002] = {0};
pair<long long, long long> bound[100002];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> heights[i];
    
    stack<long long> stk;
    // 位置0对应的附加高度
    // 从左往右遍历，找右边界
    stk.push(0);
    for (int i = 1; i <= n + 1; i++) {
        while (!stk.empty() && heights[i] < heights[stk.top()]) {
            // 当前heights[i]高度比递增栈栈顶元素小，说明右边界不能再扩大了，栈顶元素对应的右边界就是i - 1
            bound[stk.top()].second = i - 1;
            stk.pop();
        }
        // 右边界可以扩大，所以push新元素
        stk.push(i);
    }
    // 栈中剩余的元素，由于已经遍历完所有元素，所以都是以最右端为边界的
    while (!stk.empty()) {
        bound[stk.top()].second = n;
        stk.pop();
    }

    stk.push(n + 1);
    // 从右往左遍历，找左边界
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && heights[i] < heights[stk.top()]) {
            bound[stk.top()].first = i + 1;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        bound[stk.top()].first = 1;
        stk.pop();
    }

    long long res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, (bound[i].second - bound[i].first + 1) * heights[i]);

    cout << res << endl;
    return 0;
}