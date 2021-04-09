#include <iostream>
using namespace std;

int main() {
    freopen("作业/data/a.in", "r", stdin);
    freopen("作业/data/a.out", "w", stdout);
    int n = 0;
    string s;
    cin >> n;
    cin >> s;
    bool tag = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
            cout << s[i];
            tag = true;
        }
        else {
            if (tag) {
                cout << s[i];
                tag = false;
            }
        }
    }

    return 0;
}