#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    int res = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        s[i] = (s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ? 'a' : s[i];
    
    int length = s.length();
    int left = 0, right = 0;
    for (int i = 1; i < length - 1; i++) {
        left = right = i;
        int t_res = 0;
        while (left >= 0 && right < length) {
            if (s[left] != s[right])
                break;
            t_res += 2;
            left--;
            right++;
        }
        res = max(res, t_res - 1);
    }
    for (int i = 1; i < length; i++) {
        left = i - 1;
        right = i;
        int t_res = 0;
        while (left >= 0 && right < length) {
            if (s[left] != s[right])
                break;
            t_res += 2;
            left--;
            right++;
        }
        res = max(res, t_res);
    }

    cout << res;

    return 0;
}