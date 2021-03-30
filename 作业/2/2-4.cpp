#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    freopen("作业/a.in", "r", stdin);
    freopen("作业/a.out", "w", stdout);
    int m = 0, opt = 0;
    string word;
    map<string, bool> dict;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> opt;
        switch(opt) {
            case 1: {
                cin >> word;
                if (!dict.count(word)) {
                    dict[word] = true;
                    cout << "write" << endl;
                }
                else 
                    cout << "found" << endl;
                break;
            }
            case 2: {
                cin >> word;
                if (dict.count(word)) {
                    dict.erase(word);
                    cout << "erased" << endl;
                }
                else 
                    cout << "not found" << endl;
                break;
            }
            case 3: {
                for (auto &wd : dict)
                    cout << wd.first << ' ';
                cout << endl;
            }
        }
    }
    
    return 0;
}