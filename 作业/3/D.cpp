#include <iostream>
using namespace std;

int res = 0;
int num = 0;
int *nums;

bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) 
            return false;
    return true;
}

void dfs(int k, int sum, int start) {
    if (k == 0) {
        if (isPrime(sum))
            ++res;
        return;
    }
    for (int i = start; i < num; i++) {
        start = i + 1;
        dfs(k - 1, sum + nums[i], start);
    }
}

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int k = 0;
    cin >> num >> k;
    nums = new int[num];
    for (int i = 0; i < num; ++i) 
        cin >> nums[i];
    dfs(k, 0, 0);
    cout << res;
    return 0;
}