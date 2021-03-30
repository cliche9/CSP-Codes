#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;

list<int> windows;
unordered_map<int, long long> windowsLog;
int topWindow = -1;
bool isSetTopWindow = false;
int logNumber = 0;

void add(int u) {
    if (windowsLog.count(u))
        cout << "OpId #" << ++logNumber << ": same likeness.\n";
    else {
        windows.emplace_back(u);
        windowsLog[u] = 0;
        cout << "OpId #" << ++logNumber << ": success.\n";
    }
}

void close(int u) {
    if (windowsLog.count(u)) {
        if (isSetTopWindow && topWindow == u) {
            topWindow = -1;
            isSetTopWindow = false;
        }
        cout << "OpId #" << ++logNumber << ": close " << u << " with " << windowsLog[u] << ".\n";
        windows.remove(u);
        windowsLog.erase(u);
    }
    else 
        cout << "OpId #" << ++logNumber << ": invalid likeness.\n";
}

void chat(int w) {
    if (windows.empty())
        cout << "OpId #" << ++logNumber << ": empty.\n";
    else {
        if (isSetTopWindow)
            windowsLog[topWindow] += w;
        else
            windowsLog[windows.front()] += w;
        cout << "OpId #" << ++logNumber << ": success.\n";
    }
}

void rotate(int x) {
    if (x < 1 || x > windows.size())
        cout << "OpId #" << ++logNumber << ": out of range.\n";
    else {
        list<int>::iterator iter = windows.begin();
        int temp = 0;
        for (int i = 1; i < x; ++i)
            ++iter;
        temp = *iter;
        windows.erase(iter);
        windows.emplace_front(temp);
        cout << "OpId #" << ++logNumber << ": success.\n";
    }
}

void prior() {
    if (windows.empty())
        cout << "OpId #" << ++logNumber << ": empty.\n";
    else {
        int maxValue = *max_element(windows.begin(), windows.end());
        windows.remove(maxValue);
        windows.emplace_front(maxValue);
        cout << "OpId #" << ++logNumber << ": success.\n";
    }
}

void choose(int u) {
    if (windowsLog.count(u)) {
        windows.remove(u);
        windows.emplace_front(u);
        cout << "OpId #" << ++logNumber << ": success.\n";
    }
    else 
        cout << "OpId #" << ++logNumber << ": invalid likeness.\n";
}

void top(int u) {
    if (windowsLog.count(u)) {
        isSetTopWindow = true;
        topWindow = u;
        cout << "OpId #" << ++logNumber << ": success.\n";
    }
    else
        cout << "OpId #" << ++logNumber << ": invalid likeness.\n";
}

void untop() {
    if (isSetTopWindow) {
        isSetTopWindow = false;
        topWindow = -1;
        cout << "OpId #" << ++logNumber << ": success.\n";
    }
    else
        cout << "OpId #" << ++logNumber << ": no such person.\n";
}

void display() {
    if (windows.empty())
        return;
    if (isSetTopWindow) {
        if (windowsLog[topWindow] > 0)
            cout << "OpId #" << ++logNumber << ": Bye " << topWindow << ": " << windowsLog[topWindow] << ".\n";
        windows.remove(topWindow);
        windowsLog.erase(topWindow);
        isSetTopWindow = false;
        topWindow = -1;
    }
    while (!windows.empty()) {
        int iter = windows.front();
        if (windowsLog[iter] > 0)
            cout << "OpId #" << ++logNumber << ": Bye " << iter << ": " << windowsLog[iter] << ".\n";
        windows.pop_front();
        windowsLog.erase(iter);
    }
}

int main() {
    freopen("每月一题/a.in", "r", stdin);
    freopen("每月一题/a.out", "w", stdout);
    int group = 0, opts = 0;
    cin >> group;
    for (int i = 0; i < group; ++i) {
        cin >> opts;
        for (int j = 0; j < opts; ++j) {
            string opt;
            int number = 0;
            cin >> opt;
            if (opt == "Add") {
                cin >> number;
                add(number);
            }
            else if (opt == "Close") {
                cin >> number;
                close(number);
            }
            else if (opt == "Chat") {
                cin >> number;
                chat(number);
            }
            else if (opt == "Rotate") {
                cin >> number;
                rotate(number);
            }
            else if (opt == "Prior") {
                prior();
            }
            else if (opt == "Choose") {
                cin >> number;
                choose(number);
            }
            else if (opt == "Top") {
                cin >> number;
                top(number);
            }
            else if (opt == "Untop") {
                untop();
            }
        }
        display();
        logNumber = 0;
    }

    return 0;
}