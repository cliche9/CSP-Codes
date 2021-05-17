#include <iostream>
#include <vector>
using namespace std;

vector<string> page(1);
bool shift_on = false;
bool selected = false;
vector<string> selected_string;
vector<string> copy_string;
pair<int, int> cursor(0, 0);
pair<int, int> log_point(0, 0);

void _remove() {
    if (log_point.first <= cursor.first) {
        page[log_point.first] = page[log_point.first].substr(0, log_point.second) + page[cursor.first].substr(cursor.second);
        for (int i = cursor.first; i >= log_point.first + 1; --i)
            page.erase(page.begin() + i);
        cursor = log_point;
    }
    else {
        page[cursor.first] = page[cursor.first].substr(0, cursor.second) + page[log_point.first].substr(log_point.second);
        for (int i = log_point.first; i >= cursor.first + 1; --i)
            page.erase(page.begin() + i);
    }
    selected = false;
    selected_string.clear();
}

void _move(const string &cmd) {
    selected = false;
    selected_string.clear();
    if (cmd == "Home")
        cursor.second = 0;
    else if (cmd == "End")
        cursor.second = page[cursor.first].length();
    else if (cmd == "Up") {
        if (cursor.first == 0)
            return;
        --cursor.first;
        if (page[cursor.first].length() < cursor.second)
            cursor.second = page[cursor.first].length();
    }
    else if (cmd == "Down") {
        if (cursor.first == page.size() - 1)
            return;
        ++cursor.first;
        if (page[cursor.first].length() < cursor.second)
            cursor.second = page[cursor.first].length();
    }
    else if (cmd == "Left") {
        if (cursor.first == 0 && cursor.second == 0)
            return;
        if (cursor.second == 0) {
            --cursor.first;
            cursor.second = page[cursor.first].length();
        } else
            --cursor.second;
    }
    else {
        if ((cursor.first == page.size() - 1) && (cursor.second == page[cursor.first].length()))
            return;
        if (cursor.second == page[cursor.first].length()) {
            ++cursor.first;
            cursor.second = 0;
        } else
            ++cursor.second;
    }
}

void insert(const string &cmd) {
    if (cmd == "Paste" && copy_string.empty())
        return;
    if (selected)
        _remove();
    if (cmd == "Enter") {
        // 新建一行
        page.push_back("");
        // 不动的行下移
        for (int i = page.size() - 1; i > cursor.first + 1; --i)
            page[i] = page[i - 1];
        // 处理动的行
        page[cursor.first + 1] = page[cursor.first].substr(cursor.second);
        page[cursor.first] = page[cursor.first].substr(0, cursor.second);
        // 改变光标位置
        ++cursor.first;
        cursor.second = 0;
    } else if (cmd == "Space") {
        page[cursor.first] = page[cursor.first].substr(0, cursor.second) + ' ' + page[cursor.first].substr(cursor.second);
        ++cursor.second;
    } else if (cmd == "Paste") {
        // 一行
        if (copy_string.size() == 1) {
            page[cursor.first] = page[cursor.first].substr(0, cursor.second) + copy_string[0] + page[cursor.first].substr(cursor.second);
            cursor.second += copy_string[0].size();
        }
        // 多行
        else {
            page[cursor.first] = 
        }
    } else {
        char c;
        cin >> c;
        page[cursor.first] = page[cursor.first].substr(0, cursor.second) + c + page[cursor.first].substr(cursor.second);
        ++cursor.second;
    }
}

void remove(const string &cmd) {
    if (selected) {
        _remove();
        return;
    }
    if (cmd == "Del") {
        if ((cursor.first == page.size() - 1) && (cursor.second == page[cursor.first].length()))
            return;
        if (cursor.second == page[cursor.first].length()) {
            page[cursor.first] += page[cursor.first + 1];
            page.erase(page.begin() + cursor.first + 1);
        } else 
            page[cursor.first] = page[cursor.first].substr(0, cursor.second) + page[cursor.first].substr(cursor.second + 1);
    } else {
        if (cursor.first == 0 && cursor.second == 0)
            return;
        if (cursor.second == 0) {
            page[cursor.first - 1] += page[cursor.first];
            page.erase(page.begin() + cursor.first);
            --cursor.first;
            cursor.second = page[cursor.first].length();
        } else {
            page[cursor.first] = page[cursor.first].substr(0, cursor.second - 1) + page[cursor.first].substr(cursor.second);
            --cursor.second;
        }
    }
}

void shift() {
    shift_on = !shift_on;
    if (shift_on) {
        if (!selected)
            log_point = cursor;
        selected = false;
        selected_string.clear();
    }
    else {
        if (log_point != cursor)
            selected = true;
        // 更新选中的string
        if (selected) {
            if (cursor.first == log_point.first)
                selected_string = page[cursor.first].substr(min(cursor.second, log_point.second), abs(cursor.second - log_point.second));
            else if (cursor.first > log_point.first){
                selected_string = page[log_point.first].substr(log_point.second);
                for (int i = log_point.first + 1; i < cursor.first; ++i)
                    selected_string += page[i];
                selected_string += page[cursor.first].substr(0, cursor.second);
            }
            else {
                selected_string = page[cursor.first].substr(cursor.second);
                for (int i = cursor.first + 1; i < log_point.first; ++i)
                    selected_string += page[i];
                selected_string += page[log_point.first].substr(0, log_point.second);
            }
        }
    }
}

void find(const string &word) {
    int res = 0;
    if (selected) {
        int pos = 0;
        while (pos < selected_string.size()) {
            pos = selected_string.find(word, pos);
            if (pos == string::npos)
                break;
            ++res;
            pos += selected_string.size();
        }
    } else {
        for (int i = 0; i < page.size(); ++i) {
            int pos = 0;
            while (pos < page[i].size()) {
                pos = page[i].find(word, pos);
                if (pos == string::npos)
                    break;
                ++res;
                pos += page[i].size();
            }
        }
    }
    cout << res << '\n';
}

void count() {
    int res = 0;
    if (selected) {
        for (auto c : selected_string)
            if (c != ' ')
                ++res;
    }
    else
        for (int i = 0; i < page.size(); ++i)
            for (auto c : page[i])
                if (c != ' ')
                    ++res;
    cout << res << '\n';
}

void copy() {
    if (selected)
        copy_string = selected_string;
    else if (!page[cursor.first].empty())
       copy_string = page[cursor.first];
}

void print() {
    for (int i = 0; i < page.size(); ++i)
        cout << page[i] << '\n';
}

int main() {
    freopen("每月一题/a.in", "r", stdin);
    freopen("每月一题/a.out", "w", stdout);
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string inst, cmd;
        cin >> inst;
        if (inst == "MOVE") {
            cin >> cmd;
            _move(cmd);
        } else if (inst == "INSERT") {
            cin >> cmd;
            insert(cmd);
        } else if (inst == "REMOVE") {
            cin >> cmd;
            remove(cmd);
        } else if (inst == "SHIFT") {
            shift();
        } else if (inst == "FIND") {
            cin >> cmd;
            find(cmd);
        } else if (inst == "COUNT") {
            count();
        } else if (inst == "COPY") {
            copy();
        } else {
            print();
        }
    }

    return 0;
}