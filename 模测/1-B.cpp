#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int res = 0;
    int tag = 0;    // 0-number; 1-capital; 2-...
    if (s.length() < 6) {
        cout << 0;
        return 0;
    }
    else {
        ++res;
        if (s[0] >= '0' && s[0] <= '9')
            tag = 0;
        else if (s[0] >= 'A' && s[0] <= 'Z')
            tag = 1;
        else 
            tag = 2;
        
        for (auto iter = s.begin() + 1; iter != s.end(); ++iter) {
            switch (tag) {
                case 0: {
                    if (*iter < '0' || *iter > '9')
                        ++res;
                    break;
                }
                case 1: {
                    if (*iter < 'A' || *iter > 'Z')
                        ++res;
                    break;
                }
                case 2: {
                    if (*iter < 'a' || *iter > 'z')
                        ++res;
                    break;
                }
            }
            if (*iter >= '0' && *iter <= '9')
                tag = 0;
            else if (*iter >= 'A' && *iter <= 'Z')
                tag = 1;
            else 
                tag = 2;
        }
    }
    cout << res << endl;
    return 0;
}