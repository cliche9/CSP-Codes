#include <iostream>
using namespace std;

char s[200001];

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    cin >> n;
    cin >> s;
    int alphas[26] = {0};
    int count = 0;
    int left = 0, right = 0;
    int length = __INT_MAX__;
    while (left < n) {
        while (count < 26 && right < n) {
            if (alphas[s[right] - 'A']++ == 0)
                count++;
            right++;
        }
        if (count == 26)
            length = min(length, right - left);
        else
            break;

        if (--alphas[s[left] - 'A'] == 0)
            count--;
        left++;
    }
    cout << length << endl;
    
    return 0;
}