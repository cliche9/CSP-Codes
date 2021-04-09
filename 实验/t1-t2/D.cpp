#include <iostream>
using namespace std;

int main() {
    freopen("实验/t1-t2/a.in", "r", stdin);
    freopen("实验/t1-t2/a.out", "w", stdout);
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int count = 0;
        double n = 0;
        int a = 0, b = 0, c = 0;
        cin >> n >> a >> b >> c;
        string s;
        string ans;
        cin >> s;
        int t1 = a;
        int t2 = b;
        int t3 = c;
        for (auto ch : s) {
            if (ch == 'R') {
                if (b) {
                    b--;
                    count++;
                }
            }
            else if (ch == 'P') {
                if (c) {
                    c--;
                    count++;
                }
            }
            else {
                if (a) {
                    a--;
                    count++;
                }
            }
        }
        int m = ceil(n / 2.0);
        if (count < ceil(n / 2.0))
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (auto ch : s) {
                if (ch == 'R') {
                    if (t2) {
                        t2--;
                        cout << 'P';
                    }
                    else {
                        if (a) {
                            cout << 'R';
                            a--;
                        }
                        else if (c) {
                            cout << 'S';
                            c--;
                        }
                    }
                }
                else if (ch == 'P') {
                    if (t3) {
                        t3--;
                        cout << 'S';
                    }
                    else {
                        if (b) {
                            cout << 'P';
                            b--;
                        }
                        else if (a) {
                            cout << 'R';
                            a--;
                        }
                    }
                }
                else {
                    if (t1) {
                        t1--;
                        cout << 'R';
                    }
                    else {
                        if (b) {
                            cout << 'P';
                            b--;
                        }
                        else if (c) {
                            cout << 'S';
                            c--;
                        }
                    }
                }
            }
            cout << endl;
        }
    }

    return 0;
}