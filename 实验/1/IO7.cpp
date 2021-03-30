#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string inputstr;
    string individual;
    while (getline(cin, inputstr)) {
        int sum = 0;
        int t = 0;
        stringstream inputstrstream(inputstr);
        while (inputstrstream >> t)
            sum += t;
        cout << sum << endl;
    }
    
    return 0;
}