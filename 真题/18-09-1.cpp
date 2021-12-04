#include <iostream>
using namespace std;

const int inf = 1e5;
int prices[inf];
int output[inf];

int main() {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    output[0] = (prices[0] + prices[1]) / 2;
    for (int i = 1; i < n - 1; i++)
        output[i] = (prices[i - 1] + prices[i] + prices[i + 1]) / 3;
    output[n - 1] = (prices[n - 1] + prices[n - 2]) / 2;

    for (int i = 0; i < n; i++)
        cout << output[i] << ' ';

    return 0;
}
