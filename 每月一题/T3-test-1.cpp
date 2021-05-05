#include <iostream>
using namespace std;

void oneLoop(int level, int *before, int times) {
    // 递归层数，前一层的结果数组，倍数
    int temp[11] = {0};
    string s, num;
    int coeff = 0;
    int coeff_t = 0;
    while (cin >> s) {
        if (s == "END")
            break;
        else if (s == "LOOP") {
            cin >> num;
            if (num == "n")
                oneLoop(level + 1, temp, 1);
            else {
                int new_times = stoi(num);
                oneLoop(level, temp, new_times);
            }
        }
        else {
            cin >> coeff_t;
            coeff += coeff_t;
        }
    }
    temp[level] += coeff;
    for (int i = level; i <= 10; i++)
        temp[i] *= times;
    for (int i = level; i <= 10; i++)
        before[i] += temp[i];
}

int main() {
    int t = 0, coeff = 0;
    // coeff系数
    int res[11] = {0};
    int level = 0;
    string s, num;
    // 接收操作和数字
    cin >> s;
    while (cin >> s) {
        if (s == "LOOP") {
            cin >> num;
            if (num == "n")
                // 倍数为1
                oneLoop(level + 1, res, 1);
            else {
                int new_times = stoi(num);
                // 倍数更新
                oneLoop(level, res, new_times);
            }
        }
        else if (s == "OP") {
            cin >> t;
            coeff += t;
        }
    }
    res[level] += coeff;
    
    int count = 0;
    for (int i = 0; i <= 10; i++)
        if (res[i])
            count++;
    cout << "Runtime = ";
    if (count == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 10; i >= 2; i--) {
        if (res[i] == 0)
            continue;
        if (count == 1) {
            if (res[i] == 1)
                cout << "n^" << i;
            else
                cout << res[i] << "*n^" << i;
        }
        else {
            if (res[i] == 1)
                cout << "n^" << i << "+";
            else
                cout << res[i] << "*n^" << i << "+";
        }
        count--;
    }
    if (res[1]) {
        if (res[1] == 1)
            cout << "n";
        else
            cout << res[1] << "*n";
        if (res[0])
            cout << "+" << res[0] << endl;
    }
    else
        if (res[0])
            cout << res[0] << endl;

    return 0;
}