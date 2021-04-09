#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n = 0;
    map<char, int> mapping;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        mapping[c]++;
    }

    cout << min({mapping['R'], mapping['G'], mapping['B']}) << endl;
    return 0;
}